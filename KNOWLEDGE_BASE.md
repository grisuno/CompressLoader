# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM.
> No LLMs. No tokens. Pure static analysis.

**Total Files Parsed:** 13 | **Total Symbols Extracted:** 258 | **Total Imports:** 60

## Structural Knowledge Map
```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray: 5 5,color:#aaa;
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
- `getSBoxValue` (line 12) - *aes.c - tiny-AES-c (https://github.com/kokke/tiny-AES-c) include "aes.h" include <string.h> define Nb 4 define KEYLEN_256 32 define RKLENGTH (4 * (...*
- `getSBoxInvert` (line 34)
- `Td0` (line 56)
- `Td1` (line 58)
- `Td2` (line 59)
- `Td3` (line 60)
- `Td4` (line 61)
- `KeyExpansion` (line 166) - *static uint8_t getSBoxValue(uint8_t num) { return sbox[num]; }  define getSBoxValue(num) (sbox[(num)]) This function produces Nb(Nr+1) round keys. ...*
- `AES_init_ctx` (line 238)
- `AES_init_ctx_iv` (line 244) - *if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))*
- `AES_ctx_set_iv` (line 249)
- `AddRoundKey` (line 257) - *endif This function adds the round key to state. The round key is added to the state by an XOR function.*
- `SubBytes` (line 271) - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `ShiftRows` (line 286) - *The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row...*
- `xtime` (line 313)
- `MixColumns` (line 320) - *MixColumns function mixes the columns of the state matrix*
- `Multiply` (line 340) - *Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary...*
- `InvMixColumns` (line 370) - *static uint8_t getSBoxInvert(uint8_t num) { return rsbox[num]; }  define getSBoxInvert(num) (rsbox[(num)]) MixColumns function mixes the columns of...*
- `InvSubBytes` (line 391) - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `InvShiftRows` (line 402)
- `Cipher` (line 433) - *endif // #if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1) Cipher is the main function that encrypts the PlainText.*
- `InvCipher` (line 459) - *if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)*
- `AES_ECB_encrypt` (line 488) - *AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); }  } #endif // #if (defined(CBC) && CBC == 1) || (defined(ECB...*
- `AES_ECB_decrypt` (line 495)
- `XorWithIv` (line 510) - *endif // #if defined(ECB) && (ECB == 1) if defined(CBC) && (CBC == 1)*
- `AES_CBC_encrypt_buffer` (line 520)
- `AES_CBC_decrypt_buffer` (line 535)
- `AES_CTR_xcrypt_buffer` (line 558) - *XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; }  }  #endif // #if defined(CBC) && (CBC == 1)    #if def...*

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
- `read_bit` (line 63)
- `read_bits` (line 74)
- `lzss_decode_mem` (line 84)
- `hookGetCommandLineW` (line 217) - *Implementación de hooks*
- `hookGetCommandLineA` (line 218)
- `hook__p___argv` (line 219)
- `hook__p___wargv` (line 220)
- `hook__p___argc` (line 221)
- `anti_analysis` (line 226) - *=== ANTI-ANALYSIS ===*
- `selfDestruct` (line 251) - *Puff*
- `hook__wgetmainargs` (line 306)
- `hook__getmainargs` (line 312)
- `hookexit` (line 318)
- `hookExitProcess` (line 323)
- `masqueradeCmdline` (line 327)
- `freeargvA` (line 365)
- `freeargvW` (line 373)
- `GetNTHeaders` (line 381)
- `GetPEDirectory` (line 393)
- `RepairIAT` (line 403)
- `_stricmp` (line 458)
- `RunPE` (line 478)
- `PELoader` (line 484)
- `getNtdll` (line 558)
- `Unhook` (line 601)
- `DecryptAES` (line 637)
- `GetData` (line 670)
- `main` (line 791)

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
- `read_bit` (line 51)
- `read_bits` (line 60)
- `DecryptAES` (line 70)
- `get_return_address` (line 182) - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 186)
- `isShellcodeThread` (line 195) - *Verifica si la dirección está dentro de .text*
- `shellcodeEncryptDecrypt` (line 206) - *Fluctuación: encripta/desencripta SOLO .text*
- `MySleep` (line 246) - *Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)*
- `fastTrampoline` (line 261)
- `VEHHandler` (line 302)
- `lzss_decode_mem` (line 323) - *================== LZSS ==================*
- `masqueradeCmdline` (line 387) - *================== PE LOADER ==================*
- `GetNTHeaders` (line 418)
- `GetPEDirectory` (line 429)
- `RepairIAT` (line 438)
- `hookGetCommandLineA` (line 490) - *Hooks*
- `hookGetCommandLineW` (line 491)
- `hook__p___argv` (line 492)
- `hook__p___wargv` (line 493)
- `hook__p___argc` (line 494)
- `hook__getmainargs` (line 495)
- `hook__wgetmainargs` (line 498)
- `hookExitProcess` (line 501)
- `RunPE` (line 502)
- `PELoader` (line 508)
- `anti_analysis` (line 596) - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 617)
- `GetData` (line 646)
- `main` (line 731) - *================== MAIN ==================*

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
- `read_bit` (line 63)
- `read_bits` (line 72)
- `lzss_decode_mem` (line 82)
- `DecryptAES` (line 138)
- `get_return_address` (line 238) - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 241)
- `isShellcodeThread` (line 248)
- `shellcodeEncryptDecrypt` (line 257)
- `MySleep` (line 291)
- `fastTrampoline` (line 305)
- `VEHHandler` (line 341)
- `masqueradeCmdline` (line 360) - *================== PE LOADER ==================*
- `freeargvA` (line 389)
- `freeargvW` (line 397)
- `GetNTHeaders` (line 405)
- `GetPEDirectory` (line 416)
- `RepairIAT` (line 425)
- `hookGetCommandLineA` (line 478) - *Hooks*
- `hookGetCommandLineW` (line 479)
- `hook__p___argv` (line 480)
- `hook__p___wargv` (line 481)
- `hook__p___argc` (line 482)
- `hook__getmainargs` (line 483)
- `hook__wgetmainargs` (line 486)
- `hookexit` (line 489)
- `hookExitProcess` (line 493)
- `RunPE` (line 496)
- `PELoader` (line 502)
- `anti_analysis` (line 581) - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 601)
- `getNtdll` (line 629) - *================== UNHOOKING ==================*
- `Unhook` (line 664)
- `GetData` (line 689) - *================== NETWORK ==================*
- `main` (line 757) - *================== MAIN ==================*

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
- `read_bit` (line 103)
- `read_bits` (line 112)
- `deobf` (line 124) - *Helper para desofuscar*
- `SetHWBP_NtContinue` (line 132)
- `lzss_decode_mem` (line 161)
- `PatchETW` (line 218)
- `DecryptAES` (line 250)
- `get_return_address` (line 351) - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 354)
- `isShellcodeThread` (line 361)
- `shellcodeEncryptDecrypt` (line 370)
- `MySleep` (line 404)
- `fastTrampoline` (line 418)
- `VEHHandler` (line 457)
- `masqueradeCmdline` (line 476) - *================== PE LOADER ==================*
- `freeargvA` (line 505)
- `freeargvW` (line 513)
- `GetNTHeaders` (line 521)
- `GetPEDirectory` (line 532)
- `RepairIAT` (line 541)
- `hookGetCommandLineA` (line 594) - *Hooks*
- `hookGetCommandLineW` (line 595)
- `hook__p___argv` (line 596)
- `hook__p___wargv` (line 597)
- `hook__p___argc` (line 598)
- `hook__getmainargs` (line 599)
- `hook__wgetmainargs` (line 602)
- `hookexit` (line 605)
- `hookExitProcess` (line 609)
- `RunPE` (line 612)
- `PELoader` (line 618)
- `anti_analysis` (line 699) - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 719)
- `getNtdll` (line 747) - *================== UNHOOKING ==================*
- `Unhook` (line 784)
- `GetData` (line 811) - *================== NETWORK ==================*
- `main` (line 879) - *================== MAIN ==================*

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
- `error` (line 15)
- `putbit1` (line 17)
- `putbit0` (line 25)
- `flush_bit_buffer` (line 31)
- `output1` (line 34)
- `output2` (line 39)
- `encode` (line 45)
- `getbit` (line 76)
- `decode` (line 86)

**Macros:**
- `EI` (line 4)
- `EJ` (line 6)
- `P` (line 7)
- `N` (line 8)
- `F` (line 9)

#### `pack.c`
**Path:** `pack.c`

**Functions:**
- `main` (line 7)

#### `test.c`
**Path:** `test.c`

**Functions:**
- `main` (line 8)

#### `unpack.c`
**Path:** `unpack.c`

**Functions:**
- `main` (line 7)

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
- `AES_ctx` (line 33) - *define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only if defined(AES256) && (AES256 == 1) define AES_KEYLEN 32 define AES_keyExp...*

### PY (2 files)

#### `app.py`
**Path:** `app.py`

*No symbols extracted*

#### `crypter.py`
**Path:** `crypter.py`

**Functions:**
- `AESencrypt` (line 9)
- `change_ext` (line 19) - *Reemplaza la extensión del archivo por una nueva (sin el punto).*
- `main` (line 24)

### SH (1 files)

#### `install.sh`
**Path:** `install.sh`

*No symbols extracted*
