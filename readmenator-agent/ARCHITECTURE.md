# Architecture

## Internal Dependencies

- `aes.c` -> `aes.h`

## External Imports

- `aes.c` -> string.h
- `aes.h` -> stddef.h, stdint.h
- `crypter.py` -> Crypto.Cipher, hashlib, os, struct, sys
- `loader.c` -> psapi.h, stdio.h, stdlib.h, string.h, wincrypt.h, windows.h, winhttp.h, winternl.h
- `loader2.c` -> psapi.h, shellapi.h, stdbool.h, stdint.h, stdio.h, stdlib.h, string.h, wincrypt.h, windows.h, winhttp.h, winternl.h
- `loader3.c` -> psapi.h, shellapi.h, stdbool.h, stdint.h, stdio.h, stdlib.h, string.h, wincrypt.h, windows.h, winhttp.h, winternl.h
- `loader4.c` -> psapi.h, shellapi.h, stdbool.h, stdint.h, stdio.h, stdlib.h, string.h, wincrypt.h, windows.h, winhttp.h, winternl.h
- `lzss.c` -> stdio.h, stdlib.h
- `pack.c` -> stdio.h, stdlib.h
- `test.c` -> stdio.h, stdlib.h
- `unpack.c` -> stdio.h, stdlib.h
