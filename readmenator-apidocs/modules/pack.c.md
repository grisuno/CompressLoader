# `pack.c`

> Source: [pack.c:1](../../pack.c#L1) | language `c` | coverage 33.3% | [API index](../index.md)

pack.c

## Contents

- **Functions:** [`encode`](#encode), [`main`](#main)
- **Variables:** [`outfile`](#outfile)

## Call Graph

Solid arrows stay in this module, dashed arrows leave it.

```mermaid
flowchart LR
    n_pack_c__main(["main"])
    n_pack_c__encode(["encode"])
    n_pack_c__main --> n_pack_c__encode
```

## Functions

<a id="encode"></a>

### `encode`

`function` `extern` | [pack.c:5](../../pack.c#L5)

```c
extern void encode(void);
```

*Called by:* [`main`](#main)

---

<a id="main"></a>

### `main`

`function` | [pack.c:8](../../pack.c#L8)

```c
int main(int argc, char *argv[])
```

**Parameters**

| Name | Type | Default | Description |
|---|---|---|---|
| `argc` | `int` |  |  |
| `argv` | `char * []` |  |  |

**Returns:** `int`

*Calls:* [`encode`](#encode)

---

## Variables

<a id="outfile"></a>

### `outfile`

`variable` `extern` | [pack.c:6](../../pack.c#L6)

```c
extern FILE *infile, *outfile;
```

---
