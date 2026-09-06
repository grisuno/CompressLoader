# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Total Files Parsed:** 13 | **Total Symbols Extracted:** 258 | **Total Imports:** 60

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:4c8e0d2 | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Ranked Context](#ranked-context)
4. [God Nodes](#god-nodes)
5. [Community Analysis](#community-analysis)
6. [Suggested Questions](#suggested-questions)
7. [Hotspot Analysis](#hotspot-analysis)
8. [Change Impact Analysis](#change-impact-analysis)
9. [Suggested Linting Rules](#suggested-linting-rules)
10. [Orphans](#orphans)
11. [Query Recipes](#query-recipes)
12. [Structural Knowledge Map](#structural-knowledge-map)
13. [UML Class Diagram](#uml-class-diagram)
14. [Code Property Graph](#code-property-graph)
15. [Architecture Reference](#architecture-reference)
    - [C (9 files)](#c-9-files)
    - [H (1 files)](#h-1-files)
    - [PY (2 files)](#py-2-files)
    - [SH (1 files)](#sh-1-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 13 |
| Total Symbols | 258 |
| Total Imports | 60 |
| Call Edges | 50 |
| Inheritance Edges | 0 |
| Languages | 4 |
| Avg Symbols/File | 19.8 |
| Avg Imports/File | 4.6 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `loader4.c` | 12 | 53 | c |
| `loader2.c` | 11 | 44 | c |
| `loader3.c` | 11 | 46 | c |
| `loader.c` | 8 | 39 | c |
| `crypter.py` | 6 | 3 | py |
| `aes.c` | 2 | 43 | c |
| `aes.h` | 2 | 13 | h |
| `lzss.c` | 2 | 14 | c |
| `pack.c` | 2 | 1 | c |
| `test.c` | 2 | 1 | c |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `aes.h` | 1 | 13 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 12 |
| testing | 1 |

### utility

- `aes.c` (c, 43 symbols)
- `aes.h` (h, 13 symbols)
- `app.py` (py, 0 symbols)
- `crypter.py` (py, 3 symbols)
- `install.sh` (sh, 0 symbols)
- `loader.c` (c, 39 symbols)
- `loader2.c` (c, 44 symbols)
- `loader3.c` (c, 46 symbols)
- `loader4.c` (c, 53 symbols)
- `lzss.c` (c, 14 symbols)
- `pack.c` (c, 1 symbols)
- `unpack.c` (c, 1 symbols)

### testing

- `test.c` (c, 1 symbols)

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `aes.h` | 0.4296 | 0.6491 | 0.6491 | 0.00 | 0.08 |
| 2 | `aes.c` | 0.2653 | 0.3509 | 0.3509 | 0.00 | 0.37 |
| 3 | `app.py` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 4 | `pack.c` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 5 | `test.c` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 6 | `unpack.c` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 7 | `crypter.py` | 0.0333 | 0.0000 | 0.0000 | 0.00 | 0.33 |
| 8 | `loader2.c` | 0.0227 | 0.0000 | 0.0000 | 0.00 | 0.23 |
| 9 | `loader3.c` | 0.0152 | 0.0000 | 0.0000 | 0.00 | 0.15 |
| 10 | `loader4.c` | 0.0151 | 0.0000 | 0.0000 | 0.00 | 0.15 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `aes.c` | 6.3 | | 0.3509 |
| `loader4.c` | 5.3 | | 0.0000 |
| `loader3.c` | 4.6 | | 0.0000 |
| `loader2.c` | 4.4 | | 0.0000 |
| `loader.c` | 3.9 | | 0.0000 |
| `aes.h` | 3.3 | | 0.6491 |
| `lzss.c` | 1.4 | | 0.0000 |
| `crypter.py` | 0.3 | | 0.0000 |
| `pack.c` | 0.1 | | 0.0000 |
| `test.c` | 0.1 | | 0.0000 |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root (Cohesion: 1.00)

**2 files** in this community:

- `aes.c` (c, 43 symbols)
- `aes.h` (h, 13 symbols)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does aes.c depend on, and what depends on it? (1 connections)
- What does loader4.c depend on, and what depends on it? (0 connections)
- What does loader3.c depend on, and what depends on it? (0 connections)
- What is AES_ctx in aes.h and how is it used?
- What is the overall architecture of this codebase?

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `aes.h` | 0.245 | 0.250 | 0.248 | 13 | 3 |
| `aes.c` | 0.811 | 0.167 | 0.424 | 43 | 2 |
| `app.py` | 0.000 | 0.000 | 0.000 | 0 | 0 |
| `pack.c` | 0.019 | 0.167 | 0.107 | 1 | 2 |
| `test.c` | 0.019 | 0.167 | 0.107 | 1 | 2 |
| `unpack.c` | 0.019 | 0.167 | 0.107 | 1 | 2 |
| `crypter.py` | 0.057 | 0.500 | 0.323 | 3 | 6 |
| `loader2.c` | 0.830 | 0.917 | 0.882 | 44 | 11 |
| `loader3.c` | 0.868 | 0.917 | 0.897 | 46 | 11 |
| `loader4.c` | 1.000 | 1.000 | 1.000 | 53 | 12 |
| `loader.c` | 0.736 | 0.667 | 0.694 | 39 | 8 |
| `lzss.c` | 0.264 | 0.167 | 0.206 | 14 | 2 |
| `install.sh` | 0.000 | 0.000 | 0.000 | 0 | 0 |

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `aes.c` | 0 | 0 | 0 |
| `aes.h` | 0 | 0 | 0 |
| `app.py` | 0 | 0 | 0 |
| `crypter.py` | 0 | 0 | 0 |
| `install.sh` | 0 | 0 | 0 |
| `loader.c` | 0 | 0 | 0 |
| `loader2.c` | 0 | 0 | 0 |
| `loader3.c` | 0 | 0 | 0 |
| `loader4.c` | 0 | 0 | 0 |
| `lzss.c` | 0 | 0 | 0 |
| `pack.c` | 0 | 0 | 0 |
| `test.c` | 0 | 0 | 0 |
| `unpack.c` | 0 | 0 | 0 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 168 total | c | 168 |
| `RM002` | info | Large number of functions in py: 3 total | py | 3 |
| `RM003` | info | Print statement found (consider logging instead) | python | 16 |

---

## Orphans

Files with no documentation or low connectivity. These are candidates for documentation investment or cleanup.

- `install.sh` (0 symbols, no doc)

---

## Query Recipes

Example queries you can run against this knowledge base using the ranking engine:

```
# Find files most relevant to a concept
readmenator query "Where is the import resolver implemented?"

# Rank files by relevance to a topic
readmenator query "How does documentation generation work?"

# Explain why a file ranks highly
readmenator query "explain readmenator/_documentation.py"

# Trace dependency paths with ranked context
readmenator query "path from CLI to exporter"
```

The ranking model uses the following signals:

- **Personalized PageRank** (45% weight): query-specific relevance via seed propagation
- **Global Authority** (20% weight): structural importance via standard PageRank
- **Test Coverage** (15% weight): fraction of symbols referenced in test files
- **Doc Coverage** (10% weight): presence of docstrings and file-level docs
- **Freshness** (10% weight): recent modification activity

Results include score decomposition and justification paths for each ranked item.

---

## Structural Knowledge Map

```mermaid
graph TD
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    loader4_c["loader4.c (c)"]
    class loader4_c mod;
    loader4_c_read_bit["read_bit"]
    class loader4_c_read_bit fn;
    loader4_c --> loader4_c_read_bit
    loader4_c_read_bits["read_bits"]
    class loader4_c_read_bits fn;
    loader4_c --> loader4_c_read_bits
    loader4_c_deobf["deobf"]
    class loader4_c_deobf fn;
    loader4_c --> loader4_c_deobf
    loader4_c_SetHWBP_NtContinue["SetHWBP_NtContinue"]
    class loader4_c_SetHWBP_NtContinue fn;
    loader4_c --> loader4_c_SetHWBP_NtContinue
    loader4_c_lzss_decode_mem["lzss_decode_mem"]
    class loader4_c_lzss_decode_mem fn;
    loader4_c --> loader4_c_lzss_decode_mem
    loader3_c["loader3.c (c)"]
    class loader3_c mod;
    loader2_c["loader2.c (c)"]
    class loader2_c mod;
    loader_c["loader.c (c)"]
    class loader_c mod;
    crypter_py["crypter.py (py)"]
    class crypter_py mod;
    subgraph community_0 ["root"]
    aes_c["aes.c (c)"]
    class aes_c mod;
    lzss_c["lzss.c (c)"]
    class lzss_c mod;
    aes_h["aes.h (h)"]
    class aes_h mod;
    pack_c["pack.c (c)"]
    class pack_c mod;
    test_c["test.c (c)"]
    class test_c mod;
    unpack_c["unpack.c (c)"]
    class unpack_c mod;
    app_py["app.py (py)"]
    class app_py mod;
    install_sh["install.sh (sh)"]
    class install_sh mod;
    end
    ext_aes_h["aes.h"]
    class ext_aes_h ext;
    aes_c -.->|imports| ext_aes_h
    ext_string_h["string.h"]
    class ext_string_h ext;
    aes_c -.->|imports| ext_string_h
    ext_stdint_h["stdint.h"]
    class ext_stdint_h ext;
    aes_h -.->|imports| ext_stdint_h
    ext_stddef_h["stddef.h"]
    class ext_stddef_h ext;
    aes_h -.->|imports| ext_stddef_h
    ext_sys["sys"]
    class ext_sys ext;
    crypter_py -.->|imports| ext_sys
    ext_os["os"]
    class ext_os ext;
    crypter_py -.->|imports| ext_os
    ext_hashlib["hashlib"]
    class ext_hashlib ext;
    crypter_py -.->|imports| ext_hashlib
    ext_struct["struct"]
    class ext_struct ext;
    crypter_py -.->|imports| ext_struct
    crypter_py -.->|imports| ext_os
    ext_Crypto_Cipher["Crypto.Cipher"]
    class ext_Crypto_Cipher ext;
    crypter_py -.->|imports| ext_Crypto_Cipher
    ext_windows_h["windows.h"]
    class ext_windows_h ext;
    loader_c -.->|imports| ext_windows_h
    ext_stdio_h["stdio.h"]
    class ext_stdio_h ext;
    loader_c -.->|imports| ext_stdio_h
    ext_psapi_h["psapi.h"]
    class ext_psapi_h ext;
    loader_c -.->|imports| ext_psapi_h
    ext_winternl_h["winternl.h"]
    class ext_winternl_h ext;
    loader_c -.->|imports| ext_winternl_h
    ext_winhttp_h["winhttp.h"]
    class ext_winhttp_h ext;
    loader_c -.->|imports| ext_winhttp_h
    ext_wincrypt_h["wincrypt.h"]
    class ext_wincrypt_h ext;
    loader_c -.->|imports| ext_wincrypt_h
    ext_stdlib_h["stdlib.h"]
    class ext_stdlib_h ext;
    loader_c -.->|imports| ext_stdlib_h
    loader_c -.->|imports| ext_string_h
    loader2_c -.->|imports| ext_windows_h
    loader2_c -.->|imports| ext_stdio_h
    loader2_c -.->|imports| ext_stdlib_h
    loader2_c -.->|imports| ext_string_h
    loader2_c -.->|imports| ext_stdint_h
    ext_stdbool_h["stdbool.h"]
    class ext_stdbool_h ext;
    loader2_c -.->|imports| ext_stdbool_h
    loader2_c -.->|imports| ext_psapi_h
    loader2_c -.->|imports| ext_winternl_h
    loader2_c -.->|imports| ext_winhttp_h
    loader2_c -.->|imports| ext_wincrypt_h
    ext_shellapi_h["shellapi.h"]
    class ext_shellapi_h ext;
    loader2_c -.->|imports| ext_shellapi_h
    loader3_c -.->|imports| ext_windows_h
    loader3_c -.->|imports| ext_stdio_h
    loader3_c -.->|imports| ext_stdlib_h
    loader3_c -.->|imports| ext_string_h
    loader3_c -.->|imports| ext_stdint_h
    loader3_c -.->|imports| ext_stdbool_h
    loader3_c -.->|imports| ext_psapi_h
    loader3_c -.->|imports| ext_winternl_h
    loader3_c -.->|imports| ext_winhttp_h
    loader3_c -.->|imports| ext_wincrypt_h
    loader3_c -.->|imports| ext_shellapi_h
    loader4_c -.->|imports| ext_windows_h
    loader4_c -.->|imports| ext_stdio_h
    loader4_c -.->|imports| ext_stdlib_h
    loader4_c -.->|imports| ext_string_h
    loader4_c -.->|imports| ext_stdint_h
    loader4_c -.->|imports| ext_stdbool_h
    loader4_c -.->|imports| ext_psapi_h
    loader4_c -.->|imports| ext_winternl_h
    loader4_c -.->|imports| ext_winhttp_h
    loader4_c -.->|imports| ext_wincrypt_h
    loader4_c -.->|imports| ext_shellapi_h
    loader4_c -.->|imports| ext_stdio_h
    lzss_c -.->|imports| ext_stdio_h
    lzss_c -.->|imports| ext_stdlib_h
    pack_c -.->|imports| ext_stdio_h
    pack_c -.->|imports| ext_stdlib_h
    test_c -.->|imports| ext_stdio_h
    test_c -.->|imports| ext_stdlib_h
    unpack_c -.->|imports| ext_stdio_h
    unpack_c -.->|imports| ext_stdlib_h
```

---

## UML Class Diagram

Auto-generated Mermaid class diagram from parsed class-level symbols. Shows classes, structs, interfaces, traits, and their methods with inheritance and dependency relationships.

```mermaid
classDiagram
  class aes_h_AES_ctx {
    <<struct>>
  }
  class loader_c__BASE_RELOCATION_ENTRY {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +hookGetCommandLineW()
    +hookGetCommandLineA()
    +hook__p___argv(void)
    +hook__p___wargv(void)
    +hook__p___argc(void)
    +anti_analysis()
    +selfDestruct()
  }
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 1.0, "id": 0, "label": "root", "size": 2}], "god_nodes": [{"node_id": "aes.c", "score": 6.3}, {"node_id": "loader4.c", "score": 5.3}, {"node_id": "loader3.c", "score": 4.6}, {"node_id": "loader2.c", "score": 4.4}, {"node_id": "loader.c", "score": 3.9}, {"node_id": "aes.h", "score": 3.3}, {"node_id": "lzss.c", "score": 1.4}, {"node_id": "crypter.py", "score": 0.3}, {"node_id": "pack.c", "score": 0.1}, {"node_id": "test.c", "score": 0.1}], "surprising_connections": []}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "aes.c", "target": "aes.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "os"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "hashlib"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "struct"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "os"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "Crypto.Cipher"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lzss.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lzss.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "pack.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "pack.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "test.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "test.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "unpack.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "unpack.c", "target": "stdlib.h"}], "generator": "readmenator", "metadata": {"edge_count": 110, "file_count": 13, "language_count": 4, "symbol_count": 258}, "nodes": [{"doc": "aes.c - tiny-AES-c (https://github.com/kokke/tiny-AES-c) include \"aes.h\" include <string.h>  define Nb 4    define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16", "id": "aes.c", "kind": "module", "label": "aes.c", "language": "c", "sha256": "90bb0430dbddaeb8", "symbol_count": 43, "symbols": [{"doc": "define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16", "kind": "function", "line": 12, "name": "getSBoxValue", "signature": "static uint8_t getSBoxValue(uint8_t num)"}, {"kind": "function", "line": 34, "name": "getSBoxInvert", "signature": "static uint8_t getSBoxInvert(uint8_t num)"}, {"kind": "function", "line": 56, "name": "Td0", "signature": "static uint8_t Td0(int x)"}, {"kind": "function", "line": 58, "name": "Td1", "signature": "static uint8_t Td1(int x)"}, {"kind": "function", "line": 59, "name": "Td2", "signature": "static uint8_t Td2(int x)"}, {"kind": "function", "line": 60, "name": "Td3", "signature": "static uint8_t Td3(int x)"}, {"kind": "function", "line": 61, "name": "Td4", "signature": "static uint8_t Td4(int x)"}, {"doc": "This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.", "kind": "function", "line": 166, "name": "KeyExpansion", "signature": "static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)"}, {"kind": "function", "line": 238, "name": "AES_init_ctx", "signature": "void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)"}, {"doc": "if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))", "kind": "function", "line": 244, "name": "AES_init_ctx_iv", "signature": "void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)"}, {"kind": "function", "line": 249, "name": "AES_ctx_set_iv", "signature": "void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)"}, {"doc": "This function adds the round key to state. The round key is added to the state by an XOR function.", "kind": "function", "line": 257, "name": "AddRoundKey", "signature": "static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)"}, {"doc": "The SubBytes Function Substitutes the values in the state matrix with values in an S-box.", "kind": "function", "line": 271, "name": "SubBytes", "signature": "static void SubBytes(state_t* state)"}, {"doc": "The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row is not shifted.", "kind": "function", "line": 286, "name": "ShiftRows", "signature": "static void ShiftRows(state_t* state)"}, {"kind": "function", "line": 313, "name": "xtime", "signature": "static uint8_t xtime(uint8_t x)"}, {"doc": "MixColumns function mixes the columns of the state matrix", "kind": "function", "line": 320, "name": "MixColumns", "signature": "static void MixColumns(state_t* state)"}, {"doc": "Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary The compiler seems to be able to vectorize the operation better this way. See https://github.com/kokke/tiny-AES-c/pull/34 if MULTIPLY_AS_A_FUNCTION", "kind": "function", "line": 340, "name": "Multiply", "signature": "static uint8_t Multiply(uint8_t x, uint8_t y)"}, {"doc": "MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand for the inexperienced. Please use the references to gain more information.", "kind": "function", "line": 370, "name": "InvMixColumns", "signature": "static void InvMixColumns(state_t* state)"}, {"doc": "The SubBytes Function Substitutes the values in the state matrix with values in an S-box.", "kind": "function", "line": 391, "name": "InvSubBytes", "signature": "static void InvSubBytes(state_t* state)"}, {"kind": "function", "line": 402, "name": "InvShiftRows", "signature": "static void InvShiftRows(state_t* state)"}, {"doc": "Cipher is the main function that encrypts the PlainText.", "kind": "function", "line": 433, "name": "Cipher", "signature": "static void Cipher(state_t* state, const uint8_t* RoundKey)"}, {"doc": "if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)", "kind": "function", "line": 459, "name": "InvCipher", "signature": "static void InvCipher(state_t* state, const uint8_t* RoundKey)"}, {"doc": "AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); } } #endif // #if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)  /* Public functions:  if defined(ECB) && (ECB == 1)", "kind": "function", "line": 488, "name": "AES_ECB_encrypt", "signature": "void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)"}, {"kind": "function", "line": 495, "name": "AES_ECB_decrypt", "signature": "void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)"}, {"doc": "if defined(CBC) && (CBC == 1)", "kind": "function", "line": 510, "name": "XorWithIv", "signature": "static void XorWithIv(uint8_t* buf, const uint8_t* Iv)"}, {"kind": "function", "line": 520, "name": "AES_CBC_encrypt_buffer", "signature": "void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)"}, {"kind": "function", "line": 535, "name": "AES_CBC_decrypt_buffer", "signature": "void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)"}, {"doc": "XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC) && (CBC == 1) #if defined(CTR) && (CTR == 1) /* Symmetrical operation: same function for encrypting as for decrypting. Note any IV/nonce should never be reused with the same key", "kind": "function", "line": 558, "name": "AES_CTR_xcrypt_buffer", "signature": "void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)"}, {"kind": "macro", "line": 4, "name": "Nb"}, {"kind": "macro", "line": 6, "name": "KEYLEN_256"}, {"kind": "macro", "line": 10, "name": "RKLENGTH"}, {"kind": "macro", "line": 11, "name": "BLOCKLEN"}, {"kind": "macro", "line": 67, "name": "Nb"}, {"kind": "macro", "line": 70, "name": "Nk"}, {"kind": "macro", "line": 71, "name": "Nr"}, {"kind": "macro", "line": 73, "name": "Nk"}, {"kind": "macro", "line": 74, "name": "Nr"}, {"kind": "macro", "line": 76, "name": "Nk"}, {"kind": "macro", "line": 77, "name": "Nr"}, {"kind": "macro", "line": 84, "name": "MULTIPLY_AS_A_FUNCTION"}, {"kind": "macro", "line": 163, "name": "getSBoxValue"}, {"kind": "macro", "line": 349, "name": "Multiply"}, {"kind": "macro", "line": 365, "name": "getSBoxInvert"}]}, {"doc": "ifndef _AES_H_ define _AES_H_  include <stdint.h> include <stddef.h>  #define the macros below to 1/0 to enable/disable the mode of operation. ifndef CBC define CBC 1 endif ifndef ECB define ECB 1 endif ifndef CTR define CTR 1 endif  define AES256 1  // ✅ Clave de 256 bits  define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only  if defined(AES256) && (AES256 == 1) define AES_KEYLEN 32 define AES_keyExpSize 240 elif defined(AES192) && (AES192 == 1) define AES_KEYLEN 24 define AES_keyExpSize 208 else define AES_KEYLEN 16   // Key length in bytes define AES_keyExpSize 176", "id": "aes.h", "kind": "module", "label": "aes.h", "language": "h", "sha256": "b10d39289cfb8328", "symbol_count": 13, "symbols": [{"kind": "struct", "line": 33, "name": "AES_ctx"}, {"kind": "macro", "line": 2, "name": "_AES_H_"}, {"kind": "macro", "line": 9, "name": "CBC"}, {"kind": "macro", "line": 12, "name": "ECB"}, {"kind": "macro", "line": 15, "name": "CTR"}, {"kind": "macro", "line": 17, "name": "AES256"}, {"kind": "macro", "line": 19, "name": "AES_BLOCKLEN"}, {"kind": "macro", "line": 23, "name": "AES_KEYLEN"}, {"kind": "macro", "line": 24, "name": "AES_keyExpSize"}, {"kind": "macro", "line": 26, "name": "AES_KEYLEN"}, {"kind": "macro", "line": 27, "name": "AES_keyExpSize"}, {"kind": "macro", "line": 29, "name": "AES_KEYLEN"}, {"kind": "macro", "line": 30, "name": "AES_keyExpSize"}]}, {"doc": "_*_ coding: utf8 _*_", "id": "app.py", "kind": "module", "label": "app.py", "language": "py", "sha256": "57b21bdb023585b8", "symbol_count": 0, "symbols": []}, {"id": "crypter.py", "kind": "module", "label": "crypter.py", "language": "py", "sha256": "b3ded94a56b1e293", "symbol_count": 3, "symbols": [{"kind": "function", "line": 9, "name": "AESencrypt", "signature": "def AESencrypt(plaintext, key)"}, {"doc": "Reemplaza la extensión del archivo por una nueva (sin el punto).", "kind": "function", "line": 19, "name": "change_ext", "signature": "def change_ext(filename, new_ext)"}, {"kind": "function", "line": 24, "name": "main", "signature": "def main()"}]}, {"id": "install.sh", "kind": "module", "label": "install.sh", "language": "sh", "sha256": "c907d80fd6734993", "symbol_count": 0, "symbols": []}, {"id": "loader.c", "kind": "module", "label": "loader.c", "language": "c", "sha256": "a43569b2dda0588c", "symbol_count": 39, "symbols": [{"kind": "struct", "line": 41, "name": "_BASE_RELOCATION_ENTRY"}, {"kind": "function", "line": 63, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 74, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 84, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"doc": "Implementación de hooks", "kind": "function", "line": 217, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 218, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 219, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 220, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 221, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"doc": "=== ANTI-ANALYSIS ===", "kind": "function", "line": 226, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"doc": "Puff", "kind": "function", "line": 251, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"kind": "function", "line": 306, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 312, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 318, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 323, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 327, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 365, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 373, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 381, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 393, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 403, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"kind": "function", "line": 458, "name": "_stricmp", "signature": "_stricmp(func_name, \"exit\") == 0 ||\n                    _stricmp(func_name, \"_Exit\") == 0 ||\n    ..."}, {"kind": "function", "line": 478, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 484, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"kind": "function", "line": 558, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 601, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"kind": "function", "line": 637, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"kind": "function", "line": 670, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"kind": "function", "line": 791, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 19, "name": "_CRT_RAND_S"}, {"kind": "macro", "line": 30, "name": "NT_SUCCESS"}, {"kind": "macro", "line": 32, "name": "NtCurrentThread"}, {"kind": "macro", "line": 34, "name": "NtCurrentProcess"}, {"kind": "macro", "line": 37, "name": "_CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 52, "name": "EI"}, {"kind": "macro", "line": 53, "name": "EJ"}, {"kind": "macro", "line": 54, "name": "P"}, {"kind": "macro", "line": 55, "name": "N"}, {"kind": "macro", "line": 56, "name": "F"}]}, {"doc": "define _CRT_RAND_S define WIN32_LEAN_AND_MEAN include <windows.h> include <stdio.h> include <stdlib.h> include <string.h> include <stdint.h> include <stdbool.h> include <psapi.h> include <winternl.h> include <winhttp.h> include <wincrypt.h> include <shellapi.h>  === DECLARACIONES DE HOOKS ===", "id": "loader2.c", "kind": "module", "label": "loader2.c", "language": "c", "sha256": "4e37e75c920d3ceb", "symbol_count": 44, "symbols": [{"kind": "function", "line": 51, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 60, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 70, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "================== FLUCTUATION IMPLEMENTATION ==================", "kind": "function", "line": 182, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 186, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"doc": "Verifica si la dirección está dentro de .text", "kind": "function", "line": 195, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"doc": "Fluctuación: encripta/desencripta SOLO .text", "kind": "function", "line": 206, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"doc": "Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)", "kind": "function", "line": 246, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 261, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 302, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "================== LZSS ==================", "kind": "function", "line": 323, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"doc": "================== PE LOADER ==================", "kind": "function", "line": 387, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 418, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 429, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 438, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 490, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 491, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 492, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 493, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 494, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 495, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 498, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 501, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 502, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 508, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"doc": "================== ANTI-ANALYSIS & CLEANUP ==================", "kind": "function", "line": 596, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 617, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"kind": "function", "line": 646, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"doc": "================== MAIN ==================", "kind": "function", "line": 731, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 1, "name": "_CRT_RAND_S"}, {"kind": "macro", "line": 2, "name": "WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 26, "name": "_CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 29, "name": "NT_SUCCESS"}, {"kind": "macro", "line": 31, "name": "NtCurrentThread"}, {"kind": "macro", "line": 33, "name": "NtCurrentProcess"}, {"kind": "macro", "line": 34, "name": "WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 36, "name": "UNICODE"}, {"kind": "macro", "line": 37, "name": "_UNICODE"}, {"kind": "macro", "line": 40, "name": "EI"}, {"kind": "macro", "line": 41, "name": "EJ"}, {"kind": "macro", "line": 42, "name": "P"}, {"kind": "macro", "line": 43, "name": "N"}, {"kind": "macro", "line": 44, "name": "F"}, {"kind": "macro", "line": 153, "name": "log"}]}, {"id": "loader3.c", "kind": "module", "label": "loader3.c", "language": "c", "sha256": "fe727a7ab12b3d6a", "symbol_count": 46, "symbols": [{"kind": "function", "line": 63, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 72, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 82, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"kind": "function", "line": 138, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "================== FLUCTUATION IMPLEMENTATION ==================", "kind": "function", "line": 238, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 241, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"kind": "function", "line": 248, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"kind": "function", "line": 257, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"kind": "function", "line": 291, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 305, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 341, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "================== PE LOADER ==================", "kind": "function", "line": 360, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 389, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 397, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 405, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 416, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 425, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 478, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 479, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 480, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 481, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 482, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 483, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 486, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 489, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 493, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 496, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 502, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"doc": "================== ANTI-ANALYSIS & CLEANUP ==================", "kind": "function", "line": 581, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 601, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"doc": "================== UNHOOKING ==================", "kind": "function", "line": 629, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 664, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"doc": "================== NETWORK ==================", "kind": "function", "line": 689, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"doc": "================== MAIN ==================", "kind": "function", "line": 757, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 15, "name": "_CRT_RAND_S"}, {"kind": "macro", "line": 17, "name": "WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 42, "name": "_CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 45, "name": "NT_SUCCESS"}, {"kind": "macro", "line": 47, "name": "NtCurrentThread"}, {"kind": "macro", "line": 49, "name": "NtCurrentProcess"}, {"kind": "macro", "line": 52, "name": "EI"}, {"kind": "macro", "line": 53, "name": "EJ"}, {"kind": "macro", "line": 54, "name": "P"}, {"kind": "macro", "line": 55, "name": "N"}, {"kind": "macro", "line": 56, "name": "F"}, {"kind": "macro", "line": 214, "name": "log"}]}, {"id": "loader4.c", "kind": "module", "label": "loader4.c", "language": "c", "sha256": "60218c7da897d192", "symbol_count": 53, "symbols": [{"kind": "function", "line": 103, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 112, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"doc": "Helper para desofuscar", "kind": "function", "line": 124, "name": "deobf", "signature": "void deobf(const char* src, char* dst, size_t max_len)"}, {"kind": "function", "line": 132, "name": "SetHWBP_NtContinue", "signature": "BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)"}, {"kind": "function", "line": 161, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"kind": "function", "line": 218, "name": "PatchETW", "signature": "BOOL PatchETW()"}, {"kind": "function", "line": 250, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "================== FLUCTUATION IMPLEMENTATION ==================", "kind": "function", "line": 351, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 354, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"kind": "function", "line": 361, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"kind": "function", "line": 370, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"kind": "function", "line": 404, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 418, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 457, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "================== PE LOADER ==================", "kind": "function", "line": 476, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 505, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 513, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 521, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 532, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 541, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 594, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 595, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 596, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 597, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 598, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 599, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 602, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 605, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 609, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 612, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 618, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"doc": "================== ANTI-ANALYSIS & CLEANUP ==================", "kind": "function", "line": 699, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 719, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"doc": "================== UNHOOKING ==================", "kind": "function", "line": 747, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 784, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"doc": "================== NETWORK ==================", "kind": "function", "line": 811, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"doc": "================== MAIN ==================", "kind": "function", "line": 879, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 15, "name": "_CRT_RAND_S"}, {"kind": "macro", "line": 17, "name": "WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 42, "name": "XK"}, {"kind": "macro", "line": 52, "name": "_CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 55, "name": "NT_SUCCESS"}, {"kind": "macro", "line": 57, "name": "NtCurrentThread"}, {"kind": "macro", "line": 59, "name": "NtCurrentProcess"}, {"kind": "macro", "line": 62, "name": "EI"}, {"kind": "macro", "line": 63, "name": "EJ"}, {"kind": "macro", "line": 64, "name": "P"}, {"kind": "macro", "line": 65, "name": "N"}, {"kind": "macro", "line": 66, "name": "F"}, {"kind": "macro", "line": 69, "name": "OBFUSCATE_KEY"}, {"kind": "macro", "line": 72, "name": "OBFSTR"}, {"kind": "macro", "line": 85, "name": "OBFSTRW"}, {"kind": "macro", "line": 327, "name": "log"}]}, {"doc": "lzss.c – implementación de Okumura (SIN main)", "id": "lzss.c", "kind": "module", "label": "lzss.c", "language": "c", "sha256": "691380d661208be5", "symbol_count": 14, "symbols": [{"kind": "function", "line": 15, "name": "error", "signature": "static void error(void)"}, {"kind": "function", "line": 17, "name": "putbit1", "signature": "static void putbit1(void)"}, {"kind": "function", "line": 25, "name": "putbit0", "signature": "static void putbit0(void)"}, {"kind": "function", "line": 31, "name": "flush_bit_buffer", "signature": "static void flush_bit_buffer(void)"}, {"kind": "function", "line": 34, "name": "output1", "signature": "static void output1(int c)"}, {"kind": "function", "line": 39, "name": "output2", "signature": "static void output2(int x, int y)"}, {"kind": "function", "line": 45, "name": "encode", "signature": "void encode(void)"}, {"kind": "function", "line": 76, "name": "getbit", "signature": "static int getbit(int n)"}, {"kind": "function", "line": 86, "name": "decode", "signature": "void decode(void)"}, {"kind": "macro", "line": 4, "name": "EI"}, {"kind": "macro", "line": 6, "name": "EJ"}, {"kind": "macro", "line": 7, "name": "P"}, {"kind": "macro", "line": 8, "name": "N"}, {"kind": "macro", "line": 9, "name": "F"}]}, {"doc": "pack.c", "id": "pack.c", "kind": "module", "label": "pack.c", "language": "c", "sha256": "ae95bb09aad34d54", "symbol_count": 1, "symbols": [{"kind": "function", "line": 7, "name": "main", "signature": "int main(int argc, char *argv[])"}]}, {"doc": "test.c – wrapper decompress Okumura", "id": "test.c", "kind": "module", "label": "test.c", "language": "c", "sha256": "982d06a499ffefd5", "symbol_count": 1, "symbols": [{"kind": "function", "line": 8, "name": "main", "signature": "int main(void)"}]}, {"doc": "unpack.c", "id": "unpack.c", "kind": "module", "label": "unpack.c", "language": "c", "sha256": "0215a872dd6c980d", "symbol_count": 1, "symbols": [{"kind": "function", "line": 7, "name": "main", "signature": "int main(int argc, char *argv[])"}]}], "type": "CodePropertyGraph", "version": "1.0"}
```

---

## Architecture Reference

### C (9 files)

#### `aes.c`
**Path:** `aes.c`
**File Doc:** *aes.c - tiny-AES-c (https://github.com/kokke/tiny-AES-c) include "aes.h" include <string.h>  define Nb 4    define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16*

**Functions:**
- `getSBoxValue` (line 12) `static uint8_t getSBoxValue(uint8_t num)` - *define KEYLEN_256 32 define RKLENGTH (4 * (Nr + 1)) define BLOCKLEN 16*
- `getSBoxInvert` (line 34) `static uint8_t getSBoxInvert(uint8_t num)`
- `Td0` (line 56) `static uint8_t Td0(int x)`
- `Td1` (line 58) `static uint8_t Td1(int x)`
- `Td2` (line 59) `static uint8_t Td2(int x)`
- `Td3` (line 60) `static uint8_t Td3(int x)`
- `Td4` (line 61) `static uint8_t Td4(int x)`
- `KeyExpansion` (line 166) `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` - *This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.*
- `AES_init_ctx` (line 238) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- `AES_init_ctx_iv` (line 244) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` - *if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))*
- `AES_ctx_set_iv` (line 249) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- `AddRoundKey` (line 257) `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` - *This function adds the round key to state. The round key is added to the state by an XOR function.*
- `SubBytes` (line 271) `static void SubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `ShiftRows` (line 286) `static void ShiftRows(state_t* state)` - *The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row is not shifted.*
- `xtime` (line 313) `static uint8_t xtime(uint8_t x)`
- `MixColumns` (line 320) `static void MixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix*
- `Multiply` (line 340) `static uint8_t Multiply(uint8_t x, uint8_t y)` - *Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary The compiler seems to be able to vectorize the operation better this way. See https://github.com/kokke/tiny-AES-c/pull/34 if MULTIPLY_AS_A_FUNCTION*
- `InvMixColumns` (line 370) `static void InvMixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand for the inexperienced. Please use the references to gain more information.*
- `InvSubBytes` (line 391) `static void InvSubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `InvShiftRows` (line 402) `static void InvShiftRows(state_t* state)`
- `Cipher` (line 433) `static void Cipher(state_t* state, const uint8_t* RoundKey)` - *Cipher is the main function that encrypts the PlainText.*
- `InvCipher` (line 459) `static void InvCipher(state_t* state, const uint8_t* RoundKey)` - *if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)*
- `AES_ECB_encrypt` (line 488) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)` - *AddRoundKey(round, state, RoundKey); if (round == 0) { break; } InvMixColumns(state); } } #endif // #if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)  /* Public functions:  if defined(ECB) && (ECB == 1)*
- `AES_ECB_decrypt` (line 495) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `XorWithIv` (line 510) `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)` - *if defined(CBC) && (CBC == 1)*
- `AES_CBC_encrypt_buffer` (line 520) `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- `AES_CBC_decrypt_buffer` (line 535) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- `AES_CTR_xcrypt_buffer` (line 558) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` - *XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC) && (CBC == 1) #if defined(CTR) && (CTR == 1) /* Symmetrical operation: same function for encrypting as for decrypting. Note any IV/nonce should never be reused with the same key*

**Macros:**
- `Nb` (line 4)
- `KEYLEN_256` (line 6)
- `RKLENGTH` (line 10)
- `BLOCKLEN` (line 11)
- `Nb` (line 67)
- `Nk` (line 70)
- `Nr` (line 71)
- `Nk` (line 73)
- `Nr` (line 74)
- `Nk` (line 76)
- `Nr` (line 77)
- `MULTIPLY_AS_A_FUNCTION` (line 84)
- `getSBoxValue` (line 163)
- `Multiply` (line 349)
- `getSBoxInvert` (line 365)

#### `loader.c`
**Path:** `loader.c`

**Functions:**
- `read_bit` (line 63) `static int read_bit(BitReader* br)`
- `read_bits` (line 74) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 84) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `hookGetCommandLineW` (line 217) `LPWSTR hookGetCommandLineW()` - *Implementación de hooks*
- `hookGetCommandLineA` (line 218) `LPSTR hookGetCommandLineA()`
- `hook__p___argv` (line 219) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 220) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 221) `int* __cdecl hook__p___argc(void)`
- `anti_analysis` (line 226) `BOOL anti_analysis()` - *=== ANTI-ANALYSIS ===*
- `selfDestruct` (line 251) `void selfDestruct()` - *Puff*
- `hook__wgetmainargs` (line 306) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hook__getmainargs` (line 312) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 318) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 323) `void __stdcall hookExitProcess(UINT statuscode)`
- `masqueradeCmdline` (line 327) `void masqueradeCmdline()`
- `freeargvA` (line 365) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 373) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 381) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 393) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 403) `BOOL RepairIAT(PVOID modulePtr)`
- `_stricmp` (line 458) `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- `RunPE` (line 478) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 484) `void PELoader(char* data, DWORD datasize)`
- `getNtdll` (line 558) `LPVOID getNtdll()`
- `Unhook` (line 601) `BOOL Unhook(LPVOID cleanNtdll)`
- `DecryptAES` (line 637) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `GetData` (line 670) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 791) `int main(int argc, char** argv)`

**Macros:**
- `_CRT_RAND_S` (line 19)
- `NT_SUCCESS` (line 30)
- `NtCurrentThread` (line 32)
- `NtCurrentProcess` (line 34)
- `_CRT_SECURE_NO_WARNINGS` (line 37)
- `EI` (line 52)
- `EJ` (line 53)
- `P` (line 54)
- `N` (line 55)
- `F` (line 56)

**Structs:**
- `_BASE_RELOCATION_ENTRY` (line 41)

#### `loader2.c`
**Path:** `loader2.c`
**File Doc:** *define _CRT_RAND_S define WIN32_LEAN_AND_MEAN include <windows.h> include <stdio.h> include <stdlib.h> include <string.h> include <stdint.h> include <stdbool.h> include <psapi.h> include <winternl.h> include <winhttp.h> include <wincrypt.h> include <shellapi.h>  === DECLARACIONES DE HOOKS ===*

**Functions:**
- `read_bit` (line 51) `static int read_bit(BitReader* br)`
- `read_bits` (line 60) `static int read_bits(BitReader* br, int n)`
- `DecryptAES` (line 70) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 182) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 186) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 195) `bool isShellcodeThread(LPVOID addr)` - *Verifica si la dirección está dentro de .text*
- `shellcodeEncryptDecrypt` (line 206) `void shellcodeEncryptDecrypt(LPVOID caller)` - *Fluctuación: encripta/desencripta SOLO .text*
- `MySleep` (line 246) `static void WINAPI MySleep(DWORD ms)` - *Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)*
- `fastTrampoline` (line 261) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 302) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `lzss_decode_mem` (line 323) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...` - *================== LZSS ==================*
- `masqueradeCmdline` (line 387) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `GetNTHeaders` (line 418) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 429) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 438) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 490) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 491) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 492) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 493) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 494) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 495) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 498) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookExitProcess` (line 501) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 502) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 508) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 596) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 617) `void selfDestruct()`
- `GetData` (line 646) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 731) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 1)
- `WIN32_LEAN_AND_MEAN` (line 2)
- `_CRT_SECURE_NO_WARNINGS` (line 26)
- `NT_SUCCESS` (line 29)
- `NtCurrentThread` (line 31)
- `NtCurrentProcess` (line 33)
- `WIN32_LEAN_AND_MEAN` (line 34)
- `UNICODE` (line 36)
- `_UNICODE` (line 37)
- `EI` (line 40)
- `EJ` (line 41)
- `P` (line 42)
- `N` (line 43)
- `F` (line 44)
- `log` (line 153)

