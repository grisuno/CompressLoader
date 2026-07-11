# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 13 | **Total Symbols Extracted:** 258 | **Total Imports:** 60

## Structural Knowledge Map
```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    loader4_c["loader4.c (c)"]
    class loader4_c mod;
    loader4_c_read_bit["read_bit"]
    class loader4_c_read_bit fn;
    loader4_c --> loader4_c_read_bit
    loader4_c_read_bits["read_bits"]
    class loader4_c_read_bits fn;
    loader4_c --> loader4_c_read_bits
    loader4_c_deobf["deobf"]
    class loader4_c_deobf fn;
    loader4_c --> loader4_c_deobf
    loader4_c_SetHWBP_NtContinue["SetHWBP_NtContinue"]
    class loader4_c_SetHWBP_NtContinue fn;
    loader4_c --> loader4_c_SetHWBP_NtContinue
    loader4_c_lzss_decode_mem["lzss_decode_mem"]
    class loader4_c_lzss_decode_mem fn;
    loader4_c --> loader4_c_lzss_decode_mem
    loader3_c["loader3.c (c)"]
    class loader3_c mod;
    loader3_c_read_bit["read_bit"]
    class loader3_c_read_bit fn;
    loader3_c --> loader3_c_read_bit
    loader3_c_read_bits["read_bits"]
    class loader3_c_read_bits fn;
    loader3_c --> loader3_c_read_bits
    loader3_c_lzss_decode_mem["lzss_decode_mem"]
    class loader3_c_lzss_decode_mem fn;
    loader3_c --> loader3_c_lzss_decode_mem
    loader3_c_DecryptAES["DecryptAES"]
    class loader3_c_DecryptAES fn;
    loader3_c --> loader3_c_DecryptAES
    loader3_c_get_return_address["get_return_address"]
    class loader3_c_get_return_address fn;
    loader3_c --> loader3_c_get_return_address
    loader2_c["loader2.c (c)"]
    class loader2_c mod;
    loader2_c_read_bit["read_bit"]
    class loader2_c_read_bit fn;
    loader2_c --> loader2_c_read_bit
    loader2_c_read_bits["read_bits"]
    class loader2_c_read_bits fn;
    loader2_c --> loader2_c_read_bits
    loader2_c_DecryptAES["DecryptAES"]
    class loader2_c_DecryptAES fn;
    loader2_c --> loader2_c_DecryptAES
    loader2_c_get_return_address["get_return_address"]
    class loader2_c_get_return_address fn;
    loader2_c --> loader2_c_get_return_address
    loader2_c_xor32["xor32"]
    class loader2_c_xor32 fn;
    loader2_c --> loader2_c_xor32
    loader_c["loader.c (c)"]
    class loader_c mod;
    loader_c__BASE_RELOCATION_ENTRY["_BASE_RELOCATION_ENTRY"]
    class loader_c__BASE_RELOCATION_ENTRY cls;
    loader_c --> loader_c__BASE_RELOCATION_ENTRY
    loader_c_read_bit["read_bit"]
    class loader_c_read_bit fn;
    loader_c --> loader_c_read_bit
    loader_c_read_bits["read_bits"]
    class loader_c_read_bits fn;
    loader_c --> loader_c_read_bits
    loader_c_lzss_decode_mem["lzss_decode_mem"]
    class loader_c_lzss_decode_mem fn;
    loader_c --> loader_c_lzss_decode_mem
    loader_c_hookGetCommandLineW["hookGetCommandLineW"]
    class loader_c_hookGetCommandLineW fn;
    loader_c --> loader_c_hookGetCommandLineW
    crypter_py["crypter.py (py)"]
    class crypter_py mod;
    crypter_py_AESencrypt["AESencrypt"]
    class crypter_py_AESencrypt fn;
    crypter_py --> crypter_py_AESencrypt
    crypter_py_change_ext["change_ext"]
    class crypter_py_change_ext fn;
    crypter_py --> crypter_py_change_ext
    crypter_py_main["main"]
    class crypter_py_main fn;
    crypter_py --> crypter_py_main
    aes_c["aes.c (c)"]
    class aes_c mod;
    aes_c_getSBoxValue["getSBoxValue"]
    class aes_c_getSBoxValue fn;
    aes_c --> aes_c_getSBoxValue
    aes_c_getSBoxInvert["getSBoxInvert"]
    class aes_c_getSBoxInvert fn;
    aes_c --> aes_c_getSBoxInvert
    aes_c_Td0["Td0"]
    class aes_c_Td0 fn;
    aes_c --> aes_c_Td0
    aes_c_Td1["Td1"]
    class aes_c_Td1 fn;
    aes_c --> aes_c_Td1
    aes_c_Td2["Td2"]
    class aes_c_Td2 fn;
    aes_c --> aes_c_Td2
    lzss_c["lzss.c (c)"]
    class lzss_c mod;
    lzss_c_error["error"]
    class lzss_c_error fn;
    lzss_c --> lzss_c_error
    lzss_c_putbit1["putbit1"]
    class lzss_c_putbit1 fn;
    lzss_c --> lzss_c_putbit1
    lzss_c_putbit0["putbit0"]
    class lzss_c_putbit0 fn;
    lzss_c --> lzss_c_putbit0
    lzss_c_flush_bit_buffer["flush_bit_buffer"]
    class lzss_c_flush_bit_buffer fn;
    lzss_c --> lzss_c_flush_bit_buffer
    lzss_c_output1["output1"]
    class lzss_c_output1 fn;
    lzss_c --> lzss_c_output1
    aes_h["aes.h (h)"]
    class aes_h mod;
    aes_h_AES_ctx["AES_ctx"]
    class aes_h_AES_ctx cls;
    aes_h --> aes_h_AES_ctx
    aes_h__AES_H_["_AES_H_"]
    class aes_h__AES_H_ fn;
    aes_h --> aes_h__AES_H_
    aes_h_CBC["CBC"]
    class aes_h_CBC fn;
    aes_h --> aes_h_CBC
    aes_h_ECB["ECB"]
    class aes_h_ECB fn;
    aes_h --> aes_h_ECB
    aes_h_CTR["CTR"]
    class aes_h_CTR fn;
    aes_h --> aes_h_CTR
    pack_c["pack.c (c)"]
    class pack_c mod;
    pack_c_main["main"]
    class pack_c_main fn;
    pack_c --> pack_c_main
    test_c["test.c (c)"]
    class test_c mod;
    test_c_main["main"]
    class test_c_main fn;
    test_c --> test_c_main
    unpack_c["unpack.c (c)"]
    class unpack_c mod;
    unpack_c_main["main"]
    class unpack_c_main fn;
    unpack_c --> unpack_c_main
    app_py["app.py (py)"]
    class app_py mod;
    install_sh["install.sh (sh)"]
    class install_sh mod;
    ext_aes_h["aes.h"]
    class ext_aes_h ext;
    aes_c -.->|imports| ext_aes_h
    ext_string_h["string.h"]
    class ext_string_h ext;
    aes_c -.->|imports| ext_string_h
    ext_stdint_h["stdint.h"]
    class ext_stdint_h ext;
    aes_h -.->|imports| ext_stdint_h
    ext_stddef_h["stddef.h"]
    class ext_stddef_h ext;
    aes_h -.->|imports| ext_stddef_h
    ext_sys["sys"]
    class ext_sys ext;
    crypter_py -.->|imports| ext_sys
    ext_os["os"]
    class ext_os ext;
    crypter_py -.->|imports| ext_os
    ext_hashlib["hashlib"]
    class ext_hashlib ext;
    crypter_py -.->|imports| ext_hashlib
    ext_struct["struct"]
    class ext_struct ext;
    crypter_py -.->|imports| ext_struct
    crypter_py -.->|imports| ext_os
    ext_Crypto_Cipher["Crypto.Cipher"]
    class ext_Crypto_Cipher ext;
    crypter_py -.->|imports| ext_Crypto_Cipher
    ext_windows_h["windows.h"]
    class ext_windows_h ext;
    loader_c -.->|imports| ext_windows_h
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    loader_c -.->|imports| ext_stdio_h
    ext_psapi_h["psapi.h"]
    class ext_psapi_h ext;
    loader_c -.->|imports| ext_psapi_h
    ext_winternl_h["winternl.h"]
    class ext_winternl_h ext;
    loader_c -.->|imports| ext_winternl_h
    ext_winhttp_h["winhttp.h"]
    class ext_winhttp_h ext;
    loader_c -.->|imports| ext_winhttp_h
    ext_wincrypt_h["wincrypt.h"]
    class ext_wincrypt_h ext;
    loader_c -.->|imports| ext_wincrypt_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    loader_c -.->|imports| ext_stdlib_h
    loader_c -.->|imports| ext_string_h
    loader2_c -.->|imports| ext_windows_h
    loader2_c -.->|imports| ext_stdio_h
    loader2_c -.->|imports| ext_stdlib_h
    loader2_c -.->|imports| ext_string_h
    loader2_c -.->|imports| ext_stdint_h
    ext_stdbool_h["stdbool.h"]
    class ext_stdbool_h ext;
    loader2_c -.->|imports| ext_stdbool_h
    loader2_c -.->|imports| ext_psapi_h
    loader2_c -.->|imports| ext_winternl_h
    loader2_c -.->|imports| ext_winhttp_h
    loader2_c -.->|imports| ext_wincrypt_h
    ext_shellapi_h["shellapi.h"]
    class ext_shellapi_h ext;
    loader2_c -.->|imports| ext_shellapi_h
    loader3_c -.->|imports| ext_windows_h
    loader3_c -.->|imports| ext_stdio_h
    loader3_c -.->|imports| ext_stdlib_h
    loader3_c -.->|imports| ext_string_h
    loader3_c -.->|imports| ext_stdint_h
    loader3_c -.->|imports| ext_stdbool_h
    loader3_c -.->|imports| ext_psapi_h
    loader3_c -.->|imports| ext_winternl_h
    loader3_c -.->|imports| ext_winhttp_h
    loader3_c -.->|imports| ext_wincrypt_h
    loader3_c -.->|imports| ext_shellapi_h
    loader4_c -.->|imports| ext_windows_h
    loader4_c -.->|imports| ext_stdio_h
    loader4_c -.->|imports| ext_stdlib_h
    loader4_c -.->|imports| ext_string_h
    loader4_c -.->|imports| ext_stdint_h
    loader4_c -.->|imports| ext_stdbool_h
    loader4_c -.->|imports| ext_psapi_h
    loader4_c -.->|imports| ext_winternl_h
    loader4_c -.->|imports| ext_winhttp_h
    loader4_c -.->|imports| ext_wincrypt_h
    loader4_c -.->|imports| ext_shellapi_h
    loader4_c -.->|imports| ext_stdio_h
    lzss_c -.->|imports| ext_stdio_h
    lzss_c -.->|imports| ext_stdlib_h
    pack_c -.->|imports| ext_stdio_h
    pack_c -.->|imports| ext_stdlib_h
    test_c -.->|imports| ext_stdio_h
    test_c -.->|imports| ext_stdlib_h
    unpack_c -.->|imports| ext_stdio_h
    unpack_c -.->|imports| ext_stdlib_h
```

