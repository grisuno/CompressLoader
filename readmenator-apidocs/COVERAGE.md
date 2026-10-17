# Documentation Coverage

Overall: **21.6%** (89 of 412 public modules, types, and callables). Data members are excluded from the ratio.

[Back to index](index.md)

## By kind

| Kind | Documented | Total | Coverage |
|---|---|---|---|
| function | 47 | 224 | 21.0% |
| macro | 19 | 126 | 15.1% |
| module | 7 | 16 | 43.8% |
| struct | 8 | 33 | 24.2% |
| type_alias | 8 | 13 | 61.5% |

## By module (lowest first)

| Module | Documented | Total | Coverage |
|---|---|---|---|
| [`install.sh`](modules/install.sh.md) | 0 | 1 | 0.0% |
| [`lzss.c`](modules/lzss.c.md) | 1 | 8 | 12.5% |
| [`loader2.c`](modules/loader2.c.md) | 7 | 50 | 14.0% |
| [`loader.c`](modules/loader.c.md) | 6 | 42 | 14.3% |
| [`lz4.h`](modules/lz4.h.md) | 2 | 14 | 14.3% |
| [`loader3.c`](modules/loader3.c.md) | 10 | 50 | 20.0% |
| [`loader5.c`](modules/loader5.c.md) | 13 | 55 | 23.6% |
| [`loader6.c`](modules/loader6.c.md) | 13 | 55 | 23.6% |
| [`aes.h`](modules/aes.h.md) | 5 | 21 | 23.8% |
| [`loader4.c`](modules/loader4.c.md) | 14 | 57 | 24.6% |
| [`crypter`](modules/crypter.py.md) | 1 | 4 | 25.0% |
| [`lz4.c`](modules/lz4.c.md) | 6 | 24 | 25.0% |
| [`aes.c`](modules/aes.c.md) | 8 | 24 | 33.3% |
| [`pack.c`](modules/pack.c.md) | 1 | 3 | 33.3% |
| [`unpack.c`](modules/unpack.c.md) | 1 | 3 | 33.3% |
| [`app`](modules/app.py.md) | 1 | 1 | 100.0% |

## Warnings

DOC001 undocumented public item, DOC002 parameter not documented, DOC003 documented parameter missing from the signature (stale doc), DOC004 return value not documented, DOC005 raised exception not documented.

DOC001: 323

