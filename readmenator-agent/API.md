# API

## aes.c

### getSBoxValue (function) `static uint8_t getSBoxValue(uint8_t num)`
- Defined: `aes.c:13`
- Depends on: `aes.h`

### getSBoxInvert (function) `static uint8_t getSBoxInvert(uint8_t num)`
- Defined: `aes.c:35`
- Depends on: `aes.h`

### Td0 (function) `static uint8_t Td0(int x)`
- Defined: `aes.c:57`
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
- Defined: `aes.c:239`
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
- Defined: `aes.c:314`
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
- Defined: `aes.c:403`
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
- Defined: `aes.c:490`
- Depends on: `aes.h`

### AES_ECB_decrypt (function) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- Defined: `aes.c:496`
- Depends on: `aes.h`

### XorWithIv (function) `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)`
- Defined: `aes.c:512`
- Depends on: `aes.h`

### AES_CBC_encrypt_buffer (function) `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:521`
- Depends on: `aes.h`

### AES_CBC_decrypt_buffer (function) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:536`
- Depends on: `aes.h`

### AES_CTR_xcrypt_buffer (function) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:558`
- Doc: XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC)
- Depends on: `aes.h`

## aes.h

### AES_init_ctx (function) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);`
- Defined: `aes.h:41`
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
- Defined: `loader.c:64`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader.c:75`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader.c:85`

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
- Defined: `loader.c:307`

### hook__getmainargs (function) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader.c:313`

### hookexit (function) `int __cdecl hookexit(int status)`
- Defined: `loader.c:319`

### hookExitProcess (function) `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader.c:324`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader.c:328`

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader.c:366`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader.c:374`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader.c:382`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader.c:394`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader.c:404`

### _stricmp (function) `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- Defined: `loader.c:458`

### RunPE (function) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader.c:479`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader.c:485`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader.c:559`

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader.c:602`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader.c:638`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader.c:671`

### main (function) `int main(int argc, char** argv)`
- Defined: `loader.c:792`

## loader2.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader2.c:52`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader2.c:61`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader2.c:71`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader2.c:183`

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader2.c:187`

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
- Defined: `loader2.c:262`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader2.c:303`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader2.c:324`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader2.c:388`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader2.c:419`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader2.c:430`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader2.c:439`

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
- Defined: `loader2.c:503`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader2.c:509`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader2.c:597`

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader2.c:618`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader2.c:647`

### main (function) `int main(int argc, char** argv)`
- Defined: `loader2.c:732`

### freeargvA (function) `void freeargvA(char** array, int Argc);`
- Defined: `loader2.c:169`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc);`
- Defined: `loader2.c:170`

## loader3.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader3.c:64`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader3.c:73`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader3.c:83`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader3.c:139`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader3.c:238`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader3.c:242`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader3.c:249`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader3.c:258`

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader3.c:292`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader3.c:306`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader3.c:342`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader3.c:360`
- Doc: ================== PE LOADER ==================

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader3.c:390`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader3.c:398`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader3.c:406`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader3.c:417`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader3.c:426`

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
- Defined: `loader3.c:497`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader3.c:503`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader3.c:581`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader3.c:602`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader3.c:629`
- Doc: ================== UNHOOKING ==================

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader3.c:665`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader3.c:689`
- Doc: ================== NETWORK ==================

### main (function) `int main(int argc, char** argv)`
- Defined: `loader3.c:757`
- Doc: ================== MAIN ==================

## loader4.c

### read_bit (function) `static int read_bit(BitReader* br)`
- Defined: `loader4.c:104`

### read_bits (function) `static int read_bits(BitReader* br, int n)`
- Defined: `loader4.c:113`

### deobf (function) `void deobf(const char* src, char* dst, size_t max_len)`
- Defined: `loader4.c:124`
- Doc: Helper para desofuscar

### SetHWBP_NtContinue (function) `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- Defined: `loader4.c:132`

### lzss_decode_mem (function) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader4.c:163`

### PatchETW (function) `BOOL PatchETW()`
- Defined: `loader4.c:219`

### DecryptAES (function) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader4.c:252`

### get_return_address (function) `static inline UPTR get_return_address(void)`
- Defined: `loader4.c:351`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 (function) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader4.c:355`

### isShellcodeThread (function) `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader4.c:362`

### shellcodeEncryptDecrypt (function) `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader4.c:371`

### MySleep (function) `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader4.c:405`

### fastTrampoline (function) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader4.c:419`

### VEHHandler (function) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader4.c:458`

### masqueradeCmdline (function) `void masqueradeCmdline()`
- Defined: `loader4.c:476`
- Doc: ================== PE LOADER ==================

### freeargvA (function) `void freeargvA(char** array, int Argc)`
- Defined: `loader4.c:506`

### freeargvW (function) `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader4.c:514`

### GetNTHeaders (function) `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader4.c:522`

### GetPEDirectory (function) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader4.c:533`

### RepairIAT (function) `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader4.c:542`

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
- Defined: `loader4.c:613`

### PELoader (function) `void PELoader(char* data, DWORD datasize)`
- Defined: `loader4.c:619`

### anti_analysis (function) `BOOL anti_analysis()`
- Defined: `loader4.c:699`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct (function) `void selfDestruct()`
- Defined: `loader4.c:720`

### getNtdll (function) `LPVOID getNtdll()`
- Defined: `loader4.c:747`
- Doc: ================== UNHOOKING ==================

### Unhook (function) `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader4.c:785`

### GetData (function) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader4.c:811`
- Doc: ================== NETWORK ==================

### main (function) `int main(int argc, char** argv)`
- Defined: `loader4.c:879`
- Doc: ================== MAIN ==================

## lzss.c

### error (function) `static void error(void)`
- Defined: `lzss.c:16`

### putbit1 (function) `static void putbit1(void)`
- Defined: `lzss.c:18`

### putbit0 (function) `static void putbit0(void)`
- Defined: `lzss.c:25`

### flush_bit_buffer (function) `static void flush_bit_buffer(void)`
- Defined: `lzss.c:31`

### output1 (function) `static void output1(int c)`
- Defined: `lzss.c:34`

### output2 (function) `static void output2(int x, int y)`
- Defined: `lzss.c:39`

### encode (function) `void encode(void)`
- Defined: `lzss.c:46`

### getbit (function) `static int getbit(int n)`
- Defined: `lzss.c:77`

### decode (function) `void decode(void)`
- Defined: `lzss.c:87`

## pack.c

### main (function) `int main(int argc, char *argv[])`
- Defined: `pack.c:8`

### encode (function) `extern void encode(void);`
- Defined: `pack.c:5`

## test.c

### main (function) `int main(void)`
- Defined: `test.c:9`

### decode (function) `void decode(void);`
- Defined: `test.c:6`
- Doc: /* test.c – wrapper decompress Okumura #include <stdio.h> #include <stdlib.h> /* declaraciones externas de Okumura

## unpack.c

### main (function) `int main(int argc, char *argv[])`
- Defined: `unpack.c:8`

### decode (function) `extern void decode(void);`
- Defined: `unpack.c:5`
