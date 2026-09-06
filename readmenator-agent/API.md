# API

## aes.c

### getSBoxValue `static uint8_t getSBoxValue(uint8_t num)`
- Defined: `aes.c:12`
- Doc: define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16

### getSBoxInvert `static uint8_t getSBoxInvert(uint8_t num)`
- Defined: `aes.c:34`

### Td0 `static uint8_t Td0(int x)`
- Defined: `aes.c:56`

### Td1 `static uint8_t Td1(int x)`
- Defined: `aes.c:58`

### Td2 `static uint8_t Td2(int x)`
- Defined: `aes.c:59`

### Td3 `static uint8_t Td3(int x)`
- Defined: `aes.c:60`

### Td4 `static uint8_t Td4(int x)`
- Defined: `aes.c:61`

### KeyExpansion `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)`
- Defined: `aes.c:166`
- Doc: This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.

### AES_init_ctx `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- Defined: `aes.c:238`

### AES_init_ctx_iv `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)`
- Defined: `aes.c:244`
- Doc: if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))

### AES_ctx_set_iv `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- Defined: `aes.c:249`

### AddRoundKey `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:257`
- Doc: This function adds the round key to state. The round key is added to the state by an XOR function.

### SubBytes `static void SubBytes(state_t* state)`
- Defined: `aes.c:271`
- Doc: The SubBytes Function Substitutes the values in the state matrix with values in an S-box.

### ShiftRows `static void ShiftRows(state_t* state)`
- Defined: `aes.c:286`
- Doc: The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = R

### xtime `static uint8_t xtime(uint8_t x)`
- Defined: `aes.c:313`

### MixColumns `static void MixColumns(state_t* state)`
- Defined: `aes.c:320`
- Doc: MixColumns function mixes the columns of the state matrix

### Multiply `static uint8_t Multiply(uint8_t x, uint8_t y)`
- Defined: `aes.c:340`
- Doc: Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up 

### InvMixColumns `static void InvMixColumns(state_t* state)`
- Defined: `aes.c:370`
- Doc: MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand fo

### InvSubBytes `static void InvSubBytes(state_t* state)`
- Defined: `aes.c:391`
- Doc: The SubBytes Function Substitutes the values in the state matrix with values in an S-box.

### InvShiftRows `static void InvShiftRows(state_t* state)`
- Defined: `aes.c:402`

### Cipher `static void Cipher(state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:433`
- Doc: Cipher is the main function that encrypts the PlainText.

### InvCipher `static void InvCipher(state_t* state, const uint8_t* RoundKey)`
- Defined: `aes.c:459`
- Doc: if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)

### AES_ECB_encrypt `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- Defined: `aes.c:488`
- Doc: AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); } } #endif // #if (defined(CBC) &&

### AES_ECB_decrypt `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- Defined: `aes.c:495`

### XorWithIv `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)`
- Defined: `aes.c:510`
- Doc: if defined(CBC) && (CBC == 1)

### AES_CBC_encrypt_buffer `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:520`

### AES_CBC_decrypt_buffer `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:535`

### AES_CTR_xcrypt_buffer `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- Defined: `aes.c:558`
- Doc: XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC)

## crypter.py

### AESencrypt `def AESencrypt(plaintext, key)`
- Defined: `crypter.py:9`

### change_ext `def change_ext(filename, new_ext)`
- Defined: `crypter.py:19`
- Doc: Reemplaza la extensión del archivo por una nueva (sin el punto).

### main `def main()`
- Defined: `crypter.py:24`

## loader.c

### read_bit `static int read_bit(BitReader* br)`
- Defined: `loader.c:63`

### read_bits `static int read_bits(BitReader* br, int n)`
- Defined: `loader.c:74`

### lzss_decode_mem `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader.c:84`

### hookGetCommandLineW `LPWSTR hookGetCommandLineW()`
- Defined: `loader.c:217`
- Doc: Implementación de hooks

### hookGetCommandLineA `LPSTR hookGetCommandLineA()`
- Defined: `loader.c:218`

### hook__p___argv `char*** __cdecl hook__p___argv(void)`
- Defined: `loader.c:219`

### hook__p___wargv `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader.c:220`

### hook__p___argc `int* __cdecl hook__p___argc(void)`
- Defined: `loader.c:221`

### anti_analysis `BOOL anti_analysis()`
- Defined: `loader.c:226`
- Doc: === ANTI-ANALYSIS ===

### selfDestruct `void selfDestruct()`
- Defined: `loader.c:251`
- Doc: Puff

### hook__wgetmainargs `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader.c:306`

### hook__getmainargs `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader.c:312`

### hookexit `int __cdecl hookexit(int status)`
- Defined: `loader.c:318`

### hookExitProcess `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader.c:323`

### masqueradeCmdline `void masqueradeCmdline()`
- Defined: `loader.c:327`

### freeargvA `void freeargvA(char** array, int Argc)`
- Defined: `loader.c:365`

### freeargvW `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader.c:373`

### GetNTHeaders `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader.c:381`

### GetPEDirectory `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader.c:393`

### RepairIAT `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader.c:403`

