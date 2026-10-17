# Polyglot Codebase Knowledge Graph

> Generated offline by **readmenator**. 17 files, 470 symbols, 91 imports. Supports C, C++, Python, Go, Rust, JS/TS, Java, C#, Shell, PHP, Dart, GDScript, Nim, ASM, Ruby, Swift, Kotlin, Scala, Lua, Elixir.
> No LLMs. No tokens. Pure static analysis. See more [here](https://github.com/grisuno/ReadMenator)

**Start here:** Statistics Dashboard for scope, God Nodes for blast radius, Architecture Reference for per-file API. Agents: prefer `readmenator-agent/INDEX.md` + `SYMBOLS.md`.

**Wiki:** prefer `readmenator-wiki/index.md` for progressive disclosure: one synthesis page per community, `connections.json` with EXTRACTED vs INFERRED confidence, `queries.md` log, `REPORT.md` audit.

**Confidence:** EXTRACTED = parsed from source, INFERRED = heuristic bridge, AMBIGUOUS = reported, never hidden. See `readmenator-wiki/REPORT.md`.

**Total Files Parsed:** 17 | **Total Symbols Extracted:** 470 | **Total Imports:** 91
 | **Resolved Imports:** 4

<!-- ranking_model: v1.0 | weights: {ppr:0.45,auth:0.2,test:0.15,doc:0.1,fresh:0.1} | alpha:0.85 | commit:54dc722 | date:2026-07-18 -->


## Table of Contents

1. [Statistics Dashboard](#statistics-dashboard)
2. [Architectural Layers](#architectural-layers)
3. [Architecture Overview](#architecture-overview)
4. [Execution Flows](#execution-flows)
5. [Ranked Context](#ranked-context)
6. [God Nodes](#god-nodes)
7. [Community Analysis](#community-analysis)
8. [Suggested Questions](#suggested-questions)
9. [Force-Graph Explorer](#force-graph-explorer)
10. [Corpus Analytics](#corpus-analytics)
11. [Hotspot Analysis](#hotspot-analysis)
12. [Change Impact Analysis](#change-impact-analysis)
13. [Suggested Linting Rules](#suggested-linting-rules)
14. [Dataflow Analysis](#dataflow-analysis)
15. [Concept Graph](#concept-graph)
16. [Orphans](#orphans)
17. [Query Recipes](#query-recipes)
18. [Structural Knowledge Map](#structural-knowledge-map)
19. [UML Class Diagram](#uml-class-diagram)
20. [Code Property Graph](#code-property-graph)
21. [Architecture Reference](#architecture-reference)
    - [C (12 files)](#c-12-files)
    - [H (2 files)](#h-2-files)
    - [PY (2 files)](#py-2-files)
    - [SH (1 files)](#sh-1-files)

---

## Statistics Dashboard

| Metric | Value |
|--------|-------|
| Total Files | 17 |
| Total Symbols | 470 |
| Total Imports | 91 |
| Call Edges | 50 |
| Inheritance Edges | 0 |
| Languages | 4 |
| Avg Symbols/File | 27.6 |
| Avg Imports/File | 5.4 |
| Resolved Imports | 4 |

### Top Files by Import Count (Fan-Out)

| File | Imports | Symbols | Language |
|------|---------|---------|----------|
| `loader6.c` | 14 | 65 | c |
| `loader5.c` | 13 | 65 | c |
| `loader2.c` | 11 | 53 | c |
| `loader3.c` | 11 | 53 | c |
| `loader4.c` | 11 | 60 | c |
| `loader.c` | 8 | 43 | c |
| `crypter.py` | 6 | 3 | py |
| `lz4.c` | 4 | 28 | c |
| `aes.c` | 2 | 43 | c |
| `aes.h` | 2 | 21 | h |

### Top Files by Imported-By Count (Fan-In)

| File | Imported By | Symbols | Language |
|------|-------------|---------|----------|
| `lz4.h` | 3 | 13 | h |
| `aes.h` | 1 | 21 | h |

---

## Architectural Layers

Auto-detected from path patterns, naming conventions, and imported frameworks.

| Layer | Files |
|-------|-------|
| utility | 16 |
| testing | 1 |

### utility

- `aes.c` (c, 43 symbols)
- `aes.h` (h, 21 symbols)
- `app.py` (py, 0 symbols)
- `crypter.py` (py, 3 symbols)
- `install.sh` (sh, 0 symbols)
- `loader.c` (c, 43 symbols)
- `loader2.c` (c, 53 symbols)
- `loader3.c` (c, 53 symbols)
- `loader4.c` (c, 60 symbols)
- `loader5.c` (c, 65 symbols)
- `loader6.c` (c, 65 symbols)
- `lz4.c` (c, 28 symbols)
- `lz4.h` (h, 13 symbols)
- `lzss.c` (c, 14 symbols)
- `pack.c` (c, 3 symbols)
- *... and 1 more*

### testing

- `test.c` (c, 3 symbols)

---

## Architecture Overview

3 components stacked in 1 dependency tiers (weighted Eades-Lin-Smyth ordering: arrows point from dependent to dependency, top to bottom). Labels are import counts, thick arrows the top quartile; 0 transitively implied edges are omitted. Dashed red arrows are upward dependencies: the smallest set of imports that closes every cycle and breaks the layering. Cyan components hold entry points. Interactive version: `readmenator-apidocs/index.html#/flows`.

```mermaid
flowchart TB
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    subgraph lane_0["Tier 1"]
        direction LR
        n_d__root_["(root)<br/>10 files, 232 symbols<br/>Core / utility"]:::entry
        n_c1["root: aes<br/>2 files, 64 symbols<br/>Core / utility"]:::default
        n_c0["root: loader5<br/>4 files, 171 symbols<br/>Core / utility"]:::default
    end
```

---

## Execution Flows

Entry points are scored from `__main__` guards, `main` functions, entry-style names and files, and call-graph sources. Each flow walks resolved calls in call-site order (depth <= 4, <= 40 steps); numbers give the call order, dashed arrows revisit an already expanded callee, red arrows are recursion. Interactive version with zoom and per-node docs: `readmenator-apidocs/index.html#/flows`.

### `loader.main`

`loader.c:792`, score 11: `main` in a compiled-language file; entry-style name `main`.

Call tree:

```mermaid
flowchart LR
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    n_loader_c__main["loader.main<br/>loader.c:792"]:::entry
    n_loader_c__anti_analysis["loader.anti_analysis<br/>=== ANTI-ANALYSIS ===<br/>loader.c:226"]:::default
    n_loader_c__GetData["loader.GetData<br/>loader.c:671"]:::default
    n_loader_c__DecryptAES["loader.DecryptAES<br/>loader.c:638"]:::default
    n_loader_c__lzss_decode_mem["loader.lzss_decode_mem<br/>loader.c:85"]:::default
    n_loader_c__read_bit["loader.read_bit<br/>loader.c:64"]:::default
    n_loader_c__read_bits["loader.read_bits<br/>loader.c:75"]:::default
    n_loader_c__masqueradeCmdline["loader.masqueradeCmdline<br/>loader.c:328"]:::default
    n_loader_c__freeargvA["loader.freeargvA<br/>loader.c:366"]:::default
    n_loader_c__freeargvW["loader.freeargvW<br/>loader.c:374"]:::default
    n_loader_c__GetNTHeaders["loader.GetNTHeaders<br/>loader.c:382"]:::default
    n_loader_c__GetPEDirectory["loader.GetPEDirectory<br/>loader.c:394"]:::default
    n_loader_c__RepairIAT["loader.RepairIAT<br/>loader.c:404"]:::default
    n_loader_c___stricmp["loader._stricmp<br/>loader.c:458"]:::default
    n_loader_c__PELoader["loader.PELoader<br/>loader.c:485"]:::default
    n_loader_c__NTSTATUS["loader.NTSTATUS<br/>pragma warning(disable: 4996) define _CRT_SEC...<br/>loader.c:38"]:::default
    n_loader_c__NtCurrentProcess["loader.NtCurrentProcess<br/>loader.c:34"]:::default
    n_loader_c__getNtdll["loader.getNtdll<br/>loader.c:559"]:::default
    n_loader_c__main -.->|"recursion"| n_loader_c__main
    n_loader_c__main -->|"1"| n_loader_c__anti_analysis
    n_loader_c__anti_analysis -.->|"recursion"| n_loader_c__anti_analysis
    n_loader_c__main -->|"2"| n_loader_c__GetData
    n_loader_c__GetData -.->|"recursion"| n_loader_c__GetData
    n_loader_c__main -->|"3"| n_loader_c__DecryptAES
    n_loader_c__DecryptAES -.->|"recursion"| n_loader_c__DecryptAES
    n_loader_c__main -->|"4"| n_loader_c__lzss_decode_mem
    n_loader_c__lzss_decode_mem -.->|"recursion"| n_loader_c__lzss_decode_mem
    n_loader_c__lzss_decode_mem -->|"1"| n_loader_c__read_bit
    n_loader_c__lzss_decode_mem -->|"2"| n_loader_c__read_bits
    n_loader_c__read_bits -.-> n_loader_c__read_bit
    n_loader_c__lzss_decode_mem -.-> n_loader_c__DecryptAES
    n_loader_c__lzss_decode_mem -.-> n_loader_c__GetData
    n_loader_c__lzss_decode_mem -->|"3"| n_loader_c__masqueradeCmdline
    n_loader_c__masqueradeCmdline -.->|"recursion"| n_loader_c__masqueradeCmdline
    n_loader_c__lzss_decode_mem -->|"4"| n_loader_c__freeargvA
    n_loader_c__freeargvA -.->|"recursion"| n_loader_c__freeargvA
    n_loader_c__lzss_decode_mem -->|"5"| n_loader_c__freeargvW
    n_loader_c__freeargvW -.->|"recursion"| n_loader_c__freeargvW
    n_loader_c__lzss_decode_mem -->|"6"| n_loader_c__GetNTHeaders
    n_loader_c__GetNTHeaders -.->|"recursion"| n_loader_c__GetNTHeaders
    n_loader_c__lzss_decode_mem -->|"7"| n_loader_c__GetPEDirectory
    n_loader_c__GetPEDirectory -.->|"recursion"| n_loader_c__GetPEDirectory
    n_loader_c__GetPEDirectory -.-> n_loader_c__GetNTHeaders
    n_loader_c__lzss_decode_mem -->|"8"| n_loader_c__RepairIAT
    n_loader_c__RepairIAT -.->|"recursion"| n_loader_c__RepairIAT
    n_loader_c__RepairIAT -.-> n_loader_c__GetPEDirectory
    n_loader_c__RepairIAT -->|"1"| n_loader_c___stricmp
    n_loader_c___stricmp -.->|"recursion"| n_loader_c___stricmp
    n_loader_c__lzss_decode_mem -->|"9"| n_loader_c__PELoader
    n_loader_c__PELoader -.->|"recursion"| n_loader_c__PELoader
    n_loader_c__PELoader -.-> n_loader_c__masqueradeCmdline
    n_loader_c__PELoader -.-> n_loader_c__GetNTHeaders
    n_loader_c__PELoader -.-> n_loader_c__GetPEDirectory
    n_loader_c__PELoader -->|"1"| n_loader_c__NTSTATUS
    n_loader_c__PELoader -->|"2"| n_loader_c__NtCurrentProcess
    n_loader_c__PELoader -.-> n_loader_c__RepairIAT
    n_loader_c__lzss_decode_mem -->|"10"| n_loader_c__getNtdll
    n_loader_c__getNtdll -.->|"recursion"| n_loader_c__getNtdll
    linkStyle 0,2,4,6,8,15,17,19,21,23,26,29,31,39 stroke:#f87171,stroke-width:2px;
```

### `loader2.main`

`loader2.c:732`, score 11: `main` in a compiled-language file; entry-style name `main`.

Call tree:

```mermaid
flowchart LR
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    classDef external fill:#1a1530,stroke:#a78bfa,color:#ede9fe;
    n_loader2_c__main["loader2.main<br/>loader2.c:732"]:::entry
    n_loader2_c__anti_analysis["loader2.anti_analysis<br/>loader2.c:597"]:::default
    n_loader2_c__log["loader2.log<br/>loader2.c:154"]:::default
    n_loader2_c__fastTrampoline["loader2.fastTrampoline<br/>loader2.c:262"]:::default
    n_loader2_c__xor32["loader2.xor32<br/>loader2.c:187"]:::default
    n_loader2_c__isShellcodeThread["loader2.isShellcodeThread<br/>Verifica si la dirección está dentro de .text<br/>loader2.c:195"]:::default
    n_loader2_c__VEHHandler["loader2.VEHHandler<br/>loader2.c:303"]:::default
    n_loader2_c__shellcodeEncryptDecrypt["loader2.shellcodeEncryptDecrypt<br/>Fluctuación: encripta/desencripta SOLO .text<br/>loader2.c:206"]:::default
    n_loader2_c__lzss_decode_mem["loader2.lzss_decode_mem<br/>loader2.c:324"]:::default
    n_loader2_c__read_bit["loader2.read_bit<br/>loader2.c:52"]:::default
    n_loader2_c__read_bits["loader2.read_bits<br/>loader2.c:61"]:::default
    n_loader2_c__GetData["loader2.GetData<br/>loader2.c:647"]:::default
    n_loader2_c__masqueradeCmdline["loader2.masqueradeCmdline<br/>loader2.c:388"]:::default
    n_loader2_c__DecryptAES["loader2.DecryptAES<br/>loader2.c:71"]:::default
    n_loader2_c__PELoader["loader2.PELoader<br/>loader2.c:509"]:::default
    n_loader2_c__GetNTHeaders["loader2.GetNTHeaders<br/>loader2.c:419"]:::default
    n_loader_c__NTSTATUS["loader.NTSTATUS<br/>pragma warning(disable: 4996) define _CRT_SEC...<br/>loader.c:38"]:::external
    n_loader2_c__main -.->|"recursion"| n_loader2_c__main
    n_loader2_c__main -->|"1"| n_loader2_c__anti_analysis
    n_loader2_c__anti_analysis -.->|"recursion"| n_loader2_c__anti_analysis
    n_loader2_c__main -->|"2"| n_loader2_c__log
    n_loader2_c__log -->|"1"| n_loader2_c__fastTrampoline
    n_loader2_c__fastTrampoline -.->|"recursion"| n_loader2_c__fastTrampoline
    n_loader2_c__log -->|"2"| n_loader2_c__xor32
    n_loader2_c__xor32 -.->|"recursion"| n_loader2_c__xor32
    n_loader2_c__log -->|"3"| n_loader2_c__isShellcodeThread
    n_loader2_c__isShellcodeThread -.->|"recursion"| n_loader2_c__isShellcodeThread
    n_loader2_c__log -->|"4"| n_loader2_c__VEHHandler
    n_loader2_c__VEHHandler -.->|"recursion"| n_loader2_c__VEHHandler
    n_loader2_c__VEHHandler -.->|"recursion"| n_loader2_c__log
    n_loader2_c__VEHHandler -.-> n_loader2_c__isShellcodeThread
    n_loader2_c__VEHHandler -->|"1"| n_loader2_c__shellcodeEncryptDecrypt
    n_loader2_c__shellcodeEncryptDecrypt -.->|"recursion"| n_loader2_c__shellcodeEncryptDecrypt
    n_loader2_c__shellcodeEncryptDecrypt -.-> n_loader2_c__isShellcodeThread
    n_loader2_c__shellcodeEncryptDecrypt -.->|"recursion"| n_loader2_c__log
    n_loader2_c__shellcodeEncryptDecrypt -.-> n_loader2_c__xor32
    n_loader2_c__log -->|"5"| n_loader2_c__lzss_decode_mem
    n_loader2_c__lzss_decode_mem -.->|"recursion"| n_loader2_c__lzss_decode_mem
    n_loader2_c__lzss_decode_mem -->|"1"| n_loader2_c__read_bit
    n_loader2_c__lzss_decode_mem -->|"2"| n_loader2_c__read_bits
    n_loader2_c__read_bits -.-> n_loader2_c__read_bit
    n_loader2_c__log -->|"6"| n_loader2_c__GetData
    n_loader2_c__GetData -.->|"recursion"| n_loader2_c__GetData
    n_loader2_c__log -->|"7"| n_loader2_c__masqueradeCmdline
    n_loader2_c__masqueradeCmdline -.->|"recursion"| n_loader2_c__masqueradeCmdline
    n_loader2_c__main -.-> n_loader2_c__fastTrampoline
    n_loader2_c__main -.-> n_loader2_c__GetData
    n_loader2_c__main -->|"3"| n_loader2_c__DecryptAES
    n_loader2_c__DecryptAES -.->|"recursion"| n_loader2_c__DecryptAES
    n_loader2_c__main -.-> n_loader2_c__lzss_decode_mem
    n_loader2_c__main -->|"4"| n_loader2_c__PELoader
    n_loader2_c__PELoader -.->|"recursion"| n_loader2_c__PELoader
    n_loader2_c__PELoader -.-> n_loader2_c__masqueradeCmdline
    n_loader2_c__PELoader -->|"1"| n_loader2_c__GetNTHeaders
    n_loader2_c__GetNTHeaders -.->|"recursion"| n_loader2_c__GetNTHeaders
    n_loader2_c__PELoader -.-> n_loader2_c__log
    n_loader2_c__PELoader -->|"2"| n_loader_c__NTSTATUS
    linkStyle 0,2,5,7,9,11,12,15,17,20,25,27,31,34,37 stroke:#f87171,stroke-width:2px;
```

Cross-file sequence:

```mermaid
sequenceDiagram
    autonumber
    participant p_loader2_c as loader2.c
    participant p_loader_c as loader.c
    p_loader2_c->>p_loader_c: NTSTATUS()
```

### `loader3.main`

`loader3.c:757`, score 11: `main` in a compiled-language file; entry-style name `main`.

Call tree:

```mermaid
flowchart LR
    classDef default fill:#111827,stroke:#38bdf8,color:#e5e7eb;
    classDef entry fill:#0e7490,stroke:#22d3ee,color:#ecfeff,stroke-width:2px;
    classDef external fill:#1a1530,stroke:#a78bfa,color:#ede9fe;
    n_loader3_c__main["loader3.main<br/>================== MAIN ==================<br/>loader3.c:757"]:::entry
    n_loader3_c__anti_analysis["loader3.anti_analysis<br/>================== ANTI-ANALYSIS & CLEANUP ==...<br/>loader3.c:581"]:::default
    n_loader3_c__log["loader3.log<br/>loader3.c:214"]:::default
    n_loader3_c__fastTrampoline["loader3.fastTrampoline<br/>loader3.c:306"]:::default
    n_loader3_c__xor32["loader3.xor32<br/>loader3.c:242"]:::default
    n_loader3_c__isShellcodeThread["loader3.isShellcodeThread<br/>loader3.c:249"]:::default
    n_loader3_c__VEHHandler["loader3.VEHHandler<br/>loader3.c:342"]:::default
    n_loader3_c__shellcodeEncryptDecrypt["loader3.shellcodeEncryptDecrypt<br/>loader3.c:258"]:::default
    n_loader3_c__GetData["loader3.GetData<br/>================== NETWORK ==================<br/>loader3.c:689"]:::default
    n_loader3_c__masqueradeCmdline["loader3.masqueradeCmdline<br/>================== PE LOADER ==================<br/>loader3.c:360"]:::default
    n_loader3_c__freeargvA["loader3.freeargvA<br/>loader3.c:390"]:::default
    n_loader3_c__freeargvW["loader3.freeargvW<br/>loader3.c:398"]:::default
    n_loader3_c__GetNTHeaders["loader3.GetNTHeaders<br/>loader3.c:406"]:::default
    n_loader3_c__GetPEDirectory["loader3.GetPEDirectory<br/>loader3.c:417"]:::default
    n_loader3_c__RepairIAT["loader3.RepairIAT<br/>loader3.c:426"]:::default
    n_loader_c___stricmp["loader._stricmp<br/>loader.c:458"]:::external
    n_loader3_c__PELoader["loader3.PELoader<br/>loader3.c:503"]:::default
    n_loader3_c__main -.->|"recursion"| n_loader3_c__main
    n_loader3_c__main -->|"1"| n_loader3_c__anti_analysis
    n_loader3_c__anti_analysis -.->|"recursion"| n_loader3_c__anti_analysis
    n_loader3_c__main -->|"2"| n_loader3_c__log
    n_loader3_c__log -->|"1"| n_loader3_c__fastTrampoline
    n_loader3_c__fastTrampoline -.->|"recursion"| n_loader3_c__fastTrampoline
    n_loader3_c__log -->|"2"| n_loader3_c__xor32
    n_loader3_c__xor32 -.->|"recursion"| n_loader3_c__xor32
    n_loader3_c__log -->|"3"| n_loader3_c__isShellcodeThread
    n_loader3_c__isShellcodeThread -.->|"recursion"| n_loader3_c__isShellcodeThread
    n_loader3_c__log -->|"4"| n_loader3_c__VEHHandler
    n_loader3_c__VEHHandler -.->|"recursion"| n_loader3_c__VEHHandler
    n_loader3_c__VEHHandler -.->|"recursion"| n_loader3_c__log
    n_loader3_c__VEHHandler -.-> n_loader3_c__isShellcodeThread
    n_loader3_c__VEHHandler -->|"1"| n_loader3_c__shellcodeEncryptDecrypt
    n_loader3_c__shellcodeEncryptDecrypt -.->|"recursion"| n_loader3_c__shellcodeEncryptDecrypt
    n_loader3_c__shellcodeEncryptDecrypt -.-> n_loader3_c__isShellcodeThread
    n_loader3_c__shellcodeEncryptDecrypt -.->|"recursion"| n_loader3_c__log
    n_loader3_c__shellcodeEncryptDecrypt -.-> n_loader3_c__xor32
    n_loader3_c__log -->|"5"| n_loader3_c__GetData
    n_loader3_c__GetData -.->|"recursion"| n_loader3_c__GetData
    n_loader3_c__log -->|"6"| n_loader3_c__masqueradeCmdline
    n_loader3_c__masqueradeCmdline -.->|"recursion"| n_loader3_c__masqueradeCmdline
    n_loader3_c__log -->|"7"| n_loader3_c__freeargvA
    n_loader3_c__freeargvA -.->|"recursion"| n_loader3_c__freeargvA
    n_loader3_c__log -->|"8"| n_loader3_c__freeargvW
    n_loader3_c__freeargvW -.->|"recursion"| n_loader3_c__freeargvW
    n_loader3_c__log -->|"9"| n_loader3_c__GetNTHeaders
    n_loader3_c__GetNTHeaders -.->|"recursion"| n_loader3_c__GetNTHeaders
    n_loader3_c__log -->|"10"| n_loader3_c__GetPEDirectory
    n_loader3_c__GetPEDirectory -.->|"recursion"| n_loader3_c__GetPEDirectory
    n_loader3_c__GetPEDirectory -.-> n_loader3_c__GetNTHeaders
    n_loader3_c__log -->|"11"| n_loader3_c__RepairIAT
    n_loader3_c__RepairIAT -.->|"recursion"| n_loader3_c__RepairIAT
    n_loader3_c__RepairIAT -.-> n_loader3_c__GetPEDirectory
    n_loader3_c__RepairIAT -->|"1"| n_loader_c___stricmp
    n_loader_c___stricmp -.->|"recursion"| n_loader_c___stricmp
    n_loader3_c__log -->|"12"| n_loader3_c__PELoader
    n_loader3_c__PELoader -.->|"recursion"| n_loader3_c__PELoader
    n_loader3_c__PELoader -.-> n_loader3_c__masqueradeCmdline
    linkStyle 0,2,5,7,9,11,12,15,17,20,22,24,26,28,30,33,36,38 stroke:#f87171,stroke-width:2px;
```

Cross-file sequence:

```mermaid
sequenceDiagram
    autonumber
    participant p_loader3_c as loader3.c
    participant p_loader_c as loader.c
    p_loader3_c->>p_loader_c: _stricmp()
```

---

## Ranked Context

Files ranked by composite score for the current query context. The ranking combines Personalized PageRank (query relevance), global authority, test coverage, documentation coverage, and code freshness. Model: v1.0.

| Rank | File | Composite | PPR | Authority | Test | Doc |
|------|------|-----------|-----|-----------|------|-----|
| 1 | `lz4.h` | 0.2532 | 0.3777 | 0.3777 | 0.00 | 0.08 |
| 2 | `aes.h` | 0.1517 | 0.1968 | 0.1968 | 0.00 | 0.24 |
| 3 | `app.py` | 0.1000 | 0.0000 | 0.0000 | 0.00 | 1.00 |
| 4 | `aes.c` | 0.0994 | 0.1064 | 0.1064 | 0.00 | 0.30 |
| 5 | `loader5.c` | 0.0876 | 0.1064 | 0.1064 | 0.00 | 0.18 |
| 6 | `loader6.c` | 0.0876 | 0.1064 | 0.1064 | 0.00 | 0.18 |
| 7 | `lz4.c` | 0.0834 | 0.1064 | 0.1064 | 0.00 | 0.14 |
| 8 | `test.c` | 0.0667 | 0.0000 | 0.0000 | 0.00 | 0.67 |
| 9 | `crypter.py` | 0.0333 | 0.0000 | 0.0000 | 0.00 | 0.33 |
| 10 | `pack.c` | 0.0333 | 0.0000 | 0.0000 | 0.00 | 0.33 |

---

## God Nodes

Most architecturally central files ranked by combined import/export degree and symbol richness.

| File | Score | Connections | PageRank |
|------|-------|-------------|----------|
| `loader5.c` | 8.5 | | 0.1064 |
| `loader6.c` | 8.5 | | 0.1064 |
| `lz4.h` | 7.3 | | 0.3777 |
| `aes.c` | 6.3 | | 0.1064 |
| `loader4.c` | 6.0 | | 0.0000 |
| `loader2.c` | 5.3 | | 0.0000 |
| `loader3.c` | 5.3 | | 0.0000 |
| `lz4.c` | 4.8 | | 0.1064 |
| `loader.c` | 4.3 | | 0.0000 |
| `aes.h` | 4.1 | | 0.1968 |

---

## Community Analysis

Files grouped by import-based community detection. Cohesion measures how tightly connected each community is internally.

### root: loader5 (Cohesion: 1.00)

**4 files** in this community:

- `loader5.c` (c, 65 symbols)
- `loader6.c` (c, 65 symbols)
- `lz4.c` (c, 28 symbols)
- `lz4.h` (h, 13 symbols)

### root: aes (Cohesion: 1.00)

**2 files** in this community:

- `aes.c` (c, 43 symbols)
- `aes.h` (h, 21 symbols)

---

## Suggested Questions

Auto-generated exploration prompts based on graph structure:

- What does loader5.c depend on, and what depends on it? (1 connections)
- What does loader6.c depend on, and what depends on it? (1 connections)
- What does lz4.h depend on, and what depends on it? (3 connections)
- How are the 4 files in 'root: loader5' related to each other?
- What is AES_ctx in aes.h and how is it used?

---

## Force-Graph Explorer

Heterogeneous explorer payload (files, communities, layers, externals) rendered with force-graph physics, stable family colors, log2 node sizing, and convex-hull community overlays. Open `readmenator-maps/graph-force.html` (linked from the maps gallery) or run `explorer`.

- Nodes: 40 (community: 2, external: 19, file: 17, layer: 2)
- Edges: 118

---

## Corpus Analytics

Attribution funnel and distributions for the explorer dashboard.

- Files: 17 | With symbols: 15 | Attributed: 6 | God nodes: 10 | Symbols: 470

- Layer `utility`: 16 files
- Layer `testing`: 1 files

- Language `c`: 12 files
- Language `h`: 2 files
- Language `py`: 2 files
- Language `sh`: 1 files

---

## Hotspot Analysis

Files ranked by combined complexity (symbol count) and centrality (connection count). High-scoring files are architecturally critical and may need refactoring attention.

| File | Complexity | Centrality | Combined | Symbols | Connections |
|------|-----------|------------|----------|---------|-------------|
| `lz4.h` | 0.200 | 0.467 | 0.360 | 13 | 7 |
| `aes.h` | 0.323 | 0.267 | 0.289 | 21 | 4 |
| `app.py` | 0.000 | 0.000 | 0.000 | 0 | 0 |
| `aes.c` | 0.661 | 0.200 | 0.385 | 43 | 3 |
| `loader5.c` | 1.000 | 0.933 | 0.960 | 65 | 14 |
| `loader6.c` | 1.000 | 1.000 | 1.000 | 65 | 15 |
| `lz4.c` | 0.431 | 0.333 | 0.372 | 28 | 5 |
| `test.c` | 0.046 | 0.133 | 0.099 | 3 | 2 |
| `crypter.py` | 0.046 | 0.400 | 0.259 | 3 | 6 |
| `pack.c` | 0.046 | 0.133 | 0.099 | 3 | 2 |
| `loader4.c` | 0.923 | 0.733 | 0.809 | 60 | 11 |
| `loader2.c` | 0.815 | 0.733 | 0.766 | 53 | 11 |
| `loader3.c` | 0.815 | 0.733 | 0.766 | 53 | 11 |
| `loader.c` | 0.661 | 0.533 | 0.585 | 43 | 8 |
| `lzss.c` | 0.215 | 0.133 | 0.166 | 14 | 2 |

---

## Dataflow Analysis

Procedural intra-function dataflow findings (zero tokens, regex-based heuristics, all INFERRED). Each lead is grounded at file:line for manual review.

**12 findings** (UNCHECKED_ALLOC: 12).

| File | Function | Line | Kind | Variable | Description |
|------|----------|------|------|----------|-------------|
| `loader.c` | `main` | 809 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader.c` | `main` | 813 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |
| `loader2.c` | `main` | 766 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader2.c` | `main` | 770 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |
| `loader3.c` | `main` | 809 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader3.c` | `main` | 812 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |
| `loader4.c` | `main` | 938 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader4.c` | `main` | 941 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |
| `loader5.c` | `main` | 1030 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader5.c` | `main` | 1033 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |
| `loader6.c` | `main` | 1039 | `UNCHECKED_ALLOC` | `whost` | Result of allocator stored in `whost` is never checked against NULL. |
| `loader6.c` | `main` | 1042 | `UNCHECKED_ALLOC` | `wresource` | Result of allocator stored in `wresource` is never checked against NULL. |

---

## Concept Graph

Semantic second-brain layer: nouns are concept nodes, verbs are edges. Each noun maps atomically to a file set (EXTRACTED); each verb aggregates structural imports, calls, and inherits into consumes, invokes, extends, depends_on, or bridges (INFERRED).

**50 concepts, 100 relations.**

| Concept | Files | Mentions |
|---------|-------|----------|
| `decode` | 9 | 15 |
| `aes` | 8 | 43 |
| `bit` | 8 | 17 |
| `decrypt` | 8 | 16 |
| `get` | 7 | 44 |
| `encrypt` | 7 | 9 |
| `lzss` | 7 | 9 |
| `hook` | 6 | 54 |
| `command` | 6 | 12 |
| `data` | 6 | 12 |
| `line` | 6 | 12 |
| `read` | 6 | 12 |
| `crt` | 6 | 11 |
| `process` | 6 | 10 |
| `destruct` | 6 | 8 |
| `self` | 6 | 8 |
| `secure` | 6 | 7 |
| `warnings` | 6 | 7 |
| `argc` | 6 | 6 |
| `argv` | 6 | 6 |
| `bits` | 6 | 6 |
| `cmdline` | 6 | 6 |
| `exit` | 6 | 6 |
| `fast` | 6 | 6 |
| `getmainargs` | 6 | 6 |
| `iat` | 6 | 6 |
| `masquerade` | 6 | 6 |
| `ntheaders` | 6 | 6 |
| `pedirectory` | 6 | 6 |
| `reader` | 6 | 6 |

### Verb Edges

| Source | Verb | Target | Strength | Evidence |
|--------|------|--------|----------|----------|
| `aes` | `consumes` | `set` | 1.00 | 3 |
| `aes` | `depends_on` | `set` | 1.00 | 3 |
| `bit` | `consumes` | `decode` | 1.00 | 3 |
| `bit` | `depends_on` | `decode` | 1.00 | 3 |
| `bit` | `consumes` | `decompress` | 1.00 | 3 |
| `bit` | `depends_on` | `decompress` | 1.00 | 3 |
| `bit` | `consumes` | `set` | 1.00 | 3 |
| `bit` | `depends_on` | `set` | 1.00 | 3 |
| `decompress` | `consumes` | `decode` | 1.00 | 3 |
| `decompress` | `depends_on` | `decode` | 1.00 | 3 |
| `decompress` | `consumes` | `set` | 1.00 | 3 |
| `decompress` | `depends_on` | `set` | 1.00 | 3 |
| `decrypt` | `consumes` | `set` | 1.00 | 3 |
| `decrypt` | `depends_on` | `set` | 1.00 | 3 |
| `encrypt` | `consumes` | `set` | 1.00 | 3 |
| `encrypt` | `depends_on` | `set` | 1.00 | 3 |
| `fast` | `consumes` | `decode` | 1.00 | 3 |
| `fast` | `depends_on` | `decode` | 1.00 | 3 |
| `fast` | `consumes` | `decompress` | 1.00 | 3 |
| `fast` | `depends_on` | `decompress` | 1.00 | 3 |
| `fast` | `consumes` | `set` | 1.00 | 3 |
| `fast` | `depends_on` | `set` | 1.00 | 3 |
| `get` | `consumes` | `set` | 1.00 | 3 |
| `get` | `depends_on` | `set` | 1.00 | 3 |
| `key` | `consumes` | `set` | 1.00 | 3 |
| `key` | `depends_on` | `set` | 1.00 | 3 |
| `address` | `consumes` | `decode` | 0.67 | 2 |
| `address` | `depends_on` | `decode` | 0.67 | 2 |
| `address` | `consumes` | `decompress` | 0.67 | 2 |
| `address` | `depends_on` | `decompress` | 0.67 | 2 |

### Dialectic Prompts

- Thesis: `address` centralizes 5 files; Antithesis: `aes` pulls 8 files with 5 shared (Jaccard 0.62); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `argc` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `argv` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `bit` pulls 8 files with 5 shared (Jaccard 0.62); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `bits` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `buffers` pulls 5 files with 5 shared (Jaccard 1.00); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `cmdline` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `command` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `crt` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?
- Thesis: `address` centralizes 5 files; Antithesis: `data` pulls 6 files with 5 shared (Jaccard 0.83); Synthesis: should they merge, split by layer, or keep `bridges` explicit?

---

## Change Impact Analysis

Files sorted by how many other files would be affected if they changed. High-impact files should be changed with caution.

| File | Direct Dependents | Transitive Dependents | Total Impact |
|------|------------------|----------------------|--------------|
| `lz4.h` | 3 | 0 | 3 |
| `aes.h` | 1 | 0 | 1 |
| `aes.c` | 0 | 0 | 0 |
| `app.py` | 0 | 0 | 0 |
| `crypter.py` | 0 | 0 | 0 |
| `install.sh` | 0 | 0 | 0 |
| `loader.c` | 0 | 0 | 0 |
| `loader2.c` | 0 | 0 | 0 |
| `loader3.c` | 0 | 0 | 0 |
| `loader4.c` | 0 | 0 | 0 |
| `loader5.c` | 0 | 0 | 0 |
| `loader6.c` | 0 | 0 | 0 |
| `lz4.c` | 0 | 0 | 0 |
| `lzss.c` | 0 | 0 | 0 |
| `pack.c` | 0 | 0 | 0 |

---

## Suggested Linting Rules

Automatically suggested linting and security rules based on patterns detected in the codebase. These can be exported as Semgrep rules using the `--export-rules` flag.

| Rule ID | Severity | Description | Language | Matches |
|---------|----------|-------------|----------|---------|
| `RM001` | info | Large number of functions in c: 279 total | c | 279 |
| `RM002` | info | Large number of functions in h: 12 total | h | 12 |
| `RM003` | info | Large number of functions in py: 3 total | py | 3 |
| `RM004` | info | Print statement found (consider logging instead) | python | 16 |

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
graph LR
    classDef mod fill:#1e1e1e,stroke:#ff6666,stroke-width:2px,color:#fff;
    classDef cls fill:#2d2d2d,stroke:#4ec9b0,stroke-width:2px,color:#fff;
    classDef fn fill:#333,stroke:#dcdcaa,stroke-width:1px,color:#dcdcaa;
    classDef ext fill:#111,stroke:#666,stroke-dasharray:5 5,color:#aaa;
    subgraph community_0 ["root: loader5"]
    loader6_c["loader6.c (c)"]
    class loader6_c mod;
    loader6_c_SYSCALL_ENTRY["SYSCALL_ENTRY"]
    class loader6_c_SYSCALL_ENTRY cls;
    loader6_c --> loader6_c_SYSCALL_ENTRY
    loader6_c_BitReader["BitReader"]
    class loader6_c_BitReader cls;
    loader6_c --> loader6_c_BitReader
    loader6_c_EXEC_CTX["EXEC_CTX"]
    class loader6_c_EXEC_CTX cls;
    loader6_c --> loader6_c_EXEC_CTX
    loader6_c_FLUCTUATION_CTX["FLUCTUATION_CTX"]
    class loader6_c_FLUCTUATION_CTX cls;
    loader6_c --> loader6_c_FLUCTUATION_CTX
    loader6_c_HookTrampolineBuffers["HookTrampolineBuffers"]
    class loader6_c_HookTrampolineBuffers cls;
    loader6_c --> loader6_c_HookTrampolineBuffers
    loader5_c["loader5.c (c)"]
    class loader5_c mod;
    loader4_c["loader4.c (c)"]
    class loader4_c mod;
    loader2_c["loader2.c (c)"]
    class loader2_c mod;
    loader3_c["loader3.c (c)"]
    class loader3_c mod;
    loader_c["loader.c (c)"]
    class loader_c mod;
    crypter_py["crypter.py (py)"]
    class crypter_py mod;
    lz4_c["lz4.c (c)"]
    class lz4_c mod;
    end
    subgraph community_1 ["root: aes"]
    aes_c["aes.c (c)"]
    class aes_c mod;
    aes_h["aes.h (h)"]
    class aes_h mod;
    lzss_c["lzss.c (c)"]
    class lzss_c mod;
    pack_c["pack.c (c)"]
    class pack_c mod;
    test_c["test.c (c)"]
    class test_c mod;
    unpack_c["unpack.c (c)"]
    class unpack_c mod;
    lz4_h["lz4.h (h)"]
    class lz4_h mod;
    app_py["app.py (py)"]
    class app_py mod;
    install_sh["install.sh (sh)"]
    class install_sh mod;
    end
    loader4_c ~~~ pack_c
    loader2_c ~~~ test_c
    loader3_c ~~~ unpack_c
    loader_c ~~~ app_py
    crypter_py ~~~ install_sh
    aes_c -- resolved_imports --> aes_h
    loader5_c -- resolved_imports --> lz4_h
    loader6_c -- resolved_imports --> lz4_h
    lz4_c -- resolved_imports --> lz4_h
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
    loader5_c -.->|imports| ext_windows_h
    loader5_c -.->|imports| ext_stdio_h
    loader5_c -.->|imports| ext_stdlib_h
    loader5_c -.->|imports| ext_string_h
    loader5_c -.->|imports| ext_stdint_h
    loader5_c -.->|imports| ext_stdbool_h
    loader5_c -.->|imports| ext_psapi_h
    loader5_c -.->|imports| ext_winternl_h
    loader5_c -.->|imports| ext_winhttp_h
    loader5_c -.->|imports| ext_wincrypt_h
    loader5_c -.->|imports| ext_shellapi_h
    ext_intrin_h["intrin.h"]
    class ext_intrin_h ext;
    loader5_c -.->|imports| ext_intrin_h
    ext_lz4_h["lz4.h"]
    class ext_lz4_h ext;
    loader5_c -.->|imports| ext_lz4_h
    loader6_c -.->|imports| ext_windows_h
    loader6_c -.->|imports| ext_stdio_h
    loader6_c -.->|imports| ext_stdlib_h
    loader6_c -.->|imports| ext_string_h
    loader6_c -.->|imports| ext_stdint_h
    loader6_c -.->|imports| ext_stdbool_h
    loader6_c -.->|imports| ext_psapi_h
    loader6_c -.->|imports| ext_winternl_h
    loader6_c -.->|imports| ext_winhttp_h
    loader6_c -.->|imports| ext_wincrypt_h
    loader6_c -.->|imports| ext_shellapi_h
    loader6_c -.->|imports| ext_intrin_h
    ext_time_h["time.h"]
    class ext_time_h ext;
    loader6_c -.->|imports| ext_time_h
    loader6_c -.->|imports| ext_lz4_h
    lz4_c -.->|imports| ext_lz4_h
    lz4_c -.->|imports| ext_string_h
    lz4_c -.->|imports| ext_stdlib_h
    lz4_c -.->|imports| ext_stdint_h
    lz4_h -.->|imports| ext_stddef_h
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

Auto-generated Mermaid class diagrams from parsed class-level symbols, split into groups of at most 6 classes so each diagram stays readable. Per-module class diagrams with exact members live in `readmenator-apidocs/modules/`.

#### `aes.h`, `loader.c`

```mermaid
classDiagram
  direction LR
  class aes_h_AES_ctx {
    <<struct>>
    +AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);
    +AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);
    +AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);
    +AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);
    +AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);
    +AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);
    +AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);
    +AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);
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
  class loader_c_DATA {
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
  class loader_c_BitReader {
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

#### `loader2.c`

```mermaid
classDiagram
  direction LR
  class loader2_c_BitReader {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
    +VEHHandler(PEXCEPTION_POINTERS xp)
  }
  class loader2_c_FluctuationMetadata {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
    +VEHHandler(PEXCEPTION_POINTERS xp)
  }
  class loader2_c_HookTrampolineBuffers {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
    +VEHHandler(PEXCEPTION_POINTERS xp)
  }
  class loader2_c_HookedSleep {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
    +VEHHandler(PEXCEPTION_POINTERS xp)
  }
  class loader2_c_DATA {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
    +VEHHandler(PEXCEPTION_POINTERS xp)
  }
```

#### `loader3.c`

```mermaid
classDiagram
  direction LR
  class loader3_c_BitReader {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
  }
  class loader3_c_FluctuationMetadata {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
  }
  class loader3_c_HookTrampolineBuffers {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
  }
  class loader3_c_HookedSleep {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
  }
  class loader3_c_DATA {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
    +shellcodeEncryptDecrypt(LPVOID caller)
    +MySleep(DWORD ms)
    +fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)
  }
```

#### `loader4.c`

```mermaid
classDiagram
  direction LR
  class loader4_c_BitReader {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +deobf(const char* src, char* dst, size_t max_len)
    +SetHWBP_NtContinue(PVOID targetAddr, DWORD index)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +PatchETW()
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
  }
  class loader4_c_FluctuationMetadata {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +deobf(const char* src, char* dst, size_t max_len)
    +SetHWBP_NtContinue(PVOID targetAddr, DWORD index)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +PatchETW()
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
  }
  class loader4_c_HookTrampolineBuffers {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +deobf(const char* src, char* dst, size_t max_len)
    +SetHWBP_NtContinue(PVOID targetAddr, DWORD index)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +PatchETW()
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
  }
  class loader4_c_HookedSleep {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +deobf(const char* src, char* dst, size_t max_len)
    +SetHWBP_NtContinue(PVOID targetAddr, DWORD index)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +PatchETW()
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
  }
  class loader4_c_DATA {
    <<struct>>
    +read_bit(BitReader* br)
    +read_bits(BitReader* br, int n)
    +deobf(const char* src, char* dst, size_t max_len)
    +SetHWBP_NtContinue(PVOID targetAddr, DWORD index)
    +lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...
    +PatchETW()
    +DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)
    +get_return_address(void)
    +xor32(uint8_t *buf, SIZE_T sz, uint32_t key)
    +isShellcodeThread(LPVOID addr)
  }
```

#### `loader5.c`

```mermaid
classDiagram
  direction LR
  class loader5_c_SYSCALL_ENTRY {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader5_c_BitReader {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader5_c_EXEC_CTX {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader5_c_FLUCTUATION_CTX {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader5_c_HookTrampolineBuffers {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader5_c_DATA {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
```

#### `loader6.c`

```mermaid
classDiagram
  direction LR
  class loader6_c_SYSCALL_ENTRY {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader6_c_BitReader {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader6_c_EXEC_CTX {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader6_c_FLUCTUATION_CTX {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader6_c_HookTrampolineBuffers {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
  class loader6_c_DATA {
    <<struct>>
    +HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)
    +NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...
    +NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...
    +NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...
    +NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...
    +NtClose_indirect(HANDLE Handle)
    +NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...
    +NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...
    +NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)
    +NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...
  }
```

#### `lz4.c`, `lz4.h`

```mermaid
classDiagram
  direction LR
  class lz4_c_LZ4_streamDecode_t_internal {
    <<struct>>
    +LZ4_read32(const void* ptr)
    +LZ4_write32(void* ptr, U32 value)
    +LZ4_read16(const void* ptr)
    +LZ4_write16(void* ptr, U16 value)
    +LZ4_read64(const void* ptr)
    +LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize)
    +LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompre...
    +LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize)
    +LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize,...
    +LZ4_resetStreamDecode(void* streamPtr)
  }
  class lz4_h_LZ4_streamDecode_t {
    <<struct>>
    +LZ4_decompress_safe() : * compressedSize : is the exact complete size of the compressed block. * maxDecompressedSize : is the size of the destination buffer, which must be already allocated. * retur
    +LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize);
    +LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize, int maxDecompressedSize);
    +LZ4_resetStreamDecode(void* streamPtr);
  }
  lz4_c_LZ4_streamDecode_t_internal --> lz4_h_LZ4_streamDecode_t : uses
```

---

## Code Property Graph

Machine-readable Code Property Graph (CPG) in JSON-LD format. This block allows AI agents to parse the full structural graph without additional file reads. Compatible with GraphRAG pipelines.

```json
{"@context": "https://schema.org", "analysis": {"communities": [{"cohesion": 1.0, "id": 0, "label": "root: loader5", "size": 4}, {"cohesion": 1.0, "id": 1, "label": "root: aes", "size": 2}], "god_nodes": [{"node_id": "loader5.c", "score": 8.5}, {"node_id": "loader6.c", "score": 8.5}, {"node_id": "lz4.h", "score": 7.3}, {"node_id": "aes.c", "score": 6.3}, {"node_id": "loader4.c", "score": 6.0}, {"node_id": "loader2.c", "score": 5.3}, {"node_id": "loader3.c", "score": 5.3}, {"node_id": "lz4.c", "score": 4.8}, {"node_id": "loader.c", "score": 4.3}, {"node_id": "aes.h", "score": 4.1}], "surprising_connections": []}, "edges": [{"confidence": "EXTRACTED", "relation": "imports", "source": "aes.c", "target": "aes.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.h", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "aes.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "sys"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "os"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "hashlib"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "struct"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "os"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "crypter.py", "target": "Crypto.Cipher"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader2.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader3.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader4.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "intrin.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader5.c", "target": "lz4.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "windows.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "stdbool.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "psapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "winternl.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "winhttp.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "wincrypt.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "shellapi.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "intrin.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "time.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "loader6.c", "target": "lz4.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lz4.c", "target": "lz4.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lz4.c", "target": "string.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lz4.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lz4.c", "target": "stdint.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lz4.h", "target": "stddef.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lzss.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "lzss.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "pack.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "pack.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "test.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "test.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "unpack.c", "target": "stdio.h"}, {"confidence": "EXTRACTED", "relation": "imports", "source": "unpack.c", "target": "stdlib.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "aes.c", "target": "aes.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "loader5.c", "target": "lz4.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "loader6.c", "target": "lz4.h"}, {"confidence": "EXTRACTED", "relation": "resolved_imports", "source": "lz4.c", "target": "lz4.h"}], "generator": "readmenator", "metadata": {"edge_count": 145, "file_count": 17, "language_count": 4, "symbol_count": 470}, "nodes": [{"doc": "aes.c - tiny-AES-c (https://github.com/kokke/tiny-AES-c)", "id": "aes.c", "kind": "module", "label": "aes.c", "language": "c", "sha256": "12e247148b2d6453", "symbol_count": 43, "symbols": [{"kind": "function", "line": 13, "name": "getSBoxValue", "signature": "static uint8_t getSBoxValue(uint8_t num)"}, {"kind": "function", "line": 35, "name": "getSBoxInvert", "signature": "static uint8_t getSBoxInvert(uint8_t num)"}, {"kind": "function", "line": 57, "name": "Td0", "signature": "static uint8_t Td0(int x)"}, {"kind": "function", "line": 58, "name": "Td1", "signature": "static uint8_t Td1(int x)"}, {"kind": "function", "line": 59, "name": "Td2", "signature": "static uint8_t Td2(int x)"}, {"kind": "function", "line": 60, "name": "Td3", "signature": "static uint8_t Td3(int x)"}, {"kind": "function", "line": 61, "name": "Td4", "signature": "static uint8_t Td4(int x)"}, {"doc": "This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.", "kind": "function", "line": 166, "name": "KeyExpansion", "signature": "static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)"}, {"kind": "function", "line": 239, "name": "AES_init_ctx", "signature": "void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)"}, {"doc": "if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))", "kind": "function", "line": 244, "name": "AES_init_ctx_iv", "signature": "void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)"}, {"kind": "function", "line": 249, "name": "AES_ctx_set_iv", "signature": "void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)"}, {"doc": "This function adds the round key to state. The round key is added to the state by an XOR function.", "kind": "function", "line": 257, "name": "AddRoundKey", "signature": "static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)"}, {"doc": "The SubBytes Function Substitutes the values in the state matrix with values in an S-box.", "kind": "function", "line": 271, "name": "SubBytes", "signature": "static void SubBytes(state_t* state)"}, {"doc": "The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row is not shifted.", "kind": "function", "line": 286, "name": "ShiftRows", "signature": "static void ShiftRows(state_t* state)"}, {"kind": "function", "line": 314, "name": "xtime", "signature": "static uint8_t xtime(uint8_t x)"}, {"doc": "MixColumns function mixes the columns of the state matrix", "kind": "function", "line": 320, "name": "MixColumns", "signature": "static void MixColumns(state_t* state)"}, {"doc": "Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary The compiler seems to be able to vectorize the operation better this way. See https://github.com/kokke/tiny-AES-c/pull/34 if MULTIPLY_AS_A_FUNCTION", "kind": "function", "line": 340, "name": "Multiply", "signature": "static uint8_t Multiply(uint8_t x, uint8_t y)"}, {"doc": "MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand for the inexperienced. Please use the references to gain more information.", "kind": "function", "line": 370, "name": "InvMixColumns", "signature": "static void InvMixColumns(state_t* state)"}, {"doc": "The SubBytes Function Substitutes the values in the state matrix with values in an S-box.", "kind": "function", "line": 391, "name": "InvSubBytes", "signature": "static void InvSubBytes(state_t* state)"}, {"kind": "function", "line": 403, "name": "InvShiftRows", "signature": "static void InvShiftRows(state_t* state)"}, {"doc": "Cipher is the main function that encrypts the PlainText.", "kind": "function", "line": 433, "name": "Cipher", "signature": "static void Cipher(state_t* state, const uint8_t* RoundKey)"}, {"doc": "if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)", "kind": "function", "line": 459, "name": "InvCipher", "signature": "static void InvCipher(state_t* state, const uint8_t* RoundKey)"}, {"kind": "function", "line": 490, "name": "AES_ECB_encrypt", "signature": "void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)"}, {"kind": "function", "line": 496, "name": "AES_ECB_decrypt", "signature": "void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)"}, {"kind": "function", "line": 512, "name": "XorWithIv", "signature": "static void XorWithIv(uint8_t* buf, const uint8_t* Iv)"}, {"kind": "function", "line": 521, "name": "AES_CBC_encrypt_buffer", "signature": "void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)"}, {"kind": "function", "line": 536, "name": "AES_CBC_decrypt_buffer", "signature": "void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)"}, {"doc": "XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC) && (CBC == 1) #if defined(CTR) && (CTR == 1) /* Symmetrical operation: same function for encrypting as for decrypting. Note any IV/nonce should never be reused with the same key", "kind": "function", "line": 558, "name": "AES_CTR_xcrypt_buffer", "signature": "void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)"}, {"kind": "macro", "line": 5, "name": "Nb", "signature": "#define Nb"}, {"kind": "macro", "line": 9, "name": "KEYLEN_256", "signature": "#define KEYLEN_256"}, {"kind": "macro", "line": 10, "name": "RKLENGTH", "signature": "#define RKLENGTH"}, {"kind": "macro", "line": 11, "name": "BLOCKLEN", "signature": "#define BLOCKLEN"}, {"kind": "macro", "line": 67, "name": "Nb", "signature": "#define Nb"}, {"kind": "macro", "line": 70, "name": "Nk", "signature": "#define Nk"}, {"kind": "macro", "line": 71, "name": "Nr", "signature": "#define Nr"}, {"kind": "macro", "line": 73, "name": "Nk", "signature": "#define Nk"}, {"kind": "macro", "line": 74, "name": "Nr", "signature": "#define Nr"}, {"kind": "macro", "line": 76, "name": "Nk", "signature": "#define Nk"}, {"kind": "macro", "line": 77, "name": "Nr", "signature": "#define Nr"}, {"kind": "macro", "line": 84, "name": "MULTIPLY_AS_A_FUNCTION", "signature": "#define MULTIPLY_AS_A_FUNCTION"}, {"kind": "macro", "line": 163, "name": "getSBoxValue", "signature": "#define getSBoxValue(num)"}, {"kind": "macro", "line": 349, "name": "Multiply", "signature": "#define Multiply(x, y)"}, {"kind": "macro", "line": 365, "name": "getSBoxInvert", "signature": "#define getSBoxInvert(num)"}]}, {"doc": "#define the macros below to 1/0 to enable/disable the mode of operation.", "id": "aes.h", "kind": "module", "label": "aes.h", "language": "h", "sha256": "e1e91ab2bbec246c", "symbol_count": 21, "symbols": [{"kind": "struct", "line": 33, "name": "AES_ctx"}, {"kind": "function", "line": 41, "name": "AES_init_ctx", "signature": "void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);"}, {"doc": "if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))", "kind": "function", "line": 43, "name": "AES_init_ctx_iv", "signature": "void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);"}, {"kind": "function", "line": 44, "name": "AES_ctx_set_iv", "signature": "void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);"}, {"doc": "if defined(ECB) && (ECB == 1)", "kind": "function", "line": 48, "name": "AES_ECB_encrypt", "signature": "void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);"}, {"kind": "function", "line": 49, "name": "AES_ECB_decrypt", "signature": "void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);"}, {"doc": "if defined(CBC) && (CBC == 1)", "kind": "function", "line": 53, "name": "AES_CBC_encrypt_buffer", "signature": "void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);"}, {"kind": "function", "line": 54, "name": "AES_CBC_decrypt_buffer", "signature": "void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);"}, {"doc": "if defined(CTR) && (CTR == 1)", "kind": "function", "line": 58, "name": "AES_CTR_xcrypt_buffer", "signature": "void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);"}, {"kind": "macro", "line": 2, "name": "_AES_H_", "signature": "#define _AES_H_"}, {"kind": "macro", "line": 9, "name": "CBC", "signature": "#define CBC"}, {"kind": "macro", "line": 12, "name": "ECB", "signature": "#define ECB"}, {"kind": "macro", "line": 15, "name": "CTR", "signature": "#define CTR"}, {"kind": "macro", "line": 18, "name": "AES256", "signature": "#define AES256"}, {"kind": "macro", "line": 20, "name": "AES_BLOCKLEN", "signature": "#define AES_BLOCKLEN"}, {"kind": "macro", "line": 23, "name": "AES_KEYLEN", "signature": "#define AES_KEYLEN"}, {"kind": "macro", "line": 24, "name": "AES_keyExpSize", "signature": "#define AES_keyExpSize"}, {"kind": "macro", "line": 26, "name": "AES_KEYLEN", "signature": "#define AES_KEYLEN"}, {"kind": "macro", "line": 27, "name": "AES_keyExpSize", "signature": "#define AES_keyExpSize"}, {"kind": "macro", "line": 29, "name": "AES_KEYLEN", "signature": "#define AES_KEYLEN"}, {"kind": "macro", "line": 30, "name": "AES_keyExpSize", "signature": "#define AES_keyExpSize"}]}, {"doc": "app.py  Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:", "id": "app.py", "kind": "module", "label": "app.py", "language": "py", "sha256": "57b21bdb023585b8", "symbol_count": 0, "symbols": []}, {"id": "crypter.py", "kind": "module", "label": "crypter.py", "language": "py", "sha256": "b3ded94a56b1e293", "symbol_count": 3, "symbols": [{"kind": "function", "line": 9, "name": "AESencrypt", "signature": "def AESencrypt(plaintext, key)"}, {"doc": "Reemplaza la extensión del archivo por una nueva (sin el punto).", "kind": "function", "line": 19, "name": "change_ext", "signature": "def change_ext(filename, new_ext)"}, {"kind": "function", "line": 24, "name": "main", "signature": "def main()"}]}, {"id": "install.sh", "kind": "module", "label": "install.sh", "language": "sh", "sha256": "c907d80fd6734993", "symbol_count": 0, "symbols": []}, {"id": "loader.c", "kind": "module", "label": "loader.c", "language": "c", "sha256": "2d2e519a7f25448e", "symbol_count": 43, "symbols": [{"kind": "struct", "line": 41, "name": "_BASE_RELOCATION_ENTRY"}, {"kind": "struct", "line": 46, "name": "DATA"}, {"kind": "struct", "line": 58, "name": "BitReader"}, {"doc": "pragma warning(disable: 4996) define _CRT_SECURE_NO_WARNINGS", "kind": "type_alias", "line": 38, "name": "NTSTATUS", "signature": "typedef LONG NTSTATUS;"}, {"kind": "type_alias", "line": 40, "name": "12", "signature": "typedef struct _BASE_RELOCATION_ENTRY { WORD Offset : 12;"}, {"kind": "function", "line": 64, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 75, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 85, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"doc": "Implementación de hooks", "kind": "function", "line": 217, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 218, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 219, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 220, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 221, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"doc": "=== ANTI-ANALYSIS ===", "kind": "function", "line": 226, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"doc": "Puff", "kind": "function", "line": 251, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"kind": "function", "line": 307, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 313, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 319, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 324, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 328, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 366, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 374, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 382, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 394, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 404, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"kind": "function", "line": 458, "name": "_stricmp", "signature": "_stricmp(func_name, \"exit\") == 0 ||\n                    _stricmp(func_name, \"_Exit\") == 0 ||\n    ..."}, {"kind": "function", "line": 479, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 485, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"kind": "function", "line": 559, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 602, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"kind": "function", "line": 638, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"kind": "function", "line": 671, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"kind": "function", "line": 792, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 19, "name": "_CRT_RAND_S", "signature": "#define _CRT_RAND_S"}, {"kind": "macro", "line": 30, "name": "NT_SUCCESS", "signature": "#define NT_SUCCESS(Status)"}, {"kind": "macro", "line": 33, "name": "NtCurrentThread", "signature": "#define NtCurrentThread()"}, {"kind": "macro", "line": 34, "name": "NtCurrentProcess", "signature": "#define NtCurrentProcess()"}, {"kind": "macro", "line": 37, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 52, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 53, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 54, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 55, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 56, "name": "F", "signature": "#define F"}]}, {"doc": "=== DECLARACIONES DE HOOKS ===", "id": "loader2.c", "kind": "module", "label": "loader2.c", "language": "c", "sha256": "d6708ee0d481cf27", "symbol_count": 53, "symbols": [{"kind": "struct", "line": 46, "name": "BitReader"}, {"kind": "struct", "line": 111, "name": "FluctuationMetadata"}, {"kind": "struct", "line": 119, "name": "HookTrampolineBuffers"}, {"kind": "struct", "line": 129, "name": "HookedSleep"}, {"kind": "struct", "line": 134, "name": "DATA"}, {"doc": "ifdef _WIN64", "kind": "type_alias", "line": 100, "name": "UPTR", "signature": "typedef UINT64 UPTR;"}, {"doc": "else", "kind": "type_alias", "line": 102, "name": "UPTR", "signature": "typedef UINT32 UPTR;"}, {"kind": "function", "line": 52, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 61, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 71, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"kind": "function", "line": 183, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 187, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"doc": "Verifica si la dirección está dentro de .text", "kind": "function", "line": 195, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"doc": "Fluctuación: encripta/desencripta SOLO .text", "kind": "function", "line": 206, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"doc": "Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)", "kind": "function", "line": 246, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 262, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 303, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"kind": "function", "line": 324, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"kind": "function", "line": 388, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 419, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 430, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 439, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 490, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 491, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 492, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 493, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 494, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 495, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 498, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 501, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 503, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 509, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"kind": "function", "line": 597, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 618, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"kind": "function", "line": 647, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"kind": "function", "line": 732, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "function", "line": 169, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc);"}, {"kind": "function", "line": 170, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc);"}, {"kind": "macro", "line": 1, "name": "_CRT_RAND_S", "signature": "#define _CRT_RAND_S"}, {"kind": "macro", "line": 2, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 26, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 29, "name": "NT_SUCCESS", "signature": "#define NT_SUCCESS(Status)"}, {"kind": "macro", "line": 32, "name": "NtCurrentThread", "signature": "#define NtCurrentThread()"}, {"kind": "macro", "line": 33, "name": "NtCurrentProcess", "signature": "#define NtCurrentProcess()"}, {"kind": "macro", "line": 35, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 36, "name": "UNICODE", "signature": "#define UNICODE"}, {"kind": "macro", "line": 37, "name": "_UNICODE", "signature": "#define _UNICODE"}, {"kind": "macro", "line": 40, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 41, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 42, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 43, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 44, "name": "F", "signature": "#define F"}, {"kind": "macro", "line": 154, "name": "log", "signature": "#define log(...)"}]}, {"id": "loader3.c", "kind": "module", "label": "loader3.c", "language": "c", "sha256": "5c262bc2a209d5dc", "symbol_count": 53, "symbols": [{"kind": "struct", "line": 58, "name": "BitReader"}, {"kind": "struct", "line": 174, "name": "FluctuationMetadata"}, {"kind": "struct", "line": 182, "name": "HookTrampolineBuffers"}, {"kind": "struct", "line": 192, "name": "HookedSleep"}, {"kind": "struct", "line": 197, "name": "DATA"}, {"doc": "================== TYPEDEFS & STRUCTS ================== ifdef _WIN64", "kind": "type_alias", "line": 163, "name": "UPTR", "signature": "typedef UINT64 UPTR;"}, {"doc": "else", "kind": "type_alias", "line": 165, "name": "UPTR", "signature": "typedef UINT32 UPTR;"}, {"kind": "function", "line": 64, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 73, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 83, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"kind": "function", "line": 139, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "================== FLUCTUATION IMPLEMENTATION ==================", "kind": "function", "line": 238, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 242, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"kind": "function", "line": 249, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"kind": "function", "line": 258, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"kind": "function", "line": 292, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 306, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 342, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "================== PE LOADER ==================", "kind": "function", "line": 360, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 390, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 398, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 406, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 417, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 426, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 478, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 479, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 480, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 481, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 482, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 483, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 486, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 489, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 493, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 497, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 503, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"doc": "================== ANTI-ANALYSIS & CLEANUP ==================", "kind": "function", "line": 581, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 602, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"doc": "================== UNHOOKING ==================", "kind": "function", "line": 629, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 665, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"doc": "================== NETWORK ==================", "kind": "function", "line": 689, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"doc": "================== MAIN ==================", "kind": "function", "line": 757, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 16, "name": "_CRT_RAND_S", "signature": "#define _CRT_RAND_S"}, {"kind": "macro", "line": 17, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 42, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 45, "name": "NT_SUCCESS", "signature": "#define NT_SUCCESS(Status)"}, {"kind": "macro", "line": 48, "name": "NtCurrentThread", "signature": "#define NtCurrentThread()"}, {"kind": "macro", "line": 49, "name": "NtCurrentProcess", "signature": "#define NtCurrentProcess()"}, {"kind": "macro", "line": 52, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 53, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 54, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 55, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 56, "name": "F", "signature": "#define F"}, {"kind": "macro", "line": 214, "name": "log", "signature": "#define log(...)"}]}, {"id": "loader4.c", "kind": "module", "label": "loader4.c", "language": "c", "sha256": "999457cebca52227", "symbol_count": 60, "symbols": [{"kind": "struct", "line": 98, "name": "BitReader"}, {"kind": "struct", "line": 287, "name": "FluctuationMetadata"}, {"kind": "struct", "line": 295, "name": "HookTrampolineBuffers"}, {"kind": "struct", "line": 305, "name": "HookedSleep"}, {"kind": "struct", "line": 310, "name": "DATA"}, {"doc": "================== TYPEDEFS & STRUCTS ================== ifdef _WIN64", "kind": "type_alias", "line": 276, "name": "UPTR", "signature": "typedef UINT64 UPTR;"}, {"doc": "else", "kind": "type_alias", "line": 278, "name": "UPTR", "signature": "typedef UINT32 UPTR;"}, {"kind": "function", "line": 104, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 113, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"doc": "Helper para desofuscar", "kind": "function", "line": 124, "name": "deobf", "signature": "void deobf(const char* src, char* dst, size_t max_len)"}, {"kind": "function", "line": 132, "name": "SetHWBP_NtContinue", "signature": "BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)"}, {"kind": "function", "line": 163, "name": "lzss_decode_mem", "signature": "BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_..."}, {"kind": "function", "line": 219, "name": "PatchETW", "signature": "BOOL PatchETW()"}, {"kind": "function", "line": 252, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "================== FLUCTUATION IMPLEMENTATION ==================", "kind": "function", "line": 351, "name": "get_return_address", "signature": "static inline UPTR get_return_address(void)"}, {"kind": "function", "line": 355, "name": "xor32", "signature": "void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)"}, {"kind": "function", "line": 362, "name": "isShellcodeThread", "signature": "bool isShellcodeThread(LPVOID addr)"}, {"kind": "function", "line": 371, "name": "shellcodeEncryptDecrypt", "signature": "void shellcodeEncryptDecrypt(LPVOID caller)"}, {"kind": "function", "line": 405, "name": "MySleep", "signature": "static void WINAPI MySleep(DWORD ms)"}, {"kind": "function", "line": 419, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 458, "name": "VEHHandler", "signature": "LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)"}, {"doc": "================== PE LOADER ==================", "kind": "function", "line": 476, "name": "masqueradeCmdline", "signature": "void masqueradeCmdline()"}, {"kind": "function", "line": 506, "name": "freeargvA", "signature": "void freeargvA(char** array, int Argc)"}, {"kind": "function", "line": 514, "name": "freeargvW", "signature": "void freeargvW(wchar_t** array, int Argc)"}, {"kind": "function", "line": 522, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 533, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 542, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"doc": "Hooks", "kind": "function", "line": 594, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA()"}, {"kind": "function", "line": 595, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW()"}, {"kind": "function", "line": 596, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 597, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 598, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 599, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 602, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 605, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 609, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"kind": "function", "line": 613, "name": "RunPE", "signature": "DWORD WINAPI RunPE(LPVOID lpParameter)"}, {"kind": "function", "line": 619, "name": "PELoader", "signature": "void PELoader(char* data, DWORD datasize)"}, {"doc": "================== ANTI-ANALYSIS & CLEANUP ==================", "kind": "function", "line": 699, "name": "anti_analysis", "signature": "BOOL anti_analysis()"}, {"kind": "function", "line": 720, "name": "selfDestruct", "signature": "void selfDestruct()"}, {"doc": "================== UNHOOKING ==================", "kind": "function", "line": 747, "name": "getNtdll", "signature": "LPVOID getNtdll()"}, {"kind": "function", "line": 785, "name": "Unhook", "signature": "BOOL Unhook(LPVOID cleanNtdll)"}, {"doc": "================== NETWORK ==================", "kind": "function", "line": 811, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)"}, {"doc": "================== MAIN ==================", "kind": "function", "line": 879, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 16, "name": "_CRT_RAND_S", "signature": "#define _CRT_RAND_S"}, {"kind": "macro", "line": 17, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 42, "name": "XK", "signature": "#define XK"}, {"kind": "macro", "line": 52, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 55, "name": "NT_SUCCESS", "signature": "#define NT_SUCCESS(Status)"}, {"kind": "macro", "line": 58, "name": "NtCurrentThread", "signature": "#define NtCurrentThread()"}, {"kind": "macro", "line": 59, "name": "NtCurrentProcess", "signature": "#define NtCurrentProcess()"}, {"kind": "macro", "line": 62, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 63, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 64, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 65, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 66, "name": "F", "signature": "#define F"}, {"kind": "macro", "line": 69, "name": "OBFUSCATE_KEY", "signature": "#define OBFUSCATE_KEY"}, {"kind": "macro", "line": 72, "name": "OBFSTR", "signature": "#define OBFSTR(str)"}, {"kind": "macro", "line": 85, "name": "OBFSTRW", "signature": "#define OBFSTRW(str)"}, {"kind": "macro", "line": 327, "name": "log", "signature": "#define log(...)"}]}, {"id": "loader5.c", "kind": "module", "label": "loader5.c", "language": "c", "sha256": "ede77e7f110514f8", "symbol_count": 65, "symbols": [{"doc": "======================================================================== 3.  SYSCALLS (Hell's Gate + indirect) ========================================================================", "kind": "struct", "line": 60, "name": "SYSCALL_ENTRY"}, {"kind": "struct", "line": 290, "name": "BitReader"}, {"doc": "Estructuras para ejecución y fluctuación", "kind": "struct", "line": 675, "name": "EXEC_CTX"}, {"kind": "struct", "line": 679, "name": "FLUCTUATION_CTX"}, {"kind": "struct", "line": 739, "name": "HookTrampolineBuffers"}, {"doc": "======================================================================== 11. NETWORK DOWNLOAD ========================================================================", "kind": "struct", "line": 904, "name": "DATA"}, {"kind": "function", "line": 65, "name": "HellGate", "signature": "BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)"}, {"kind": "function", "line": 86, "name": "NtAllocateVirtualMemory_indirect", "signature": "static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_..."}, {"kind": "function", "line": 106, "name": "NtProtectVirtualMemory_indirect", "signature": "static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T..."}, {"kind": "function", "line": 126, "name": "NtWriteVirtualMemory_indirect", "signature": "static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff..."}, {"kind": "function", "line": 146, "name": "NtFlushInstructionCache_indirect", "signature": "static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ..."}, {"kind": "function", "line": 166, "name": "NtClose_indirect", "signature": "static NTSTATUS NtClose_indirect(HANDLE Handle)"}, {"kind": "function", "line": 185, "name": "NtOpenSection_indirect", "signature": "static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_..."}, {"kind": "function", "line": 205, "name": "NtMapViewOfSection_indirect", "signature": "static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba..."}, {"kind": "function", "line": 226, "name": "NtUnmapViewOfSection_indirect", "signature": "static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)"}, {"kind": "function", "line": 246, "name": "NtFreeVirtualMemory_indirect", "signature": "static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re..."}, {"doc": "======================================================================== 4.  COMPRESIÓN: LZSS (por defecto) ======================================================================== ifdef USE_LZ4 include \"lz4.h\"", "kind": "function", "line": 271, "name": "decompress_payload", "signature": "BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz..."}, {"kind": "function", "line": 296, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 305, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 315, "name": "decompress_payload", "signature": "BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si..."}, {"doc": "======================================================================== 5.  CRYPTO (AES-256-CBC con CryptoAPI directa) ========================================================================", "kind": "function", "line": 375, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "======================================================================== 6.  ANTIDEBUG / ANTIANALYSIS ========================================================================", "kind": "function", "line": 396, "name": "IsDebuggerPresentEx", "signature": "BOOL IsDebuggerPresentEx()"}, {"kind": "function", "line": 400, "name": "HasHWBreakpoints", "signature": "BOOL HasHWBreakpoints()"}, {"kind": "function", "line": 407, "name": "IsDomainJoined", "signature": "BOOL IsDomainJoined()"}, {"kind": "function", "line": 416, "name": "HasRealGPU", "signature": "BOOL HasRealGPU()"}, {"kind": "function", "line": 434, "name": "HasUserActivity", "signature": "BOOL HasUserActivity()"}, {"kind": "function", "line": 443, "name": "IsSandbox", "signature": "BOOL IsSandbox()"}, {"doc": "======================================================================== 7.  AMSI BYPASS (module stomping) ========================================================================", "kind": "function", "line": 478, "name": "PatchAmsiViaStomping", "signature": "BOOL PatchAmsiViaStomping()"}, {"doc": "======================================================================== 8.  UNHOOKING ntdll (KnownDlls) ========================================================================", "kind": "function", "line": 510, "name": "getCleanNtdllViaKnownDlls", "signature": "LPVOID getCleanNtdllViaKnownDlls()"}, {"kind": "function", "line": 535, "name": "UnhookNtdll", "signature": "BOOL UnhookNtdll(LPVOID cleanNtdll)"}, {"kind": "function", "line": 568, "name": "MasqueradeCmdline", "signature": "void MasqueradeCmdline()"}, {"kind": "function", "line": 592, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA(void)"}, {"kind": "function", "line": 593, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW(void)"}, {"kind": "function", "line": 594, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 595, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 596, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 597, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 600, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 603, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 604, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"doc": "======================================================================== 10. PE LOADER WITH FLUCTUATION ========================================================================", "kind": "function", "line": 609, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 620, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 629, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"kind": "function", "line": 691, "name": "FluctuateEncrypt", "signature": "void FluctuateEncrypt(FLUCTUATION_CTX* ctx)"}, {"kind": "function", "line": 715, "name": "FluctuateDecrypt", "signature": "void FluctuateDecrypt(FLUCTUATION_CTX* ctx)"}, {"kind": "function", "line": 746, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 770, "name": "MySleep", "signature": "void WINAPI MySleep(DWORD ms)"}, {"doc": "Stack spoofing", "kind": "function", "line": 784, "name": "GetSpoofedReturnAddress", "signature": "ULONG_PTR GetSpoofedReturnAddress()"}, {"kind": "function", "line": 790, "name": "ExecuteWithSpoofedRet", "signature": "void ExecuteWithSpoofedRet(PVOID entry)"}, {"kind": "function", "line": 803, "name": "TimerExecCallback", "signature": "VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)"}, {"kind": "function", "line": 810, "name": "ModuleStompAndExecute", "signature": "BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)"}, {"kind": "function", "line": 909, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)"}, {"doc": "======================================================================== 12. SELF-DESTRUCT ========================================================================", "kind": "function", "line": 971, "name": "SelfDestruct", "signature": "void SelfDestruct()"}, {"doc": "======================================================================== 13. MAIN ========================================================================", "kind": "function", "line": 995, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 14, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 29, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 35, "name": "DEBUG_PRINT", "signature": "#define DEBUG_PRINT(fmt, ...)"}, {"kind": "macro", "line": 37, "name": "DEBUG_PRINT", "signature": "#define DEBUG_PRINT(fmt, ...)"}, {"kind": "macro", "line": 43, "name": "OBF_KEY", "signature": "#define OBF_KEY"}, {"kind": "macro", "line": 45, "name": "OBFSTR", "signature": "#define OBFSTR(str)"}, {"kind": "macro", "line": 284, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 285, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 286, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 287, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 288, "name": "F", "signature": "#define F"}]}, {"id": "loader6.c", "kind": "module", "label": "loader6.c", "language": "c", "sha256": "d77cff05b7100e2b", "symbol_count": 65, "symbols": [{"doc": "======================================================================== 3.  SYSCALLS (Hell's Gate + indirect) ========================================================================", "kind": "struct", "line": 62, "name": "SYSCALL_ENTRY"}, {"kind": "struct", "line": 292, "name": "BitReader"}, {"doc": "Estructuras para ejecución y fluctuación", "kind": "struct", "line": 678, "name": "EXEC_CTX"}, {"kind": "struct", "line": 682, "name": "FLUCTUATION_CTX"}, {"kind": "struct", "line": 742, "name": "HookTrampolineBuffers"}, {"doc": "======================================================================== 11. NETWORK DOWNLOAD ========================================================================", "kind": "struct", "line": 908, "name": "DATA"}, {"kind": "function", "line": 67, "name": "HellGate", "signature": "BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)"}, {"kind": "function", "line": 88, "name": "NtAllocateVirtualMemory_indirect", "signature": "static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_..."}, {"kind": "function", "line": 108, "name": "NtProtectVirtualMemory_indirect", "signature": "static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T..."}, {"kind": "function", "line": 128, "name": "NtWriteVirtualMemory_indirect", "signature": "static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff..."}, {"kind": "function", "line": 148, "name": "NtFlushInstructionCache_indirect", "signature": "static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ..."}, {"kind": "function", "line": 168, "name": "NtClose_indirect", "signature": "static NTSTATUS NtClose_indirect(HANDLE Handle)"}, {"kind": "function", "line": 187, "name": "NtOpenSection_indirect", "signature": "static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_..."}, {"kind": "function", "line": 207, "name": "NtMapViewOfSection_indirect", "signature": "static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba..."}, {"kind": "function", "line": 228, "name": "NtUnmapViewOfSection_indirect", "signature": "static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)"}, {"kind": "function", "line": 248, "name": "NtFreeVirtualMemory_indirect", "signature": "static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re..."}, {"doc": "======================================================================== 4.  COMPRESIÓN: LZSS (por defecto) o LZ4 (si se define USE_LZ4) ======================================================================== ifdef USE_LZ4 include \"lz4.h\"", "kind": "function", "line": 273, "name": "decompress_payload", "signature": "BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz..."}, {"kind": "function", "line": 298, "name": "read_bit", "signature": "static int read_bit(BitReader* br)"}, {"kind": "function", "line": 307, "name": "read_bits", "signature": "static int read_bits(BitReader* br, int n)"}, {"kind": "function", "line": 317, "name": "decompress_payload", "signature": "BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si..."}, {"doc": "======================================================================== 5.  CRYPTO (AES-256-CBC con CryptoAPI directa) ========================================================================", "kind": "function", "line": 377, "name": "DecryptAES", "signature": "void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)"}, {"doc": "======================================================================== 6.  ANTIDEBUG / ANTIANALYSIS ========================================================================", "kind": "function", "line": 398, "name": "IsDebuggerPresentEx", "signature": "BOOL IsDebuggerPresentEx()"}, {"kind": "function", "line": 402, "name": "HasHWBreakpoints", "signature": "BOOL HasHWBreakpoints()"}, {"kind": "function", "line": 409, "name": "IsDomainJoined", "signature": "BOOL IsDomainJoined()"}, {"kind": "function", "line": 418, "name": "HasRealGPU", "signature": "BOOL HasRealGPU()"}, {"kind": "function", "line": 436, "name": "HasUserActivity", "signature": "BOOL HasUserActivity()"}, {"kind": "function", "line": 445, "name": "IsSandbox", "signature": "BOOL IsSandbox()"}, {"doc": "======================================================================== 7.  AMSI BYPASS (module stomping) - usando syscall para permisos ========================================================================", "kind": "function", "line": 479, "name": "PatchAmsiViaStomping", "signature": "BOOL PatchAmsiViaStomping()"}, {"doc": "======================================================================== 8.  UNHOOKING ntdll (KnownDlls) - usando syscall para permisos ========================================================================", "kind": "function", "line": 512, "name": "getCleanNtdllViaKnownDlls", "signature": "LPVOID getCleanNtdllViaKnownDlls()"}, {"kind": "function", "line": 537, "name": "UnhookNtdll", "signature": "BOOL UnhookNtdll(LPVOID cleanNtdll)"}, {"kind": "function", "line": 571, "name": "MasqueradeCmdline", "signature": "void MasqueradeCmdline()"}, {"kind": "function", "line": 595, "name": "hookGetCommandLineA", "signature": "LPSTR hookGetCommandLineA(void)"}, {"kind": "function", "line": 596, "name": "hookGetCommandLineW", "signature": "LPWSTR hookGetCommandLineW(void)"}, {"kind": "function", "line": 597, "name": "hook__p___argv", "signature": "char*** __cdecl hook__p___argv(void)"}, {"kind": "function", "line": 598, "name": "hook__p___wargv", "signature": "wchar_t*** __cdecl hook__p___wargv(void)"}, {"kind": "function", "line": 599, "name": "hook__p___argc", "signature": "int* __cdecl hook__p___argc(void)"}, {"kind": "function", "line": 600, "name": "hook__getmainargs", "signature": "int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 603, "name": "hook__wgetmainargs", "signature": "int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)"}, {"kind": "function", "line": 606, "name": "hookexit", "signature": "int __cdecl hookexit(int status)"}, {"kind": "function", "line": 607, "name": "hookExitProcess", "signature": "void __stdcall hookExitProcess(UINT statuscode)"}, {"doc": "======================================================================== 10. PE LOADER WITH FLUCTUATION ========================================================================", "kind": "function", "line": 612, "name": "GetNTHeaders", "signature": "char* GetNTHeaders(char* pe_buffer)"}, {"kind": "function", "line": 623, "name": "GetPEDirectory", "signature": "IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)"}, {"kind": "function", "line": 632, "name": "RepairIAT", "signature": "BOOL RepairIAT(PVOID modulePtr)"}, {"kind": "function", "line": 694, "name": "FluctuateEncrypt", "signature": "void FluctuateEncrypt(FLUCTUATION_CTX* ctx)"}, {"kind": "function", "line": 718, "name": "FluctuateDecrypt", "signature": "void FluctuateDecrypt(FLUCTUATION_CTX* ctx)"}, {"kind": "function", "line": 749, "name": "fastTrampoline", "signature": "bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)"}, {"kind": "function", "line": 773, "name": "MySleep", "signature": "void WINAPI MySleep(DWORD ms)"}, {"doc": "Stack spoofing", "kind": "function", "line": 787, "name": "GetSpoofedReturnAddress", "signature": "ULONG_PTR GetSpoofedReturnAddress()"}, {"kind": "function", "line": 793, "name": "ExecuteWithSpoofedRet", "signature": "void ExecuteWithSpoofedRet(PVOID entry)"}, {"kind": "function", "line": 806, "name": "TimerExecCallback", "signature": "VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)"}, {"kind": "function", "line": 814, "name": "ModuleStompAndExecute", "signature": "BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)"}, {"kind": "function", "line": 913, "name": "GetData", "signature": "DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)"}, {"doc": "======================================================================== 12. SELF-DESTRUCT ========================================================================", "kind": "function", "line": 974, "name": "SelfDestruct", "signature": "void SelfDestruct()"}, {"doc": "======================================================================== 13. MAIN ========================================================================", "kind": "function", "line": 998, "name": "main", "signature": "int main(int argc, char** argv)"}, {"kind": "macro", "line": 15, "name": "WIN32_LEAN_AND_MEAN", "signature": "#define WIN32_LEAN_AND_MEAN"}, {"kind": "macro", "line": 31, "name": "_CRT_SECURE_NO_WARNINGS", "signature": "#define _CRT_SECURE_NO_WARNINGS"}, {"kind": "macro", "line": 37, "name": "DEBUG_PRINT", "signature": "#define DEBUG_PRINT(fmt, ...)"}, {"kind": "macro", "line": 39, "name": "DEBUG_PRINT", "signature": "#define DEBUG_PRINT(fmt, ...)"}, {"kind": "macro", "line": 45, "name": "OBF_KEY", "signature": "#define OBF_KEY"}, {"kind": "macro", "line": 47, "name": "OBFSTR", "signature": "#define OBFSTR(str)"}, {"kind": "macro", "line": 286, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 287, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 288, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 289, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 290, "name": "F", "signature": "#define F"}]}, {"id": "lz4.c", "kind": "module", "label": "lz4.c", "language": "c", "sha256": "4598995f68539213", "symbol_count": 28, "symbols": [{"doc": "************************************ Internal state", "kind": "struct", "line": 52, "name": "LZ4_streamDecode_t_internal"}, {"doc": "************************************ Basic Types", "kind": "type_alias", "line": 23, "name": "BYTE", "signature": "typedef uint8_t BYTE;"}, {"kind": "type_alias", "line": 24, "name": "U16", "signature": "typedef uint16_t U16;"}, {"kind": "type_alias", "line": 25, "name": "U32", "signature": "typedef uint32_t U32;"}, {"kind": "type_alias", "line": 26, "name": "S32", "signature": "typedef int32_t S32;"}, {"kind": "type_alias", "line": 27, "name": "U64", "signature": "typedef uint64_t U64;"}, {"doc": "************************************ Private functions", "kind": "function", "line": 62, "name": "LZ4_read32", "signature": "static U32 LZ4_read32(const void* ptr)"}, {"kind": "function", "line": 68, "name": "LZ4_write32", "signature": "static void LZ4_write32(void* ptr, U32 value)"}, {"kind": "function", "line": 72, "name": "LZ4_read16", "signature": "static U16 LZ4_read16(const void* ptr)"}, {"kind": "function", "line": 78, "name": "LZ4_write16", "signature": "static void LZ4_write16(void* ptr, U16 value)"}, {"kind": "function", "line": 82, "name": "LZ4_read64", "signature": "static U64 LZ4_read64(const void* ptr)"}, {"doc": "************************************ Core decompression function", "kind": "function", "line": 91, "name": "LZ4_decompress_safe", "signature": "int LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize)"}, {"kind": "function", "line": 95, "name": "LZ4_decompress_safe_usingDict", "signature": "int LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompre..."}, {"kind": "function", "line": 189, "name": "LZ4_setStreamDecode", "signature": "int LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize)"}, {"kind": "function", "line": 198, "name": "LZ4_decompress_safe_continue", "signature": "int LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize,..."}, {"kind": "function", "line": 205, "name": "LZ4_resetStreamDecode", "signature": "void LZ4_resetStreamDecode(void* streamPtr)"}, {"kind": "macro", "line": 16, "name": "LZ4_ALIGN", "signature": "#define LZ4_ALIGN(x)"}, {"kind": "macro", "line": 17, "name": "LZ4_ARCH_64", "signature": "#define LZ4_ARCH_64"}, {"kind": "macro", "line": 18, "name": "LZ4_FAST_DEC_LOOP", "signature": "#define LZ4_FAST_DEC_LOOP"}, {"kind": "macro", "line": 30, "name": "MEMORY_SANITIZER", "signature": "#  define MEMORY_SANITIZER"}, {"kind": "macro", "line": 36, "name": "LZ4_8_BIT", "signature": "#define LZ4_8_BIT"}, {"kind": "macro", "line": 37, "name": "LZ4_16_BIT", "signature": "#define LZ4_16_BIT"}, {"kind": "macro", "line": 38, "name": "LZ4_32_BIT", "signature": "#define LZ4_32_BIT"}, {"kind": "macro", "line": 39, "name": "LZ4_64_BIT", "signature": "#define LZ4_64_BIT"}, {"kind": "macro", "line": 42, "name": "LZ4_64K", "signature": "#define LZ4_64K"}, {"kind": "macro", "line": 45, "name": "LZ4_MEMORY_USAGE", "signature": "#define LZ4_MEMORY_USAGE"}, {"kind": "macro", "line": 46, "name": "LZ4_MAX_INPUT_SIZE", "signature": "#define LZ4_MAX_INPUT_SIZE"}, {"kind": "macro", "line": 47, "name": "LZ4_COMPRESSBOUND", "signature": "#define LZ4_COMPRESSBOUND(isize)"}]}, {"id": "lz4.h", "kind": "module", "label": "lz4.h", "language": "h", "sha256": "30d11d81a0b4d93e", "symbol_count": 13, "symbols": [{"doc": "! LZ4_setStreamDecode() : An LZ4_streamDecode_t context can be allocated once and re-used multiple times. Use this context to decompress multiple blocks in streaming mode. If a dictionary is provided, it will be used as the first reference for all future blocks. The dictionary pointer must remain accessible during the lifetime of the stream.", "kind": "struct", "line": 89, "name": "LZ4_streamDecode_t"}, {"kind": "function", "line": 65, "name": "LZ4_decompress_safe", "signature": "* LZ4_decompress_safe() : * compressedSize : is the exact complete size of the compressed block. * maxDecompressedSize : is the size of the destination buffer, which must be already allocated. * retur"}, {"kind": "function", "line": 90, "name": "LZ4_setStreamDecode", "signature": "LZ4_EXPORT int LZ4_setStreamDecode (void* streamPtr, const char* dictPtr, int dictSize);"}, {"kind": "function", "line": 91, "name": "LZ4_decompress_safe_continue", "signature": "LZ4_EXPORT int LZ4_decompress_safe_continue (void* streamPtr, const char* src, char* dst, int compressedSize, int maxDecompressedSize);"}, {"kind": "function", "line": 92, "name": "LZ4_resetStreamDecode", "signature": "LZ4_EXPORT void LZ4_resetStreamDecode (void* streamPtr);"}, {"kind": "macro", "line": 36, "name": "LZ4_H_2983827168210", "signature": "#define LZ4_H_2983827168210"}, {"kind": "macro", "line": 50, "name": "LZ4_EXPORT", "signature": "#    define LZ4_EXPORT"}, {"kind": "macro", "line": 52, "name": "LZ4_EXPORT", "signature": "#    define LZ4_EXPORT"}, {"kind": "macro", "line": 54, "name": "LZ4_EXPORT", "signature": "#    define LZ4_EXPORT"}, {"kind": "macro", "line": 59, "name": "LZ4_VERSION_MAJOR", "signature": "#define LZ4_VERSION_MAJOR"}, {"kind": "macro", "line": 60, "name": "LZ4_VERSION_MINOR", "signature": "#define LZ4_VERSION_MINOR"}, {"kind": "macro", "line": 61, "name": "LZ4_VERSION_RELEASE", "signature": "#define LZ4_VERSION_RELEASE"}, {"kind": "macro", "line": 62, "name": "LZ4_VERSION_NUMBER", "signature": "#define LZ4_VERSION_NUMBER"}]}, {"doc": "lzss.c – implementación de Okumura (SIN main)", "id": "lzss.c", "kind": "module", "label": "lzss.c", "language": "c", "sha256": "1d9371fee85d67e1", "symbol_count": 14, "symbols": [{"kind": "function", "line": 16, "name": "error", "signature": "static void error(void)"}, {"kind": "function", "line": 18, "name": "putbit1", "signature": "static void putbit1(void)"}, {"kind": "function", "line": 25, "name": "putbit0", "signature": "static void putbit0(void)"}, {"kind": "function", "line": 31, "name": "flush_bit_buffer", "signature": "static void flush_bit_buffer(void)"}, {"kind": "function", "line": 34, "name": "output1", "signature": "static void output1(int c)"}, {"kind": "function", "line": 39, "name": "output2", "signature": "static void output2(int x, int y)"}, {"kind": "function", "line": 46, "name": "encode", "signature": "void encode(void)"}, {"kind": "function", "line": 77, "name": "getbit", "signature": "static int getbit(int n)"}, {"kind": "function", "line": 87, "name": "decode", "signature": "void decode(void)"}, {"kind": "macro", "line": 5, "name": "EI", "signature": "#define EI"}, {"kind": "macro", "line": 6, "name": "EJ", "signature": "#define EJ"}, {"kind": "macro", "line": 7, "name": "P", "signature": "#define P"}, {"kind": "macro", "line": 8, "name": "N", "signature": "#define N"}, {"kind": "macro", "line": 9, "name": "F", "signature": "#define F"}]}, {"doc": "pack.c", "id": "pack.c", "kind": "module", "label": "pack.c", "language": "c", "sha256": "df6c175f0e4acb47", "symbol_count": 3, "symbols": [{"kind": "function", "line": 8, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "function", "line": 5, "name": "encode", "signature": "extern void encode(void);"}, {"kind": "variable", "line": 6, "name": "outfile", "signature": "extern FILE *infile, *outfile;"}]}, {"doc": "test.c – wrapper decompress Okumura", "id": "test.c", "kind": "module", "label": "test.c", "language": "c", "sha256": "a39ad18bc06f447c", "symbol_count": 3, "symbols": [{"kind": "function", "line": 9, "name": "main", "signature": "int main(void)"}, {"doc": "/* test.c – wrapper decompress Okumura #include <stdio.h> #include <stdlib.h> /* declaraciones externas de Okumura", "kind": "function", "line": 6, "name": "decode", "signature": "void decode(void);"}, {"kind": "variable", "line": 7, "name": "outfile", "signature": "extern FILE *infile, *outfile;"}]}, {"doc": "unpack.c", "id": "unpack.c", "kind": "module", "label": "unpack.c", "language": "c", "sha256": "0e76c5fd4ac48bd5", "symbol_count": 3, "symbols": [{"kind": "function", "line": 8, "name": "main", "signature": "int main(int argc, char *argv[])"}, {"kind": "function", "line": 5, "name": "decode", "signature": "extern void decode(void);"}, {"kind": "variable", "line": 6, "name": "outfile", "signature": "extern FILE *infile, *outfile;"}]}], "type": "CodePropertyGraph", "version": "1.0"}
```

---

## Architecture Reference

### C (12 files)

#### `aes.c`
**Path:** `aes.c`
**File Doc:** *aes.c - tiny-AES-c (https://github.com/kokke/tiny-AES-c)*

**Functions:**
- `getSBoxValue` (line 13) `static uint8_t getSBoxValue(uint8_t num)`
- `getSBoxInvert` (line 35) `static uint8_t getSBoxInvert(uint8_t num)`
- `Td0` (line 57) `static uint8_t Td0(int x)`
- `Td1` (line 58) `static uint8_t Td1(int x)`
- `Td2` (line 59) `static uint8_t Td2(int x)`
- `Td3` (line 60) `static uint8_t Td3(int x)`
- `Td4` (line 61) `static uint8_t Td4(int x)`
- `KeyExpansion` (line 166) `static void KeyExpansion(uint8_t* RoundKey, const uint8_t* Key)` - *This function produces Nb(Nr+1) round keys. The round keys are used in each round to decrypt the states.*
- `AES_init_ctx` (line 239) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key)`
- `AES_init_ctx_iv` (line 244) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv)` - *if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))*
- `AES_ctx_set_iv` (line 249) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv)`
- `AddRoundKey` (line 257) `static void AddRoundKey(uint8_t round, state_t* state, const uint8_t* RoundKey)` - *This function adds the round key to state. The round key is added to the state by an XOR function.*
- `SubBytes` (line 271) `static void SubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `ShiftRows` (line 286) `static void ShiftRows(state_t* state)` - *The ShiftRows() function shifts the rows in the state to the left. Each row is shifted with different offset. Offset = Row number. So the first row is not shifted.*
- `xtime` (line 314) `static uint8_t xtime(uint8_t x)`
- `MixColumns` (line 320) `static void MixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix*
- `Multiply` (line 340) `static uint8_t Multiply(uint8_t x, uint8_t y)` - *Multiply is used to multiply numbers in the field GF(2^8) Note: The last call to xtime() is unneeded, but often ends up generating a smaller binary The compiler seems to be able to vectorize the operation better this way. See https://github.com/kokke/tiny-AES-c/pull/34 if MULTIPLY_AS_A_FUNCTION*
- `InvMixColumns` (line 370) `static void InvMixColumns(state_t* state)` - *MixColumns function mixes the columns of the state matrix. The method used to multiply may be difficult to understand for the inexperienced. Please use the references to gain more information.*
- `InvSubBytes` (line 391) `static void InvSubBytes(state_t* state)` - *The SubBytes Function Substitutes the values in the state matrix with values in an S-box.*
- `InvShiftRows` (line 403) `static void InvShiftRows(state_t* state)`
- `Cipher` (line 433) `static void Cipher(state_t* state, const uint8_t* RoundKey)` - *Cipher is the main function that encrypts the PlainText.*
- `InvCipher` (line 459) `static void InvCipher(state_t* state, const uint8_t* RoundKey)` - *if (defined(CBC) && CBC == 1) || (defined(ECB) && ECB == 1)*
- `AES_ECB_encrypt` (line 490) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `AES_ECB_decrypt` (line 496) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf)`
- `XorWithIv` (line 512) `static void XorWithIv(uint8_t* buf, const uint8_t* Iv)`
- `AES_CBC_encrypt_buffer` (line 521) `void AES_CBC_encrypt_buffer(struct AES_ctx *ctx, uint8_t* buf, size_t length)`
- `AES_CBC_decrypt_buffer` (line 536) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)`
- `AES_CTR_xcrypt_buffer` (line 558) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length)` - *XorWithIv(buf, ctx->Iv); memcpy(ctx->Iv, storeNextIv, AES_BLOCKLEN); buf += AES_BLOCKLEN; } } #endif // #if defined(CBC) && (CBC == 1) #if defined(CTR) && (CTR == 1) /* Symmetrical operation: same function for encrypting as for decrypting. Note any IV/nonce should never be reused with the same key*

**Macros:**
- `Nb` (line 5) `#define Nb`
- `KEYLEN_256` (line 9) `#define KEYLEN_256`
- `RKLENGTH` (line 10) `#define RKLENGTH`
- `BLOCKLEN` (line 11) `#define BLOCKLEN`
- `Nb` (line 67) `#define Nb`
- `Nk` (line 70) `#define Nk`
- `Nr` (line 71) `#define Nr`
- `Nk` (line 73) `#define Nk`
- `Nr` (line 74) `#define Nr`
- `Nk` (line 76) `#define Nk`
- `Nr` (line 77) `#define Nr`
- `MULTIPLY_AS_A_FUNCTION` (line 84) `#define MULTIPLY_AS_A_FUNCTION`
- `getSBoxValue` (line 163) `#define getSBoxValue(num)`
- `Multiply` (line 349) `#define Multiply(x, y)`
- `getSBoxInvert` (line 365) `#define getSBoxInvert(num)`

#### `loader.c`
**Path:** `loader.c`

**Functions:**
- `read_bit` (line 64) `static int read_bit(BitReader* br)`
- `read_bits` (line 75) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 85) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `hookGetCommandLineW` (line 217) `LPWSTR hookGetCommandLineW()` - *Implementación de hooks*
- `hookGetCommandLineA` (line 218) `LPSTR hookGetCommandLineA()`
- `hook__p___argv` (line 219) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 220) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 221) `int* __cdecl hook__p___argc(void)`
- `anti_analysis` (line 226) `BOOL anti_analysis()` - *=== ANTI-ANALYSIS ===*
- `selfDestruct` (line 251) `void selfDestruct()` - *Puff*
- `hook__wgetmainargs` (line 307) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hook__getmainargs` (line 313) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 319) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 324) `void __stdcall hookExitProcess(UINT statuscode)`
- `masqueradeCmdline` (line 328) `void masqueradeCmdline()`
- `freeargvA` (line 366) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 374) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 382) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 394) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 404) `BOOL RepairIAT(PVOID modulePtr)`
- `_stricmp` (line 458) `_stricmp(func_name, "exit") == 0 ||
                    _stricmp(func_name, "_Exit") == 0 ||
    ...`
- `RunPE` (line 479) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 485) `void PELoader(char* data, DWORD datasize)`
- `getNtdll` (line 559) `LPVOID getNtdll()`
- `Unhook` (line 602) `BOOL Unhook(LPVOID cleanNtdll)`
- `DecryptAES` (line 638) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `GetData` (line 671) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 792) `int main(int argc, char** argv)`

**Macros:**
- `_CRT_RAND_S` (line 19) `#define _CRT_RAND_S`
- `NT_SUCCESS` (line 30) `#define NT_SUCCESS(Status)`
- `NtCurrentThread` (line 33) `#define NtCurrentThread()`
- `NtCurrentProcess` (line 34) `#define NtCurrentProcess()`
- `_CRT_SECURE_NO_WARNINGS` (line 37) `#define _CRT_SECURE_NO_WARNINGS`
- `EI` (line 52) `#define EI`
- `EJ` (line 53) `#define EJ`
- `P` (line 54) `#define P`
- `N` (line 55) `#define N`
- `F` (line 56) `#define F`

**Structs:**
- `_BASE_RELOCATION_ENTRY` (line 41)
- `DATA` (line 46)
- `BitReader` (line 58)

**Type_Aliases:**
- `NTSTATUS` (line 38) `typedef LONG NTSTATUS;` - *pragma warning(disable: 4996) define _CRT_SECURE_NO_WARNINGS*
- `12` (line 40) `typedef struct _BASE_RELOCATION_ENTRY { WORD Offset : 12;`

#### `loader2.c`
**Path:** `loader2.c`
**File Doc:** *=== DECLARACIONES DE HOOKS ===*

**Functions:**
- `read_bit` (line 52) `static int read_bit(BitReader* br)`
- `read_bits` (line 61) `static int read_bits(BitReader* br, int n)`
- `DecryptAES` (line 71) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 183) `static inline UPTR get_return_address(void)`
- `xor32` (line 187) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 195) `bool isShellcodeThread(LPVOID addr)` - *Verifica si la dirección está dentro de .text*
- `shellcodeEncryptDecrypt` (line 206) `void shellcodeEncryptDecrypt(LPVOID caller)` - *Fluctuación: encripta/desencripta SOLO .text*
- `MySleep` (line 246) `static void WINAPI MySleep(DWORD ms)` - *Hook de Sleep: ya NO inicializa fluctuación (se hace en PELoader)*
- `fastTrampoline` (line 262) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 303) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `lzss_decode_mem` (line 324) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `masqueradeCmdline` (line 388) `void masqueradeCmdline()`
- `GetNTHeaders` (line 419) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 430) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 439) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 490) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 491) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 492) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 493) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 494) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 495) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 498) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookExitProcess` (line 501) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 503) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 509) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 597) `BOOL anti_analysis()`
- `selfDestruct` (line 618) `void selfDestruct()`
- `GetData` (line 647) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)`
- `main` (line 732) `int main(int argc, char** argv)`
- `freeargvA` (line 169) `void freeargvA(char** array, int Argc);`
- `freeargvW` (line 170) `void freeargvW(wchar_t** array, int Argc);`

