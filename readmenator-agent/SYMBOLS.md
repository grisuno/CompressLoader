# Symbols

| Symbol | Kind | File:Line | Signature |
|--------|------|-----------|-----------|
| `AES_CBC_decrypt_buffer` | function | `aes.c:536` | `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` |
| `AES_CBC_encrypt_buffer` | function | `aes.c:521` | `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)` |
| `AES_CTR_xcrypt_buffer` | function | `aes.c:558` | `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` |
| `AES_ECB_decrypt` | function | `aes.c:496` | `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)` |
| `AES_ECB_encrypt` | function | `aes.c:490` | `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)` |
| `AES_ctx_set_iv` | function | `aes.c:249` | `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)` |
| `AES_init_ctx` | function | `aes.c:239` | `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)` |
| `AES_init_ctx_iv` | function | `aes.c:244` | `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` |
| `AddRoundKey` | function | `aes.c:257` | `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` |
| `BLOCKLEN` | macro | `aes.c:11` | `#define BLOCKLEN` |
| `Cipher` | function | `aes.c:433` | `static void Cipher(state_t* state, const uint8_t* RoundKey)` |
| `InvCipher` | function | `aes.c:459` | `static void InvCipher(state_t* state, const uint8_t* RoundKey)` |
| `InvMixColumns` | function | `aes.c:370` | `static void InvMixColumns(state_t* state)` |
| `InvShiftRows` | function | `aes.c:403` | `static void InvShiftRows(state_t* state)` |
| `InvSubBytes` | function | `aes.c:391` | `static void InvSubBytes(state_t* state)` |
| `KEYLEN_256` | macro | `aes.c:9` | `#define KEYLEN_256` |
| `KeyExpansion` | function | `aes.c:166` | `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` |
| `MULTIPLY_AS_A_FUNCTION` | macro | `aes.c:84` | `#define MULTIPLY_AS_A_FUNCTION` |
| `MixColumns` | function | `aes.c:320` | `static void MixColumns(state_t* state)` |
| `Multiply` | function | `aes.c:340` | `static uint8_t Multiply(uint8_t x, uint8_t y)` |
| `Multiply` | macro | `aes.c:349` | `#define Multiply(x, y)` |
| `Nb` | macro | `aes.c:5` | `#define Nb` |
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
| `Td0` | function | `aes.c:57` | `static uint8_t Td0(int x)` |
| `Td1` | function | `aes.c:58` | `static uint8_t Td1(int x)` |
| `Td2` | function | `aes.c:59` | `static uint8_t Td2(int x)` |
| `Td3` | function | `aes.c:60` | `static uint8_t Td3(int x)` |
| `Td4` | function | `aes.c:61` | `static uint8_t Td4(int x)` |
| `XorWithIv` | function | `aes.c:512` | `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)` |
| `getSBoxInvert` | function | `aes.c:35` | `static uint8_t getSBoxInvert(uint8_t num)` |
| `getSBoxInvert` | macro | `aes.c:365` | `#define getSBoxInvert(num)` |
| `getSBoxValue` | function | `aes.c:13` | `static uint8_t getSBoxValue(uint8_t num)` |
| `getSBoxValue` | macro | `aes.c:163` | `#define getSBoxValue(num)` |
| `xtime` | function | `aes.c:314` | `static uint8_t xtime(uint8_t x)` |
| `AES256` | macro | `aes.h:18` | `#define AES256` |
| `AES_BLOCKLEN` | macro | `aes.h:20` | `#define AES_BLOCKLEN` |
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
| `AES_init_ctx` | function | `aes.h:41` | `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);` |
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
| `DATA` | struct | `loader.c:46` | `` |
| `DecryptAES` | function | `loader.c:638` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader.c:52` | `#define EI` |
| `EJ` | macro | `loader.c:53` | `#define EJ` |
| `F` | macro | `loader.c:56` | `#define F` |
| `GetData` | function | `loader.c:671` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader.c:382` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader.c:394` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `N` | macro | `loader.c:55` | `#define N` |
| `NTSTATUS` | type_alias | `loader.c:38` | `typedef LONG NTSTATUS;` |
| `NT_SUCCESS` | macro | `loader.c:30` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader.c:34` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader.c:33` | `#define NtCurrentThread()` |
| `P` | macro | `loader.c:54` | `#define P` |
| `PELoader` | function | `loader.c:485` | `void PELoader(char* data, DWORD datasize)` |
| `RepairIAT` | function | `loader.c:404` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader.c:479` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `Unhook` | function | `loader.c:602` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `_BASE_RELOCATION_ENTRY` | struct | `loader.c:41` | `` |
| `_CRT_RAND_S` | macro | `loader.c:19` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader.c:37` | `#define _CRT_SECURE_NO_WARNINGS` |
| `_stricmp` | function | `loader.c:458` | `_stricmp(func_name, "exit") == 0 \|\|
                    _stricmp(func_name, "_Exit") == 0 \|\|
    ...` |
