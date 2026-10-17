# API

## aes.c
Depends on: `aes.h`
- `getSBoxValue` (function) `aes.c:13` `static uint8_t getSBoxValue(uint8_t num)`
- `getSBoxInvert` (function) `aes.c:35` `static uint8_t getSBoxInvert(uint8_t num)`
- `Td0` (function) `aes.c:57` `static uint8_t Td0(int x)`
- `Td1` (function) `aes.c:58` `static uint8_t Td1(int x)`
- `Td2` (function) `aes.c:59` `static uint8_t Td2(int x)`
- `Td3` (function) `aes.c:60` `static uint8_t Td3(int x)`
- `Td4` (function) `aes.c:61` `static uint8_t Td4(int x)`
- `KeyExpansion` (function) `aes.c:166` `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` -- This function produces Nb(Nr+1) round keys.
- `AES_init_ctx` (function) `aes.c:239` `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- `AES_init_ctx_iv` (function) `aes.c:244` `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` -- if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))
- `AES_ctx_set_iv` (function) `aes.c:249` `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- `AddRoundKey` (function) `aes.c:257` `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` -- This function adds the round key to state.
- `SubBytes` (function) `aes.c:271` `static void SubBytes(state_t* state)` -- The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
- `ShiftRows` (function) `aes.c:286` `static void ShiftRows(state_t* state)` -- The ShiftRows() function shifts the rows in the state to the left.
- `xtime` (function) `aes.c:314` `static uint8_t xtime(uint8_t x)`
- `MixColumns` (function) `aes.c:320` `static void MixColumns(state_t* state)` -- MixColumns function mixes the columns of the state matrix
- `Multiply` (function) `aes.c:340` `static uint8_t Multiply(uint8_t x, uint8_t y)` -- Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends...
- `InvMixColumns` (function) `aes.c:370` `static void InvMixColumns(state_t* state)` -- MixColumns function mixes the columns of the state matrix.
- `InvSubBytes` (function) `aes.c:391` `static void InvSubBytes(state_t* state)` -- The SubBytes Function Substitutes the values in the state matrix with values in an S-box.
- `InvShiftRows` (function) `aes.c:403` `static void InvShiftRows(state_t* state)`
- `Cipher` (function) `aes.c:433` `static void Cipher(state_t* state, const uint8_t* RoundKey)` -- Cipher is the main function that encrypts the PlainText.
- `InvCipher` (function) `aes.c:459` `static void InvCipher(state_t* state, const uint8_t* RoundKey)` -- if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)
- `AES_ECB_encrypt` (function) `aes.c:490` `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `AES_ECB_decrypt` (function) `aes.c:496` `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `XorWithIv` (function) `aes.c:512` `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)`
- `AES_CBC_encrypt_buffer` (function) `aes.c:521` `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- `AES_CBC_decrypt_buffer` (function) `aes.c:536` `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- `AES_CTR_xcrypt_buffer` (function) `aes.c:558` `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` -- XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if...

## aes.h
Imported by: `aes.c`
- `AES_init_ctx` (function) `aes.h:41` `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);`
- `AES_init_ctx_iv` (function) `aes.h:43` `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);` -- if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))
- `AES_ctx_set_iv` (function) `aes.h:44` `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);`
- `AES_ECB_encrypt` (function) `aes.h:48` `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);` -- if defined(ECB) && (ECB == 1)
- `AES_ECB_decrypt` (function) `aes.h:49` `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);`
- `AES_CBC_encrypt_buffer` (function) `aes.h:53` `void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` -- if defined(CBC) && (CBC == 1)
- `AES_CBC_decrypt_buffer` (function) `aes.h:54` `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);`
- `AES_CTR_xcrypt_buffer` (function) `aes.h:58` `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` -- if defined(CTR) && (CTR == 1)

