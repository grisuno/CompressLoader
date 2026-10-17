# Subsystem: root (page 2 of 2)
Previous: [KB_root.md](KB_root.md)

## lz4.c
- Layer: utility
- Language: c
- Symbols:
  - `LZ4_streamDecode_t_internal` (struct, line 52)
  - `BYTE` (type_alias, line 23) `typedef uint8_t BYTE;`
  - `U16` (type_alias, line 24) `typedef uint16_t U16;`
  - `U32` (type_alias, line 25) `typedef uint32_t U32;`
  - `S32` (type_alias, line 26) `typedef int32_t S32;`
  - `U64` (type_alias, line 27) `typedef uint64_t U64;`
  - `LZ4_read32` (function, line 62) `static U32 LZ4_read32(const void* ptr)`
  - `LZ4_write32` (function, line 68) `static void LZ4_write32(void* ptr, U32 value)`
  - `LZ4_read16` (function, line 72) `static U16 LZ4_read16(const void* ptr)`
  - `LZ4_write16` (function, line 78) `static void LZ4_write16(void* ptr, U16 value)`
  - `LZ4_read64` (function, line 82) `static U64 LZ4_read64(const void* ptr)`
  - `LZ4_decompress_safe` (function, line 91) `int LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize)`
  - `LZ4_decompress_safe_usingDict` (function, line 95) `int LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompre...`
  - `LZ4_setStreamDecode` (function, line 189) `int LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize)`
  - `LZ4_decompress_safe_continue` (function, line 198) `int LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize,...`
  - `LZ4_resetStreamDecode` (function, line 205) `void LZ4_resetStreamDecode(void* streamPtr)`
  - `LZ4_ALIGN` (macro, line 16) `#define LZ4_ALIGN(x)`
  - `LZ4_ARCH_64` (macro, line 17) `#define LZ4_ARCH_64`
  - `LZ4_FAST_DEC_LOOP` (macro, line 18) `#define LZ4_FAST_DEC_LOOP`
  - `MEMORY_SANITIZER` (macro, line 30) `#  define MEMORY_SANITIZER`
  - `LZ4_8_BIT` (macro, line 36) `#define LZ4_8_BIT`
  - `LZ4_16_BIT` (macro, line 37) `#define LZ4_16_BIT`
  - `LZ4_32_BIT` (macro, line 38) `#define LZ4_32_BIT`
  - `LZ4_64_BIT` (macro, line 39) `#define LZ4_64_BIT`
  - `LZ4_64K` (macro, line 42) `#define LZ4_64K`
  - `LZ4_MEMORY_USAGE` (macro, line 45) `#define LZ4_MEMORY_USAGE`
  - `LZ4_MAX_INPUT_SIZE` (macro, line 46) `#define LZ4_MAX_INPUT_SIZE`
  - `LZ4_COMPRESSBOUND` (macro, line 47) `#define LZ4_COMPRESSBOUND(isize)`
- Depends on: `lz4.h`

## lz4.h
- Doc: LZ4_streamDecode_t: !
- Layer: utility
- Language: h
- Symbols:
  - `LZ4_streamDecode_t` (struct, line 89)
  - `LZ4_decompress_safe` (function, line 65) `* LZ4_decompress_safe() : * compressedSize : is the exact complete size of the compressed block. *...`
  - `LZ4_setStreamDecode` (function, line 90) `LZ4_EXPORT int LZ4_setStreamDecode (void* streamPtr, const char* dictPtr, int dictSize);`
  - `LZ4_decompress_safe_continue` (function, line 91) `LZ4_EXPORT int LZ4_decompress_safe_continue (void* streamPtr, const char* src, char* dst, int compressedSize, int...`
  - `LZ4_resetStreamDecode` (function, line 92) `LZ4_EXPORT void LZ4_resetStreamDecode (void* streamPtr);`
  - `LZ4_H_2983827168210` (macro, line 36) `#define LZ4_H_2983827168210`
  - `LZ4_EXPORT` (macro, line 50) `#    define LZ4_EXPORT`
  - `LZ4_EXPORT` (macro, line 52) `#    define LZ4_EXPORT`
  - `LZ4_EXPORT` (macro, line 54) `#    define LZ4_EXPORT`
  - `LZ4_VERSION_MAJOR` (macro, line 59) `#define LZ4_VERSION_MAJOR`
  - `LZ4_VERSION_MINOR` (macro, line 60) `#define LZ4_VERSION_MINOR`
  - `LZ4_VERSION_RELEASE` (macro, line 61) `#define LZ4_VERSION_RELEASE`
  - `LZ4_VERSION_NUMBER` (macro, line 62) `#define LZ4_VERSION_NUMBER`
- Imported by: `loader5.c`, `loader6.c`, `lz4.c`

## lzss.c
- Doc: – implementación de Okumura (SIN main)
- Layer: utility
- Language: c
- Symbols:
  - `error` (function, line 16) `static void error(void)`
  - `putbit1` (function, line 18) `static void putbit1(void)`
  - `putbit0` (function, line 25) `static void putbit0(void)`
  - `flush_bit_buffer` (function, line 31) `static void flush_bit_buffer(void)`
  - `output1` (function, line 34) `static void output1(int c)`
  - `output2` (function, line 39) `static void output2(int x, int y)`
  - `encode` (function, line 46) `void encode(void)`
  - `getbit` (function, line 77) `static int getbit(int n)`
  - `decode` (function, line 87) `void decode(void)`
  - `EI` (macro, line 5) `#define EI`
  - `EJ` (macro, line 6) `#define EJ`
  - `P` (macro, line 7) `#define P`
  - `N` (macro, line 8) `#define N`
  - `F` (macro, line 9) `#define F`

## pack.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 8) `int main(int argc, char *argv[])`
  - `encode` (function, line 5) `extern void encode(void);`
  - `outfile` (variable, line 6) `extern FILE *infile, *outfile;`

## test.c
- Doc: – wrapper decompress Okumura
- Layer: testing
- Language: c
- Symbols:
  - `main` (function, line 9) `int main(void)`
  - `decode` (function, line 6) `void decode(void);`
  - `outfile` (variable, line 7) `extern FILE *infile, *outfile;`

## unpack.c
- Layer: utility
- Language: c
- Symbols:
  - `main` (function, line 8) `int main(int argc, char *argv[])`
  - `decode` (function, line 5) `extern void decode(void);`
  - `outfile` (variable, line 6) `extern FILE *infile, *outfile;`

