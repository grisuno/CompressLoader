/*
 * LZ4 - Fast LZ compression algorithm
 * Implementation
 * Copyright (C) 2011-2020, Yann Collet.
 * BSD 2-Clause License (see lz4.h for full license)
 */

#include "lz4.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/*-************************************
 *  Macros
 **************************************/
#define LZ4_ALIGN(x) (((x) + 3) & ~3)
#define LZ4_ARCH_64
#define LZ4_FAST_DEC_LOOP 1

/*-************************************
 *  Basic Types
 **************************************/
typedef uint8_t BYTE;
typedef uint16_t U16;
typedef uint32_t U32;
typedef int32_t S32;
typedef uint64_t U64;

#ifndef MEMORY_SANITIZER
#  define MEMORY_SANITIZER 0
#endif

/*-************************************
 *  Constants
 **************************************/
#define LZ4_8_BIT 0
#define LZ4_16_BIT 1
#define LZ4_32_BIT 2
#define LZ4_64_BIT 3

#ifndef LZ4_64K
#define LZ4_64K ((1 << 16))
#endif

#define LZ4_MEMORY_USAGE 14
#define LZ4_MAX_INPUT_SIZE 0x7E000000   /* 2 113 929 216 bytes */
#define LZ4_COMPRESSBOUND(isize)  ((unsigned)(isize) > (unsigned)LZ4_MAX_INPUT_SIZE ? 0 : (isize) + ((isize)/255) + 16)

/*-************************************
 *  Internal state
 **************************************/
typedef struct {
    U32 hashTable[LZ4_64K + 1];
    const BYTE* dictionary;
    U32 dictSize;
    U32 currentOffset;
} LZ4_streamDecode_t_internal;

/*-************************************
 *  Private functions
 **************************************/
static U32 LZ4_read32(const void* ptr) {
    U32 val;
    memcpy(&val, ptr, 4);
    return val;
}

static void LZ4_write32(void* ptr, U32 value) {
    memcpy(ptr, &value, 4);
}

static U16 LZ4_read16(const void* ptr) {
    U16 val;
    memcpy(&val, ptr, 2);
    return val;
}

static void LZ4_write16(void* ptr, U16 value) {
    memcpy(ptr, &value, 2);
}

static U64 LZ4_read64(const void* ptr) {
    U64 val;
    memcpy(&val, ptr, 8);
    return val;
}

/*-************************************
 *  Core decompression function
 **************************************/
int LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize) {
    return LZ4_decompress_safe_usingDict(src, dst, compressedSize, maxDecompressedSize, NULL, 0);
}

int LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompressedSize, const char* dictStart, int dictSize) {
    const BYTE* ip = (const BYTE*)src;
    const BYTE* const iend = ip + compressedSize;
    BYTE* op = (BYTE*)dst;
    BYTE* const oend = op + maxDecompressedSize;
    const BYTE* const dictEnd = (const BYTE*)dictStart + dictSize;
    const BYTE* dict = (const BYTE*)dictStart;

    if (compressedSize < 4) return -1; /* too small */
    if (maxDecompressedSize < 0) return -1; /* invalid */

    /* Main loop: decode sequences */
    while (1) {
        unsigned token = *ip++;
        unsigned literalLength = token >> 4;
        unsigned matchLength = token & 0xF;

        /* Decode literal length */
        if (literalLength == 0xF) {
            do {
                if (ip >= iend) return -2;
                literalLength += *ip++;
            } while (literalLength == 255);
        }

        /* Copy literals */
        if (literalLength > 0) {
            if (op + literalLength > oend) return -3;
            if (ip + literalLength > iend) return -4;
            memcpy(op, ip, literalLength);
            op += literalLength;
            ip += literalLength;
        }

        if (ip >= iend) break; /* end of stream */

        /* Decode offset */
        if (ip + 2 > iend) return -5;
        U16 offset = LZ4_read16(ip);
        ip += 2;

        if (offset == 0) return -6;

        /* Decode match length */
        if (matchLength == 0xF) {
            do {
                if (ip >= iend) return -7;
                matchLength += *ip++;
            } while (matchLength == 255);
        }
        matchLength += 4; /* minimum match length */

        /* Copy match */
        if (offset <= (size_t)(op - (BYTE*)dst)) {
            /* within current output */
            if (op + matchLength > oend) return -8;
            BYTE* match = op - offset;
            if (matchLength == 4 && (match == op - offset)) {
                /* fast path for small match */
                *op++ = *match++;
                *op++ = *match++;
                *op++ = *match++;
                *op++ = *match++;
            } else {
                while (matchLength--) {
                    *op++ = *match++;
                }
            }
        } else {
            /* offset references dictionary */
            size_t dictOffset = offset - (size_t)(op - (BYTE*)dst);
            if (dictOffset > dictSize) return -9;
            const BYTE* match = dictEnd - dictOffset;
            size_t copySize = matchLength;
            if (copySize > dictSize - dictOffset) {
                /* partial copy from dict, then from output */
                size_t dictPart = dictSize - dictOffset;
                memcpy(op, match, dictPart);
                op += dictPart;
                copySize -= dictPart;
                match = (BYTE*)dst;
                while (copySize--) *op++ = *match++;
            } else {
                if (op + copySize > oend) return -10;
                memcpy(op, match, copySize);
                op += copySize;
            }
        }
    }

    /* end of decoding */
    return (int)(op - (BYTE*)dst);
}

int LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize) {
    LZ4_streamDecode_t_internal* stream = (LZ4_streamDecode_t_internal*)streamPtr;
    if (!stream) return 0;
    stream->dictionary = (const BYTE*)dictPtr;
    stream->dictSize = dictSize;
    stream->currentOffset = 0;
    return 1;
}

int LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize, int maxDecompressedSize) {
    LZ4_streamDecode_t_internal* stream = (LZ4_streamDecode_t_internal*)streamPtr;
    if (!stream) return LZ4_decompress_safe(src, dst, compressedSize, maxDecompressedSize);
    return LZ4_decompress_safe_usingDict(src, dst, compressedSize, maxDecompressedSize,
                                         (const char*)stream->dictionary, stream->dictSize);
}

void LZ4_resetStreamDecode(void* streamPtr) {
    LZ4_streamDecode_t_internal* stream = (LZ4_streamDecode_t_internal*)streamPtr;
    if (stream) {
        memset(stream, 0, sizeof(*stream));
    }
}
