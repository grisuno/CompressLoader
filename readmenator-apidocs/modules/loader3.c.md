# `loader3.c`

> Source: [loader3.c:1](../../loader3.c#L1) | language `c` | coverage 20.0% | [API index](../index.md)

## Contents

- **Structs:** [`BitReader`](#bitreader), [`FluctuationMetadata`](#fluctuationmetadata), [`HookTrampolineBuffers`](#hooktrampolinebuffers), [`HookedSleep`](#hookedsleep), [`DATA`](#data)
- **Type Aliases:** [`UPTR`](#uptr), [`UPTR`](#uptr)
- **Functions:** [`lzss_decode_mem`](#lzss_decode_mem), [`DecryptAES`](#decryptaes), [`xor32`](#xor32), [`isShellcodeThread`](#isshellcodethread), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt), [`fastTrampoline`](#fasttrampoline), [`VEHHandler`](#vehhandler), [`masqueradeCmdline`](#masqueradecmdline), [`freeargvA`](#freeargva), [`freeargvW`](#freeargvw), [`GetNTHeaders`](#getntheaders), [`GetPEDirectory`](#getpedirectory), [`RepairIAT`](#repairiat), [`hookGetCommandLineA`](#hookgetcommandlinea), [`hookGetCommandLineW`](#hookgetcommandlinew), [`hook__p___argv`](#hook__p___argv), [`hook__p___wargv`](#hook__p___wargv), [`hook__p___argc`](#hook__p___argc), [`hook__getmainargs`](#hook__getmainargs), [`hook__wgetmainargs`](#hook__wgetmainargs), [`hookexit`](#hookexit), [`hookExitProcess`](#hookexitprocess), [`RunPE`](#runpe), [`PELoader`](#peloader), [`anti_analysis`](#anti_analysis), [`selfDestruct`](#selfdestruct), [`getNtdll`](#getntdll), [`Unhook`](#unhook), [`GetData`](#getdata), [`main`](#main)
- **Macros:** [`_CRT_RAND_S`](#_crt_rand_s), [`WIN32_LEAN_AND_MEAN`](#win32_lean_and_mean), [`_CRT_SECURE_NO_WARNINGS`](#_crt_secure_no_warnings), [`NT_SUCCESS`](#nt_success), [`NtCurrentThread`](#ntcurrentthread), [`NtCurrentProcess`](#ntcurrentprocess), [`EI`](#ei), [`EJ`](#ej), [`P`](#p), [`N`](#n), [`F`](#f), [`log`](#log)

## Type Diagram

```mermaid
classDiagram
    direction LR
    class BitReader
    <<struct>> BitReader
    class UPTR
    <<type_alias>> UPTR
    class UPTR
    <<type_alias>> UPTR
    class FluctuationMetadata
    <<struct>> FluctuationMetadata
    class HookTrampolineBuffers
    <<struct>> HookTrampolineBuffers
    class HookedSleep
    <<struct>> HookedSleep
    class DATA
    <<struct>> DATA
```

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_loader3_c__shellcodeEncryptDecrypt(["shellcodeEncryptDecrypt"])
    n_loader3_c__isShellcodeThread(["isShellcodeThread"])
    n_loader3_c__log(["log"])
    n_loader3_c__xor32(["xor32"])
    n_loader3_c__VEHHandler(["VEHHandler"])
    n_loader3_c__GetPEDirectory(["GetPEDirectory"])
    n_loader3_c__GetNTHeaders(["GetNTHeaders"])
    n_loader3_c__RepairIAT(["RepairIAT"])
    n_loader3_c__PELoader(["PELoader"])
    n_loader3_c__NtCurrentProcess(["NtCurrentProcess"])
    n_loader3_c__masqueradeCmdline(["masqueradeCmdline"])
    n_loader3_c__selfDestruct(["selfDestruct"])
    n_loader3_c__main(["main"])
    n_loader3_c__DecryptAES(["DecryptAES"])
    n_loader3_c__GetData(["GetData"])
    n_loader3_c__Unhook(["Unhook"])
    n_loader3_c__anti_analysis(["anti_analysis"])
    n_loader3_c__fastTrampoline(["fastTrampoline"])
    n_loader3_c__getNtdll(["getNtdll"])
    n_loader3_c__lzss_decode_mem(["lzss_decode_mem"])
    n_loader3_c__shellcodeEncryptDecrypt --> n_loader3_c__isShellcodeThread
    n_loader3_c__shellcodeEncryptDecrypt --> n_loader3_c__log
    n_loader3_c__shellcodeEncryptDecrypt --> n_loader3_c__xor32
    n_loader3_c__VEHHandler --> n_loader3_c__isShellcodeThread
    n_loader3_c__VEHHandler --> n_loader3_c__log
    n_loader3_c__VEHHandler --> n_loader3_c__shellcodeEncryptDecrypt
    n_loader3_c__GetPEDirectory --> n_loader3_c__GetNTHeaders
    n_loader3_c__RepairIAT --> n_loader3_c__GetPEDirectory
    n_loader3_c__PELoader --> n_loader3_c__GetNTHeaders
    n_loader3_c__PELoader --> n_loader3_c__NtCurrentProcess
    n_loader3_c__PELoader --> n_loader3_c__RepairIAT
    n_loader3_c__PELoader --> n_loader3_c__log
    n_loader3_c__PELoader --> n_loader3_c__masqueradeCmdline
    n_loader3_c__PELoader --> n_loader3_c__xor32
    n_loader3_c__selfDestruct --> n_loader3_c__log
    n_loader3_c__main --> n_loader3_c__DecryptAES
    n_loader3_c__main --> n_loader3_c__GetData
    n_loader3_c__main --> n_loader3_c__PELoader
    n_loader3_c__main --> n_loader3_c__Unhook
    n_loader3_c__main --> n_loader3_c__anti_analysis
    n_loader3_c__main --> n_loader3_c__fastTrampoline
    n_loader3_c__main --> n_loader3_c__getNtdll
    n_loader3_c__main --> n_loader3_c__log
    n_loader3_c__main --> n_loader3_c__lzss_decode_mem
```

## Structs

<a id="bitreader"></a>

### `BitReader`

`struct` | [loader3.c:58](../../loader3.c#L58)

```c
typedef struct
```

---

<a id="fluctuationmetadata"></a>

### `FluctuationMetadata`

`struct` | [loader3.c:174](../../loader3.c#L174)

```c
typedef struct
```

---

<a id="hooktrampolinebuffers"></a>

### `HookTrampolineBuffers`

`struct` | [loader3.c:182](../../loader3.c#L182)

```c
typedef struct
```

---

<a id="hookedsleep"></a>

### `HookedSleep`

`struct` | [loader3.c:192](../../loader3.c#L192)

```c
typedef struct
```

---

<a id="data"></a>

### `DATA`

`struct` | [loader3.c:197](../../loader3.c#L197)

```c
typedef struct
```

---

## Type Aliases

<a id="uptr"></a>

### `UPTR`

`type_alias` | [loader3.c:163](../../loader3.c#L163)

```c
typedef UINT64 UPTR;
```

================== TYPEDEFS & STRUCTS ================== ifdef _WIN64

---

<a id="uptr"></a>

### `UPTR`

`type_alias` | [loader3.c:165](../../loader3.c#L165)

```c
typedef UINT32 UPTR;
```

else

---

## Functions

<a id="lzss_decode_mem"></a>

### `lzss_decode_mem`

`function` | [loader3.c:83](../../loader3.c#L83)

```c
BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `input` | `unsigned char*` |  |  |
| `input_size` | `size_t` |  |  |
| `output` | `unsigned char**` |  |  |
| `output_size` | `size_t*` |  |  |

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="decryptaes"></a>

### `DecryptAES`

`function` | [loader3.c:139](../../loader3.c#L139)

```c
void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `data` | `char*` |  |  |
| `pDataLen` | `DWORD*` |  |  |
| `key` | `char*` |  |  |
| `keyLen` | `DWORD` |  |  |

*Called by:* [`main`](#main)

---

<a id="xor32"></a>

### `xor32`

`function` | [loader3.c:242](../../loader3.c#L242)

```c
void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `buf` | `uint8_t *` |  |  |
| `sz` | `SIZE_T` |  |  |
| `key` | `uint32_t` |  |  |

*Called by:* [`PELoader`](#peloader), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---

<a id="isshellcodethread"></a>

### `isShellcodeThread`

`function` | [loader3.c:249](../../loader3.c#L249)

```c
bool isShellcodeThread(LPVOID addr)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `addr` | `LPVOID` |  |  |

**Returns:** `bool`

*Called by:* [`VEHHandler`](#vehhandler), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---

<a id="shellcodeencryptdecrypt"></a>

### `shellcodeEncryptDecrypt`

`function` | [loader3.c:258](../../loader3.c#L258)

```c
void shellcodeEncryptDecrypt(LPVOID caller)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `caller` | `LPVOID` |  |  |

*Calls:* [`isShellcodeThread`](#isshellcodethread), [`log`](#log), [`xor32`](#xor32)

*Called by:* [`VEHHandler`](#vehhandler)

---

<a id="fasttrampoline"></a>

### `fastTrampoline`

`function` | [loader3.c:306](../../loader3.c#L306)

```c
bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `install` | `bool` |  |  |
| `target` | `BYTE *` |  |  |
| `jump` | `LPVOID` |  |  |
| `b` | `HookTrampolineBuffers *` |  |  |

**Returns:** `bool`

*Called by:* [`main`](#main)

---

<a id="vehhandler"></a>

### `VEHHandler`

`function` | [loader3.c:342](../../loader3.c#L342)

```c
LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `xp` | `PEXCEPTION_POINTERS` |  |  |

**Returns:** `LONG NTAPI`

*Calls:* [`isShellcodeThread`](#isshellcodethread), [`log`](#log), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---

<a id="masqueradecmdline"></a>

### `masqueradeCmdline`

`function` | [loader3.c:360](../../loader3.c#L360)

```c
void masqueradeCmdline()
```

================== PE LOADER ==================

*Called by:* [`PELoader`](#peloader)

---

<a id="freeargva"></a>

### `freeargvA`

`function` | [loader3.c:390](../../loader3.c#L390)

```c
void freeargvA(char** array, int Argc)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `array` | `char**` |  |  |
| `Argc` | `int` |  |  |

---

<a id="freeargvw"></a>

### `freeargvW`

`function` | [loader3.c:398](../../loader3.c#L398)

```c
void freeargvW(wchar_t** array, int Argc)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `array` | `wchar_t**` |  |  |
| `Argc` | `int` |  |  |

---

<a id="getntheaders"></a>

### `GetNTHeaders`

`function` | [loader3.c:406](../../loader3.c#L406)

```c
char* GetNTHeaders(char* pe_buffer)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pe_buffer` | `char*` |  |  |

**Returns:** `char*`

*Called by:* [`GetPEDirectory`](#getpedirectory), [`PELoader`](#peloader)

---

<a id="getpedirectory"></a>

### `GetPEDirectory`

`function` | [loader3.c:417](../../loader3.c#L417)

```c
IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pe_buffer` | `PVOID` |  |  |
| `dir_id` | `size_t` |  |  |

**Returns:** `IMAGE_DATA_DIRECTORY*`

*Calls:* [`GetNTHeaders`](#getntheaders)

*Called by:* [`RepairIAT`](#repairiat)

---

<a id="repairiat"></a>

### `RepairIAT`

`function` | [loader3.c:426](../../loader3.c#L426)

```c
BOOL RepairIAT(PVOID modulePtr)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `modulePtr` | `PVOID` |  |  |

**Returns:** `BOOL`

*Calls:* [`_stricmp`](loader.c.md#_stricmp), [`GetPEDirectory`](#getpedirectory)

*Called by:* [`PELoader`](#peloader)

---

<a id="hookgetcommandlinea"></a>

### `hookGetCommandLineA`

`function` | [loader3.c:478](../../loader3.c#L478)

```c
LPSTR hookGetCommandLineA()
```

Hooks

**Returns:** `LPSTR`

---

<a id="hookgetcommandlinew"></a>

### `hookGetCommandLineW`

`function` | [loader3.c:479](../../loader3.c#L479)

```c
LPWSTR hookGetCommandLineW()
```

**Returns:** `LPWSTR`

---

<a id="hook__p___argv"></a>

### `hook__p___argv`

`function` | [loader3.c:480](../../loader3.c#L480)

```c
char*** __cdecl hook__p___argv(void)
```

**Returns:** `char*** __cdecl`

---

<a id="hook__p___wargv"></a>

### `hook__p___wargv`

`function` | [loader3.c:481](../../loader3.c#L481)

```c
wchar_t*** __cdecl hook__p___wargv(void)
```

**Returns:** `wchar_t*** __cdecl`

---

<a id="hook__p___argc"></a>

### `hook__p___argc`

`function` | [loader3.c:482](../../loader3.c#L482)

```c
int* __cdecl hook__p___argc(void)
```

**Returns:** `int* __cdecl`

---

<a id="hook__getmainargs"></a>

### `hook__getmainargs`

`function` | [loader3.c:483](../../loader3.c#L483)

```c
int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `_Argc` | `int*` |  |  |
| `_Argv` | `char***` |  |  |
| `_Env` | `char***` |  |  |
| `_useless_` | `int` |  |  |
| `_useless` | `void*` |  |  |

**Returns:** `int`

---

<a id="hook__wgetmainargs"></a>

### `hook__wgetmainargs`

`function` | [loader3.c:486](../../loader3.c#L486)

```c
int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `_Argc` | `int*` |  |  |
| `_Argv` | `wchar_t***` |  |  |
| `_Env` | `wchar_t***` |  |  |
| `_useless_` | `int` |  |  |
| `_useless` | `void*` |  |  |

**Returns:** `int`

---

<a id="hookexit"></a>

### `hookexit`

`function` | [loader3.c:489](../../loader3.c#L489)

```c
int __cdecl hookexit(int status)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `status` | `int` |  |  |

**Returns:** `int __cdecl`

---

<a id="hookexitprocess"></a>

### `hookExitProcess`

`function` | [loader3.c:493](../../loader3.c#L493)

```c
void __stdcall hookExitProcess(UINT statuscode)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `statuscode` | `UINT` |  |  |

**Returns:** `void __stdcall`

---

<a id="runpe"></a>

### `RunPE`

`function` | [loader3.c:497](../../loader3.c#L497)

```c
DWORD WINAPI RunPE(LPVOID lpParameter)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `lpParameter` | `LPVOID` |  |  |

**Returns:** `DWORD WINAPI`

---

<a id="peloader"></a>

### `PELoader`

`function` | [loader3.c:503](../../loader3.c#L503)

```c
void PELoader(char* data, DWORD datasize)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `data` | `char*` |  |  |
| `datasize` | `DWORD` |  |  |

*Calls:* [`NTSTATUS`](loader.c.md#ntstatus), [`GetNTHeaders`](#getntheaders), [`NtCurrentProcess`](#ntcurrentprocess), [`RepairIAT`](#repairiat), [`log`](#log), [`masqueradeCmdline`](#masqueradecmdline), [`xor32`](#xor32)

*Called by:* [`main`](#main)

---

<a id="anti_analysis"></a>

### `anti_analysis`

`function` | [loader3.c:581](../../loader3.c#L581)

```c
BOOL anti_analysis()
```

================== ANTI-ANALYSIS & CLEANUP ==================

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="selfdestruct"></a>

### `selfDestruct`

`function` | [loader3.c:602](../../loader3.c#L602)

```c
void selfDestruct()
```

*Calls:* [`log`](#log)

*Called by:* [`main`](#main)

---

<a id="getntdll"></a>

### `getNtdll`

`function` | [loader3.c:629](../../loader3.c#L629)

```c
LPVOID getNtdll()
```

================== UNHOOKING ==================

**Returns:** `LPVOID`

*Called by:* [`main`](#main)

---

<a id="unhook"></a>

### `Unhook`

`function` | [loader3.c:665](../../loader3.c#L665)

```c
BOOL Unhook(LPVOID cleanNtdll)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `cleanNtdll` | `LPVOID` |  |  |

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="getdata"></a>

### `GetData`

`function` | [loader3.c:689](../../loader3.c#L689)

```c
DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)
```

================== NETWORK ==================

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `whost` | `wchar_t*` |  |  |
| `port` | `DWORD` |  |  |
| `wresource` | `wchar_t*` |  |  |

**Returns:** `DATA`

*Called by:* [`main`](#main)

---

<a id="main"></a>

### `main`

`function` | [loader3.c:757](../../loader3.c#L757)

```c
int main(int argc, char** argv)
```

================== MAIN ==================

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char**` |  |  |

**Returns:** `int`

*Calls:* [`DecryptAES`](#decryptaes), [`GetData`](#getdata), [`PELoader`](#peloader), [`Unhook`](#unhook), [`anti_analysis`](#anti_analysis), [`fastTrampoline`](#fasttrampoline), [`getNtdll`](#getntdll), [`log`](#log), [`lzss_decode_mem`](#lzss_decode_mem), [`selfDestruct`](#selfdestruct)

---

## Macros

<a id="_crt_rand_s"></a>

### `_CRT_RAND_S`

`macro` | [loader3.c:16](../../loader3.c#L16)

```c
#define _CRT_RAND_S
```

---

<a id="win32_lean_and_mean"></a>

### `WIN32_LEAN_AND_MEAN`

`macro` | [loader3.c:17](../../loader3.c#L17)

```c
#define WIN32_LEAN_AND_MEAN
```

---

<a id="_crt_secure_no_warnings"></a>

### `_CRT_SECURE_NO_WARNINGS`

`macro` | [loader3.c:42](../../loader3.c#L42)

```c
#define _CRT_SECURE_NO_WARNINGS
```

---

<a id="nt_success"></a>

### `NT_SUCCESS`

`macro` | [loader3.c:45](../../loader3.c#L45)

```c
#define NT_SUCCESS(Status)
```

---

<a id="ntcurrentthread"></a>

### `NtCurrentThread`

`macro` | [loader3.c:48](../../loader3.c#L48)

```c
#define NtCurrentThread()
```

---

<a id="ntcurrentprocess"></a>

### `NtCurrentProcess`

`macro` | [loader3.c:49](../../loader3.c#L49)

```c
#define NtCurrentProcess()
```

*Called by:* [`PELoader`](#peloader)

---

<a id="ei"></a>

### `EI`

`macro` | [loader3.c:52](../../loader3.c#L52)

```c
#define EI
```

=== LZSS DECOMPRESSOR (Okumura - in memory) ===

---

<a id="ej"></a>

### `EJ`

`macro` | [loader3.c:53](../../loader3.c#L53)

```c
#define EJ
```

---

<a id="p"></a>

### `P`

`macro` | [loader3.c:54](../../loader3.c#L54)

```c
#define P
```

---

<a id="n"></a>

### `N`

`macro` | [loader3.c:55](../../loader3.c#L55)

```c
#define N
```

---

<a id="f"></a>

### `F`

`macro` | [loader3.c:56](../../loader3.c#L56)

```c
#define F
```

---

<a id="log"></a>

### `log`

`macro` | [loader3.c:214](../../loader3.c#L214)

```c
#define log(...)
```

================== UTIL MACROS ==================

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `...` |  |  |  |

*Called by:* [`PELoader`](#peloader), [`VEHHandler`](#vehhandler), [`main`](#main), [`selfDestruct`](#selfdestruct), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---
