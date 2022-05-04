#include <stdio.h>
#include "./io_module/io.h"
#include "./file_module/file.h"
#include "./log_module/logger.h"

void Q1();
void C1(int *n_prev, int *flag, FILE** F, FILE** LOG_FILE);
void C2(int *n_prev, int *flag, FILE** F, FILE** LOG_FILE);
void C3(int *n_prev, int *flag);

int main() {
    Q1();
    return 0;
}

void Q1() {
    int flag = 0, n_prev = 0;
    FILE *F, *LOG_FILE;
    LOG_FILE = log_init("./logs/LOGS");
    #ifdef DEBUG_
    logcat("LOG_INIT\n", info, LOG_FILE);
    #endif  //  DEBUG_ break;
    while (flag == 0) {
        int n; char dummy;
        scanf("%d%c", &n, &dummy);
        switch (n) {
            case 1: C1(&n_prev, &flag, &F, &LOG_FILE);  break;
            case 2: C2(&n_prev, &flag, &F, &LOG_FILE);  break;
            case 3: C3(&n_prev, &flag);                 break;
            case -1: flag = 1;                          break;
            default: flag = 2;                          break;
        }
    }
    log_close(LOG_FILE);
    #ifdef DEBUG_
    logcat("CLOSED LOG_FILE\n", info, LOG_FILE);
    #endif  //  DEBUG_ break;
    fclose(F);
    #ifdef DEBUG_
    logcat("CLOSED FILE\n", info, LOG_FILE);
    #endif  //  DEBUG_ break;
    #ifdef DEBUG_
    if (flag == 1)
        logcat("EXIT WITH CODE -1\n", info, LOG_FILE);
    #endif  //  DEBUG_ break;
    if (flag == 2) {
        #ifdef DEBUG_
        logcat("EXIT WITH CODE 2\n", error, LOG_FILE);
        #endif  //  DEBUG_ break;
        printf("n/a");
    }
}

void C1(int *n_prev, int *flag, FILE** F, FILE** LOG_FILE) {
    #ifdef DEBUG_
    logcat("C1()\n", info, *LOG_FILE);
    #endif  //  DEBUG_
    int Sk = _SIZE_; char line[Sk];
    input(line);
    #ifdef DEBUG_
    logcat("OPENED FILE\n", info, *LOG_FILE);
    #endif  //  DEBUG_
    *F = fopen(line, "r+t");
    if (*F == NULL) {
        #ifdef DEBUG_
        logcat("FILE NOT FOUND\n", error, *LOG_FILE);
        #endif  //  DEBUG_
        *flag = 2;
    } else {
        #ifdef DEBUG_
        logcat("FILE OUTPUT\n", info, *LOG_FILE);
        #endif  //  DEBUG_
        foutput(*F);
        *n_prev = 1;
    }
}

void C2(int *n_prev, int *flag, FILE** F, FILE** LOG_FILE) {
    #ifdef DEBUG_
    logcat("C2()\n", info, *LOG_FILE);
    #endif  //  DEBUG_
    if (*n_prev == 1) {
        int Sk = _SIZE_; char line[Sk];
        input(line);
        fprintf(*F, "\n%s", line);
        #ifdef DEBUG_
        logcat("FILE REWIND\n", info, *LOG_FILE);
        #endif  //  DEBUG_
        rewind(*F);
        #ifdef DEBUG_
        logcat("FILE OUTPUT\n", info, *LOG_FILE);
        #endif  //  DEBUG_
        foutput(*F);
    } else {
        *flag = 2;
    }
}

void C3(int *n_prev, int *flag) {
    fclose(fopen("ai_modules/m1.h", "w+"));
    fclose(fopen("ai_modules/m2.h", "w+"));
    FILE* F1 = fopen("ai_modules/m1.c", "rt");
    FILE* F2 = fopen("ai_modules/m2.c", "rt");
    FILE* F3 = fopen("ai_modules/m1_c.c", "a+");
    FILE* F4 = fopen("ai_modules/m2_c.c", "a+");
    int shift = 0; char dummy;
    scanf("%d%c", &shift, &dummy);
    fcipher(F1, F3, shift); fcipher(F2, F4, shift);
    remove("ai_modules/m1.c"); remove("ai_modules/m2.c");
    rename("ai_modules/m1_c.c", "ai_modules/m1.c");
    rename("ai_modules/m2_c.c", "ai_modules/m2.c");
    fclose(F1); fclose(F2); fclose(F3); fclose(F4);
}
