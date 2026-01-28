#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: cat <filename>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "r");
    if (!f) {
        perror("cat");
        return 1;
    }

    char ch;
    while ((ch = fgetc(f)) != EOF) {
        putchar(ch);
    }

    fclose(f);
    return 0;
}
