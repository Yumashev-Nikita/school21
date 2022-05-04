#include <stdio.h>
#include <time.h>
#include "print_module.h"

void print_log(char (*print)(char), char* message) {
    char log[] = Log_prefix;
    for (char *ch = log; *ch; ch++)
        print(*ch);
    print(' ');

    time_t t; struct tm * timeinfo;
    time(&t); timeinfo = localtime(&t);
    printf("%02d:%02d:%02d ", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    while (*message) {
        print(*message);
        message++;
    }
}

char print_char(char ch) {
    return putchar(ch);
}