## crypter.py
- `AESencrypt` (function) `crypter.py:9` `def AESencrypt(plaintext, key)`
- `change_ext` (function) `crypter.py:19` `def change_ext(filename, new_ext)` -- Reemplaza la extensión del archivo por una nueva (sin el punto).
- `main` (function) `crypter.py:24` `def main()`

## loader.c
- `read_bit` (function) `loader.c:64` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader.c:75` `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (function) `loader.c:85` `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `hookGetCommandLineW` (function) `loader.c:217` `LPWSTR hookGetCommandLineW()` -- Implementación de hooks
- `hookGetCommandLineA` (function) `loader.c:218` `LPSTR hookGetCommandLineA()`
- `hook__p___argv` (function) `loader.c:219` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader.c:220` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader.c:221` `int* __cdecl hook__p___argc(void)`
- `anti_analysis` (function) `loader.c:226` `BOOL anti_analysis()` -- === ANTI-ANALYSIS ===
- `selfDestruct` (function) `loader.c:251` `void selfDestruct()` -- Puff
- `hook__wgetmainargs` (function) `loader.c:307` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hook__getmainargs` (function) `loader.c:313` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hookexit` (function) `loader.c:319` `int __cdecl hookexit(int status)`
- `hookExitProcess` (function) `loader.c:324` `void __stdcall hookExitProcess(UINT statuscode)`
- `masqueradeCmdline` (function) `loader.c:328` `void masqueradeCmdline()`
- `freeargvA` (function) `loader.c:366` `void freeargvA(char** array, int Argc)`
- `freeargvW` (function) `loader.c:374` `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (function) `loader.c:382` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader.c:394` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader.c:404` `BOOL RepairIAT(PVOID modulePtr)`
- `RunPE` (function) `loader.c:479` `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (function) `loader.c:485` `void PELoader(char* data, DWORD datasize)`
- `getNtdll` (function) `loader.c:559` `LPVOID getNtdll()`
- `Unhook` (function) `loader.c:602` `BOOL Unhook(LPVOID cleanNtdll)`
- `DecryptAES` (function) `loader.c:638` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `GetData` (function) `loader.c:671` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (function) `loader.c:792` `int main(int argc, char** argv)`

## loader2.c
- `read_bit` (function) `loader2.c:52` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader2.c:61` `static int read_bits(BitReader* br, int n)`
- `DecryptAES` (function) `loader2.c:71` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `freeargvA` (function) `loader2.c:169` `void freeargvA(char** array, int Argc);`
- `freeargvW` (function) `loader2.c:170` `void freeargvW(wchar_t** array, int Argc);`
- `get_return_address` (function) `loader2.c:183` `static inline UPTR get_return_address(void)`
- `xor32` (function) `loader2.c:187` `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (function) `loader2.c:195` `bool isShellcodeThread(LPVOID addr)` -- Verifica si la dirección está dentro de .text
- `shellcodeEncryptDecrypt` (function) `loader2.c:206` `void shellcodeEncryptDecrypt(LPVOID caller)` -- Fluctuación: encripta/desencripta SOLO .text
- `MySleep` (function) `loader2.c:246` `static void WINAPI MySleep(DWORD ms)` -- Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)
- `fastTrampoline` (function) `loader2.c:262` `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (function) `loader2.c:303` `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `lzss_decode_mem` (function) `loader2.c:324` `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `masqueradeCmdline` (function) `loader2.c:388` `void masqueradeCmdline()`
- `GetNTHeaders` (function) `loader2.c:419` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader2.c:430` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader2.c:439` `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (function) `loader2.c:490` `LPSTR hookGetCommandLineA()` -- Hooks
- `hookGetCommandLineW` (function) `loader2.c:491` `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (function) `loader2.c:492` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader2.c:493` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader2.c:494` `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (function) `loader2.c:495` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (function) `loader2.c:498` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookExitProcess` (function) `loader2.c:501` `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (function) `loader2.c:503` `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (function) `loader2.c:509` `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (function) `loader2.c:597` `BOOL anti_analysis()`
- `selfDestruct` (function) `loader2.c:618` `void selfDestruct()`
- `GetData` (function) `loader2.c:647` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (function) `loader2.c:732` `int main(int argc, char** argv)`

## loader3.c
- `read_bit` (function) `loader3.c:64` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader3.c:73` `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (function) `loader3.c:83` `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `DecryptAES` (function) `loader3.c:139` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (function) `loader3.c:238` `static inline UPTR get_return_address(void)`
- `xor32` (function) `loader3.c:242` `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (function) `loader3.c:249` `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (function) `loader3.c:258` `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (function) `loader3.c:292` `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (function) `loader3.c:306` `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (function) `loader3.c:342` `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (function) `loader3.c:360` `void masqueradeCmdline()`
- `freeargvA` (function) `loader3.c:390` `void freeargvA(char** array, int Argc)`
- `freeargvW` (function) `loader3.c:398` `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (function) `loader3.c:406` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader3.c:417` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader3.c:426` `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (function) `loader3.c:478` `LPSTR hookGetCommandLineA()` -- Hooks
- `hookGetCommandLineW` (function) `loader3.c:479` `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (function) `loader3.c:480` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader3.c:481` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader3.c:482` `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (function) `loader3.c:483` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (function) `loader3.c:486` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (function) `loader3.c:489` `int __cdecl hookexit(int status)`
- `hookExitProcess` (function) `loader3.c:493` `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (function) `loader3.c:497` `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (function) `loader3.c:503` `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (function) `loader3.c:581` `BOOL anti_analysis()`
- `selfDestruct` (function) `loader3.c:602` `void selfDestruct()`
- `getNtdll` (function) `loader3.c:629` `LPVOID getNtdll()`
- `Unhook` (function) `loader3.c:665` `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (function) `loader3.c:689` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (function) `loader3.c:757` `int main(int argc, char** argv)`

