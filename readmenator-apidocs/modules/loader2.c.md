# `loader2.c`

> Source: [loader2.c:1](../../loader2.c#L1) | language `c` | coverage 14.0% | [API index](../index.md)

=== DECLARACIONES DE HOOKS ===

## Contents

- **Structs:** [`BitReader`](#bitreader), [`FluctuationMetadata`](#fluctuationmetadata), [`HookTrampolineBuffers`](#hooktrampolinebuffers), [`HookedSleep`](#hookedsleep), [`DATA`](#data)
- **Type Aliases:** [`UPTR`](#uptr), [`UPTR`](#uptr)
- **Functions:** [`DecryptAES`](#decryptaes), [`freeargvA`](#freeargva), [`freeargvW`](#freeargvw), [`xor32`](#xor32), [`isShellcodeThread`](#isshellcodethread), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt), [`fastTrampoline`](#fasttrampoline), [`VEHHandler`](#vehhandler), [`lzss_decode_mem`](#lzss_decode_mem), [`masqueradeCmdline`](#masqueradecmdline), [`GetNTHeaders`](#getntheaders), [`GetPEDirectory`](#getpedirectory), [`RepairIAT`](#repairiat), [`hookGetCommandLineA`](#hookgetcommandlinea), [`hookGetCommandLineW`](#hookgetcommandlinew), [`hook__p___argv`](#hook__p___argv), [`hook__p___wargv`](#hook__p___wargv), [`hook__p___argc`](#hook__p___argc), [`hook__getmainargs`](#hook__getmainargs), [`hook__wgetmainargs`](#hook__wgetmainargs), [`hookExitProcess`](#hookexitprocess), [`RunPE`](#runpe), [`PELoader`](#peloader), [`anti_analysis`](#anti_analysis), [`selfDestruct`](#selfdestruct), [`GetData`](#getdata), [`main`](#main)
- **Macros:** [`_CRT_RAND_S`](#_crt_rand_s), [`WIN32_LEAN_AND_MEAN`](#win32_lean_and_mean), [`_CRT_SECURE_NO_WARNINGS`](#_crt_secure_no_warnings), [`NT_SUCCESS`](#nt_success), [`NtCurrentThread`](#ntcurrentthread), [`NtCurrentProcess`](#ntcurrentprocess), [`WIN32_LEAN_AND_MEAN`](#win32_lean_and_mean), [`UNICODE`](#unicode), [`_UNICODE`](#_unicode), [`EI`](#ei), [`EJ`](#ej), [`P`](#p), [`N`](#n), [`F`](#f), [`log`](#log)

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
    n_loader2_c__shellcodeEncryptDecrypt(["shellcodeEncryptDecrypt"])
    n_loader2_c__isShellcodeThread(["isShellcodeThread"])
    n_loader2_c__log(["log"])
    n_loader2_c__xor32(["xor32"])
    n_loader2_c__VEHHandler(["VEHHandler"])
    n_loader2_c__GetPEDirectory(["GetPEDirectory"])
    n_loader2_c__GetNTHeaders(["GetNTHeaders"])
    n_loader2_c__RepairIAT(["RepairIAT"])
    n_loader2_c__PELoader(["PELoader"])
    n_loader2_c__NtCurrentProcess(["NtCurrentProcess"])
    n_loader2_c__masqueradeCmdline(["masqueradeCmdline"])
    n_loader2_c__selfDestruct(["selfDestruct"])
    n_loader2_c__main(["main"])
    n_loader2_c__DecryptAES(["DecryptAES"])
    n_loader2_c__GetData(["GetData"])
    n_loader2_c__anti_analysis(["anti_analysis"])
    n_loader2_c__fastTrampoline(["fastTrampoline"])
    n_loader2_c__lzss_decode_mem(["lzss_decode_mem"])
    n_loader_c___stricmp["loader._stricmp"]
    n_loader2_c__shellcodeEncryptDecrypt --> n_loader2_c__isShellcodeThread
    n_loader2_c__shellcodeEncryptDecrypt --> n_loader2_c__log
    n_loader2_c__shellcodeEncryptDecrypt --> n_loader2_c__xor32
    n_loader2_c__VEHHandler --> n_loader2_c__isShellcodeThread
    n_loader2_c__VEHHandler --> n_loader2_c__log
    n_loader2_c__VEHHandler --> n_loader2_c__shellcodeEncryptDecrypt
    n_loader2_c__GetPEDirectory --> n_loader2_c__GetNTHeaders
    n_loader2_c__RepairIAT --> n_loader2_c__GetPEDirectory
    n_loader2_c__PELoader --> n_loader2_c__GetNTHeaders
    n_loader2_c__PELoader --> n_loader2_c__NtCurrentProcess
    n_loader2_c__PELoader --> n_loader2_c__RepairIAT
    n_loader2_c__PELoader --> n_loader2_c__log
    n_loader2_c__PELoader --> n_loader2_c__masqueradeCmdline
    n_loader2_c__PELoader --> n_loader2_c__xor32
    n_loader2_c__selfDestruct --> n_loader2_c__log
    n_loader2_c__main --> n_loader2_c__DecryptAES
    n_loader2_c__main --> n_loader2_c__GetData
    n_loader2_c__main --> n_loader2_c__PELoader
    n_loader2_c__main --> n_loader2_c__anti_analysis
    n_loader2_c__main --> n_loader2_c__fastTrampoline
    n_loader2_c__main --> n_loader2_c__log
    n_loader2_c__main --> n_loader2_c__lzss_decode_mem
    n_loader2_c__main --> n_loader2_c__selfDestruct
    n_loader2_c__RepairIAT -.-> n_loader_c___stricmp
```

## Structs

<a id="bitreader"></a>

### `BitReader`

`struct` | [loader2.c:46](../../loader2.c#L46)

```c
typedef struct
```

---

<a id="fluctuationmetadata"></a>

### `FluctuationMetadata`

`struct` | [loader2.c:111](../../loader2.c#L111)

```c
typedef struct
```

---

<a id="hooktrampolinebuffers"></a>

### `HookTrampolineBuffers`

`struct` | [loader2.c:119](../../loader2.c#L119)

```c
typedef struct
```

---

<a id="hookedsleep"></a>

### `HookedSleep`

`struct` | [loader2.c:129](../../loader2.c#L129)

```c
typedef struct
```

---

<a id="data"></a>

### `DATA`

`struct` | [loader2.c:134](../../loader2.c#L134)

```c
typedef struct
```

---

## Type Aliases

<a id="uptr"></a>

### `UPTR`

`type_alias` | [loader2.c:100](../../loader2.c#L100)

```c
typedef UINT64 UPTR;
```

ifdef _WIN64

---

<a id="uptr"></a>

### `UPTR`

`type_alias` | [loader2.c:102](../../loader2.c#L102)

```c
typedef UINT32 UPTR;
```

else

---

## Functions

<a id="decryptaes"></a>

### `DecryptAES`

`function` | [loader2.c:71](../../loader2.c#L71)

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

<a id="freeargva"></a>

### `freeargvA`

`function` | [loader2.c:169](../../loader2.c#L169)

```c
void freeargvA(char** array, int Argc);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `array` | `char**` |  |  |
| `Argc` | `int` |  |  |

---

<a id="freeargvw"></a>

### `freeargvW`

`function` | [loader2.c:170](../../loader2.c#L170)

```c
void freeargvW(wchar_t** array, int Argc);
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `array` | `wchar_t**` |  |  |
| `Argc` | `int` |  |  |

---

<a id="xor32"></a>

### `xor32`

`function` | [loader2.c:187](../../loader2.c#L187)

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

`function` | [loader2.c:195](../../loader2.c#L195)

```c
bool isShellcodeThread(LPVOID addr)
```

Verifica si la dirección está dentro de .text

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `addr` | `LPVOID` |  |  |

**Returns:** `bool`

*Called by:* [`VEHHandler`](#vehhandler), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---

<a id="shellcodeencryptdecrypt"></a>

### `shellcodeEncryptDecrypt`

`function` | [loader2.c:206](../../loader2.c#L206)

```c
void shellcodeEncryptDecrypt(LPVOID caller)
```

Fluctuación: encripta/desencripta SOLO .text

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `caller` | `LPVOID` |  |  |

*Calls:* [`isShellcodeThread`](#isshellcodethread), [`log`](#log), [`xor32`](#xor32)

*Called by:* [`VEHHandler`](#vehhandler)

---

<a id="fasttrampoline"></a>

### `fastTrampoline`

`function` | [loader2.c:262](../../loader2.c#L262)

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

`function` | [loader2.c:303](../../loader2.c#L303)

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

<a id="lzss_decode_mem"></a>

### `lzss_decode_mem`

`function` | [loader2.c:324](../../loader2.c#L324)

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

<a id="masqueradecmdline"></a>

### `masqueradeCmdline`

`function` | [loader2.c:388](../../loader2.c#L388)

```c
void masqueradeCmdline()
```

*Called by:* [`PELoader`](#peloader)

---

<a id="getntheaders"></a>

### `GetNTHeaders`

`function` | [loader2.c:419](../../loader2.c#L419)

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

`function` | [loader2.c:430](../../loader2.c#L430)

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

`function` | [loader2.c:439](../../loader2.c#L439)

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

`function` | [loader2.c:490](../../loader2.c#L490)

```c
LPSTR hookGetCommandLineA()
```

Hooks

**Returns:** `LPSTR`

---

<a id="hookgetcommandlinew"></a>

### `hookGetCommandLineW`

`function` | [loader2.c:491](../../loader2.c#L491)

```c
LPWSTR hookGetCommandLineW()
```

**Returns:** `LPWSTR`

---

<a id="hook__p___argv"></a>

### `hook__p___argv`

`function` | [loader2.c:492](../../loader2.c#L492)

```c
char*** __cdecl hook__p___argv(void)
```

**Returns:** `char*** __cdecl`

---

<a id="hook__p___wargv"></a>

### `hook__p___wargv`

`function` | [loader2.c:493](../../loader2.c#L493)

```c
wchar_t*** __cdecl hook__p___wargv(void)
```

**Returns:** `wchar_t*** __cdecl`

---

<a id="hook__p___argc"></a>

### `hook__p___argc`

`function` | [loader2.c:494](../../loader2.c#L494)

```c
int* __cdecl hook__p___argc(void)
```

**Returns:** `int* __cdecl`

---

<a id="hook__getmainargs"></a>

### `hook__getmainargs`

`function` | [loader2.c:495](../../loader2.c#L495)

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

`function` | [loader2.c:498](../../loader2.c#L498)

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

<a id="hookexitprocess"></a>

### `hookExitProcess`

`function` | [loader2.c:501](../../loader2.c#L501)

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

`function` | [loader2.c:503](../../loader2.c#L503)

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

`function` | [loader2.c:509](../../loader2.c#L509)

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

`function` | [loader2.c:597](../../loader2.c#L597)

```c
BOOL anti_analysis()
```

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="selfdestruct"></a>

### `selfDestruct`

`function` | [loader2.c:618](../../loader2.c#L618)

```c
void selfDestruct()
```

*Calls:* [`log`](#log)

*Called by:* [`main`](#main)

---

<a id="getdata"></a>

### `GetData`

`function` | [loader2.c:647](../../loader2.c#L647)

```c
DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)
```

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

`function` | [loader2.c:732](../../loader2.c#L732)

```c
int main(int argc, char** argv)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char**` |  |  |

**Returns:** `int`

*Calls:* [`DecryptAES`](#decryptaes), [`GetData`](#getdata), [`PELoader`](#peloader), [`anti_analysis`](#anti_analysis), [`fastTrampoline`](#fasttrampoline), [`log`](#log), [`lzss_decode_mem`](#lzss_decode_mem), [`selfDestruct`](#selfdestruct)

---

## Macros

<a id="_crt_rand_s"></a>

### `_CRT_RAND_S`

`macro` | [loader2.c:1](../../loader2.c#L1)

```c
#define _CRT_RAND_S
```

---

<a id="win32_lean_and_mean"></a>

### `WIN32_LEAN_AND_MEAN`

`macro` | [loader2.c:2](../../loader2.c#L2)

```c
#define WIN32_LEAN_AND_MEAN
```

---

<a id="_crt_secure_no_warnings"></a>

### `_CRT_SECURE_NO_WARNINGS`

`macro` | [loader2.c:26](../../loader2.c#L26)

```c
#define _CRT_SECURE_NO_WARNINGS
```

---

<a id="nt_success"></a>

### `NT_SUCCESS`

`macro` | [loader2.c:29](../../loader2.c#L29)

```c
#define NT_SUCCESS(Status)
```

---

<a id="ntcurrentthread"></a>

### `NtCurrentThread`

`macro` | [loader2.c:32](../../loader2.c#L32)

```c
#define NtCurrentThread()
```

---

<a id="ntcurrentprocess"></a>

### `NtCurrentProcess`

`macro` | [loader2.c:33](../../loader2.c#L33)

```c
#define NtCurrentProcess()
```

*Called by:* [`PELoader`](#peloader)

---

<a id="win32_lean_and_mean"></a>

### `WIN32_LEAN_AND_MEAN`

`macro` | [loader2.c:35](../../loader2.c#L35)

```c
#define WIN32_LEAN_AND_MEAN
```

---

<a id="unicode"></a>

### `UNICODE`

`macro` | [loader2.c:36](../../loader2.c#L36)

```c
#define UNICODE
```

---

<a id="_unicode"></a>

### `_UNICODE`

`macro` | [loader2.c:37](../../loader2.c#L37)

```c
#define _UNICODE
```

---

<a id="ei"></a>

### `EI`

`macro` | [loader2.c:40](../../loader2.c#L40)

```c
#define EI
```

=== LZSS DECOMPRESSOR (Okumura - in memory) ===

---

<a id="ej"></a>

### `EJ`

`macro` | [loader2.c:41](../../loader2.c#L41)

```c
#define EJ
```

---

<a id="p"></a>

### `P`

`macro` | [loader2.c:42](../../loader2.c#L42)

```c
#define P
```

---

<a id="n"></a>

### `N`

`macro` | [loader2.c:43](../../loader2.c#L43)

```c
#define N
```

---

<a id="f"></a>

### `F`

`macro` | [loader2.c:44](../../loader2.c#L44)

```c
#define F
```

---

<a id="log"></a>

### `log`

`macro` | [loader2.c:154](../../loader2.c#L154)

```c
#define log(...)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `...` |  |  |  |

*Called by:* [`PELoader`](#peloader), [`VEHHandler`](#vehhandler), [`main`](#main), [`selfDestruct`](#selfdestruct), [`shellcodeEncryptDecrypt`](#shellcodeencryptdecrypt)

---
