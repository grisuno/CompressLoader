# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `aes.c` (score: 6.30)
- `loader4.c` (score: 6.00)
- `loader2.c` (score: 5.30)
- `loader3.c` (score: 5.30)
- `loader.c` (score: 4.30)
- `aes.h` (score: 4.10, imported by 1 files)
- `lzss.c` (score: 1.40)
- `crypter.py` (score: 0.30)
- `pack.c` (score: 0.30)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `aes.h` -- 1 direct, 1 total dependents

## Hotspots (complexity + centrality)

- `loader4.c` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `loader2.c` -- complexity: 0.9, centrality: 1.0, combined: 1.0
- `loader3.c` -- complexity: 0.9, centrality: 1.0, combined: 1.0
- `loader.c` -- complexity: 0.7, centrality: 0.7, combined: 0.7
- `aes.c` -- complexity: 0.7, centrality: 0.3, combined: 0.5
- `aes.h` -- complexity: 0.3, centrality: 0.4, combined: 0.4
- `crypter.py` -- complexity: 0.1, centrality: 0.5, combined: 0.3
- `lzss.c` -- complexity: 0.2, centrality: 0.2, combined: 0.2
- `pack.c` -- complexity: 0.1, centrality: 0.2, combined: 0.1
- `unpack.c` -- complexity: 0.1, centrality: 0.2, combined: 0.1

## Dataflow Issues (INFERRED, review each lead)

- `loader.c:809` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader.c:813` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader2.c:766` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader2.c:770` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader3.c:809` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader3.c:812` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader4.c:938` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader4.c:941` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