---

## Architecture Reference

### C (9 files)

#### `aes.c`
**Path:** `aes.c`

**Functions:**
- `getSBoxValue` (line 12) `static uint8_t getSBoxValue(uint8_t num)` - *define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16*
- `getSBoxInvert` (line 34) `static uint8_t getSBoxInvert(uint8_t num)`
- `Td0` (line 56) `static uint8_t Td0(int x)`
- `Td1` (line 58) `static uint8_t Td1(int x)`
- `Td2` (line 59) `static uint8_t Td2(int x)`
- `Td3` (line 60) `static uint8_t Td3(int x)`
- `Td4` (line 61) `static uint8_t Td4(int x)`
- `KeyExpansion` (line 166) `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` - *This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.*
- `AES_init_ctx` (line 238) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- `AES_init_ctx_iv` (line 244) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` - *if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))*
- `AES_ctx_set_iv` (line 249) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- `AddRoundKey` (line 257) `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` - *This function adds the round key to state. The round key is added to the state by an XOR function.*
- `SubBytes` (line 271) `static void SubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `ShiftRows` (line 286) `static void ShiftRows(state_t* state)` - *The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row...*
- `xtime` (line 313) `static uint8_t xtime(uint8_t x)`
- `MixColumns` (line 320) `static void MixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix*
- `Multiply` (line 340) `static uint8_t Multiply(uint8_t x, uint8_t y)` - *Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary...*
- `InvMixColumns` (line 370) `static void InvMixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand for the inexperienced. Please...*
- `InvSubBytes` (line 391) `static void InvSubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `InvShiftRows` (line 402) `static void InvShiftRows(state_t* state)`
- `Cipher` (line 433) `static void Cipher(state_t* state, const uint8_t* RoundKey)` - *Cipher is the main function that encrypts the PlainText.*
- `InvCipher` (line 459) `static void InvCipher(state_t* state, const uint8_t* RoundKey)` - *if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)*
- `AES_ECB_encrypt` (line 488) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)` - *AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); } } #endif // #if (defined(CBC) && CBC == 1) || (defined(ECB)...*
- `AES_ECB_decrypt` (line 495) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `XorWithIv` (line 510) `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)` - *if defined(CBC) && (CBC == 1)*
- `AES_CBC_encrypt_buffer` (line 520) `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- `AES_CBC_decrypt_buffer` (line 535) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- `AES_CTR_xcrypt_buffer` (line 558) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` - *XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC) && (CBC == 1) #if defined(...*

