#include <stdio.h>
#include "file.h"

void foutput(FILE* F) {
    if (F != NULL) {
        char symb = fgetc(F);
        while (symb != -1) {
            printf("%c", symb);
            symb = fgetc(F);
        }
    } else {
        printf("n/a");
    }
    printf("\n");
}

void fcipher(FILE *FROM, FILE *TO, int shift) {
    if (FROM != NULL && TO != NULL) {
        char symb = fgetc(FROM);
        while (symb != -1) {
            if (((symb >= 65 && symb <= 90) || (symb >= 97 && symb <= 122)) &&
                    (symb + shift < 127 && symb + shift > 31)) {
                symb += shift;
            }
            fprintf(TO, "%c", symb);
            symb = fgetc(FROM);
        }
    } else {
        printf("n/a");
    }
}
