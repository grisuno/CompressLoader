/*
 * LZ4 - Fast LZ compression algorithm
 * Header File
 * Copyright (C) 2011-2020, Yann Collet.
 * BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 * 
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * You can contact the author at :
 *  - LZ4 homepage : http://www.lz4.org
 *  - LZ4 source repository : https://github.com/lz4/lz4
 */

#ifndef LZ4_H_2983827168210
#define LZ4_H_2983827168210

#if defined(__cplusplus)
extern "C" {
#endif

#include <stddef.h>   /* size_t */

/**
 * LZ4_EXPORT
 * Define LZ4_EXPORT to control symbol visibility.
 */
#ifndef LZ4_EXPORT
#  if defined(_WIN32) && defined(LZ4_DLL_EXPORT) && (LZ4_DLL_EXPORT==1)
#    define LZ4_EXPORT __declspec(dllexport)
#  elif defined(_WIN32) && defined(LZ4_DLL_IMPORT) && (LZ4_DLL_IMPORT==1)
#    define LZ4_EXPORT __declspec(dllimport)
#  else
#    define LZ4_EXPORT extern
#  endif
#endif

/*------   Version   ------*/
#define LZ4_VERSION_MAJOR    1
#define LZ4_VERSION_MINOR    9
#define LZ4_VERSION_RELEASE  4
#define LZ4_VERSION_NUMBER (LZ4_VERSION_MAJOR *100*100 + LZ4_VERSION_MINOR *100 + LZ4_VERSION_RELEASE)

/**
 * LZ4_decompress_safe() :
 *  compressedSize : is the exact complete size of the compressed block.
 *  maxDecompressedSize : is the size of the destination buffer, which must be already allocated.
 *  return : the number of bytes decompressed into destination buffer (necessarily <= maxDecompressedSize)
 *           If destination buffer is not large enough, decoding will stop and output an error code (negative).
 *           If the source stream is detected malformed, the function will stop decoding and return a negative result.
 *  This function is protected against buffer overflow exploits, including malicious data packets.
 *  It never writes outside of output buffer, nor reads outside of input buffer.
 */
LZ4_EXPORT int LZ4_decompress_safe (const char* src, char* dst, int compressedSize, int maxDecompressedSize);

/*! LZ4_decompress_safe_usingDict() :
 *  Same as LZ4_decompress_safe() using a dictionary.
 *  dictStart and dictSize must be the start and size of the dictionary.
 *  Note: dictionary content must be accessible throughout the decompression.
 */
LZ4_EXPORT int LZ4_decompress_safe_usingDict (const char* src, char* dst, int compressedSize, int maxDecompressedSize, const char* dictStart, int dictSize);

/*! LZ4_setStreamDecode() :
 *  An LZ4_streamDecode_t context can be allocated once and re-used multiple times.
 *  Use this context to decompress multiple blocks in streaming mode.
 *  If a dictionary is provided, it will be used as the first reference for all future blocks.
 *  The dictionary pointer must remain accessible during the lifetime of the stream.
 */
typedef struct { unsigned long long table[64]; } LZ4_streamDecode_t;
LZ4_EXPORT int LZ4_setStreamDecode (void* streamPtr, const char* dictPtr, int dictSize);
LZ4_EXPORT int LZ4_decompress_safe_continue (void* streamPtr, const char* src, char* dst, int compressedSize, int maxDecompressedSize);
LZ4_EXPORT void LZ4_resetStreamDecode (void* streamPtr);

#if defined(__cplusplus)
}
#endif

#endif /* LZ4_H_2983827168210 */