**Macros:**
- `_CRT_RAND_S` (line 1) `#define _CRT_RAND_S`
- `WIN32_LEAN_AND_MEAN` (line 2) `#define WIN32_LEAN_AND_MEAN`
- `_CRT_SECURE_NO_WARNINGS` (line 26) `#define _CRT_SECURE_NO_WARNINGS`
- `NT_SUCCESS` (line 29) `#define NT_SUCCESS(Status)`
- `NtCurrentThread` (line 32) `#define NtCurrentThread()`
- `NtCurrentProcess` (line 33) `#define NtCurrentProcess()`
- `WIN32_LEAN_AND_MEAN` (line 35) `#define WIN32_LEAN_AND_MEAN`
- `UNICODE` (line 36) `#define UNICODE`
- `_UNICODE` (line 37) `#define _UNICODE`
- `EI` (line 40) `#define EI`
- `EJ` (line 41) `#define EJ`
- `P` (line 42) `#define P`
- `N` (line 43) `#define N`
- `F` (line 44) `#define F`
- `log` (line 154) `#define log(...)`

**Structs:**
- `BitReader` (line 46)
- `FluctuationMetadata` (line 111)
- `HookTrampolineBuffers` (line 119)
- `HookedSleep` (line 129)
- `DATA` (line 134)

