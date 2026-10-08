# orphans

*Community 1 | 11 files | cohesion 0.00*

## Definition

This community groups 11 file(s) rooted at `root` with dominant language c (cohesion 0.00). Central symbols: `12`, `AESencrypt`, `BitReader`, `DATA`, `DecryptAES`, `EI`, `EJ`, `F`. Core file: `loader4.c` (60 symbols). Documented purpose: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:.

## Files

| File | Language | Layer | Symbols | Doc |
|------|----------|-------|---------|-----|
| `app.py` | py | utility | 0 | yes |
| `crypter.py` | py | utility | 3 | no |
| `install.sh` | sh | utility | 0 | no |
| `loader.c` | c | utility | 43 | no |
| `loader2.c` | c | utility | 53 | yes |
| `loader3.c` | c | utility | 53 | no |
| `loader4.c` | c | utility | 60 | no |
| `lzss.c` | c | utility | 14 | yes |
| `pack.c` | c | utility | 3 | yes |
| `test.c` | c | testing | 3 | yes |
| `unpack.c` | c | utility | 3 | yes |

## Key Symbols

- `AESencrypt` (function, `crypter.py:9`) `def AESencrypt(plaintext, key)`
- `change_ext` (function, `crypter.py:19`) `def change_ext(filename, new_ext)` - Reemplaza la extensión del archivo por una nueva (sin el punto).
- `main` (function, `crypter.py:24`) `def main()`
- `_CRT_RAND_S` (macro, `loader.c:19`) `#define _CRT_RAND_S`
- `NT_SUCCESS` (macro, `loader.c:30`) `#define NT_SUCCESS(Status)`
- `NtCurrentThread` (macro, `loader.c:33`) `#define NtCurrentThread()`
- `NtCurrentProcess` (macro, `loader.c:34`) `#define NtCurrentProcess()`
- `_CRT_SECURE_NO_WARNINGS` (macro, `loader.c:37`) `#define _CRT_SECURE_NO_WARNINGS`
- `NTSTATUS` (type_alias, `loader.c:38`) `typedef LONG NTSTATUS;` - pragma warning(disable: 4996) define _CRT_SECURE_NO_WARNINGS
- `12` (type_alias, `loader.c:40`) `typedef struct _BASE_RELOCATION_ENTRY { WORD Offset : 12;`
- `_BASE_RELOCATION_ENTRY` (struct, `loader.c:41`)
- `DATA` (struct, `loader.c:46`)
- `EI` (macro, `loader.c:52`) `#define EI`
- `EJ` (macro, `loader.c:53`) `#define EJ`
- `P` (macro, `loader.c:54`) `#define P`
- `N` (macro, `loader.c:55`) `#define N`
- `F` (macro, `loader.c:56`) `#define F`
- `BitReader` (struct, `loader.c:58`)
- `read_bit` (function, `loader.c:64`) `static int read_bit(BitReader* br)`
- `read_bits` (function, `loader.c:75`) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (function, `loader.c:85`) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned cha`
- `hookGetCommandLineW` (function, `loader.c:217`) `LPWSTR hookGetCommandLineW()` - Implementación de hooks
- `hookGetCommandLineA` (function, `loader.c:218`) `LPSTR hookGetCommandLineA()`
- `hook__p___argv` (function, `loader.c:219`) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function, `loader.c:220`) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function, `loader.c:221`) `int* __cdecl hook__p___argc(void)`
- `anti_analysis` (function, `loader.c:226`) `BOOL anti_analysis()` - === ANTI-ANALYSIS ===
- `selfDestruct` (function, `loader.c:251`) `void selfDestruct()` - Puff
- `hook__wgetmainargs` (function, `loader.c:307`) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _usele`
- `hook__getmainargs` (function, `loader.c:313`) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, vo`

## Internal vs External Edges

- Internal resolved imports (EXTRACTED): 0
- Cross-boundary resolved imports (EXTRACTED): 0

## Connections

- [INFERRED] shares_context community 0 <-> 1 (strength 0.5): Inferred shared context (language c and layer utility) with no import path between community 0 (root) and community 1 (orphans).

## Risks

- [dataflow UNCHECKED_ALLOC] `loader.c:809` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader.c:813` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader2.c:766` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader2.c:770` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader3.c:809` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader3.c:812` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader4.c:938` `main` `whost`: Result of allocator stored in `whost` is never checked against NULL.
- [dataflow UNCHECKED_ALLOC] `loader4.c:941` `main` `wresource`: Result of allocator stored in `wresource` is never checked against NULL.

## Open Questions

- Why do 5 file(s) lack file-level docs (e.g. `crypter.py`)? What purpose do they serve?
- What would break if the most connected file in orphans changed?
- Should orphans be split, given cohesion 0.00?

## Sources

- `app.py`
- `crypter.py`
- `install.sh`
- `loader.c`
- `loader2.c`
- `loader3.c`
- `loader4.c`
- `lzss.c`
- `pack.c`
- `test.c`
- `unpack.c`