**Macros:**
- `Nb` (line 4)
- `KEYLEN_256` (line 6)
- `RKLENGTH` (line 10)
- `BLOCKLEN` (line 11)
- `Nb` (line 67)
- `Nk` (line 70)
- `Nr` (line 71)
- `Nk` (line 73)
- `Nr` (line 74)
- `Nk` (line 76)
- `Nr` (line 77)
- `MULTIPLY_AS_A_FUNCTION` (line 84)
- `getSBoxValue` (line 163)
- `Multiply` (line 349)
- `getSBoxInvert` (line 365)

#### `loader.c`
**Path:** `loader.c`

**Functions:**
- `read_bit` (line 63) `static int read_bit(BitReader* br)`
- `read_bits` (line 74) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 84) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `hookGetCommandLineW` (line 217) `LPWSTR hookGetCommandLineW()` - *Implementación de hooks*
- `hookGetCommandLineA` (line 218) `LPSTR hookGetCommandLineA()`
- `hook__p___argv` (line 219) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 220) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 221) `int* __cdecl hook__p___argc(void)`
- `anti_analysis` (line 226) `BOOL anti_analysis()` - *=== ANTI-ANALYSIS ===*
- `selfDestruct` (line 251) `void selfDestruct()` - *Puff*
- `hook__wgetmainargs` (line 306) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hook__getmainargs` (line 312) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 318) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 323) `void __stdcall hookExitProcess(UINT statuscode)`
- `masqueradeCmdline` (line 327) `void masqueradeCmdline()`
- `freeargvA` (line 365) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 373) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 381) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 393) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 403) `BOOL RepairIAT(PVOID modulePtr)`
- `_stricmp` (line 458) `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- `RunPE` (line 478) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 484) `void PELoader(char* data, DWORD datasize)`
- `getNtdll` (line 558) `LPVOID getNtdll()`
- `Unhook` (line 601) `BOOL Unhook(LPVOID cleanNtdll)`
- `DecryptAES` (line 637) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `GetData` (line 670) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 791) `int main(int argc, char** argv)`

