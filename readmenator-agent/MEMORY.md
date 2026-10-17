# Project Memory

> Cross-session context for agents. Sections 1-6 are regenerated from the source tree with zero LLM tokens: declared rules are quoted verbatim with `file:line`, measured baselines come from the scan. Section 7 is written by agents and humans and is preserved across rebuilds.

Generated from 17 files at commit `54dc72204474`. Read this first, then `readmenator-wiki/index.md`, then `readmenator . ask "<question>"` for anything specific.

## 1. Purpose and domain

- What it is: Download, decrypt, decompress, and reflectively load Windows PE payloads entirely in memory. (`README.md:3`)
- Domain vocabulary (term, files): `decode` (9), `aes` (8), `bit` (8), `decrypt` (8), `get` (7), `encrypt` (7), `lzss` (7), `hook` (6), `command` (6), `data` (6), `line` (6), `read` (6), `crt` (6), `process` (6), `destruct` (6)
- Subsystem `root: loader5`: 4 files, core `loader5.c`: EXEC_CTX: Estructuras para ejecución y fluctuación
- Subsystem `root: aes`: 2 files, core `aes.c`: tiny-AES-c (https://github.com/kokke/tiny-AES-c)
- Business rules that the code cannot show live in section 7: record them there.

## 2. Workflow

Detected commands:
- `make all` (Makefile)
- `make info` (Makefile)
- `make help` (Makefile)
- `make config` (Makefile)
- `make pack-tools` (Makefile)
- `make pack` (Makefile)
- `make unpack` (Makefile)
- `make lzss-test` (Makefile)
- `make loaders` (Makefile)
- `make test` (Makefile)
- `make payload` (Makefile)
- `make install` (Makefile)

Session protocol:
1. Start: read this file, then `readmenator . fresh` (exit 1 means run `readmenator . --rebuild`).
2. Orient: `readmenator-wiki/index.md`; for a question use `readmenator . ask "<question>"` (local = entities + sources, `--global` = community reports).
3. Before editing a file: `grep -n '<file>' readmenator-agent/GOTCHAS.md readmenator-agent/SECURITY.md`.
4. After the change: run the tests above, then `readmenator . --rebuild` so the maps, wiki, and this file stay true.
5. End: record decisions, business rules, and gotchas with `readmenator . remember "<note>" --kind decision`.

## 3. Rules and constraints

Declared:
- none declared in instruction files (add them to AGENTS.md or record them in section 7)

Measured baseline:
- Security findings at medium or above: 0 (see `readmenator-agent/SECURITY.md`); do not add new ones.
- Dependency cycles: 0; layer violations: 0 (see `readmenator-agent/GOTCHAS.md`).

## 4. Style norms

Declared:
- none declared in instruction files (add them to AGENTS.md or record them in section 7)

Measured baseline:
- c: 12 files, 433 symbols; docstrings on 16% of symbols; functions snake_case (21%); types PascalCase (74%); median file 822 lines, max 1085.
- h: 2 files, 34 symbols; docstrings on 15% of symbols; functions snake_case (0%); types PascalCase (0%); median file 98 lines, max 98.
- py: 2 files, 3 symbols; docstrings on 33% of symbols; functions snake_case (67%); median file 98 lines, max 98.
- sh: 1 files, 0 symbols; median file 9 lines, max 9.

## 5. Minimum deliverables

Declared:
- none declared in instruction files (add them to AGENTS.md or record them in section 7)

Measured baseline:
- Tests pass: `make lzss-test`.
- Docstring coverage stays at or above 16%.
- No new security findings at medium or above (current: 0).
- No new dependency cycles (current: 0).
- Files stay under 300 lines where possible (`readmenator . lint`).
- Docs refreshed: `readmenator . --rebuild`, and decisions recorded in section 7.

## 6. Risks to respect

- God nodes (changes ripple widely): `loader5.c`, `loader6.c`, `lz4.h`, `aes.c`, `loader4.c`
- Hotspots (complex and central): `loader6.c`, `loader5.c`, `loader4.c`, `loader2.c`, `loader3.c`
- Full blast radius: `readmenator-agent/GOTCHAS.md`; findings: `readmenator-agent/SECURITY.md`.

## 7. Session log (preserved across rebuilds)

Append with `readmenator . remember "<note>" --kind <kind>` (kinds: business, decision, rule, workflow, style, deliverable, gotcha, todo, note) or the MCP tool `readmenator.remember`. Record business rules, decisions and their reasons, workflow changes, and anything the next session must not rediscover.

<!-- readmenator:memory:notes:begin -->
<!-- readmenator:memory:notes:end -->
