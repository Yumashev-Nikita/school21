#include <stdio.h>
#include <stdlib.h>
#include "./file/file.h"
#include "./data/data.h"
#include "./io/io.h"

int C0(char path[_SIZE_]);
int C1(char path[_SIZE_]);
int C2(char path[_SIZE_]);

int main() {
    int flag = 0;
    int Sk = _SIZE_; char path[Sk];
    input(path);
    int n = 0; char dummy;
    scanf("%d%c", &n, &dummy);
    switch (n) {
        case 0:  flag = C0(path); break;
        case 1:  flag = C1(path); break;
        case 2:  flag = C2(path); break;
        default: flag = 1;        break;
    }
    if (flag)
        printf("n/a");
    return flag;
}

int C0(char path[_SIZE_]) {
    int flag = 0;
    FILE *fp = fopen(path, "r+b");
    if (fp != NULL) {
        foutput(fp);
        fclose(fp);
    } else {
        flag = 1;
    }
    return flag;
}

int C1(char path[_SIZE_]) {
    int flag = 0;
    FILE *fp = fopen(path, "r+b");
    if (fp != NULL) {
        fsort(fp);
        foutput(fp);
        fclose(fp);
    } else {
        flag = 1;
    }
    return flag;
}

int C2(char path[_SIZE_]) {
    int flag = 0;
    FILE *fp = fopen(path, "r+b");
    if (fp != NULL) {
        int Sk = _SIZE_; char line[Sk];
        input(line);
        FILE* dummy = fopen("dummy", "r+b");
        int n;
        while (nstrtol(line, ' ', 10)) {
            fwrite(line, sizeof(int), _SIZE_, dummy);
        }
        // rewind(dummy);
        // data* date = bitR(dummy);
        // doutput(date);
        fclose(fp);
        fclose(dummy);
        remove("dummy");
    } else {
        flag = 1;
    }
    return flag;
}
