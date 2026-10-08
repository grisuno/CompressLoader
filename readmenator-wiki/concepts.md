# Concepts

Second-brain semantic layer: nouns map atomically to file sets (EXTRACTED); verbs aggregate structural edges (INFERRED).

| Concept | Files | Mentions | Top Files |
|---------|-------|----------|-----------|
| `decode` | 7 | 7 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c`, `lzss.c` |
| `aes` | 6 | 39 | `aes.c`, `aes.h`, `loader.c`, `loader2.c`, `loader3.c` |
| `decrypt` | 6 | 12 | `aes.c`, `aes.h`, `loader.c`, `loader2.c`, `loader3.c` |
| `get` | 5 | 30 | `aes.c`, `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `bit` | 5 | 9 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c`, `lzss.c` |
| `encrypt` | 5 | 7 | `aes.c`, `aes.h`, `loader2.c`, `loader3.c`, `loader4.c` |
| `lzss` | 5 | 7 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c`, `lzss.c` |
| `hook` | 4 | 36 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `crt` | 4 | 9 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `command` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `current` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `data` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `freeargv` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `line` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `process` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `read` | 4 | 8 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `analysis` | 4 | 7 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `anti` | 4 | 7 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `thread` | 4 | 7 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `hooks` | 4 | 5 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `peloader` | 4 | 5 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `secure` | 4 | 5 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `warnings` | 4 | 5 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `argc` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `argv` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `bits` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `cmdline` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `destruct` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `exit` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `getmainargs` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `iat` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `masquerade` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `mem` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `ntheaders` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `pedirectory` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `rand` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `reader` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `repair` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `run` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `self` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `success` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `wargv` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `wgetmainargs` | 4 | 4 | `loader.c`, `loader2.c`, `loader3.c`, `loader4.c` |
| `key` | 3 | 9 | `aes.c`, `aes.h`, `loader4.c` |
| `buffer` | 3 | 7 | `aes.c`, `aes.h`, `lzss.c` |
| `sleep` | 3 | 7 | `loader2.c`, `loader3.c`, `loader4.c` |
| `shellcode` | 3 | 6 | `loader2.c`, `loader3.c`, `loader4.c` |
| `trampoline` | 3 | 6 | `loader2.c`, `loader3.c`, `loader4.c` |
| `uptr` | 3 | 6 | `loader2.c`, `loader3.c`, `loader4.c` |
| `fluctuation` | 3 | 5 | `loader2.c`, `loader3.c`, `loader4.c` |

## Verb Edges

| Source | Verb | Target | Strength |
|--------|------|--------|----------|
| `aes` | `consumes` | `buffer` | 1.00 |
| `aes` | `depends_on` | `buffer` | 1.00 |
| `aes` | `consumes` | `decrypt` | 1.00 |
| `aes` | `depends_on` | `decrypt` | 1.00 |
| `aes` | `consumes` | `encrypt` | 1.00 |
| `aes` | `depends_on` | `encrypt` | 1.00 |
| `aes` | `consumes` | `key` | 1.00 |
| `aes` | `depends_on` | `key` | 1.00 |
| `buffer` | `consumes` | `aes` | 1.00 |
| `buffer` | `depends_on` | `aes` | 1.00 |
| `buffer` | `consumes` | `decrypt` | 1.00 |
| `buffer` | `depends_on` | `decrypt` | 1.00 |
| `buffer` | `consumes` | `encrypt` | 1.00 |
| `buffer` | `depends_on` | `encrypt` | 1.00 |
| `buffer` | `consumes` | `key` | 1.00 |
| `buffer` | `depends_on` | `key` | 1.00 |
| `decrypt` | `consumes` | `aes` | 1.00 |
| `decrypt` | `depends_on` | `aes` | 1.00 |
| `decrypt` | `consumes` | `buffer` | 1.00 |
| `decrypt` | `depends_on` | `buffer` | 1.00 |
| `decrypt` | `consumes` | `encrypt` | 1.00 |
| `decrypt` | `depends_on` | `encrypt` | 1.00 |
| `decrypt` | `consumes` | `key` | 1.00 |
| `decrypt` | `depends_on` | `key` | 1.00 |
| `encrypt` | `consumes` | `aes` | 1.00 |
| `encrypt` | `depends_on` | `aes` | 1.00 |
| `encrypt` | `consumes` | `buffer` | 1.00 |
| `encrypt` | `depends_on` | `buffer` | 1.00 |
| `encrypt` | `consumes` | `decrypt` | 1.00 |
| `encrypt` | `depends_on` | `decrypt` | 1.00 |
| `encrypt` | `consumes` | `key` | 1.00 |
| `encrypt` | `depends_on` | `key` | 1.00 |
| `get` | `consumes` | `aes` | 1.00 |
| `get` | `depends_on` | `aes` | 1.00 |
| `get` | `consumes` | `buffer` | 1.00 |
| `get` | `depends_on` | `buffer` | 1.00 |
| `get` | `consumes` | `decrypt` | 1.00 |
| `get` | `depends_on` | `decrypt` | 1.00 |
| `get` | `consumes` | `encrypt` | 1.00 |
| `get` | `depends_on` | `encrypt` | 1.00 |
| `get` | `consumes` | `key` | 1.00 |
| `get` | `depends_on` | `key` | 1.00 |
| `key` | `consumes` | `aes` | 1.00 |
| `key` | `depends_on` | `aes` | 1.00 |
| `key` | `consumes` | `buffer` | 1.00 |
| `key` | `depends_on` | `buffer` | 1.00 |
| `key` | `consumes` | `decrypt` | 1.00 |
| `key` | `depends_on` | `decrypt` | 1.00 |
| `key` | `consumes` | `encrypt` | 1.00 |
| `key` | `depends_on` | `encrypt` | 1.00 |

## Dialectic Prompts

- Thesis: `aes` centralizes 6 files; Antithesis: `analysis` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `anti` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `argc` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `argv` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `bit` pulls 5 files with 4 shared (Jaccard 0.57); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `bits` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `cmdline` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `command` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `crt` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `aes` centralizes 6 files; Antithesis: `current` pulls 4 files with 4 shared (Jaccard 0.67); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
