/* test.c – wrapper decompress Okumura */
#include <stdio.h>
#include <stdlib.h>

/* declaraciones externas de Okumura */
void decode(void);
extern FILE *infile, *outfile;

int main(void)
{
    infile  = fopen("mimikatz.lzss", "rb");
    if (!infile)  { perror("fopen mimikatz.lzss"); return 1; }
    outfile = fopen("test.exe", "wb");
    if (!outfile) { perror("fopen test.exe"); fclose(infile); return 1; }

    decode();                       /* llama a Okumura */
    fclose(infile);
    fclose(outfile);
    printf("LZSS OK: decompressed -> test.exe\n");
    return 0;
}