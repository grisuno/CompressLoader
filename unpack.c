/* unpack.c */
#include <stdio.h>
#include <stdlib.h>

extern void decode(void);
extern FILE *infile, *outfile;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.lzss> <output.exe>\n", argv[0]);
        return 1;
    }
    infile = fopen(argv[1], "rb");
    if (!infile) { perror("fopen in"); return 1; }
    outfile = fopen(argv[2], "wb");
    if (!outfile) { perror("fopen out"); fclose(infile); return 1; }

    decode();
    fclose(infile);
    fclose(outfile);
    printf("Decompressed to %s\n", argv[2]);
    return 0;
}