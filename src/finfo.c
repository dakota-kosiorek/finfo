#include <stdio.h>
#include <stdlib.h>

// get newline, word, character, and byte counts for each file

int main(int argc, char *argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; ++i) {
            unsigned int bCount = 0;
            unsigned int nlCount = 0;
            unsigned int cCount = 0;
            unsigned int wCount = 0;
            int inWord = 0;

            if (i >= 2) printf("\n");

            FILE* fptr;
            fptr = fopen(argv[i], "r");
            
            if (fptr == NULL) {
                printf("Could not open the file '%s'\n", argv[i]);
                exit(EXIT_FAILURE);
            }

            fseek(fptr, 0, SEEK_END);
            bCount = ftell(fptr);
            fseek(fptr, 0, SEEK_SET);

            int c;
            while ( (c = getc(fptr)) != EOF ) {
                if (c == '\n') ++nlCount;
                else if (c != '\r') ++cCount;

                if (c != '\n' && c != '\r' && c != ' ' && inWord == 0) {
                    inWord = 1;
                    ++wCount;
                } else if (c == '\n' || c == '\r' || c == ' ') {
                    inWord = 0;
                }
            }

            printf("-- %s --\n", argv[i]);
            printf("Bytes: %u\nNewlines: %u\nCharacters: %u\nWords: %u\n", bCount, nlCount, cCount, wCount);
        }
    } else {
        printf("Additional file name argument required\n");
    }

    return 0;
}