#### `loader3.c`
**Path:** `loader3.c`

**Functions:**
- `read_bit` (line 63) `static int read_bit(BitReader* br)`
- `read_bits` (line 72) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 82) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `DecryptAES` (line 138) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 238) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 241) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 248) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 257) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 291) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 305) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 341) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 360) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 389) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 397) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 405) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 416) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 425) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 478) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 479) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 480) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 481) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 482) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 483) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 486) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 489) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 493) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 496) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 502) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 581) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 601) `void selfDestruct()`
- `getNtdll` (line 629) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 664) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 689) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 757) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 15)
- `WIN32_LEAN_AND_MEAN` (line 17)
- `_CRT_SECURE_NO_WARNINGS` (line 42)
- `NT_SUCCESS` (line 45)
- `NtCurrentThread` (line 47)
- `NtCurrentProcess` (line 49)
- `EI` (line 52)
- `EJ` (line 53)
- `P` (line 54)
- `N` (line 55)
- `F` (line 56)
- `log` (line 214)

#### `loader4.c`
**Path:** `loader4.c`

**Functions:**
- `read_bit` (line 103) `static int read_bit(BitReader* br)`
- `read_bits` (line 112) `static int read_bits(BitReader* br, int n)`
- `deobf` (line 124) `void deobf(const char* src, char* dst, size_t max_len)` - *Helper para desofuscar*
- `SetHWBP_NtContinue` (line 132) `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- `lzss_decode_mem` (line 161) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `PatchETW` (line 218) `BOOL PatchETW()`
- `DecryptAES` (line 250) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 351) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 354) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 361) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 370) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 404) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 418) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 457) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 476) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 505) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 513) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 521) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 532) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 541) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 594) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 595) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 596) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 597) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 598) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 599) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 602) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 605) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 609) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 612) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 618) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 699) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 719) `void selfDestruct()`
- `getNtdll` (line 747) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 784) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 811) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 879) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 15)
- `WIN32_LEAN_AND_MEAN` (line 17)
- `XK` (line 42)
- `_CRT_SECURE_NO_WARNINGS` (line 52)
- `NT_SUCCESS` (line 55)
- `NtCurrentThread` (line 57)
- `NtCurrentProcess` (line 59)
- `EI` (line 62)
- `EJ` (line 63)
- `P` (line 64)
- `N` (line 65)
- `F` (line 66)
- `OBFUSCATE_KEY` (line 69)
- `OBFSTR` (line 72)
- `OBFSTRW` (line 85)
- `log` (line 327)

#### `lzss.c`
**Path:** `lzss.c`
**File Doc:** *lzss.c – implementación de Okumura (SIN main)*

**Functions:**
- `error` (line 15) `static void error(void)`
- `putbit1` (line 17) `static void putbit1(void)`
- `putbit0` (line 25) `static void putbit0(void)`
- `flush_bit_buffer` (line 31) `static void flush_bit_buffer(void)`
- `output1` (line 34) `static void output1(int c)`
- `output2` (line 39) `static void output2(int x, int y)`
- `encode` (line 45) `void encode(void)`
- `getbit` (line 76) `static int getbit(int n)`
- `decode` (line 86) `void decode(void)`

**Macros:**
- `EI` (line 4)
- `EJ` (line 6)
- `P` (line 7)
- `N` (line 8)
- `F` (line 9)

#### `pack.c`
**Path:** `pack.c`
**File Doc:** *pack.c*

**Functions:**
- `main` (line 7) `int main(int argc, char *argv[])`

#### `test.c`
**Path:** `test.c`
**File Doc:** *test.c – wrapper decompress Okumura*

**Functions:**
- `main` (line 8) `int main(void)`

#### `unpack.c`
**Path:** `unpack.c`
**File Doc:** *unpack.c*

**Functions:**
- `main` (line 7) `int main(int argc, char *argv[])`

### H (1 files)

#### `aes.h`
**Path:** `aes.h`
**File Doc:** *ifndef _AES_H_ define _AES_H_  include <stdint.h> include <stddef.h>  #define the macros below to 1/0 to enable/disable the mode of operation. ifndef CBC define CBC 1 endif ifndef ECB define ECB 1 endif ifndef CTR define CTR 1 endif  define AES256 1  // ✅ Clave de 256 bits  define AES_BLOCKLEN 16 // Block length in bytes - AES is 128b block only  if defined(AES256) && (AES256 == 1) define AES_KEYLEN 32 define AES_keyExpSize 240 elif defined(AES192) && (AES192 == 1) define AES_KEYLEN 24 define AES_keyExpSize 208 else define AES_KEYLEN 16   // Key length in bytes define AES_keyExpSize 176*

**Imported by:** `aes.c`

**Macros:**
- `_AES_H_` (line 2)
- `CBC` (line 9)
- `ECB` (line 12)
- `CTR` (line 15)
- `AES256` (line 17)
- `AES_BLOCKLEN` (line 19)
- `AES_KEYLEN` (line 23)
- `AES_keyExpSize` (line 24)
- `AES_KEYLEN` (line 26)
- `AES_keyExpSize` (line 27)
- `AES_KEYLEN` (line 29)
- `AES_keyExpSize` (line 30)

**Structs:**
- `AES_ctx` (line 33)

### PY (2 files)

#### `app.py`
**Path:** `app.py`
**File Doc:** *_*_ coding: utf8 _*_*

*No symbols extracted*

#### `crypter.py`
**Path:** `crypter.py`

**Functions:**
- `AESencrypt` (line 9) `def AESencrypt(plaintext, key)`
- `change_ext` (line 19) `def change_ext(filename, new_ext)` - *Reemplaza la extensión del archivo por una nueva (sin el punto).*
- `main` (line 24) `def main()`

### SH (1 files)

#### `install.sh`
**Path:** `install.sh`

*No symbols extracted*
