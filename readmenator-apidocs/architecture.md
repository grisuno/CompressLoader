# CompressLoader Architecture and Execution Flows

[Back to index](index.md)

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