**Type_Aliases:**
- `UPTR` (line 100) `typedef UINT64 UPTR;` - *ifdef _WIN64*
- `UPTR` (line 102) `typedef UINT32 UPTR;` - *else*

#### `loader3.c`
**Path:** `loader3.c`

**Functions:**
- `read_bit` (line 64) `static int read_bit(BitReader* br)`
- `read_bits` (line 73) `static int read_bits(BitReader* br, int n)`
- `lzss_decode_mem` (line 83) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `DecryptAES` (line 139) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 238) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 242) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 249) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 258) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 292) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 306) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 342) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 360) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 390) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 398) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 406) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 417) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 426) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 478) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 479) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 480) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 481) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 482) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 483) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 486) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 489) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 493) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 497) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 503) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 581) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 602) `void selfDestruct()`
- `getNtdll` (line 629) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 665) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 689) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 757) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 16) `#define _CRT_RAND_S`
- `WIN32_LEAN_AND_MEAN` (line 17) `#define WIN32_LEAN_AND_MEAN`
- `_CRT_SECURE_NO_WARNINGS` (line 42) `#define _CRT_SECURE_NO_WARNINGS`
- `NT_SUCCESS` (line 45) `#define NT_SUCCESS(Status)`
- `NtCurrentThread` (line 48) `#define NtCurrentThread()`
- `NtCurrentProcess` (line 49) `#define NtCurrentProcess()`
- `EI` (line 52) `#define EI`
- `EJ` (line 53) `#define EJ`
- `P` (line 54) `#define P`
- `N` (line 55) `#define N`
- `F` (line 56) `#define F`
- `log` (line 214) `#define log(...)`