## loader4.c
- `read_bit` (function) `loader4.c:104` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader4.c:113` `static int read_bits(BitReader* br, int n)`
- `deobf` (function) `loader4.c:124` `void deobf(const char* src, char* dst, size_t max_len)` -- Helper para desofuscar
- `SetHWBP_NtContinue` (function) `loader4.c:132` `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- `lzss_decode_mem` (function) `loader4.c:163` `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `PatchETW` (function) `loader4.c:219` `BOOL PatchETW()`
- `DecryptAES` (function) `loader4.c:252` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (function) `loader4.c:351` `static inline UPTR get_return_address(void)`
- `xor32` (function) `loader4.c:355` `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (function) `loader4.c:362` `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (function) `loader4.c:371` `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (function) `loader4.c:405` `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (function) `loader4.c:419` `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (function) `loader4.c:458` `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (function) `loader4.c:476` `void masqueradeCmdline()`
- `freeargvA` (function) `loader4.c:506` `void freeargvA(char** array, int Argc)`
- `freeargvW` (function) `loader4.c:514` `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (function) `loader4.c:522` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader4.c:533` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader4.c:542` `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (function) `loader4.c:594` `LPSTR hookGetCommandLineA()` -- Hooks
- `hookGetCommandLineW` (function) `loader4.c:595` `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (function) `loader4.c:596` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader4.c:597` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader4.c:598` `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (function) `loader4.c:599` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (function) `loader4.c:602` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (function) `loader4.c:605` `int __cdecl hookexit(int status)`
- `hookExitProcess` (function) `loader4.c:609` `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (function) `loader4.c:613` `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (function) `loader4.c:619` `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (function) `loader4.c:699` `BOOL anti_analysis()`
- `selfDestruct` (function) `loader4.c:720` `void selfDestruct()`
- `getNtdll` (function) `loader4.c:747` `LPVOID getNtdll()`
- `Unhook` (function) `loader4.c:785` `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (function) `loader4.c:811` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (function) `loader4.c:879` `int main(int argc, char** argv)`

## loader5.c
Depends on: `lz4.h`
- `HellGate` (function) `loader5.c:65` `BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)`
- `NtAllocateVirtualMemory_indirect` (function) `loader5.c:86` `static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...`
- `NtProtectVirtualMemory_indirect` (function) `loader5.c:106` `static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...`
- `NtWriteVirtualMemory_indirect` (function) `loader5.c:126` `static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...`
- `NtFlushInstructionCache_indirect` (function) `loader5.c:146` `static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...`
- `NtClose_indirect` (function) `loader5.c:166` `static NTSTATUS NtClose_indirect(HANDLE Handle)`
- `NtOpenSection_indirect` (function) `loader5.c:185` `static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...`
- `NtMapViewOfSection_indirect` (function) `loader5.c:205` `static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...`
- `NtUnmapViewOfSection_indirect` (function) `loader5.c:226` `static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)`
- `NtFreeVirtualMemory_indirect` (function) `loader5.c:246` `static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...`
- `decompress_payload` (function) `loader5.c:271` `BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz...`
- `read_bit` (function) `loader5.c:296` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader5.c:305` `static int read_bits(BitReader* br, int n)`
- `decompress_payload` (function) `loader5.c:315` `BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si...`
- `DecryptAES` (function) `loader5.c:375` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `IsDebuggerPresentEx` (function) `loader5.c:396` `BOOL IsDebuggerPresentEx()`
- `HasHWBreakpoints` (function) `loader5.c:400` `BOOL HasHWBreakpoints()`
- `IsDomainJoined` (function) `loader5.c:407` `BOOL IsDomainJoined()`
- `HasRealGPU` (function) `loader5.c:416` `BOOL HasRealGPU()`
- `HasUserActivity` (function) `loader5.c:434` `BOOL HasUserActivity()`
- `IsSandbox` (function) `loader5.c:443` `BOOL IsSandbox()`
- `PatchAmsiViaStomping` (function) `loader5.c:478` `BOOL PatchAmsiViaStomping()`
- `getCleanNtdllViaKnownDlls` (function) `loader5.c:510` `LPVOID getCleanNtdllViaKnownDlls()`
- `UnhookNtdll` (function) `loader5.c:535` `BOOL UnhookNtdll(LPVOID cleanNtdll)`
- `MasqueradeCmdline` (function) `loader5.c:568` `void MasqueradeCmdline()`
- `hookGetCommandLineA` (function) `loader5.c:592` `LPSTR hookGetCommandLineA(void)`
- `hookGetCommandLineW` (function) `loader5.c:593` `LPWSTR hookGetCommandLineW(void)`
- `hook__p___argv` (function) `loader5.c:594` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader5.c:595` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader5.c:596` `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (function) `loader5.c:597` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (function) `loader5.c:600` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (function) `loader5.c:603` `int __cdecl hookexit(int status)`
- `hookExitProcess` (function) `loader5.c:604` `void __stdcall hookExitProcess(UINT statuscode)`
- `GetNTHeaders` (function) `loader5.c:609` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader5.c:620` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader5.c:629` `BOOL RepairIAT(PVOID modulePtr)`
- `FluctuateEncrypt` (function) `loader5.c:691` `void FluctuateEncrypt(FLUCTUATION_CTX* ctx)`
- `FluctuateDecrypt` (function) `loader5.c:715` `void FluctuateDecrypt(FLUCTUATION_CTX* ctx)`
- `fastTrampoline` (function) `loader5.c:746` `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `MySleep` (function) `loader5.c:770` `void WINAPI MySleep(DWORD ms)`
- `GetSpoofedReturnAddress` (function) `loader5.c:784` `ULONG_PTR GetSpoofedReturnAddress()` -- Stack spoofing
- `ExecuteWithSpoofedRet` (function) `loader5.c:790` `void ExecuteWithSpoofedRet(PVOID entry)`
- `TimerExecCallback` (function) `loader5.c:803` `VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)`
- `ModuleStompAndExecute` (function) `loader5.c:810` `BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)`
- `GetData` (function) `loader5.c:909` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)`
- `SelfDestruct` (function) `loader5.c:971` `void SelfDestruct()`
- `main` (function) `loader5.c:995` `int main(int argc, char** argv)`

## loader6.c
Depends on: `lz4.h`
- `HellGate` (function) `loader6.c:67` `BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)`
- `NtAllocateVirtualMemory_indirect` (function) `loader6.c:88` `static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...`
- `NtProtectVirtualMemory_indirect` (function) `loader6.c:108` `static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...`
- `NtWriteVirtualMemory_indirect` (function) `loader6.c:128` `static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...`
- `NtFlushInstructionCache_indirect` (function) `loader6.c:148` `static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...`
- `NtClose_indirect` (function) `loader6.c:168` `static NTSTATUS NtClose_indirect(HANDLE Handle)`
- `NtOpenSection_indirect` (function) `loader6.c:187` `static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...`
- `NtMapViewOfSection_indirect` (function) `loader6.c:207` `static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...`
- `NtUnmapViewOfSection_indirect` (function) `loader6.c:228` `static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)`
- `NtFreeVirtualMemory_indirect` (function) `loader6.c:248` `static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...`
- `decompress_payload` (function) `loader6.c:273` `BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz...`
- `read_bit` (function) `loader6.c:298` `static int read_bit(BitReader* br)`
- `read_bits` (function) `loader6.c:307` `static int read_bits(BitReader* br, int n)`
- `decompress_payload` (function) `loader6.c:317` `BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si...`
- `DecryptAES` (function) `loader6.c:377` `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `IsDebuggerPresentEx` (function) `loader6.c:398` `BOOL IsDebuggerPresentEx()`
- `HasHWBreakpoints` (function) `loader6.c:402` `BOOL HasHWBreakpoints()`
- `IsDomainJoined` (function) `loader6.c:409` `BOOL IsDomainJoined()`
- `HasRealGPU` (function) `loader6.c:418` `BOOL HasRealGPU()`
- `HasUserActivity` (function) `loader6.c:436` `BOOL HasUserActivity()`
- `IsSandbox` (function) `loader6.c:445` `BOOL IsSandbox()`
- `PatchAmsiViaStomping` (function) `loader6.c:479` `BOOL PatchAmsiViaStomping()`
- `getCleanNtdllViaKnownDlls` (function) `loader6.c:512` `LPVOID getCleanNtdllViaKnownDlls()`
- `UnhookNtdll` (function) `loader6.c:537` `BOOL UnhookNtdll(LPVOID cleanNtdll)`
- `MasqueradeCmdline` (function) `loader6.c:571` `void MasqueradeCmdline()`
- `hookGetCommandLineA` (function) `loader6.c:595` `LPSTR hookGetCommandLineA(void)`
- `hookGetCommandLineW` (function) `loader6.c:596` `LPWSTR hookGetCommandLineW(void)`
- `hook__p___argv` (function) `loader6.c:597` `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (function) `loader6.c:598` `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (function) `loader6.c:599` `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (function) `loader6.c:600` `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (function) `loader6.c:603` `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (function) `loader6.c:606` `int __cdecl hookexit(int status)`
- `hookExitProcess` (function) `loader6.c:607` `void __stdcall hookExitProcess(UINT statuscode)`
- `GetNTHeaders` (function) `loader6.c:612` `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (function) `loader6.c:623` `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (function) `loader6.c:632` `BOOL RepairIAT(PVOID modulePtr)`
- `FluctuateEncrypt` (function) `loader6.c:694` `void FluctuateEncrypt(FLUCTUATION_CTX* ctx)`
- `FluctuateDecrypt` (function) `loader6.c:718` `void FluctuateDecrypt(FLUCTUATION_CTX* ctx)`
- `fastTrampoline` (function) `loader6.c:749` `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `MySleep` (function) `loader6.c:773` `void WINAPI MySleep(DWORD ms)`
- `GetSpoofedReturnAddress` (function) `loader6.c:787` `ULONG_PTR GetSpoofedReturnAddress()` -- Stack spoofing
- `ExecuteWithSpoofedRet` (function) `loader6.c:793` `void ExecuteWithSpoofedRet(PVOID entry)`
- `TimerExecCallback` (function) `loader6.c:806` `VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)`
- `ModuleStompAndExecute` (function) `loader6.c:814` `BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)`
- `GetData` (function) `loader6.c:913` `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)`
- `SelfDestruct` (function) `loader6.c:974` `void SelfDestruct()`
- `main` (function) `loader6.c:998` `int main(int argc, char** argv)`

