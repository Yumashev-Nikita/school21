#include <stdio.h>
#include <string.h>

void encode();
void decode();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        if (strcmp(argv[1], "1") == 0) {
            decode();
        } else if (strcmp(argv[1], "0") == 0) {
            encode();
        } else {
            printf("n/a");
        }
    } else {
        printf("n/a");
    }
    return 0;
}

void encode() {
    char line[255];
    int ps = 0, size = 0;
    do {
        scanf("%c", line + ps);
        ps++;
        size++;
    }while (getc(stdin) != '\n');
    for (int i = 0; i < size; i++) {
        printf("%X ", line[i]);
    }
}

void decode() {
    int line[255];
    int ps = 0, size = 0;
    do {
        scanf("%X", line + ps);
        ps++;
        size++;
    }while (getc(stdin) != '\n');
    for (int i = 0; i < size; i++) {
        printf("%c ", line[i]);
    }
}
