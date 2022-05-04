#include <stdio.h>
#include <stdlib.h>
#define MLEN 100

int input(int **a, int n1, int n2);
void output(int **a, int n1, int n2);
int C1(); int C2(); int C3(); int C4();
int main_part(int **a, int n1, int n2);

int main() {
    char dummy;
    int flag = 0, n;
    if (scanf("%d%c", &n, &dummy) == 2 && dummy == '\n' && n > 0 && n < 5) {
        switch (n) {
            case 1: flag = C1(); break;
            case 2: flag = C2(); break;
            case 3: flag = C3(); break;
            case 4: flag = C4(); break;
        }
    } else {
        flag = 1;
    }
    if (flag)
        printf("n/a");
    return flag;
}

int input(int **a, int n1, int n2) {
    char dummy;
    int flag = 0;
    for (int i = 0; i < n1; i++) if (!flag) {
        for (int j = 0; j < n2; j++) if (!flag) {
            if (j < n2 - 1) {
                if (scanf("%d%c", &a[i][j], &dummy) != 1 && dummy != ' ') {
                    flag = 1;
                }
            } else {
                if (scanf("%d%c", &a[i][j], &dummy) != 2 || dummy != '\n') {
                    flag = 1;
                }
            }
        }
    }
    return flag;
}

void output(int **a, int n1, int n2) {
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (j != n2 - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int size_input(int *n1, int *n2) {
    int flag = 0;
    char dummy;
    if (scanf("%d%c", n1, &dummy) != 2
            || (dummy != '\n' && dummy != ' ')
            || *n1 <= 0) {
                flag = 1;
            }
    if (!flag) {
        if (scanf("%d%c", n2, &dummy) != 2
                || (dummy != '\n' && dummy != ' ')
                || *n2 <= 0) {
                    flag = 1;
                }
    }
    return flag;
}

int C1() {
    int flag = 0, n1, n2;
    flag = size_input(&n1, &n2);
    if (!flag) {
        if (n1 < MLEN && n2 < MLEN) {
            int *pointers[MLEN];
            int data[MLEN * MLEN];
            for (int i = 0; i < MLEN; i++) {
                pointers[i] = data + i * MLEN;
            }
            flag = main_part(pointers, n1, n2);
        } else {
            flag = 1;
        }
    }
    return flag;
}

int C2() {
    int flag = 0, n1, n2;
    flag = size_input(&n1, &n2);
    if (!flag) {
        if (n1 < MLEN && n2 < MLEN) {
            int **data = malloc(n1 * sizeof(int*));
            for (int i = 0; i < n1; i++)
                data[i] = malloc(n2 + sizeof(int));
            flag = main_part(data, n1, n2);
            free(data);
        } else {
            flag = 1;
        }
    }
    return flag;
}

int C3() {
    int flag = 0, n1, n2;
    flag = size_input(&n1, &n2);
    if (!flag) {
        if (n1 < MLEN && n2 < MLEN) {
            int **pointers = malloc(n1 * sizeof(int*));
            int *data = malloc(n2 * n1 * sizeof(int));
            for (int i = 0; i < n1; i++) {
                pointers[i] = data + i * n2;
            }
            flag = main_part(pointers, n1, n2);
            free(pointers);
            free(data);
        } else {
            flag = 1;
        }
    }
    return flag;
}

int C4() {
    int flag = 0, n1, n2;
    flag = size_input(&n1, &n2);
    if (!flag) {
        if (n1 < MLEN && n2 < MLEN) {
            int **buffer = malloc(n1 * sizeof(int*) + n1 * n2 * sizeof(int));
            for (int i = 0; i < n1; i++)
                buffer[i] = (int*)buffer + n1 * (sizeof(int**)) + i * n2;
            flag = main_part(buffer, n1, n2);
            free(buffer);
        } else {
            flag = 1;
        }
    }
    return flag;
}

int main_part(int **a, int n1, int n2) {
    int flag = 0;
    flag = input(a, n1, n2);
    if (!flag)
        output(a, n1, n2);
    return flag;
}
