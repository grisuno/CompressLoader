# root: loader5

*Community 0 | 4 files | cohesion 1.00*

## Definition

This community groups 4 file(s) rooted at `root` with dominant language c (cohesion 1.00). Central symbols: `BYTE`, `BitReader`, `DATA`, `DEBUG_PRINT`, `DecryptAES`, `EI`, `EJ`, `EXEC_CTX`. Core file: `loader5.c` (65 symbols).

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `loader5.c` | c | utility | 65 | no |
| `loader6.c` | c | utility | 65 | no |
| `lz4.c` | c | utility | 28 | no |
| `lz4.h` | h | utility | 13 | no |

## Key Symbols

- `WIN32_LEAN_AND_MEAN` (macro, `loader5.c:14`) `#define WIN32_LEAN_AND_MEAN`
- `_CRT_SECURE_NO_WARNINGS` (macro, `loader5.c:29`) `#define _CRT_SECURE_NO_WARNINGS`
- `DEBUG_PRINT` (macro, `loader5.c:35`) `#define DEBUG_PRINT(fmt, ...)`
- `DEBUG_PRINT` (macro, `loader5.c:37`) `#define DEBUG_PRINT(fmt, ...)`
- `OBF_KEY` (macro, `loader5.c:43`) `#define OBF_KEY`
- `OBFSTR` (macro, `loader5.c:45`) `#define OBFSTR(str)`
- `SYSCALL_ENTRY` (struct, `loader5.c:60`) - ======================================================================== 3.  SYSCALLS (Hell's Gate +
- `HellGate` (function, `loader5.c:65`) `BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)`
- `NtAllocateVirtualMemory_indirect` (function, `loader5.c:86`) `static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* Ba`
- `NtProtectVirtualMemory_indirect` (function, `loader5.c:106`) `static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* Bas`
- `NtWriteVirtualMemory_indirect` (function, `loader5.c:126`) `static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAd`
- `NtFlushInstructionCache_indirect` (function, `loader5.c:146`) `static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID Bas`
- `NtClose_indirect` (function, `loader5.c:166`) `static NTSTATUS NtClose_indirect(HANDLE Handle)`
- `NtOpenSection_indirect` (function, `loader5.c:185`) `static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK Desire`
- `NtMapViewOfSection_indirect` (function, `loader5.c:205`) `static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE Process`
- `NtUnmapViewOfSection_indirect` (function, `loader5.c:226`) `static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAd`
- `NtFreeVirtualMemory_indirect` (function, `loader5.c:246`) `static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAd`
- `decompress_payload` (function, `loader5.c:271`) `BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned c` - ======================================================================== 4.  COMPRESIÓN: LZSS (por d
- `EI` (macro, `loader5.c:284`) `#define EI`
- `EJ` (macro, `loader5.c:285`) `#define EJ`
- `P` (macro, `loader5.c:286`) `#define P`
- `N` (macro, `loader5.c:287`) `#define N`
- `F` (macro, `loader5.c:288`) `#define F`
- `BitReader` (struct, `loader5.c:290`)
- `read_bit` (function, `loader5.c:296`) `static int read_bit(BitReader* br)`
- `read_bits` (function, `loader5.c:305`) `static int read_bits(BitReader* br, int n)`
- `decompress_payload` (function, `loader5.c:315`) `BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned`
- `DecryptAES` (function, `loader5.c:375`) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` - ======================================================================== 5.  CRYPTO (AES-256-CBC con
- `IsDebuggerPresentEx` (function, `loader5.c:396`) `BOOL IsDebuggerPresentEx()` - ======================================================================== 6.  ANTIDEBUG / ANTIANALYSI
- `HasHWBreakpoints` (function, `loader5.c:400`) `BOOL HasHWBreakpoints()`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 3
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 1 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (root: loader5) and community 1 (root: aes).
- [INFERRED] shares_context community 0 <-> 2 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (root: loader5) and community 2 (orphans).

## Risks

- [dataflow UNCHECKED_ALLOC] `loader5.c:1030` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader5.c:1033` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader6.c:1039` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader6.c:1042` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.

## Open Questions

- Why do 4 file(s) lack file-level docs (e.g. `loader5.c`)? What purpose do they serve?
- What would break if the most connected file in root: loader5 changed?
- Should root: loader5 be split, given cohesion 1.00?

## Sources

- `loader5.c`
- `loader6.c`
- `lz4.c`
- `lz4.h`