**Structs:**
- `BitReader` (line 58)
- `FluctuationMetadata` (line 174)
- `HookTrampolineBuffers` (line 182)
- `HookedSleep` (line 192)
- `DATA` (line 197)

**Type_Aliases:**
- `UPTR` (line 163) `typedef UINT64 UPTR;` - *================== TYPEDEFS & STRUCTS ================== ifdef _WIN64*
- `UPTR` (line 165) `typedef UINT32 UPTR;` - *else*

#### `loader4.c`
**Path:** `loader4.c`

**Functions:**
- `read_bit` (line 104) `static int read_bit(BitReader* br)`
- `read_bits` (line 113) `static int read_bits(BitReader* br, int n)`
- `deobf` (line 124) `void deobf(const char* src, char* dst, size_t max_len)` - *Helper para desofuscar*
- `SetHWBP_NtContinue` (line 132) `BOOL SetHWBP_NtContinue(PVOID targetAddr, DWORD index)`
- `lzss_decode_mem` (line 163) `BOOL lzss_decode_mem(const unsigned char* input, size_t input_size, unsigned char** output, size_...`
- `PatchETW` (line 219) `BOOL PatchETW()`
- `DecryptAES` (line 252) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)`
- `get_return_address` (line 351) `static inline UPTR get_return_address(void)` - *================== FLUCTUATION IMPLEMENTATION ==================*
- `xor32` (line 355) `void xor32(uint8_t *buf, SIZE_T sz, uint32_t key)`
- `isShellcodeThread` (line 362) `bool isShellcodeThread(LPVOID addr)`
- `shellcodeEncryptDecrypt` (line 371) `void shellcodeEncryptDecrypt(LPVOID caller)`
- `MySleep` (line 405) `static void WINAPI MySleep(DWORD ms)`
- `fastTrampoline` (line 419) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `VEHHandler` (line 458) `LONG NTAPI VEHHandler(PEXCEPTION_POINTERS xp)`
- `masqueradeCmdline` (line 476) `void masqueradeCmdline()` - *================== PE LOADER ==================*
- `freeargvA` (line 506) `void freeargvA(char** array, int Argc)`
- `freeargvW` (line 514) `void freeargvW(wchar_t** array, int Argc)`
- `GetNTHeaders` (line 522) `char* GetNTHeaders(char* pe_buffer)`
- `GetPEDirectory` (line 533) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 542) `BOOL RepairIAT(PVOID modulePtr)`
- `hookGetCommandLineA` (line 594) `LPSTR hookGetCommandLineA()` - *Hooks*
- `hookGetCommandLineW` (line 595) `LPWSTR hookGetCommandLineW()`
- `hook__p___argv` (line 596) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 597) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 598) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 599) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 602) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 605) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 609) `void __stdcall hookExitProcess(UINT statuscode)`
- `RunPE` (line 613) `DWORD WINAPI RunPE(LPVOID lpParameter)`
- `PELoader` (line 619) `void PELoader(char* data, DWORD datasize)`
- `anti_analysis` (line 699) `BOOL anti_analysis()` - *================== ANTI-ANALYSIS & CLEANUP ==================*
- `selfDestruct` (line 720) `void selfDestruct()`
- `getNtdll` (line 747) `LPVOID getNtdll()` - *================== UNHOOKING ==================*
- `Unhook` (line 785) `BOOL Unhook(LPVOID cleanNtdll)`
- `GetData` (line 811) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource)` - *================== NETWORK ==================*
- `main` (line 879) `int main(int argc, char** argv)` - *================== MAIN ==================*

