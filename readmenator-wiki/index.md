# Second Brain

*Last synthesized: 2026-10-16 | 17 files | 3 concept pages | offline, zero tokens*

> Raw sources -> readmenator wiki -> links (Karpathy LLM Wiki Pattern, deterministic).
> Start here, then open one community page. Prefer grep over full reads.

## Vault Overview

The codebase centres on `loader5.c`, `loader6.c`, `lz4.h`. Architecturally it is 2 layers, dominant utility (16 files) across 3 import-based communities. Recorded risk surface: 0 security findings and 0 dependency cycles.

Surprising tissue lives between root: loader5, root: aes, orphans: 0 extracted cross-community imports and 3 inferred bridges. Follow `connections.json` sorted by strength before refactoring.

Open work clusters around documentation (47% file coverage), 0 security findings, 0 taint paths, and 5 suggested exploration questions in `queries.md`.

## Stats

| Metric | Value |
|--------|-------|
| Files | 17 |
| Symbols | 470 |
| Resolved imports | 4 |
| Languages | c, h, py, sh |
| Communities | 3 |
| Doc coverage | 47% (8/17 files) |
| Security findings | 0 |
| Estimated read cost | ~3930 tokens (chars/4, offline so $0) |

## Reading Order

1. Skim Stats and God Nodes below for blast radius.
2. Open the largest community page first, then follow Connections.
3. Use `queries.md` for the next question; log the answer there.

```
grep -rn '<keyword>' index.md community_*.md
readmenator query "<question>" --target CompressLoader
```

## Concept Wiki

- [root: loader5 (4 files, cohesion 1.00)](./community_0_root_loader5.md)
- [root: aes (2 files, cohesion 1.00)](./community_1_root_aes.md)
- [orphans (11 files, cohesion 0.00)](./community_2_orphans.md)

## God Nodes

| File | Score |
|------|-------|
| `loader5.c` | 8.5 |
| `loader6.c` | 8.5 |
| `lz4.h` | 7.3 |
| `aes.c` | 6.3 |
| `loader4.c` | 6.0 |

## Strongest Connections

- 0 -> 1: shares_context (strength 0.5, INFERRED)
- 0 -> 2: shares_context (strength 0.5, INFERRED)
- 1 -> 2: shares_context (strength 0.5, INFERRED)

## Navigation Tips

- Obsidian Graph View works: every community page links back here.
- `connections.json` is machine-readable for GraphRAG pipelines.
- `REPORT.md` states what was extracted vs inferred and current limits.
- Regenerate offline: `readmenator . --rebuild` (no network, no tokens).