### _stricmp `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- Defined: `loader.c:458`

### RunPE `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader.c:478`

### PELoader `void PELoader(char* data, DWORD datasize)`
- Defined: `loader.c:484`

### getNtdll `LPVOID getNtdll()`
- Defined: `loader.c:558`

### Unhook `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader.c:601`

### DecryptAES `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader.c:637`

### GetData `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader.c:670`

### main `int main(int argc, char** argv)`
- Defined: `loader.c:791`

## loader2.c

### read_bit `static int read_bit(BitReader* br)`
- Defined: `loader2.c:51`

### read_bits `static int read_bits(BitReader* br, int n)`
- Defined: `loader2.c:60`

### DecryptAES `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader2.c:70`

### get_return_address `static inline UPTR get_return_address(void)`
- Defined: `loader2.c:182`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader2.c:186`

### isShellcodeThread `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader2.c:195`
- Doc: Verifica si la dirección está dentro de .text

### shellcodeEncryptDecrypt `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader2.c:206`
- Doc: Fluctuación: encripta/desencripta SOLO .text

### MySleep `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader2.c:246`
- Doc: Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)

### fastTrampoline `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader2.c:261`

### VEHHandler `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader2.c:302`

### lzss_decode_mem `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader2.c:323`
- Doc: ================== LZSS ==================

### masqueradeCmdline `void masqueradeCmdline()`
- Defined: `loader2.c:387`
- Doc: ================== PE LOADER ==================

### GetNTHeaders `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader2.c:418`

### GetPEDirectory `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader2.c:429`

### RepairIAT `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader2.c:438`

### hookGetCommandLineA `LPSTR hookGetCommandLineA()`
- Defined: `loader2.c:490`
- Doc: Hooks

### hookGetCommandLineW `LPWSTR hookGetCommandLineW()`
- Defined: `loader2.c:491`

### hook__p___argv `char*** __cdecl hook__p___argv(void)`
- Defined: `loader2.c:492`

### hook__p___wargv `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader2.c:493`

### hook__p___argc `int* __cdecl hook__p___argc(void)`
- Defined: `loader2.c:494`

### hook__getmainargs `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader2.c:495`

### hook__wgetmainargs `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader2.c:498`

### hookExitProcess `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader2.c:501`

### RunPE `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader2.c:502`

### PELoader `void PELoader(char* data, DWORD datasize)`
- Defined: `loader2.c:508`

### anti_analysis `BOOL anti_analysis()`
- Defined: `loader2.c:596`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct `void selfDestruct()`
- Defined: `loader2.c:617`

### GetData `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader2.c:646`

### main `int main(int argc, char** argv)`
- Defined: `loader2.c:731`
- Doc: ================== MAIN ==================

## loader3.c

### read_bit `static int read_bit(BitReader* br)`
- Defined: `loader3.c:63`

### read_bits `static int read_bits(BitReader* br, int n)`
- Defined: `loader3.c:72`

### lzss_decode_mem `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader3.c:82`

### DecryptAES `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader3.c:138`

### get_return_address `static inline UPTR get_return_address(void)`
- Defined: `loader3.c:238`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader3.c:241`

### isShellcodeThread `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader3.c:248`

### shellcodeEncryptDecrypt `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader3.c:257`

### MySleep `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader3.c:291`

### fastTrampoline `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader3.c:305`

### VEHHandler `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader3.c:341`

### masqueradeCmdline `void masqueradeCmdline()`
- Defined: `loader3.c:360`
- Doc: ================== PE LOADER ==================

### freeargvA `void freeargvA(char** array, int Argc)`
- Defined: `loader3.c:389`

### freeargvW `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader3.c:397`

### GetNTHeaders `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader3.c:405`

### GetPEDirectory `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader3.c:416`

### RepairIAT `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader3.c:425`

### hookGetCommandLineA `LPSTR hookGetCommandLineA()`
- Defined: `loader3.c:478`
- Doc: Hooks

### hookGetCommandLineW `LPWSTR hookGetCommandLineW()`
- Defined: `loader3.c:479`

### hook__p___argv `char*** __cdecl hook__p___argv(void)`
- Defined: `loader3.c:480`

### hook__p___wargv `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader3.c:481`

### hook__p___argc `int* __cdecl hook__p___argc(void)`
- Defined: `loader3.c:482`

### hook__getmainargs `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader3.c:483`

### hook__wgetmainargs `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader3.c:486`

### hookexit `int __cdecl hookexit(int status)`
- Defined: `loader3.c:489`

### hookExitProcess `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader3.c:493`

### RunPE `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader3.c:496`

### PELoader `void PELoader(char* data, DWORD datasize)`
- Defined: `loader3.c:502`

### anti_analysis `BOOL anti_analysis()`
- Defined: `loader3.c:581`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct `void selfDestruct()`
- Defined: `loader3.c:601`

### getNtdll `LPVOID getNtdll()`
- Defined: `loader3.c:629`
- Doc: ================== UNHOOKING ==================

### Unhook `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader3.c:664`