**Macros:**
- `_CRT_RAND_S` (line 16) `#define _CRT_RAND_S`
- `WIN32_LEAN_AND_MEAN` (line 17) `#define WIN32_LEAN_AND_MEAN`
- `XK` (line 42) `#define XK`
- `_CRT_SECURE_NO_WARNINGS` (line 52) `#define _CRT_SECURE_NO_WARNINGS`
- `NT_SUCCESS` (line 55) `#define NT_SUCCESS(Status)`
- `NtCurrentThread` (line 58) `#define NtCurrentThread()`
- `NtCurrentProcess` (line 59) `#define NtCurrentProcess()`
- `EI` (line 62) `#define EI`
- `EJ` (line 63) `#define EJ`
- `P` (line 64) `#define P`
- `N` (line 65) `#define N`
- `F` (line 66) `#define F`
- `OBFUSCATE_KEY` (line 69) `#define OBFUSCATE_KEY`
- `OBFSTR` (line 72) `#define OBFSTR(str)`
- `OBFSTRW` (line 85) `#define OBFSTRW(str)`
- `log` (line 327) `#define log(...)`

**Structs:**
- `BitReader` (line 98)
- `FluctuationMetadata` (line 287)
- `HookTrampolineBuffers` (line 295)
- `HookedSleep` (line 305)
- `DATA` (line 310)