**Macros:**
- `_CRT_RAND_S` (line 19)
- `NT_SUCCESS` (line 30)
- `NtCurrentThread` (line 32)
- `NtCurrentProcess` (line 34)
- `_CRT_SECURE_NO_WARNINGS` (line 37)
- `EI` (line 52)
- `EJ` (line 53)
- `P` (line 54)
- `N` (line 55)
- `F` (line 56)

**Structs:**
- `_BASE_RELOCATION_ENTRY` (line 41)

#### `loader2.c`
**Path:** `loader2.c`

**Functions:**
- `read_bit` (line 51) `static int read_bit(BitReader* br)`
- `read_bits` (line 60) `static int read_bits(BitReader* br, int n)`
- `DecryptAES` (line 70) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 182) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 186) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 195) `bool isShellcodeThread(LPVOID addr)` - *Verifica si la dirección está dentro de .text*
- `shellcodeEncryptDecrypt` (line 206) `void shellcodeEncryptDecrypt(LPVOID caller)` - *Fluctuación: encripta/desencripta SOLO .text*
- `MySleep` (line 246) `static void WINAPI MySleep(DWORD ms)` - *Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)*
- `fastTrampoline` (line 261) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 302) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `lzss_decode_mem` (line 323) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` - *================== LZSS ==================*
- `masqueradeCmdline` (line 387) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `GetNTHeaders` (line 418) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 429) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 438) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 490) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 491) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 492) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 493) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 494) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 495) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 498) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookExitProcess` (line 501) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 502) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 508) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 596) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 617) `void selfDestruct()`
- `GetData` (line 646) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 731) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 1)
- `WIN32_LEAN_AND_MEAN` (line 2)
- `_CRT_SECURE_NO_WARNINGS` (line 26)
- `NT_SUCCESS` (line 29)
- `NtCurrentThread` (line 31)
- `NtCurrentProcess` (line 33)
- `WIN32_LEAN_AND_MEAN` (line 34)
- `UNICODE` (line 36)
- `_UNICODE` (line 37)
- `EI` (line 40)
- `EJ` (line 41)
- `P` (line 42)
- `N` (line 43)
- `F` (line 44)
- `log` (line 153)

#### `loader3.c`
**Path:** `loader3.c`

