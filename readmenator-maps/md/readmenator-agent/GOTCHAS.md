# Gotchas

## God Nodes (high connectivity)

These files have the most connections. Changes here have high blast radius.

- `loader5.c` (score: 8.50)
- `loader6.c` (score: 8.50)
- `lz4.h` (score: 7.30, imported by 3 files)
- `aes.c` (score: 6.30)
- `loader4.c` (score: 6.00)
- `loader2.c` (score: 5.30)
- `loader3.c` (score: 5.30)
- `lz4.c` (score: 4.80)
- `loader.c` (score: 4.30)
- `aes.h` (score: 4.10, imported by 1 files)

## Blast Radius (change impact)

Editing these files can break the listed number of dependents. Run their tests after any change.

- `lz4.h` -- 3 direct, 3 total dependents
- `aes.h` -- 1 direct, 1 total dependents

## Hotspots (complexity + centrality)

- `loader6.c` -- complexity: 1.0, centrality: 1.0, combined: 1.0
- `loader5.c` -- complexity: 1.0, centrality: 0.9, combined: 1.0
- `loader4.c` -- complexity: 0.9, centrality: 0.7, combined: 0.8
- `loader2.c` -- complexity: 0.8, centrality: 0.7, combined: 0.8
- `loader3.c` -- complexity: 0.8, centrality: 0.7, combined: 0.8
- `loader.c` -- complexity: 0.7, centrality: 0.5, combined: 0.6
- `aes.c` -- complexity: 0.7, centrality: 0.2, combined: 0.4
- `lz4.c` -- complexity: 0.4, centrality: 0.3, combined: 0.4
- `lz4.h` -- complexity: 0.2, centrality: 0.5, combined: 0.4
- `aes.h` -- complexity: 0.3, centrality: 0.3, combined: 0.3

## Dataflow Issues (INFERRED, review each lead)

- `loader.c:809` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader.c:813` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader2.c:766` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader2.c:770` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader3.c:809` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader3.c:812` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader4.c:938` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader4.c:941` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
- `loader5.c:1030` `main` [UNCHECKED_ALLOC] `whost`: Result of allocator stored in `whost` is never checked against NULL.
- `loader5.c:1033` `main` [UNCHECKED_ALLOC] `wresource`: Result of allocator stored in `wresource` is never checked against NULL.
