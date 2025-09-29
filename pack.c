/* pack.c */
#include <stdio.h>
#include <stdlib.h>

extern void encode(void);
extern FILE *infile, *outfile;

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <input.exe> <output.lzss>\n", argv[0]);
        return 1;
    }
    infile = fopen(argv[1], "rb");
    if (!infile) { perror("fopen in"); return 1; }
    outfile = fopen(argv[2], "wb");
    if (!outfile) { perror("fopen out"); fclose(infile); return 1; }

    encode();
    fclose(infile);
    fclose(outfile);
    return 0;
}