**Type_Aliases:**
- `UPTR` (line 276) `typedef UINT64 UPTR;` - *================== TYPEDEFS & STRUCTS ================== ifdef _WIN64*
- `UPTR` (line 278) `typedef UINT32 UPTR;` - *else*

#### `loader5.c`
**Path:** `loader5.c`

**Functions:**
- `HellGate` (line 65) `BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)`
- `NtAllocateVirtualMemory_indirect` (line 86) `static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...`
- `NtProtectVirtualMemory_indirect` (line 106) `static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...`
- `NtWriteVirtualMemory_indirect` (line 126) `static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...`
- `NtFlushInstructionCache_indirect` (line 146) `static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...`
- `NtClose_indirect` (line 166) `static NTSTATUS NtClose_indirect(HANDLE Handle)`
- `NtOpenSection_indirect` (line 185) `static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...`
- `NtMapViewOfSection_indirect` (line 205) `static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...`
- `NtUnmapViewOfSection_indirect` (line 226) `static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)`
- `NtFreeVirtualMemory_indirect` (line 246) `static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...`
- `decompress_payload` (line 271) `BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz...` - *======================================================================== 4.  COMPRESIÓN: LZSS (por defecto) ======================================================================== ifdef USE_LZ4 include "lz4.h"*
- `read_bit` (line 296) `static int read_bit(BitReader* br)`
- `read_bits` (line 305) `static int read_bits(BitReader* br, int n)`
- `decompress_payload` (line 315) `BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si...`
- `DecryptAES` (line 375) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` - *======================================================================== 5.  CRYPTO (AES-256-CBC con CryptoAPI directa) ========================================================================*
- `IsDebuggerPresentEx` (line 396) `BOOL IsDebuggerPresentEx()` - *======================================================================== 6.  ANTIDEBUG / ANTIANALYSIS ========================================================================*
- `HasHWBreakpoints` (line 400) `BOOL HasHWBreakpoints()`
- `IsDomainJoined` (line 407) `BOOL IsDomainJoined()`
- `HasRealGPU` (line 416) `BOOL HasRealGPU()`
- `HasUserActivity` (line 434) `BOOL HasUserActivity()`
- `IsSandbox` (line 443) `BOOL IsSandbox()`
- `PatchAmsiViaStomping` (line 478) `BOOL PatchAmsiViaStomping()` - *======================================================================== 7.  AMSI BYPASS (module stomping) ========================================================================*
- `getCleanNtdllViaKnownDlls` (line 510) `LPVOID getCleanNtdllViaKnownDlls()` - *======================================================================== 8.  UNHOOKING ntdll (KnownDlls) ========================================================================*
- `UnhookNtdll` (line 535) `BOOL UnhookNtdll(LPVOID cleanNtdll)`
- `MasqueradeCmdline` (line 568) `void MasqueradeCmdline()`
- `hookGetCommandLineA` (line 592) `LPSTR hookGetCommandLineA(void)`
- `hookGetCommandLineW` (line 593) `LPWSTR hookGetCommandLineW(void)`
- `hook__p___argv` (line 594) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 595) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 596) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 597) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 600) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 603) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 604) `void __stdcall hookExitProcess(UINT statuscode)`
- `GetNTHeaders` (line 609) `char* GetNTHeaders(char* pe_buffer)` - *======================================================================== 10. PE LOADER WITH FLUCTUATION ========================================================================*
- `GetPEDirectory` (line 620) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 629) `BOOL RepairIAT(PVOID modulePtr)`
- `FluctuateEncrypt` (line 691) `void FluctuateEncrypt(FLUCTUATION_CTX* ctx)`
- `FluctuateDecrypt` (line 715) `void FluctuateDecrypt(FLUCTUATION_CTX* ctx)`
- `fastTrampoline` (line 746) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `MySleep` (line 770) `void WINAPI MySleep(DWORD ms)`
- `GetSpoofedReturnAddress` (line 784) `ULONG_PTR GetSpoofedReturnAddress()` - *Stack spoofing*
- `ExecuteWithSpoofedRet` (line 790) `void ExecuteWithSpoofedRet(PVOID entry)`
- `TimerExecCallback` (line 803) `VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)`
- `ModuleStompAndExecute` (line 810) `BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)`
- `GetData` (line 909) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)`
- `SelfDestruct` (line 971) `void SelfDestruct()` - *======================================================================== 12. SELF-DESTRUCT ========================================================================*
- `main` (line 995) `int main(int argc, char** argv)` - *======================================================================== 13. MAIN ========================================================================*