| `anti_analysis` | function | `loader.c:226` | `BOOL anti_analysis()` |
| `freeargvA` | function | `loader.c:366` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader.c:374` | `void freeargvW(wchar_t** array, int Argc)` |
| `getNtdll` | function | `loader.c:559` | `LPVOID getNtdll()` |
| `hookExitProcess` | function | `loader.c:324` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader.c:218` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader.c:217` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader.c:313` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader.c:221` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader.c:219` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader.c:220` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader.c:307` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `hookexit` | function | `loader.c:319` | `int __cdecl hookexit(int status)` |
| `lzss_decode_mem` | function | `loader.c:85` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader.c:792` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader.c:328` | `void masqueradeCmdline()` |
| `read_bit` | function | `loader.c:64` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader.c:75` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader.c:251` | `void selfDestruct()` |
| `BitReader` | struct | `loader2.c:46` | `` |
| `DATA` | struct | `loader2.c:134` | `` |
| `DecryptAES` | function | `loader2.c:71` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader2.c:40` | `#define EI` |
| `EJ` | macro | `loader2.c:41` | `#define EJ` |
| `F` | macro | `loader2.c:44` | `#define F` |
| `FluctuationMetadata` | struct | `loader2.c:111` | `` |
| `GetData` | function | `loader2.c:647` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader2.c:419` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader2.c:430` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `HookTrampolineBuffers` | struct | `loader2.c:119` | `` |
| `HookedSleep` | struct | `loader2.c:129` | `` |
| `MySleep` | function | `loader2.c:246` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader2.c:43` | `#define N` |
| `NT_SUCCESS` | macro | `loader2.c:29` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader2.c:33` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader2.c:32` | `#define NtCurrentThread()` |
| `P` | macro | `loader2.c:42` | `#define P` |
| `PELoader` | function | `loader2.c:509` | `void PELoader(char* data, DWORD datasize)` |
| `RepairIAT` | function | `loader2.c:439` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader2.c:503` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `UNICODE` | macro | `loader2.c:36` | `#define UNICODE` |
| `UPTR` | type_alias | `loader2.c:100` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader2.c:102` | `typedef UINT32 UPTR;` |
| `VEHHandler` | function | `loader2.c:303` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader2.c:2` | `#define WIN32_LEAN_AND_MEAN` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader2.c:35` | `#define WIN32_LEAN_AND_MEAN` |
| `_CRT_RAND_S` | macro | `loader2.c:1` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader2.c:26` | `#define _CRT_SECURE_NO_WARNINGS` |
| `_UNICODE` | macro | `loader2.c:37` | `#define _UNICODE` |
| `anti_analysis` | function | `loader2.c:597` | `BOOL anti_analysis()` |
| `fastTrampoline` | function | `loader2.c:262` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `freeargvA` | function | `loader2.c:169` | `void freeargvA(char** array, int Argc);` |
| `freeargvW` | function | `loader2.c:170` | `void freeargvW(wchar_t** array, int Argc);` |
| `get_return_address` | function | `loader2.c:183` | `static inline UPTR get_return_address(void)` |
| `hookExitProcess` | function | `loader2.c:501` | `void __stdcall hookExitProcess(UINT statuscode)` |
| `hookGetCommandLineA` | function | `loader2.c:490` | `LPSTR hookGetCommandLineA()` |
| `hookGetCommandLineW` | function | `loader2.c:491` | `LPWSTR hookGetCommandLineW()` |
| `hook__getmainargs` | function | `loader2.c:495` | `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)` |
| `hook__p___argc` | function | `loader2.c:494` | `int* __cdecl hook__p___argc(void)` |
| `hook__p___argv` | function | `loader2.c:492` | `char*** __cdecl hook__p___argv(void)` |
| `hook__p___wargv` | function | `loader2.c:493` | `wchar_t*** __cdecl hook__p___wargv(void)` |
| `hook__wgetmainargs` | function | `loader2.c:498` | `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)` |
| `isShellcodeThread` | function | `loader2.c:195` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader2.c:154` | `#define log(...)` |
| `lzss_decode_mem` | function | `loader2.c:324` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader2.c:732` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader2.c:388` | `void masqueradeCmdline()` |
| `read_bit` | function | `loader2.c:52` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader2.c:61` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader2.c:618` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader2.c:206` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `xor32` | function | `loader2.c:187` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `BitReader` | struct | `loader3.c:58` | `` |
| `DATA` | struct | `loader3.c:197` | `` |
| `DecryptAES` | function | `loader3.c:139` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader3.c:52` | `#define EI` |
| `EJ` | macro | `loader3.c:53` | `#define EJ` |
| `F` | macro | `loader3.c:56` | `#define F` |
| `FluctuationMetadata` | struct | `loader3.c:174` | `` |
| `GetData` | function | `loader3.c:689` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader3.c:406` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader3.c:417` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `HookTrampolineBuffers` | struct | `loader3.c:182` | `` |
| `HookedSleep` | struct | `loader3.c:192` | `` |
| `MySleep` | function | `loader3.c:292` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader3.c:55` | `#define N` |
| `NT_SUCCESS` | macro | `loader3.c:45` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader3.c:49` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader3.c:48` | `#define NtCurrentThread()` |
| `P` | macro | `loader3.c:54` | `#define P` |
| `PELoader` | function | `loader3.c:503` | `void PELoader(char* data, DWORD datasize)` |
| `RepairIAT` | function | `loader3.c:426` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader3.c:497` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `UPTR` | type_alias | `loader3.c:163` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader3.c:165` | `typedef UINT32 UPTR;` |
| `Unhook` | function | `loader3.c:665` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `VEHHandler` | function | `loader3.c:342` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader3.c:17` | `#define WIN32_LEAN_AND_MEAN` |
| `_CRT_RAND_S` | macro | `loader3.c:16` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader3.c:42` | `#define _CRT_SECURE_NO_WARNINGS` |
| `anti_analysis` | function | `loader3.c:581` | `BOOL anti_analysis()` |
| `fastTrampoline` | function | `loader3.c:306` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `freeargvA` | function | `loader3.c:390` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader3.c:398` | `void freeargvW(wchar_t** array, int Argc)` |
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
| `isShellcodeThread` | function | `loader3.c:249` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader3.c:214` | `#define log(...)` |
| `lzss_decode_mem` | function | `loader3.c:83` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader3.c:757` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader3.c:360` | `void masqueradeCmdline()` |
| `read_bit` | function | `loader3.c:64` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader3.c:73` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader3.c:602` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader3.c:258` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `xor32` | function | `loader3.c:242` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `BitReader` | struct | `loader4.c:98` | `` |
| `DATA` | struct | `loader4.c:310` | `` |
| `DecryptAES` | function | `loader4.c:252` | `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` |
| `EI` | macro | `loader4.c:62` | `#define EI` |
| `EJ` | macro | `loader4.c:63` | `#define EJ` |
| `F` | macro | `loader4.c:66` | `#define F` |
| `FluctuationMetadata` | struct | `loader4.c:287` | `` |
| `GetData` | function | `loader4.c:811` | `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` |
| `GetNTHeaders` | function | `loader4.c:522` | `char* GetNTHeaders(char* pe_buffer)` |
| `GetPEDirectory` | function | `loader4.c:533` | `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)` |
| `HookTrampolineBuffers` | struct | `loader4.c:295` | `` |
| `HookedSleep` | struct | `loader4.c:305` | `` |
| `MySleep` | function | `loader4.c:405` | `static void WINAPI MySleep(DWORD ms)` |
| `N` | macro | `loader4.c:65` | `#define N` |
| `NT_SUCCESS` | macro | `loader4.c:55` | `#define NT_SUCCESS(Status)` |
| `NtCurrentProcess` | macro | `loader4.c:59` | `#define NtCurrentProcess()` |
| `NtCurrentThread` | macro | `loader4.c:58` | `#define NtCurrentThread()` |
| `OBFSTR` | macro | `loader4.c:72` | `#define OBFSTR(str)` |
| `OBFSTRW` | macro | `loader4.c:85` | `#define OBFSTRW(str)` |
| `OBFUSCATE_KEY` | macro | `loader4.c:69` | `#define OBFUSCATE_KEY` |
| `P` | macro | `loader4.c:64` | `#define P` |
| `PELoader` | function | `loader4.c:619` | `void PELoader(char* data, DWORD datasize)` |
| `PatchETW` | function | `loader4.c:219` | `BOOL PatchETW()` |
| `RepairIAT` | function | `loader4.c:542` | `BOOL RepairIAT(PVOID modulePtr)` |
| `RunPE` | function | `loader4.c:613` | `DWORD WINAPI RunPE(LPVOID lpParameter)` |
| `SetHWBP_NtContinue` | function | `loader4.c:132` | `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)` |
| `UPTR` | type_alias | `loader4.c:276` | `typedef UINT64 UPTR;` |
| `UPTR` | type_alias | `loader4.c:278` | `typedef UINT32 UPTR;` |
| `Unhook` | function | `loader4.c:785` | `BOOL Unhook(LPVOID cleanNtdll)` |
| `VEHHandler` | function | `loader4.c:458` | `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)` |
| `WIN32_LEAN_AND_MEAN` | macro | `loader4.c:17` | `#define WIN32_LEAN_AND_MEAN` |
| `XK` | macro | `loader4.c:42` | `#define XK` |
| `_CRT_RAND_S` | macro | `loader4.c:16` | `#define _CRT_RAND_S` |
| `_CRT_SECURE_NO_WARNINGS` | macro | `loader4.c:52` | `#define _CRT_SECURE_NO_WARNINGS` |
| `anti_analysis` | function | `loader4.c:699` | `BOOL anti_analysis()` |
| `deobf` | function | `loader4.c:124` | `void deobf(const char* src, char* dst, size_t max_len)` |
| `fastTrampoline` | function | `loader4.c:419` | `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)` |
| `freeargvA` | function | `loader4.c:506` | `void freeargvA(char** array, int Argc)` |
| `freeargvW` | function | `loader4.c:514` | `void freeargvW(wchar_t** array, int Argc)` |
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
| `isShellcodeThread` | function | `loader4.c:362` | `bool isShellcodeThread(LPVOID addr)` |
| `log` | macro | `loader4.c:327` | `#define log(...)` |
| `lzss_decode_mem` | function | `loader4.c:163` | `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` |
| `main` | function | `loader4.c:879` | `int main(int argc, char** argv)` |
| `masqueradeCmdline` | function | `loader4.c:476` | `void masqueradeCmdline()` |
| `read_bit` | function | `loader4.c:104` | `static int read_bit(BitReader* br)` |
| `read_bits` | function | `loader4.c:113` | `static int read_bits(BitReader* br, int n)` |
| `selfDestruct` | function | `loader4.c:720` | `void selfDestruct()` |
| `shellcodeEncryptDecrypt` | function | `loader4.c:371` | `void shellcodeEncryptDecrypt(LPVOID caller)` |
| `xor32` | function | `loader4.c:355` | `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)` |
| `EI` | macro | `lzss.c:5` | `#define EI` |
| `EJ` | macro | `lzss.c:6` | `#define EJ` |
| `F` | macro | `lzss.c:9` | `#define F` |
| `N` | macro | `lzss.c:8` | `#define N` |
| `P` | macro | `lzss.c:7` | `#define P` |
| `decode` | function | `lzss.c:87` | `void decode(void)` |
| `encode` | function | `lzss.c:46` | `void encode(void)` |
| `error` | function | `lzss.c:16` | `static void error(void)` |
| `flush_bit_buffer` | function | `lzss.c:31` | `static void flush_bit_buffer(void)` |
| `getbit` | function | `lzss.c:77` | `static int getbit(int n)` |
| `output1` | function | `lzss.c:34` | `static void output1(int c)` |
| `output2` | function | `lzss.c:39` | `static void output2(int x, int y)` |
| `putbit0` | function | `lzss.c:25` | `static void putbit0(void)` |
| `putbit1` | function | `lzss.c:18` | `static void putbit1(void)` |
| `encode` | function | `pack.c:5` | `extern void encode(void);` |
| `main` | function | `pack.c:8` | `int main(int argc, char *argv[])` |
| `outfile` | variable | `pack.c:6` | `extern FILE *infile, *outfile;` |
| `decode` | function | `test.c:6` | `void decode(void);` |
| `main` | function | `test.c:9` | `int main(void)` |
| `outfile` | variable | `test.c:7` | `extern FILE *infile, *outfile;` |
| `decode` | function | `unpack.c:5` | `extern void decode(void);` |
| `main` | function | `unpack.c:8` | `int main(int argc, char *argv[])` |
| `outfile` | variable | `unpack.c:6` | `extern FILE *infile, *outfile;` |