**Functions:**
- `read_bit` (line 63) `static int read_bit(BitReader* br)`
- `read_bits` (line 72) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 82) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `DecryptAES` (line 138) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 238) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 241) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 248) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 257) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 291) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 305) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 341) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 360) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 389) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 397) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 405) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 416) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 425) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 478) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 479) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 480) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 481) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 482) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 483) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 486) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 489) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 493) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 496) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 502) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 581) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 601) `void selfDestruct()`
- `getNtdll` (line 629) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 664) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 689) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 757) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 15)
- `WIN32_LEAN_AND_MEAN` (line 17)
- `_CRT_SECURE_NO_WARNINGS` (line 42)
- `NT_SUCCESS` (line 45)
- `NtCurrentThread` (line 47)
- `NtCurrentProcess` (line 49)
- `EI` (line 52)
- `EJ` (line 53)
- `P` (line 54)
- `N` (line 55)
- `F` (line 56)
- `log` (line 214)

#### `loader4.c`
**Path:** `loader4.c`

**Functions:**
- `read_bit` (line 103) `static int read_bit(BitReader* br)`
- `read_bits` (line 112) `static int read_bits(BitReader* br, int n)`
- `deobf` (line 124) `void deobf(const char* src, char* dst, size_t max_len)` - *Helper para desofuscar*
- `SetHWBP_NtContinue` (line 132) `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- `lzss_decode_mem` (line 161) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `PatchETW` (line 218) `BOOL PatchETW()`
- `DecryptAES` (line 250) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 351) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 354) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 361) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 370) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 404) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 418) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 457) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 476) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 505) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 513) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 521) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 532) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 541) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 594) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 595) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 596) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 597) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 598) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 599) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 602) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 605) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 609) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 612) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 618) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 699) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 719) `void selfDestruct()`
- `getNtdll` (line 747) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 784) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 811) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 879) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 15)
- `WIN32_LEAN_AND_MEAN` (line 17)
- `XK` (line 42)
- `_CRT_SECURE_NO_WARNINGS` (line 52)
- `NT_SUCCESS` (line 55)
- `NtCurrentThread` (line 57)
- `NtCurrentProcess` (line 59)
- `EI` (line 62)
- `EJ` (line 63)
- `P` (line 64)
- `N` (line 65)
- `F` (line 66)
- `OBFUSCATE_KEY` (line 69)
- `OBFSTR` (line 72)
- `OBFSTRW` (line 85)
- `log` (line 327)

#### `lzss.c`
**Path:** `lzss.c`

**Functions:**
- `error` (line 15) `static void error(void)`
- `putbit1` (line 17) `static void putbit1(void)`
- `putbit0` (line 25) `static void putbit0(void)`
- `flush_bit_buffer` (line 31) `static void flush_bit_buffer(void)`
- `output1` (line 34) `static void output1(int c)`
- `output2` (line 39) `static void output2(int x, int y)`
- `encode` (line 45) `void encode(void)`
- `getbit` (line 76) `static int getbit(int n)`
- `decode` (line 86) `void decode(void)`

**Macros:**
- `EI` (line 4)
- `EJ` (line 6)
- `P` (line 7)
- `N` (line 8)
- `F` (line 9)

#### `pack.c`
**Path:** `pack.c`

**Functions:**
- `main` (line 7) `int main(int argc, char *argv[])`

#### `test.c`
**Path:** `test.c`

**Functions:**
- `main` (line 8) `int main(void)`

#### `unpack.c`
**Path:** `unpack.c`

**Functions:**
- `main` (line 7) `int main(int argc, char *argv[])`

### H (1 files)

#### `aes.h`
**Path:** `aes.h`

**Macros:**
- `_AES_H_` (line 2)
- `CBC` (line 9)
- `ECB` (line 12)
- `CTR` (line 15)
- `AES256` (line 17)
- `AES_BLOCKLEN` (line 19)
- `AES_KEYLEN` (line 23)
- `AES_keyExpSize` (line 24)
- `AES_KEYLEN` (line 26)
- `AES_keyExpSize` (line 27)
- `AES_KEYLEN` (line 29)
- `AES_keyExpSize` (line 30)

**Structs:**
- `AES_ctx` (line 33)

### PY (2 files)

#### `app.py`
**Path:** `app.py`

*No symbols extracted*

#### `crypter.py`
**Path:** `crypter.py`

**Functions:**
- `AESencrypt` (line 9) `def AESencrypt(plaintext, key)`
- `change_ext` (line 19) `def change_ext(filename, new_ext)` - *Reemplaza la extensión del archivo por una nueva (sin el punto).*
- `main` (line 24) `def main()`

### SH (1 files)

#### `install.sh`
**Path:** `install.sh`

*No symbols extracted*