### GetData `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader3.c:689`
- Doc: ================== NETWORK ==================

### main `int main(int argc, char** argv)`
- Defined: `loader3.c:757`
- Doc: ================== MAIN ==================

## loader4.c

### read_bit `static int read_bit(BitReader* br)`
- Defined: `loader4.c:103`

### read_bits `static int read_bits(BitReader* br, int n)`
- Defined: `loader4.c:112`

### deobf `void deobf(const char* src, char* dst, size_t max_len)`
- Defined: `loader4.c:124`
- Doc: Helper para desofuscar

### SetHWBP_NtContinue `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- Defined: `loader4.c:132`

### lzss_decode_mem `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- Defined: `loader4.c:161`

### PatchETW `BOOL PatchETW()`
- Defined: `loader4.c:218`

### DecryptAES `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- Defined: `loader4.c:250`

### get_return_address `static inline UPTR get_return_address(void)`
- Defined: `loader4.c:351`
- Doc: ================== FLUCTUATION IMPLEMENTATION ==================

### xor32 `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- Defined: `loader4.c:354`

### isShellcodeThread `bool isShellcodeThread(LPVOID addr)`
- Defined: `loader4.c:361`

### shellcodeEncryptDecrypt `void shellcodeEncryptDecrypt(LPVOID caller)`
- Defined: `loader4.c:370`

### MySleep `static void WINAPI MySleep(DWORD ms)`
- Defined: `loader4.c:404`

### fastTrampoline `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- Defined: `loader4.c:418`

### VEHHandler `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- Defined: `loader4.c:457`

### masqueradeCmdline `void masqueradeCmdline()`
- Defined: `loader4.c:476`
- Doc: ================== PE LOADER ==================

### freeargvA `void freeargvA(char** array, int Argc)`
- Defined: `loader4.c:505`

### freeargvW `void freeargvW(wchar_t** array, int Argc)`
- Defined: `loader4.c:513`

### GetNTHeaders `char* GetNTHeaders(char* pe_buffer)`
- Defined: `loader4.c:521`

### GetPEDirectory `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- Defined: `loader4.c:532`

### RepairIAT `BOOL RepairIAT(PVOID modulePtr)`
- Defined: `loader4.c:541`

### hookGetCommandLineA `LPSTR hookGetCommandLineA()`
- Defined: `loader4.c:594`
- Doc: Hooks

### hookGetCommandLineW `LPWSTR hookGetCommandLineW()`
- Defined: `loader4.c:595`

### hook__p___argv `char*** __cdecl hook__p___argv(void)`
- Defined: `loader4.c:596`

### hook__p___wargv `wchar_t*** __cdecl hook__p___wargv(void)`
- Defined: `loader4.c:597`

### hook__p___argc `int* __cdecl hook__p___argc(void)`
- Defined: `loader4.c:598`

### hook__getmainargs `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- Defined: `loader4.c:599`

### hook__wgetmainargs `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- Defined: `loader4.c:602`

### hookexit `int __cdecl hookexit(int status)`
- Defined: `loader4.c:605`

### hookExitProcess `void __stdcall hookExitProcess(UINT statuscode)`
- Defined: `loader4.c:609`

### RunPE `DWORD WINAPI RunPE(LPVOID lpParameter)`
- Defined: `loader4.c:612`

### PELoader `void PELoader(char* data, DWORD datasize)`
- Defined: `loader4.c:618`

### anti_analysis `BOOL anti_analysis()`
- Defined: `loader4.c:699`
- Doc: ================== ANTI-ANALYSIS & CLEANUP ==================

### selfDestruct `void selfDestruct()`
- Defined: `loader4.c:719`

### getNtdll `LPVOID getNtdll()`
- Defined: `loader4.c:747`
- Doc: ================== UNHOOKING ==================

### Unhook `BOOL Unhook(LPVOID cleanNtdll)`
- Defined: `loader4.c:784`

### GetData `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- Defined: `loader4.c:811`
- Doc: ================== NETWORK ==================

### main `int main(int argc, char** argv)`
- Defined: `loader4.c:879`
- Doc: ================== MAIN ==================

## lzss.c

### error `static void error(void)`
- Defined: `lzss.c:15`

### putbit1 `static void putbit1(void)`
- Defined: `lzss.c:17`

### putbit0 `static void putbit0(void)`
- Defined: `lzss.c:25`

### flush_bit_buffer `static void flush_bit_buffer(void)`
- Defined: `lzss.c:31`

### output1 `static void output1(int c)`
- Defined: `lzss.c:34`

### output2 `static void output2(int x, int y)`
- Defined: `lzss.c:39`

### encode `void encode(void)`
- Defined: `lzss.c:45`

### getbit `static int getbit(int n)`
- Defined: `lzss.c:76`

### decode `void decode(void)`
- Defined: `lzss.c:86`

## pack.c

### main `int main(int argc, char *argv[])`
- Defined: `pack.c:7`

## test.c

### main `int main(void)`
- Defined: `test.c:8`

## unpack.c

### main `int main(int argc, char *argv[])`
- Defined: `unpack.c:7`