**Macros:**
- `WIN32_LEAN_AND_MEAN` (line 14) `#define WIN32_LEAN_AND_MEAN`
- `_CRT_SECURE_NO_WARNINGS` (line 29) `#define _CRT_SECURE_NO_WARNINGS`
- `DEBUG_PRINT` (line 35) `#define DEBUG_PRINT(fmt, ...)`
- `DEBUG_PRINT` (line 37) `#define DEBUG_PRINT(fmt, ...)`
- `OBF_KEY` (line 43) `#define OBF_KEY`
- `OBFSTR` (line 45) `#define OBFSTR(str)`
- `EI` (line 284) `#define EI`
- `EJ` (line 285) `#define EJ`
- `P` (line 286) `#define P`
- `N` (line 287) `#define N`
- `F` (line 288) `#define F`

**Structs:**
- `SYSCALL_ENTRY` (line 60) - *======================================================================== 3.  SYSCALLS (Hell's Gate + indirect) ========================================================================*
- `BitReader` (line 290)
- `EXEC_CTX` (line 675) - *Estructuras para ejecución y fluctuación*
- `FLUCTUATION_CTX` (line 679)
- `HookTrampolineBuffers` (line 739)
- `DATA` (line 904) - *======================================================================== 11. NETWORK DOWNLOAD ========================================================================*

#### `loader6.c`
**Path:** `loader6.c`

**Functions:**
- `HellGate` (line 67) `BOOL HellGate(PCSTR funcName, SYSCALL_ENTRY* entry)`
- `NtAllocateVirtualMemory_indirect` (line 88) `static NTSTATUS NtAllocateVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, ULONG_...`
- `NtProtectVirtualMemory_indirect` (line 108) `static NTSTATUS NtProtectVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T...`
- `NtWriteVirtualMemory_indirect` (line 128) `static NTSTATUS NtWriteVirtualMemory_indirect(HANDLE ProcessHandle, PVOID BaseAddress, PVOID Buff...`
- `NtFlushInstructionCache_indirect` (line 148) `static NTSTATUS NtFlushInstructionCache_indirect(HANDLE ProcessHandle, PVOID BaseAddress, SIZE_T ...`
- `NtClose_indirect` (line 168) `static NTSTATUS NtClose_indirect(HANDLE Handle)`
- `NtOpenSection_indirect` (line 187) `static NTSTATUS NtOpenSection_indirect(PHANDLE SectionHandle, ACCESS_MASK DesiredAccess, POBJECT_...`
- `NtMapViewOfSection_indirect` (line 207) `static NTSTATUS NtMapViewOfSection_indirect(HANDLE SectionHandle, HANDLE ProcessHandle, PVOID* Ba...`
- `NtUnmapViewOfSection_indirect` (line 228) `static NTSTATUS NtUnmapViewOfSection_indirect(HANDLE ProcessHandle, PVOID BaseAddress)`
- `NtFreeVirtualMemory_indirect` (line 248) `static NTSTATUS NtFreeVirtualMemory_indirect(HANDLE ProcessHandle, PVOID* BaseAddress, PSIZE_T Re...`
- `decompress_payload` (line 273) `BOOL decompress_payload(const unsigned char* input, size_t inputSize, unsigned char** output, siz...` - *======================================================================== 4.  COMPRESIÓN: LZSS (por defecto) o LZ4 (si se define USE_LZ4) ======================================================================== ifdef USE_LZ4 include "lz4.h"*
- `read_bit` (line 298) `static int read_bit(BitReader* br)`
- `read_bits` (line 307) `static int read_bits(BitReader* br, int n)`
- `decompress_payload` (line 317) `BOOL decompress_payload(const unsigned char* input, size_t input_size, unsigned char** output, si...`
- `DecryptAES` (line 377) `void DecryptAES(char* data, DWORD* pDataLen, char* key, DWORD keyLen)` - *======================================================================== 5.  CRYPTO (AES-256-CBC con CryptoAPI directa) ========================================================================*
- `IsDebuggerPresentEx` (line 398) `BOOL IsDebuggerPresentEx()` - *======================================================================== 6.  ANTIDEBUG / ANTIANALYSIS ========================================================================*
- `HasHWBreakpoints` (line 402) `BOOL HasHWBreakpoints()`
- `IsDomainJoined` (line 409) `BOOL IsDomainJoined()`
- `HasRealGPU` (line 418) `BOOL HasRealGPU()`
- `HasUserActivity` (line 436) `BOOL HasUserActivity()`
- `IsSandbox` (line 445) `BOOL IsSandbox()`
- `PatchAmsiViaStomping` (line 479) `BOOL PatchAmsiViaStomping()` - *======================================================================== 7.  AMSI BYPASS (module stomping) - usando syscall para permisos ========================================================================*
- `getCleanNtdllViaKnownDlls` (line 512) `LPVOID getCleanNtdllViaKnownDlls()` - *======================================================================== 8.  UNHOOKING ntdll (KnownDlls) - usando syscall para permisos ========================================================================*
- `UnhookNtdll` (line 537) `BOOL UnhookNtdll(LPVOID cleanNtdll)`
- `MasqueradeCmdline` (line 571) `void MasqueradeCmdline()`
- `hookGetCommandLineA` (line 595) `LPSTR hookGetCommandLineA(void)`
- `hookGetCommandLineW` (line 596) `LPWSTR hookGetCommandLineW(void)`
- `hook__p___argv` (line 597) `char*** __cdecl hook__p___argv(void)`
- `hook__p___wargv` (line 598) `wchar_t*** __cdecl hook__p___wargv(void)`
- `hook__p___argc` (line 599) `int* __cdecl hook__p___argc(void)`
- `hook__getmainargs` (line 600) `int hook__getmainargs(int* _Argc, char*** _Argv, char*** _Env, int _useless_, void* _useless)`
- `hook__wgetmainargs` (line 603) `int hook__wgetmainargs(int* _Argc, wchar_t*** _Argv, wchar_t*** _Env, int _useless_, void* _useless)`
- `hookexit` (line 606) `int __cdecl hookexit(int status)`
- `hookExitProcess` (line 607) `void __stdcall hookExitProcess(UINT statuscode)`
- `GetNTHeaders` (line 612) `char* GetNTHeaders(char* pe_buffer)` - *======================================================================== 10. PE LOADER WITH FLUCTUATION ========================================================================*
- `GetPEDirectory` (line 623) `IMAGE_DATA_DIRECTORY* GetPEDirectory(PVOID pe_buffer, size_t dir_id)`
- `RepairIAT` (line 632) `BOOL RepairIAT(PVOID modulePtr)`
- `FluctuateEncrypt` (line 694) `void FluctuateEncrypt(FLUCTUATION_CTX* ctx)`
- `FluctuateDecrypt` (line 718) `void FluctuateDecrypt(FLUCTUATION_CTX* ctx)`
- `fastTrampoline` (line 749) `bool fastTrampoline(bool install, BYTE *target, LPVOID jump, HookTrampolineBuffers *b)`
- `MySleep` (line 773) `void WINAPI MySleep(DWORD ms)`
- `GetSpoofedReturnAddress` (line 787) `ULONG_PTR GetSpoofedReturnAddress()` - *Stack spoofing*
- `ExecuteWithSpoofedRet` (line 793) `void ExecuteWithSpoofedRet(PVOID entry)`
- `TimerExecCallback` (line 806) `VOID CALLBACK TimerExecCallback(PVOID lpParam, BOOLEAN TimerOrWaitFired)`
- `ModuleStompAndExecute` (line 814) `BOOL ModuleStompAndExecute(PVOID shellcode, SIZE_T shellcodeSize, int fluctMode)`
- `GetData` (line 913) `DATA GetData(wchar_t* whost, DWORD port, wchar_t* wresource, wchar_t* userAgent)`
- `SelfDestruct` (line 974) `void SelfDestruct()` - *======================================================================== 12. SELF-DESTRUCT ========================================================================*
- `main` (line 998) `int main(int argc, char** argv)` - *======================================================================== 13. MAIN ========================================================================*

**Macros:**
- `WIN32_LEAN_AND_MEAN` (line 15) `#define WIN32_LEAN_AND_MEAN`
- `_CRT_SECURE_NO_WARNINGS` (line 31) `#define _CRT_SECURE_NO_WARNINGS`
- `DEBUG_PRINT` (line 37) `#define DEBUG_PRINT(fmt, ...)`
- `DEBUG_PRINT` (line 39) `#define DEBUG_PRINT(fmt, ...)`
- `OBF_KEY` (line 45) `#define OBF_KEY`
- `OBFSTR` (line 47) `#define OBFSTR(str)`
- `EI` (line 286) `#define EI`
- `EJ` (line 287) `#define EJ`
- `P` (line 288) `#define P`
- `N` (line 289) `#define N`
- `F` (line 290) `#define F`

**Structs:**
- `SYSCALL_ENTRY` (line 62) - *======================================================================== 3.  SYSCALLS (Hell's Gate + indirect) ========================================================================*
- `BitReader` (line 292)
- `EXEC_CTX` (line 678) - *Estructuras para ejecución y fluctuación*
- `FLUCTUATION_CTX` (line 682)
- `HookTrampolineBuffers` (line 742)
- `DATA` (line 908) - *======================================================================== 11. NETWORK DOWNLOAD ========================================================================*

#### `lz4.c`
**Path:** `lz4.c`

**Functions:**
- `LZ4_read32` (line 62) `static U32 LZ4_read32(const void* ptr)` - ************************************* Private functions*
- `LZ4_write32` (line 68) `static void LZ4_write32(void* ptr, U32 value)`
- `LZ4_read16` (line 72) `static U16 LZ4_read16(const void* ptr)`
- `LZ4_write16` (line 78) `static void LZ4_write16(void* ptr, U16 value)`
- `LZ4_read64` (line 82) `static U64 LZ4_read64(const void* ptr)`
- `LZ4_decompress_safe` (line 91) `int LZ4_decompress_safe(const char* src, char* dst, int compressedSize, int maxDecompressedSize)` - ************************************* Core decompression function*
- `LZ4_decompress_safe_usingDict` (line 95) `int LZ4_decompress_safe_usingDict(const char* src, char* dst, int compressedSize, int maxDecompre...`
- `LZ4_setStreamDecode` (line 189) `int LZ4_setStreamDecode(void* streamPtr, const char* dictPtr, int dictSize)`
- `LZ4_decompress_safe_continue` (line 198) `int LZ4_decompress_safe_continue(void* streamPtr, const char* src, char* dst, int compressedSize,...`
- `LZ4_resetStreamDecode` (line 205) `void LZ4_resetStreamDecode(void* streamPtr)`

**Macros:**
- `LZ4_ALIGN` (line 16) `#define LZ4_ALIGN(x)`
- `LZ4_ARCH_64` (line 17) `#define LZ4_ARCH_64`
- `LZ4_FAST_DEC_LOOP` (line 18) `#define LZ4_FAST_DEC_LOOP`
- `MEMORY_SANITIZER` (line 30) `#  define MEMORY_SANITIZER`
- `LZ4_8_BIT` (line 36) `#define LZ4_8_BIT`
- `LZ4_16_BIT` (line 37) `#define LZ4_16_BIT`
- `LZ4_32_BIT` (line 38) `#define LZ4_32_BIT`
- `LZ4_64_BIT` (line 39) `#define LZ4_64_BIT`
- `LZ4_64K` (line 42) `#define LZ4_64K`
- `LZ4_MEMORY_USAGE` (line 45) `#define LZ4_MEMORY_USAGE`
- `LZ4_MAX_INPUT_SIZE` (line 46) `#define LZ4_MAX_INPUT_SIZE`
- `LZ4_COMPRESSBOUND` (line 47) `#define LZ4_COMPRESSBOUND(isize)`

**Structs:**
- `LZ4_streamDecode_t_internal` (line 52) - ************************************* Internal state*

**Type_Aliases:**
- `BYTE` (line 23) `typedef uint8_t BYTE;` - ************************************* Basic Types*
- `U16` (line 24) `typedef uint16_t U16;`
- `U32` (line 25) `typedef uint32_t U32;`
- `S32` (line 26) `typedef int32_t S32;`
- `U64` (line 27) `typedef uint64_t U64;`

#### `lzss.c`
**Path:** `lzss.c`
**File Doc:** *lzss.c – implementación de Okumura (SIN main)*

**Functions:**
- `error` (line 16) `static void error(void)`
- `putbit1` (line 18) `static void putbit1(void)`
- `putbit0` (line 25) `static void putbit0(void)`
- `flush_bit_buffer` (line 31) `static void flush_bit_buffer(void)`
- `output1` (line 34) `static void output1(int c)`
- `output2` (line 39) `static void output2(int x, int y)`
- `encode` (line 46) `void encode(void)`
- `getbit` (line 77) `static int getbit(int n)`
- `decode` (line 87) `void decode(void)`

**Macros:**
- `EI` (line 5) `#define EI`
- `EJ` (line 6) `#define EJ`
- `P` (line 7) `#define P`
- `N` (line 8) `#define N`
- `F` (line 9) `#define F`

#### `pack.c`
**Path:** `pack.c`
**File Doc:** *pack.c*

**Functions:**
- `main` (line 8) `int main(int argc, char *argv[])`
- `encode` (line 5) `extern void encode(void);`

**Variables:**
- `outfile` (line 6) `extern FILE *infile, *outfile;`

#### `test.c`
**Path:** `test.c`
**File Doc:** *test.c – wrapper decompress Okumura*

**Functions:**
- `main` (line 9) `int main(void)`
- `decode` (line 6) `void decode(void);` - */* test.c – wrapper decompress Okumura #include <stdio.h> #include <stdlib.h> /* declaraciones externas de Okumura*

**Variables:**
- `outfile` (line 7) `extern FILE *infile, *outfile;`

#### `unpack.c`
**Path:** `unpack.c`
**File Doc:** *unpack.c*

**Functions:**
- `main` (line 8) `int main(int argc, char *argv[])`
- `decode` (line 5) `extern void decode(void);`

**Variables:**
- `outfile` (line 6) `extern FILE *infile, *outfile;`

### H (2 files)

#### `aes.h`
**Path:** `aes.h`
**File Doc:** *#define the macros below to 1/0 to enable/disable the mode of operation.*

**Imported by:** `aes.c`

**Functions:**
- `AES_init_ctx` (line 41) `void AES_init_ctx(struct AES_ctx* ctx, const uint8_t* key);`
- `AES_init_ctx_iv` (line 43) `void AES_init_ctx_iv(struct AES_ctx* ctx, const uint8_t* key, const uint8_t* iv);` - *if (defined(CBC) && (CBC == 1)) || (defined(CTR) && (CTR == 1))*
- `AES_ctx_set_iv` (line 44) `void AES_ctx_set_iv(struct AES_ctx* ctx, const uint8_t* iv);`
- `AES_ECB_encrypt` (line 48) `void AES_ECB_encrypt(const struct AES_ctx* ctx, uint8_t* buf);` - *if defined(ECB) && (ECB == 1)*
- `AES_ECB_decrypt` (line 49) `void AES_ECB_decrypt(const struct AES_ctx* ctx, uint8_t* buf);`
- `AES_CBC_encrypt_buffer` (line 53) `void AES_CBC_encrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` - *if defined(CBC) && (CBC == 1)*
- `AES_CBC_decrypt_buffer` (line 54) `void AES_CBC_decrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);`
- `AES_CTR_xcrypt_buffer` (line 58) `void AES_CTR_xcrypt_buffer(struct AES_ctx* ctx, uint8_t* buf, size_t length);` - *if defined(CTR) && (CTR == 1)*

**Macros:**
- `_AES_H_` (line 2) `#define _AES_H_`
- `CBC` (line 9) `#define CBC`
- `ECB` (line 12) `#define ECB`
- `CTR` (line 15) `#define CTR`
- `AES256` (line 18) `#define AES256`
- `AES_BLOCKLEN` (line 20) `#define AES_BLOCKLEN`
- `AES_KEYLEN` (line 23) `#define AES_KEYLEN`
- `AES_keyExpSize` (line 24) `#define AES_keyExpSize`
- `AES_KEYLEN` (line 26) `#define AES_KEYLEN`
- `AES_keyExpSize` (line 27) `#define AES_keyExpSize`
- `AES_KEYLEN` (line 29) `#define AES_KEYLEN`
- `AES_keyExpSize` (line 30) `#define AES_keyExpSize`

**Structs:**
- `AES_ctx` (line 33)

#### `lz4.h`
**Path:** `lz4.h`

**Imported by:** `loader5.c`, `loader6.c`, `lz4.c`

**Functions:**
- `LZ4_decompress_safe` (line 65) `* LZ4_decompress_safe() : * compressedSize : is the exact complete size of the compressed block. * maxDecompressedSize : is the size of the destination buffer, which must be already allocated. * retur`
- `LZ4_setStreamDecode` (line 90) `LZ4_EXPORT int LZ4_setStreamDecode (void* streamPtr, const char* dictPtr, int dictSize);`
- `LZ4_decompress_safe_continue` (line 91) `LZ4_EXPORT int LZ4_decompress_safe_continue (void* streamPtr, const char* src, char* dst, int compressedSize, int maxDecompressedSize);`
- `LZ4_resetStreamDecode` (line 92) `LZ4_EXPORT void LZ4_resetStreamDecode (void* streamPtr);`

**Macros:**
- `LZ4_H_2983827168210` (line 36) `#define LZ4_H_2983827168210`
- `LZ4_EXPORT` (line 50) `#    define LZ4_EXPORT`
- `LZ4_EXPORT` (line 52) `#    define LZ4_EXPORT`
- `LZ4_EXPORT` (line 54) `#    define LZ4_EXPORT`
- `LZ4_VERSION_MAJOR` (line 59) `#define LZ4_VERSION_MAJOR`
- `LZ4_VERSION_MINOR` (line 60) `#define LZ4_VERSION_MINOR`
- `LZ4_VERSION_RELEASE` (line 61) `#define LZ4_VERSION_RELEASE`
- `LZ4_VERSION_NUMBER` (line 62) `#define LZ4_VERSION_NUMBER`

**Structs:**
- `LZ4_streamDecode_t` (line 89) - *! LZ4_setStreamDecode() : An LZ4_streamDecode_t context can be allocated once and re-used multiple times. Use this context to decompress multiple blocks in streaming mode. If a dictionary is provided, it will be used as the first reference for all future blocks. The dictionary pointer must remain accessible during the lifetime of the stream.*

### PY (2 files)

#### `app.py`
**Path:** `app.py`
**File Doc:** *app.py  Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:*

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