- DOC001 `aes.c:5` macro Nb is not documented
- DOC001 `aes.c:9` macro KEYLEN_256 is not documented
- DOC001 `aes.c:10` macro RKLENGTH is not documented
- DOC001 `aes.c:11` macro BLOCKLEN is not documented
- DOC001 `aes.c:70` macro Nk is not documented
- DOC001 `aes.c:71` macro Nr is not documented
- DOC001 `aes.c:73` macro Nk is not documented
- DOC001 `aes.c:74` macro Nr is not documented
- DOC001 `aes.c:76` macro Nk is not documented
- DOC001 `aes.c:77` macro Nr is not documented
- DOC001 `aes.c:84` macro MULTIPLY_AS_A_FUNCTION is not documented
- DOC001 `aes.c:239` function AES_init_ctx is not documented
- DOC001 `aes.c:249` function AES_ctx_set_iv is not documented
- DOC001 `aes.c:349` macro Multiply is not documented
- DOC001 `aes.c:496` function AES_ECB_decrypt is not documented
- DOC001 `aes.c:536` function AES_CBC_decrypt_buffer is not documented
- DOC001 `aes.h:9` macro CBC is not documented
- DOC001 `aes.h:12` macro ECB is not documented
- DOC001 `aes.h:15` macro CTR is not documented
- DOC001 `aes.h:18` macro AES256 is not documented
- DOC001 `aes.h:20` macro AES_BLOCKLEN is not documented
- DOC001 `aes.h:23` macro AES_KEYLEN is not documented
- DOC001 `aes.h:24` macro AES_keyExpSize is not documented
- DOC001 `aes.h:26` macro AES_KEYLEN is not documented
- DOC001 `aes.h:27` macro AES_keyExpSize is not documented
- DOC001 `aes.h:29` macro AES_KEYLEN is not documented
- DOC001 `aes.h:30` macro AES_keyExpSize is not documented
- DOC001 `aes.h:33` struct AES_ctx is not documented
- DOC001 `aes.h:41` function AES_init_ctx is not documented
- DOC001 `aes.h:44` function AES_ctx_set_iv is not documented
- DOC001 `aes.h:49` function AES_ECB_decrypt is not documented
- DOC001 `aes.h:54` function AES_CBC_decrypt_buffer is not documented
- DOC001 `crypter.py:1` module crypter.py is not documented
- DOC001 `crypter.py:9` function AESencrypt is not documented
- DOC001 `crypter.py:24` function main is not documented
- DOC001 `install.sh:1` module install.sh is not documented
- DOC001 `loader.c:1` module loader.c is not documented
- DOC001 `loader.c:30` macro NT_SUCCESS is not documented
- DOC001 `loader.c:33` macro NtCurrentThread is not documented
- DOC001 `loader.c:34` macro NtCurrentProcess is not documented
- DOC001 `loader.c:37` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader.c:40` type_alias 12 is not documented
- DOC001 `loader.c:41` struct _BASE_RELOCATION_ENTRY is not documented
- DOC001 `loader.c:46` struct DATA is not documented
- DOC001 `loader.c:53` macro EJ is not documented
- DOC001 `loader.c:54` macro P is not documented
- DOC001 `loader.c:55` macro N is not documented
- DOC001 `loader.c:56` macro F is not documented
- DOC001 `loader.c:58` struct BitReader is not documented
- DOC001 `loader.c:85` function lzss_decode_mem is not documented
- DOC001 `loader.c:218` function hookGetCommandLineA is not documented
- DOC001 `loader.c:219` function hook__p___argv is not documented
- DOC001 `loader.c:220` function hook__p___wargv is not documented
- DOC001 `loader.c:221` function hook__p___argc is not documented
- DOC001 `loader.c:307` function hook__wgetmainargs is not documented
- DOC001 `loader.c:313` function hook__getmainargs is not documented
- DOC001 `loader.c:319` function hookexit is not documented
- DOC001 `loader.c:324` function hookExitProcess is not documented
- DOC001 `loader.c:328` function masqueradeCmdline is not documented
- DOC001 `loader.c:366` function freeargvA is not documented
- DOC001 `loader.c:374` function freeargvW is not documented
- DOC001 `loader.c:382` function GetNTHeaders is not documented
- DOC001 `loader.c:394` function GetPEDirectory is not documented
- DOC001 `loader.c:404` function RepairIAT is not documented
- DOC001 `loader.c:458` function _stricmp is not documented
- DOC001 `loader.c:479` function RunPE is not documented
- DOC001 `loader.c:485` function PELoader is not documented
- DOC001 `loader.c:559` function getNtdll is not documented
- DOC001 `loader.c:602` function Unhook is not documented
- DOC001 `loader.c:638` function DecryptAES is not documented
- DOC001 `loader.c:671` function GetData is not documented
- DOC001 `loader.c:792` function main is not documented
- DOC001 `loader2.c:1` macro _CRT_RAND_S is not documented
- DOC001 `loader2.c:2` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader2.c:26` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader2.c:29` macro NT_SUCCESS is not documented
- DOC001 `loader2.c:32` macro NtCurrentThread is not documented
- DOC001 `loader2.c:33` macro NtCurrentProcess is not documented
- DOC001 `loader2.c:35` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader2.c:36` macro UNICODE is not documented
- DOC001 `loader2.c:37` macro _UNICODE is not documented
- DOC001 `loader2.c:41` macro EJ is not documented
- DOC001 `loader2.c:42` macro P is not documented
- DOC001 `loader2.c:43` macro N is not documented
- DOC001 `loader2.c:44` macro F is not documented
- DOC001 `loader2.c:46` struct BitReader is not documented
- DOC001 `loader2.c:71` function DecryptAES is not documented
- DOC001 `loader2.c:111` struct FluctuationMetadata is not documented
- DOC001 `loader2.c:119` struct HookTrampolineBuffers is not documented
- DOC001 `loader2.c:129` struct HookedSleep is not documented
- DOC001 `loader2.c:134` struct DATA is not documented
- DOC001 `loader2.c:154` macro log is not documented
- DOC001 `loader2.c:169` function freeargvA is not documented
- DOC001 `loader2.c:170` function freeargvW is not documented
- DOC001 `loader2.c:187` function xor32 is not documented
- DOC001 `loader2.c:262` function fastTrampoline is not documented
- DOC001 `loader2.c:303` function VEHHandler is not documented
- DOC001 `loader2.c:324` function lzss_decode_mem is not documented
- DOC001 `loader2.c:388` function masqueradeCmdline is not documented
- DOC001 `loader2.c:419` function GetNTHeaders is not documented
- DOC001 `loader2.c:430` function GetPEDirectory is not documented
- DOC001 `loader2.c:439` function RepairIAT is not documented
- DOC001 `loader2.c:491` function hookGetCommandLineW is not documented
- DOC001 `loader2.c:492` function hook__p___argv is not documented
- DOC001 `loader2.c:493` function hook__p___wargv is not documented
- DOC001 `loader2.c:494` function hook__p___argc is not documented
- DOC001 `loader2.c:495` function hook__getmainargs is not documented
- DOC001 `loader2.c:498` function hook__wgetmainargs is not documented
- DOC001 `loader2.c:501` function hookExitProcess is not documented
- DOC001 `loader2.c:503` function RunPE is not documented
- DOC001 `loader2.c:509` function PELoader is not documented
- DOC001 `loader2.c:597` function anti_analysis is not documented
- DOC001 `loader2.c:618` function selfDestruct is not documented
- DOC001 `loader2.c:647` function GetData is not documented
- DOC001 `loader2.c:732` function main is not documented
- DOC001 `loader3.c:1` module loader3.c is not documented
- DOC001 `loader3.c:16` macro _CRT_RAND_S is not documented
- DOC001 `loader3.c:17` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader3.c:42` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader3.c:45` macro NT_SUCCESS is not documented
- DOC001 `loader3.c:48` macro NtCurrentThread is not documented
- DOC001 `loader3.c:49` macro NtCurrentProcess is not documented
- DOC001 `loader3.c:53` macro EJ is not documented
- DOC001 `loader3.c:54` macro P is not documented
- DOC001 `loader3.c:55` macro N is not documented
- DOC001 `loader3.c:56` macro F is not documented
- DOC001 `loader3.c:58` struct BitReader is not documented
- DOC001 `loader3.c:83` function lzss_decode_mem is not documented
- DOC001 `loader3.c:139` function DecryptAES is not documented
- DOC001 `loader3.c:174` struct FluctuationMetadata is not documented
- DOC001 `loader3.c:182` struct HookTrampolineBuffers is not documented
- DOC001 `loader3.c:192` struct HookedSleep is not documented
- DOC001 `loader3.c:197` struct DATA is not documented
- DOC001 `loader3.c:242` function xor32 is not documented
- DOC001 `loader3.c:249` function isShellcodeThread is not documented
- DOC001 `loader3.c:258` function shellcodeEncryptDecrypt is not documented
- DOC001 `loader3.c:306` function fastTrampoline is not documented
- DOC001 `loader3.c:342` function VEHHandler is not documented
- DOC001 `loader3.c:390` function freeargvA is not documented
- DOC001 `loader3.c:398` function freeargvW is not documented
- DOC001 `loader3.c:406` function GetNTHeaders is not documented
- DOC001 `loader3.c:417` function GetPEDirectory is not documented
- DOC001 `loader3.c:426` function RepairIAT is not documented
- DOC001 `loader3.c:479` function hookGetCommandLineW is not documented
- DOC001 `loader3.c:480` function hook__p___argv is not documented
- DOC001 `loader3.c:481` function hook__p___wargv is not documented
- DOC001 `loader3.c:482` function hook__p___argc is not documented
- DOC001 `loader3.c:483` function hook__getmainargs is not documented
- DOC001 `loader3.c:486` function hook__wgetmainargs is not documented
- DOC001 `loader3.c:489` function hookexit is not documented
- DOC001 `loader3.c:493` function hookExitProcess is not documented
- DOC001 `loader3.c:497` function RunPE is not documented
- DOC001 `loader3.c:503` function PELoader is not documented
- DOC001 `loader3.c:602` function selfDestruct is not documented
- DOC001 `loader3.c:665` function Unhook is not documented
- DOC001 `loader4.c:1` module loader4.c is not documented
- DOC001 `loader4.c:16` macro _CRT_RAND_S is not documented
- DOC001 `loader4.c:17` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader4.c:42` macro XK is not documented
- DOC001 `loader4.c:52` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader4.c:55` macro NT_SUCCESS is not documented
- DOC001 `loader4.c:58` macro NtCurrentThread is not documented
- DOC001 `loader4.c:59` macro NtCurrentProcess is not documented
- DOC001 `loader4.c:63` macro EJ is not documented
- DOC001 `loader4.c:64` macro P is not documented
- DOC001 `loader4.c:65` macro N is not documented
- DOC001 `loader4.c:66` macro F is not documented
- DOC001 `loader4.c:98` struct BitReader is not documented
- DOC001 `loader4.c:132` function SetHWBP_NtContinue is not documented
- DOC001 `loader4.c:163` function lzss_decode_mem is not documented
- DOC001 `loader4.c:219` function PatchETW is not documented
- DOC001 `loader4.c:252` function DecryptAES is not documented
- DOC001 `loader4.c:287` struct FluctuationMetadata is not documented
- DOC001 `loader4.c:295` struct HookTrampolineBuffers is not documented
- DOC001 `loader4.c:305` struct HookedSleep is not documented
- DOC001 `loader4.c:310` struct DATA is not documented
- DOC001 `loader4.c:355` function xor32 is not documented
- DOC001 `loader4.c:362` function isShellcodeThread is not documented
- DOC001 `loader4.c:371` function shellcodeEncryptDecrypt is not documented
- DOC001 `loader4.c:419` function fastTrampoline is not documented
- DOC001 `loader4.c:458` function VEHHandler is not documented
- DOC001 `loader4.c:506` function freeargvA is not documented
- DOC001 `loader4.c:514` function freeargvW is not documented
- DOC001 `loader4.c:522` function GetNTHeaders is not documented
- DOC001 `loader4.c:533` function GetPEDirectory is not documented
- DOC001 `loader4.c:542` function RepairIAT is not documented
- DOC001 `loader4.c:595` function hookGetCommandLineW is not documented
- DOC001 `loader4.c:596` function hook__p___argv is not documented
- DOC001 `loader4.c:597` function hook__p___wargv is not documented
- DOC001 `loader4.c:598` function hook__p___argc is not documented
- DOC001 `loader4.c:599` function hook__getmainargs is not documented
- DOC001 `loader4.c:602` function hook__wgetmainargs is not documented
- DOC001 `loader4.c:605` function hookexit is not documented
- DOC001 `loader4.c:609` function hookExitProcess is not documented
- DOC001 `loader4.c:613` function RunPE is not documented
- DOC001 `loader4.c:619` function PELoader is not documented
- DOC001 `loader4.c:720` function selfDestruct is not documented
- DOC001 `loader4.c:785` function Unhook is not documented
- DOC001 `loader5.c:1` module loader5.c is not documented
- DOC001 `loader5.c:14` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader5.c:29` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader5.c:35` macro DEBUG_PRINT is not documented
- DOC001 `loader5.c:37` macro DEBUG_PRINT is not documented
- DOC001 `loader5.c:45` macro OBFSTR is not documented
- DOC001 `loader5.c:65` function HellGate is not documented
- DOC001 `loader5.c:284` macro EI is not documented
- DOC001 `loader5.c:285` macro EJ is not documented
- DOC001 `loader5.c:286` macro P is not documented
- DOC001 `loader5.c:287` macro N is not documented
- DOC001 `loader5.c:288` macro F is not documented
- DOC001 `loader5.c:290` struct BitReader is not documented
- DOC001 `loader5.c:315` function decompress_payload is not documented
- DOC001 `loader5.c:400` function HasHWBreakpoints is not documented
- DOC001 `loader5.c:407` function IsDomainJoined is not documented
- DOC001 `loader5.c:416` function HasRealGPU is not documented
- DOC001 `loader5.c:434` function HasUserActivity is not documented
- DOC001 `loader5.c:443` function IsSandbox is not documented
- DOC001 `loader5.c:535` function UnhookNtdll is not documented
- DOC001 `loader5.c:568` function MasqueradeCmdline is not documented
- DOC001 `loader5.c:592` function hookGetCommandLineA is not documented
- DOC001 `loader5.c:593` function hookGetCommandLineW is not documented
- DOC001 `loader5.c:594` function hook__p___argv is not documented
- DOC001 `loader5.c:595` function hook__p___wargv is not documented
- DOC001 `loader5.c:596` function hook__p___argc is not documented
- DOC001 `loader5.c:597` function hook__getmainargs is not documented
- DOC001 `loader5.c:600` function hook__wgetmainargs is not documented
- DOC001 `loader5.c:603` function hookexit is not documented
- DOC001 `loader5.c:604` function hookExitProcess is not documented
- DOC001 `loader5.c:620` function GetPEDirectory is not documented
- DOC001 `loader5.c:629` function RepairIAT is not documented
- DOC001 `loader5.c:679` struct FLUCTUATION_CTX is not documented
- DOC001 `loader5.c:691` function FluctuateEncrypt is not documented
- DOC001 `loader5.c:715` function FluctuateDecrypt is not documented
- DOC001 `loader5.c:739` struct HookTrampolineBuffers is not documented
- DOC001 `loader5.c:746` function fastTrampoline is not documented
- DOC001 `loader5.c:770` function MySleep is not documented
- DOC001 `loader5.c:790` function ExecuteWithSpoofedRet is not documented
- DOC001 `loader5.c:803` function TimerExecCallback is not documented
- DOC001 `loader5.c:810` function ModuleStompAndExecute is not documented
- DOC001 `loader5.c:909` function GetData is not documented
- DOC001 `loader6.c:1` module loader6.c is not documented
- DOC001 `loader6.c:15` macro WIN32_LEAN_AND_MEAN is not documented
- DOC001 `loader6.c:31` macro _CRT_SECURE_NO_WARNINGS is not documented
- DOC001 `loader6.c:37` macro DEBUG_PRINT is not documented
- DOC001 `loader6.c:39` macro DEBUG_PRINT is not documented
- DOC001 `loader6.c:47` macro OBFSTR is not documented
- DOC001 `loader6.c:67` function HellGate is not documented
- DOC001 `loader6.c:286` macro EI is not documented
- DOC001 `loader6.c:287` macro EJ is not documented
- DOC001 `loader6.c:288` macro P is not documented
- DOC001 `loader6.c:289` macro N is not documented
- DOC001 `loader6.c:290` macro F is not documented
- DOC001 `loader6.c:292` struct BitReader is not documented
- DOC001 `loader6.c:317` function decompress_payload is not documented
- DOC001 `loader6.c:402` function HasHWBreakpoints is not documented
- DOC001 `loader6.c:409` function IsDomainJoined is not documented
- DOC001 `loader6.c:418` function HasRealGPU is not documented
- DOC001 `loader6.c:436` function HasUserActivity is not documented
- DOC001 `loader6.c:445` function IsSandbox is not documented
- DOC001 `loader6.c:537` function UnhookNtdll is not documented
- DOC001 `loader6.c:571` function MasqueradeCmdline is not documented
- DOC001 `loader6.c:595` function hookGetCommandLineA is not documented
- DOC001 `loader6.c:596` function hookGetCommandLineW is not documented
- DOC001 `loader6.c:597` function hook__p___argv is not documented
- DOC001 `loader6.c:598` function hook__p___wargv is not documented
- DOC001 `loader6.c:599` function hook__p___argc is not documented
- DOC001 `loader6.c:600` function hook__getmainargs is not documented
- DOC001 `loader6.c:603` function hook__wgetmainargs is not documented
- DOC001 `loader6.c:606` function hookexit is not documented
- DOC001 `loader6.c:607` function hookExitProcess is not documented
- DOC001 `loader6.c:623` function GetPEDirectory is not documented
- DOC001 `loader6.c:632` function RepairIAT is not documented
- DOC001 `loader6.c:682` struct FLUCTUATION_CTX is not documented
- DOC001 `loader6.c:694` function FluctuateEncrypt is not documented
- DOC001 `loader6.c:718` function FluctuateDecrypt is not documented
- DOC001 `loader6.c:742` struct HookTrampolineBuffers is not documented
- DOC001 `loader6.c:749` function fastTrampoline is not documented
- DOC001 `loader6.c:773` function MySleep is not documented
- DOC001 `loader6.c:793` function ExecuteWithSpoofedRet is not documented
- DOC001 `loader6.c:806` function TimerExecCallback is not documented
- DOC001 `loader6.c:814` function ModuleStompAndExecute is not documented
- DOC001 `loader6.c:913` function GetData is not documented
- DOC001 `lz4.c:1` module lz4.c is not documented
- DOC001 `lz4.c:17` macro LZ4_ARCH_64 is not documented
- DOC001 `lz4.c:18` macro LZ4_FAST_DEC_LOOP is not documented
- DOC001 `lz4.c:24` type_alias U16 is not documented
- DOC001 `lz4.c:25` type_alias U32 is not documented
- DOC001 `lz4.c:26` type_alias S32 is not documented
- DOC001 `lz4.c:27` type_alias U64 is not documented
- DOC001 `lz4.c:30` macro MEMORY_SANITIZER is not documented
- DOC001 `lz4.c:37` macro LZ4_16_BIT is not documented
- DOC001 `lz4.c:38` macro LZ4_32_BIT is not documented
- DOC001 `lz4.c:39` macro LZ4_64_BIT is not documented
- DOC001 `lz4.c:42` macro LZ4_64K is not documented
- DOC001 `lz4.c:45` macro LZ4_MEMORY_USAGE is not documented
- DOC001 `lz4.c:46` macro LZ4_MAX_INPUT_SIZE is not documented
- DOC001 `lz4.c:95` function LZ4_decompress_safe_usingDict is not documented
- DOC001 `lz4.c:189` function LZ4_setStreamDecode is not documented
- DOC001 `lz4.c:198` function LZ4_decompress_safe_continue is not documented
- DOC001 `lz4.c:205` function LZ4_resetStreamDecode is not documented
- DOC001 `lz4.h:1` module lz4.h is not documented
- DOC001 `lz4.h:36` macro LZ4_H_2983827168210 is not documented
- DOC001 `lz4.h:50` macro LZ4_EXPORT is not documented
- DOC001 `lz4.h:52` macro LZ4_EXPORT is not documented
- DOC001 `lz4.h:54` macro LZ4_EXPORT is not documented
- DOC001 `lz4.h:60` macro LZ4_VERSION_MINOR is not documented
- DOC001 `lz4.h:61` macro LZ4_VERSION_RELEASE is not documented
- DOC001 `lz4.h:62` macro LZ4_VERSION_NUMBER is not documented
- DOC001 `lz4.h:65` function LZ4_decompress_safe is not documented
- DOC001 `lz4.h:90` function LZ4_setStreamDecode is not documented
- DOC001 `lz4.h:91` function LZ4_decompress_safe_continue is not documented
- DOC001 `lz4.h:92` function LZ4_resetStreamDecode is not documented
- DOC001 `lzss.c:5` macro EI is not documented
- DOC001 `lzss.c:6` macro EJ is not documented
- DOC001 `lzss.c:7` macro P is not documented
- DOC001 `lzss.c:8` macro N is not documented
- DOC001 `lzss.c:9` macro F is not documented
- DOC001 `lzss.c:46` function encode is not documented
- DOC001 `lzss.c:87` function decode is not documented
- DOC001 `pack.c:5` function encode is not documented
- DOC001 `pack.c:8` function main is not documented
- DOC001 `unpack.c:5` function decode is not documented
- DOC001 `unpack.c:8` function main is not documented
