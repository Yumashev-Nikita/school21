#include <stdio.h>
#include <stdlib.h>
#include "file.h"

void foutput(FILE* fp) {
    data* date = bitR(fp);
    while (date != NULL) {
        doutput(date);
        date = bitR(fp);
    }
    rewind(fp);
    free(date);
}

data* bitR(FILE* fp) {
    data* date = malloc(sizeof(data));
    if (!fread(date, sizeof(data), 1, fp)) {
        free(date);
        date = NULL;
    }
    return date;
}

int fcount(FILE* fp) {
    int i = 0;
    while (bitR(fp))
        i++;
    rewind(fp);
    return i;
}

void fsort(FILE* fp) {
    int count = fcount(fp);
    for (int i = 1; i <= count; i++) {
        fseek(fp, sizeof(data) * i, SEEK_SET);
        for (int j = i - 1; j > 0; j--) {
            fseek(fp, sizeof(data) * j, SEEK_SET);       data* date1 = bitR(fp);
            fseek(fp, sizeof(data) * (j - 1), SEEK_SET); data* date2 = bitR(fp);
            if (dcmp(date1, date2)) {
                fseek(fp, sizeof(data) * (j - 1), SEEK_SET);
                fwrite(date1, sizeof(data), 1, fp);
                fseek(fp, sizeof(data) * j, SEEK_SET);
                fwrite(date2, sizeof(data), 1, fp);
            }
            free(date1); free(date2);
        }
    }
    rewind(fp);
}
