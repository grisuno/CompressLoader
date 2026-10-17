# GraphRAG Community Reports

Entities: 556 | Relationships: 907 | Communities: 3 | Themes: 0 | Text units: 477

Query with `readmenator . ask "<question>"` (local: BM25 + Personalized PageRank; global: map-reduce over these reports) or the MCP tool `readmenator.graphrag`.

## Project overview (`root`, root, rating 7.0)

17 files in 3 communities. Highest-impact communities: unassigned files (7.0), root: loader5 (4.2), root: aes (1.8). God nodes: loader5.c, loader6.c, lz4.h, aes.c, loader4.c.

- [unassigned files] rating 7.0: `app.py` ranks 1 by PageRank, 0 importers, 0 symbols: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:
- [root: loader5] rating 4.2: `lz4.h` ranks 1 by PageRank, 3 importers, 13 symbols: LZ4_streamDecode_t: !
- [root: aes] rating 1.8: `aes.h` ranks 1 by PageRank, 1 importers, 21 symbols: #define the macros below to 1/0 to enable/disable the mode of operation.
- Key entities: file:loader4.c, file:loader3.c, file:loader6.c, file:loader5.c, file:aes.c, file:aes.h
- Children: c0, c1, c2
- Root rating = highest community rating.

## unassigned files (`c2`, community, rating 7.0)

11 files under root (c 8, py 2, sh 1), mostly utility. Core file app.py (PageRank 0.0490, imported by 0 files): Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción: Key abstractions: AESencrypt, change_ext, main, DATA, BitReader, NT_SUCCESS.

- `app.py` ranks 1 by PageRank, 0 importers, 0 symbols: Autor: Gris Iscomeback Correo electrónico: grisiscomeback[at]gmail[dot]com Fecha de creación: xx/xx/xxxx Licencia: GPL v3  Descripción:
- `crypter.py` ranks 2 by PageRank, 0 importers, 3 symbols: change_ext: Reemplaza la extensión del archivo por una nueva (sin el punto).
- `install.sh` ranks 3 by PageRank, 0 importers, 0 symbols.
- Hotspot `loader4.c`: 60 symbols, 11 connections (score 0.81).
- Hotspot `loader2.c`: 53 symbols, 11 connections (score 0.77).
- Dataflow: 8 INFERRED issues (first: UNCHECKED_ALLOC in main).
- Key entities: file:loader4.c, file:loader3.c, file:loader2.c, file:loader.c, file:lzss.c, file:crypter.py, file:test.c, file:unpack.c
- Rating 7.0/10 = 7 x PageRank share 1.00 + 3 x risk 0.00. Internal imports: 0.

## root: loader5 (`c0`, community, rating 4.2)

4 files under root (c 3, h 1), mostly utility. Core file lz4.h (PageRank 0.1740, imported by 3 files): LZ4_streamDecode_t: ! Key abstractions: LZ4_streamDecode_t, LZ4_H_2983827168210, LZ4_EXPORT, LZ4_EXPORT, LZ4_EXPORT, LZ4_VERSION_MAJOR.

- `lz4.h` ranks 1 by PageRank, 3 importers, 13 symbols: LZ4_streamDecode_t: !
- `loader5.c` ranks 2 by PageRank, 0 importers, 65 symbols: EXEC_CTX: Estructuras para ejecución y fluctuación
- `loader6.c` ranks 3 by PageRank, 0 importers, 65 symbols: EXEC_CTX: Estructuras para ejecución y fluctuación
- Hotspot `loader6.c`: 65 symbols, 15 connections (score 1.00).
- Hotspot `loader5.c`: 65 symbols, 14 connections (score 0.96).
- Dataflow: 4 INFERRED issues (first: UNCHECKED_ALLOC in main).
- Key entities: file:loader6.c, file:loader5.c, file:lz4.c, file:lz4.h, sym:lz4.c::BYTE@23, sym:lz4.c::LZ4_16_BIT@37, sym:lz4.c::LZ4_32_BIT@38, sym:lz4.c::LZ4_64K@42
- Rating 4.2/10 = 7 x PageRank share 0.60 + 3 x risk 0.00. Internal imports: 3.

## root: aes (`c1`, community, rating 1.8)

2 files under root (c 1, h 1), mostly utility. Core file aes.h (PageRank 0.0907, imported by 1 files): #define the macros below to 1/0 to enable/disable the mode of operation. Key abstractions: AES_ctx, CBC, ECB, CTR, AES256, AES_BLOCKLEN.

- `aes.h` ranks 1 by PageRank, 1 importers, 21 symbols: #define the macros below to 1/0 to enable/disable the mode of operation.
- `aes.c` ranks 2 by PageRank, 0 importers, 43 symbols: tiny-AES-c (https://github.com/kokke/tiny-AES-c)
- Hotspot `aes.c`: 43 symbols, 3 connections (score 0.38).
- Hotspot `aes.h`: 21 symbols, 4 connections (score 0.29).
- Key entities: file:aes.c, file:aes.h, sym:aes.c::AES_CBC_decrypt_buffer@536, sym:aes.c::AES_CBC_encrypt_buffer@521, sym:aes.c::AES_CTR_xcrypt_buffer@558, sym:aes.c::AES_ECB_decrypt@496, sym:aes.c::AES_ECB_encrypt@490, sym:aes.c::AES_ctx_set_iv@249
- Rating 1.8/10 = 7 x PageRank share 0.26 + 3 x risk 0.00. Internal imports: 1.