## lz4.c
Depends on: `lz4.h`
- `LZ4_read32` (function) `lz4.c:62` `static U32 LZ4_read32(const void* ptr)`
- `LZ4_write32` (function) `lz4.c:68` `static void LZ4_write32(void* ptr, U32 value)`
- `LZ4_read16` (function) `lz4.c:72` `static U16 LZ4_read16(const void* ptr)`
- `LZ4_write16` (function) `lz4.c:78` `static void LZ4_write16(void* ptr, U16 value)`
- `LZ4_read64` (function) `lz4.c:82` `static U64 LZ4_read64(const void* ptr)`
- `LZ4_decompress_safe` (function) `lz4.c:91` `int LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize)`
- `LZ4_decompress_safe_usingDict` (function) `lz4.c:95` `int LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompre...`
- `LZ4_setStreamDecode` (function) `lz4.c:189` `int LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize)`
- `LZ4_decompress_safe_continue` (function) `lz4.c:198` `int LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize,...`
- `LZ4_resetStreamDecode` (function) `lz4.c:205` `void LZ4_resetStreamDecode(void* streamPtr)`

## lz4.h
Imported by: `loader5.c`, `loader6.c`, `lz4.c`
- `LZ4_decompress_safe` (function) `lz4.h:65` `* LZ4_decompress_safe() : * compressedSize : is the exact complete size of the compressed block. *...`
- `LZ4_setStreamDecode` (function) `lz4.h:90` `LZ4_EXPORT int LZ4_setStreamDecode (void* streamPtr, const char* dictPtr, int dictSize);`
- `LZ4_decompress_safe_continue` (function) `lz4.h:91` `LZ4_EXPORT int LZ4_decompress_safe_continue (void* streamPtr, const char* src, char* dst, int compressedSize, int...`
- `LZ4_resetStreamDecode` (function) `lz4.h:92` `LZ4_EXPORT void LZ4_resetStreamDecode (void* streamPtr);`

## lzss.c
- `error` (function) `lzss.c:16` `static void error(void)`
- `putbit1` (function) `lzss.c:18` `static void putbit1(void)`
- `putbit0` (function) `lzss.c:25` `static void putbit0(void)`
- `flush_bit_buffer` (function) `lzss.c:31` `static void flush_bit_buffer(void)`
- `output1` (function) `lzss.c:34` `static void output1(int c)`
- `output2` (function) `lzss.c:39` `static void output2(int x, int y)`
- `encode` (function) `lzss.c:46` `void encode(void)`
- `getbit` (function) `lzss.c:77` `static int getbit(int n)`
- `decode` (function) `lzss.c:87` `void decode(void)`

## pack.c
- `encode` (function) `pack.c:5` `extern void encode(void);`
- `main` (function) `pack.c:8` `int main(int argc, char *argv[])`

## unpack.c
- `decode` (function) `unpack.c:5` `extern void decode(void);`
- `main` (function) `unpack.c:8` `int main(int argc, char *argv[])`
