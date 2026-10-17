# `loader6.c`

> Source: [loader6.c:1](../../loader6.c#L1) | language `c` | coverage 23.6% | [API index](../index.md)

## Contents

- **Structs:** [`SYSCALL_ENTRY`](#syscall_entry), [`BitReader`](#bitreader), [`EXEC_CTX`](#exec_ctx), [`FLUCTUATION_CTX`](#fluctuation_ctx), [`HookTrampolineBuffers`](#hooktrampolinebuffers), [`DATA`](#data)
- **Functions:** [`HellGate`](#hellgate), [`decompress_payload`](#decompress_payload), [`decompress_payload`](#decompress_payload), [`DecryptAES`](#decryptaes), [`IsDebuggerPresentEx`](#isdebuggerpresentex), [`HasHWBreakpoints`](#hashwbreakpoints), [`IsDomainJoined`](#isdomainjoined), [`HasRealGPU`](#hasrealgpu), [`HasUserActivity`](#hasuseractivity), [`IsSandbox`](#issandbox), [`PatchAmsiViaStomping`](#patchamsiviastomping), [`getCleanNtdllViaKnownDlls`](#getcleanntdllviaknowndlls), [`UnhookNtdll`](#unhookntdll), [`MasqueradeCmdline`](#masqueradecmdline), [`hookGetCommandLineA`](#hookgetcommandlinea), [`hookGetCommandLineW`](#hookgetcommandlinew), [`hook__p___argv`](#hook__p___argv), [`hook__p___wargv`](#hook__p___wargv), [`hook__p___argc`](#hook__p___argc), [`hook__getmainargs`](#hook__getmainargs), [`hook__wgetmainargs`](#hook__wgetmainargs), [`hookexit`](#hookexit), [`hookExitProcess`](#hookexitprocess), [`GetNTHeaders`](#getntheaders), [`GetPEDirectory`](#getpedirectory), [`RepairIAT`](#repairiat), [`FluctuateEncrypt`](#fluctuateencrypt), [`FluctuateDecrypt`](#fluctuatedecrypt), [`fastTrampoline`](#fasttrampoline), [`MySleep`](#mysleep), [`GetSpoofedReturnAddress`](#getspoofedreturnaddress), [`ExecuteWithSpoofedRet`](#executewithspoofedret), [`TimerExecCallback`](#timerexeccallback), [`ModuleStompAndExecute`](#modulestompandexecute), [`GetData`](#getdata), [`SelfDestruct`](#selfdestruct), [`main`](#main)
- **Macros:** [`WIN32_LEAN_AND_MEAN`](#win32_lean_and_mean), [`_CRT_SECURE_NO_WARNINGS`](#_crt_secure_no_warnings), [`DEBUG_PRINT`](#debug_print), [`DEBUG_PRINT`](#debug_print), [`OBF_KEY`](#obf_key), [`OBFSTR`](#obfstr), [`EI`](#ei), [`EJ`](#ej), [`P`](#p), [`N`](#n), [`F`](#f)

## Type Diagram

```mermaid
classDiagram
    direction LR
    class SYSCALL_ENTRY
    <<struct>> SYSCALL_ENTRY
    class BitReader
    <<struct>> BitReader
    class EXEC_CTX
    <<struct>> EXEC_CTX
    class FLUCTUATION_CTX
    <<struct>> FLUCTUATION_CTX
    class HookTrampolineBuffers
    <<struct>> HookTrampolineBuffers
    class DATA
    <<struct>> DATA
```

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_loader6_c__decompress_payload_317(["decompress_payload"])
    n_loader6_c__decompress_payload(["decompress_payload"])
    n_loader6_c__IsSandbox(["IsSandbox"])
    n_loader6_c__HasRealGPU(["HasRealGPU"])
    n_loader6_c__HasUserActivity(["HasUserActivity"])
    n_loader6_c__IsDomainJoined(["IsDomainJoined"])
    n_loader6_c__PatchAmsiViaStomping(["PatchAmsiViaStomping"])
    n_loader6_c__DEBUG_PRINT(["DEBUG_PRINT"])
    n_loader6_c__getCleanNtdllViaKnownDlls(["getCleanNtdllViaKnownDlls"])
    n_loader6_c__UnhookNtdll(["UnhookNtdll"])
    n_loader6_c__GetPEDirectory(["GetPEDirectory"])
    n_loader6_c__GetNTHeaders(["GetNTHeaders"])
    n_loader6_c__RepairIAT(["RepairIAT"])
    n_loader6_c__MySleep(["MySleep"])
    n_loader6_c__FluctuateDecrypt(["FluctuateDecrypt"])
    n_loader6_c__FluctuateEncrypt(["FluctuateEncrypt"])
    n_loader6_c__fastTrampoline(["fastTrampoline"])
    n_loader6_c__ExecuteWithSpoofedRet(["ExecuteWithSpoofedRet"])
    n_loader6_c__GetSpoofedReturnAddress(["GetSpoofedReturnAddress"])
    n_loader6_c__TimerExecCallback(["TimerExecCallback"])
    n_loader6_c__ModuleStompAndExecute(["ModuleStompAndExecute"])
    n_loader6_c__SelfDestruct(["SelfDestruct"])
    n_loader6_c__main(["main"])
    n_loader6_c__DecryptAES(["DecryptAES"])
    n_loader6_c__GetData(["GetData"])
    n_loader6_c__HasHWBreakpoints(["HasHWBreakpoints"])
    n_loader6_c__IsDebuggerPresentEx(["IsDebuggerPresentEx"])
    n_loader6_c__MasqueradeCmdline(["MasqueradeCmdline"])
    n_loader6_c__decompress_payload_317 --> n_loader6_c__decompress_payload
    n_loader6_c__IsSandbox --> n_loader6_c__HasRealGPU
    n_loader6_c__IsSandbox --> n_loader6_c__HasUserActivity
    n_loader6_c__IsSandbox --> n_loader6_c__IsDomainJoined
    n_loader6_c__PatchAmsiViaStomping --> n_loader6_c__DEBUG_PRINT
    n_loader6_c__getCleanNtdllViaKnownDlls --> n_loader6_c__DEBUG_PRINT
    n_loader6_c__UnhookNtdll --> n_loader6_c__DEBUG_PRINT
    n_loader6_c__GetPEDirectory --> n_loader6_c__GetNTHeaders
    n_loader6_c__RepairIAT --> n_loader6_c__GetPEDirectory
    n_loader6_c__MySleep --> n_loader6_c__FluctuateDecrypt
    n_loader6_c__MySleep --> n_loader6_c__FluctuateEncrypt
    n_loader6_c__MySleep --> n_loader6_c__fastTrampoline
    n_loader6_c__ExecuteWithSpoofedRet --> n_loader6_c__GetSpoofedReturnAddress
    n_loader6_c__TimerExecCallback --> n_loader6_c__ExecuteWithSpoofedRet
    n_loader6_c__ModuleStompAndExecute --> n_loader6_c__fastTrampoline
    n_loader6_c__SelfDestruct --> n_loader6_c__DEBUG_PRINT
    n_loader6_c__main --> n_loader6_c__DEBUG_PRINT
    n_loader6_c__main --> n_loader6_c__DecryptAES
    n_loader6_c__main --> n_loader6_c__GetData
    n_loader6_c__main --> n_loader6_c__HasHWBreakpoints
    n_loader6_c__main --> n_loader6_c__IsDebuggerPresentEx
    n_loader6_c__main --> n_loader6_c__IsSandbox
    n_loader6_c__main --> n_loader6_c__MasqueradeCmdline
    n_loader6_c__main --> n_loader6_c__ModuleStompAndExecute
```

## Structs

<a id="syscall_entry"></a>

### `SYSCALL_ENTRY`

`struct` | [loader6.c:62](../../loader6.c#L62)

```c
typedef struct
```

3.

SYSCALLS (Hell's Gate + indirect)

---

<a id="bitreader"></a>

### `BitReader`

`struct` | [loader6.c:292](../../loader6.c#L292)

```c
typedef struct
```

---

<a id="exec_ctx"></a>

### `EXEC_CTX`

`struct` | [loader6.c:678](../../loader6.c#L678)

```c
typedef struct
```

Estructuras para ejecución y fluctuación

---

<a id="fluctuation_ctx"></a>

### `FLUCTUATION_CTX`

`struct` | [loader6.c:682](../../loader6.c#L682)

```c
typedef struct
```

---

<a id="hooktrampolinebuffers"></a>

### `HookTrampolineBuffers`

`struct` | [loader6.c:742](../../loader6.c#L742)

```c
typedef struct
```

---

<a id="data"></a>

### `DATA`

`struct` | [loader6.c:908](../../loader6.c#L908)

```c
typedef struct
```

11.

NETWORK DOWNLOAD

---

## Functions

<a id="hellgate"></a>

### `HellGate`

`function` | [loader6.c:67](../../loader6.c#L67)

```c
BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `funcName` | `PCSTR` |  |  |
| `entry` | `SYSCALL_ENTRY*` |  |  |

**Returns:** `BOOL`

---

<a id="decompress_payload"></a>

### `decompress_payload`

`function` | [loader6.c:273](../../loader6.c#L273)

```c
BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, size_t* outputSize)
```

======================================================================== 4.

COMPRESIÓN: LZSS (por defecto) o LZ4 (si se define USE_LZ4) ======================================================================== ifdef USE_LZ4 include "lz4.h"

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `input` | `unsigned char*` |  |  |
| `inputSize` | `size_t` |  |  |
| `output` | `unsigned char**` |  |  |
| `outputSize` | `size_t*` |  |  |

**Returns:** `BOOL`

*Calls:* [`LZ4_decompress_safe`](lz4.h.md#lz4_decompress_safe)

*Called by:* [`decompress_payload`](#decompress_payload), [`main`](#main)

---

<a id="decompress_payload"></a>

### `decompress_payload`

`function` | [loader6.c:317](../../loader6.c#L317)

```c
BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `input` | `unsigned char*` |  |  |
| `input_size` | `size_t` |  |  |
| `output` | `unsigned char**` |  |  |
| `output_size` | `size_t*` |  |  |

**Returns:** `BOOL`

*Calls:* [`decompress_payload`](#decompress_payload)

---

<a id="decryptaes"></a>

### `DecryptAES`

`function` | [loader6.c:377](../../loader6.c#L377)

```c
void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
```

5.

CRYPTO (AES-256-CBC con CryptoAPI directa)

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `data` | `char*` |  |  |
| `pDataLen` | `DWORD*` |  |  |
| `key` | `char*` |  |  |
| `keyLen` | `DWORD` |  |  |

*Called by:* [`main`](#main)

---

<a id="isdebuggerpresentex"></a>

### `IsDebuggerPresentEx`

`function` | [loader6.c:398](../../loader6.c#L398)

```c
BOOL IsDebuggerPresentEx()
```

6.

ANTIDEBUG / ANTIANALYSIS

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="hashwbreakpoints"></a>

### `HasHWBreakpoints`

`function` | [loader6.c:402](../../loader6.c#L402)

```c
BOOL HasHWBreakpoints()
```

**Returns:** `BOOL`

*Called by:* [`main`](#main)

---

<a id="isdomainjoined"></a>

### `IsDomainJoined`

`function` | [loader6.c:409](../../loader6.c#L409)

```c
BOOL IsDomainJoined()
```

**Returns:** `BOOL`

*Called by:* [`IsSandbox`](#issandbox)

---

<a id="hasrealgpu"></a>

### `HasRealGPU`

`function` | [loader6.c:418](../../loader6.c#L418)

```c
BOOL HasRealGPU()
```

**Returns:** `BOOL`

*Called by:* [`IsSandbox`](#issandbox)

---

<a id="hasuseractivity"></a>

### `HasUserActivity`

`function` | [loader6.c:436](../../loader6.c#L436)

```c
BOOL HasUserActivity()
```

**Returns:** `BOOL`

*Called by:* [`IsSandbox`](#issandbox)

---

<a id="issandbox"></a>

### `IsSandbox`

`function` | [loader6.c:445](../../loader6.c#L445)

```c
BOOL IsSandbox()
```

**Returns:** `BOOL`

*Calls:* [`HasRealGPU`](#hasrealgpu), [`HasUserActivity`](#hasuseractivity), [`IsDomainJoined`](#isdomainjoined)

*Called by:* [`main`](#main)

---

<a id="patchamsiviastomping"></a>

### `PatchAmsiViaStomping`

`function` | [loader6.c:479](../../loader6.c#L479)

```c
BOOL PatchAmsiViaStomping()
```

7.

AMSI BYPASS (module stomping) - usando syscall para permisos

**Returns:** `BOOL`

*Calls:* [`DEBUG_PRINT`](#debug_print)

*Called by:* [`main`](#main)

---

<a id="getcleanntdllviaknowndlls"></a>

### `getCleanNtdllViaKnownDlls`

`function` | [loader6.c:512](../../loader6.c#L512)

```c
LPVOID getCleanNtdllViaKnownDlls()
```

8.

UNHOOKING ntdll (KnownDlls) - usando syscall para permisos

**Returns:** `LPVOID`

*Calls:* [`DEBUG_PRINT`](#debug_print)

*Called by:* [`main`](#main)

---

<a id="unhookntdll"></a>

### `UnhookNtdll`

`function` | [loader6.c:537](../../loader6.c#L537)

```c
BOOL UnhookNtdll(LPVOID cleanNtdll)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `cleanNtdll` | `LPVOID` |  |  |

**Returns:** `BOOL`

*Calls:* [`DEBUG_PRINT`](#debug_print)

*Called by:* [`main`](#main)

---

<a id="masqueradecmdline"></a>

### `MasqueradeCmdline`

`function` | [loader6.c:571](../../loader6.c#L571)

```c
void MasqueradeCmdline()
```

*Called by:* [`main`](#main)

---

<a id="hookgetcommandlinea"></a>

### `hookGetCommandLineA`

`function` | [loader6.c:595](../../loader6.c#L595)

```c
LPSTR hookGetCommandLineA(void)
```

**Returns:** `LPSTR`

---

<a id="hookgetcommandlinew"></a>

### `hookGetCommandLineW`

`function` | [loader6.c:596](../../loader6.c#L596)

```c
LPWSTR hookGetCommandLineW(void)
```

**Returns:** `LPWSTR`

---

<a id="hook__p___argv"></a>

### `hook__p___argv`

`function` | [loader6.c:597](../../loader6.c#L597)

```c
char*** __cdecl hook__p___argv(void)
```

**Returns:** `char*** __cdecl`

---

<a id="hook__p___wargv"></a>

### `hook__p___wargv`

`function` | [loader6.c:598](../../loader6.c#L598)

```c
wchar_t*** __cdecl hook__p___wargv(void)
```

**Returns:** `wchar_t*** __cdecl`

---

<a id="hook__p___argc"></a>

### `hook__p___argc`

`function` | [loader6.c:599](../../loader6.c#L599)

```c
int* __cdecl hook__p___argc(void)
```

**Returns:** `int* __cdecl`

---

<a id="hook__getmainargs"></a>

### `hook__getmainargs`

`function` | [loader6.c:600](../../loader6.c#L600)

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

`function` | [loader6.c:603](../../loader6.c#L603)

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

`function` | [loader6.c:606](../../loader6.c#L606)

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

`function` | [loader6.c:607](../../loader6.c#L607)

```c
void __stdcall hookExitProcess(UINT statuscode)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `statuscode` | `UINT` |  |  |

**Returns:** `void __stdcall`

---

<a id="getntheaders"></a>

### `GetNTHeaders`

`function` | [loader6.c:612](../../loader6.c#L612)

```c
char* GetNTHeaders(char* pe_buffer)
```

10.

PE LOADER WITH FLUCTUATION

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `pe_buffer` | `char*` |  |  |

**Returns:** `char*`

*Called by:* [`GetPEDirectory`](#getpedirectory)

---

<a id="getpedirectory"></a>

### `GetPEDirectory`

`function` | [loader6.c:623](../../loader6.c#L623)

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

`function` | [loader6.c:632](../../loader6.c#L632)

```c
BOOL RepairIAT(PVOID modulePtr)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `modulePtr` | `PVOID` |  |  |

**Returns:** `BOOL`

*Calls:* [`_stricmp`](loader.c.md#_stricmp), [`GetPEDirectory`](#getpedirectory)

---

<a id="fluctuateencrypt"></a>

### `FluctuateEncrypt`

`function` | [loader6.c:694](../../loader6.c#L694)

```c
void FluctuateEncrypt(FLUCTUATION_CTX* ctx)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `ctx` | `FLUCTUATION_CTX*` |  |  |

*Called by:* [`MySleep`](#mysleep)

---

<a id="fluctuatedecrypt"></a>

### `FluctuateDecrypt`

`function` | [loader6.c:718](../../loader6.c#L718)

```c
void FluctuateDecrypt(FLUCTUATION_CTX* ctx)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `ctx` | `FLUCTUATION_CTX*` |  |  |

*Called by:* [`MySleep`](#mysleep)

---

<a id="fasttrampoline"></a>

### `fastTrampoline`

`function` | [loader6.c:749](../../loader6.c#L749)

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

*Called by:* [`ModuleStompAndExecute`](#modulestompandexecute), [`MySleep`](#mysleep)

---

<a id="mysleep"></a>

### `MySleep`

`function` | [loader6.c:773](../../loader6.c#L773)

```c
void WINAPI MySleep(DWORD ms)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `ms` | `DWORD` |  |  |

**Returns:** `void WINAPI`

*Calls:* [`FluctuateDecrypt`](#fluctuatedecrypt), [`FluctuateEncrypt`](#fluctuateencrypt), [`fastTrampoline`](#fasttrampoline)

---

<a id="getspoofedreturnaddress"></a>

### `GetSpoofedReturnAddress`

`function` | [loader6.c:787](../../loader6.c#L787)

```c
ULONG_PTR GetSpoofedReturnAddress()
```

Stack spoofing

**Returns:** `ULONG_PTR`

*Called by:* [`ExecuteWithSpoofedRet`](#executewithspoofedret)

---

<a id="executewithspoofedret"></a>

### `ExecuteWithSpoofedRet`

`function` | [loader6.c:793](../../loader6.c#L793)

```c
void ExecuteWithSpoofedRet(PVOID entry)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `entry` | `PVOID` |  |  |

*Calls:* [`GetSpoofedReturnAddress`](#getspoofedreturnaddress)

*Called by:* [`TimerExecCallback`](#timerexeccallback)

---

<a id="timerexeccallback"></a>

### `TimerExecCallback`

`function` | [loader6.c:806](../../loader6.c#L806)

```c
VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `lpParam` | `PVOID` |  |  |
| `TimerOrWaitFired` | `BOOLEAN` |  |  |

**Returns:** `VOID CALLBACK`

*Calls:* [`ExecuteWithSpoofedRet`](#executewithspoofedret)

---

<a id="modulestompandexecute"></a>

### `ModuleStompAndExecute`

`function` | [loader6.c:814](../../loader6.c#L814)

```c
BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `shellcode` | `PVOID` |  |  |
| `shellcodeSize` | `SIZE_T` |  |  |
| `fluctMode` | `int` |  |  |

**Returns:** `BOOL`

*Calls:* [`fastTrampoline`](#fasttrampoline)

*Called by:* [`main`](#main)

---

<a id="getdata"></a>

### `GetData`

`function` | [loader6.c:913](../../loader6.c#L913)

```c
DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `whost` | `wchar_t*` |  |  |
| `port` | `DWORD` |  |  |
| `wresource` | `wchar_t*` |  |  |
| `userAgent` | `wchar_t*` |  |  |

**Returns:** `DATA`

*Called by:* [`main`](#main)

---

<a id="selfdestruct"></a>

### `SelfDestruct`

`function` | [loader6.c:974](../../loader6.c#L974)

```c
void SelfDestruct()
```

12.

SELF-DESTRUCT

*Calls:* [`DEBUG_PRINT`](#debug_print)

*Called by:* [`main`](#main)

---

<a id="main"></a>

### `main`

`function` | [loader6.c:998](../../loader6.c#L998)

```c
int main(int argc, char** argv)
```

13.

MAIN

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char**` |  |  |

**Returns:** `int`

*Calls:* [`DEBUG_PRINT`](#debug_print), [`DecryptAES`](#decryptaes), [`GetData`](#getdata), [`HasHWBreakpoints`](#hashwbreakpoints), [`IsDebuggerPresentEx`](#isdebuggerpresentex), [`IsSandbox`](#issandbox), [`MasqueradeCmdline`](#masqueradecmdline), [`ModuleStompAndExecute`](#modulestompandexecute), [`PatchAmsiViaStomping`](#patchamsiviastomping), [`SelfDestruct`](#selfdestruct), [`UnhookNtdll`](#unhookntdll), [`decompress_payload`](#decompress_payload) and 1 more

---

## Macros

<a id="win32_lean_and_mean"></a>

### `WIN32_LEAN_AND_MEAN`

`macro` | [loader6.c:15](../../loader6.c#L15)

```c
#define WIN32_LEAN_AND_MEAN
```

---

<a id="_crt_secure_no_warnings"></a>

### `_CRT_SECURE_NO_WARNINGS`

`macro` | [loader6.c:31](../../loader6.c#L31)

```c
#define _CRT_SECURE_NO_WARNINGS
```

---

<a id="debug_print"></a>

### `DEBUG_PRINT`

`macro` | [loader6.c:37](../../loader6.c#L37)

```c
#define DEBUG_PRINT(fmt, ...)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `...` |  |  |  |

*Called by:* [`PatchAmsiViaStomping`](#patchamsiviastomping), [`SelfDestruct`](#selfdestruct), [`UnhookNtdll`](#unhookntdll), [`getCleanNtdllViaKnownDlls`](#getcleanntdllviaknowndlls), [`main`](#main)

---

<a id="debug_print"></a>

### `DEBUG_PRINT`

`macro` | [loader6.c:39](../../loader6.c#L39)

```c
#define DEBUG_PRINT(fmt, ...)
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `...` |  |  |  |

---

<a id="obf_key"></a>

### `OBF_KEY`

`macro` | [loader6.c:45](../../loader6.c#L45)

```c
#define OBF_KEY
```

2.

STRING OBFUSCATION

---

<a id="obfstr"></a>

### `OBFSTR`

`macro` | [loader6.c:47](../../loader6.c#L47)

```c
#define OBFSTR(str)
```

---

<a id="ei"></a>

### `EI`

`macro` | [loader6.c:286](../../loader6.c#L286)

```c
#define EI
```

---

<a id="ej"></a>

### `EJ`

`macro` | [loader6.c:287](../../loader6.c#L287)

```c
#define EJ
```

---

<a id="p"></a>

### `P`

`macro` | [loader6.c:288](../../loader6.c#L288)

```c
#define P
```

---

<a id="n"></a>

### `N`

`macro` | [loader6.c:289](../../loader6.c#L289)

```c
#define N
```

---

<a id="f"></a>

### `F`

`macro` | [loader6.c:290](../../loader6.c#L290)

```c
#define F
```

---
