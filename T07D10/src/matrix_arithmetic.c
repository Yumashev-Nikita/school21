#include <stdio.h>
#include <stdlib.h>
#define MLEN 100

int input(int **a, int n, int m);
void output(int **a, int n, int m);
void sum(int **a1, int **a2, int **res, int n, int m);
void mul(int **a1, int **a2, int **res, int n1, int m1, int m2);
void transpose(int **a, int**res, int n, int m);
int res_calc(int **a1, int **a2, int I, int J, int m1);
int size_input(int *n, int *m);
int C1(); int C2(); int C3();

int main() {
    char dummy;
    int flag = 0, n;
    if (scanf("%d%c", &n, &dummy) == 2 && dummy == '\n' && n > 0 && n < 4) {
        switch (n) {
            case 1: flag = C1(); break;
            case 2: flag = C2(); break;
            case 3: flag = C3(); break;
        }
    } else {
        flag = 1;
    }
    if (flag)
        printf("n/a");
    return flag;
}

int input(int **a, int n, int m) {
    // printf("input()\n");
    char dummy;
    int flag = 0;
    for (int i = 0; i < n; i++) if (!flag) {
        for (int j = 0; j < m; j++) if (!flag) {
            if (j < m - 1) {
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

void output(int **a, int n, int m) {
    // printf("output()\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j != m - 1)
                printf("%d ", a[i][j]);
            else
                printf("%d", a[i][j]);
        }
        printf("\n");
    }
}

int size_input(int *n, int *m) {
    // printf("size_input()\n");
    int flag = 0;
    char dummy;
    if (scanf("%d%c", n, &dummy) != 2
            || (dummy != '\n' && dummy != ' ')
            || *n <= 0
            || *n > MLEN) {
                flag = 1;
            }
    if (!flag) {
        if (scanf("%d%c", m, &dummy) != 2
                || (dummy != '\n' && dummy != ' ')
                || *m <= 0
                || *m > MLEN) {
                    flag = 1;
                }
    }
    return flag;
}

int C1() {
    // printf("C1()\n");
    int flag = 0, n1, n2, m1, m2;
    flag = size_input(&n1, &m1);
    if (!flag) {
        int **pointers_1 = malloc(n1 * sizeof(int*));
        int *data_1 = malloc(m1 * n1 * sizeof(int));
        for (int i = 0; i < n1; i++) {
            pointers_1[i] = data_1 + i * m1;
        }
        flag = input(pointers_1, n1, m1);
        if (!flag) {
            flag = size_input(&n2, &m2);
            if (!flag && n1 == n2 && m1 == m2) {
                int **pointers_2 = malloc(n2 * sizeof(int*));
                int *data_2 = malloc(m2 * n2 * sizeof(int));
                for (int i = 0; i < n2; i++) {
                    pointers_2[i] = data_2 + i * m2;
                }
                input(pointers_2, n2, m2);
                int **res = malloc(n1 * sizeof(int*));
                int *data_res = malloc(m1 * n1 * sizeof(int));
                for (int i = 0; i < n1; i++) {
                    res[i] = data_res + i * m1;
                }
                sum(pointers_1, pointers_2, res, n1, m1);
                output(res, n1, m1);
                free(pointers_1); free(data_1);
                free(pointers_2); free(data_2);
                free(res);        free(data_res);
            }
        }
    }
    return flag;
}

int C2() {
    // printf("C2()\n");
    int flag = 0, n1, n2, m1, m2;
    flag = size_input(&n1, &m1);
    if (!flag) {
        int **pointers_1 = malloc(n1 * sizeof(int*));
        int *data_1 = malloc(m1 * n1 * sizeof(int));
        for (int i = 0; i < n1; i++) {
            pointers_1[i] = data_1 + i * m1;
        }
        flag = input(pointers_1, n1, m1);
        if (!flag) {
            flag = size_input(&n2, &m2);
            if (!flag && m1 == n2) {
                int **pointers_2 = malloc(n2 * sizeof(int*));
                int *data_2 = malloc(m2 * n2 * sizeof(int));
                for (int i = 0; i < n2; i++) {
                    pointers_2[i] = data_2 + i * m2;
                }
                flag = input(pointers_2, n2, m2);
                if (!flag) {
                    int **res = malloc(n1 * sizeof(int*));
                    int *data_res = malloc(m2 * n1 * sizeof(int));
                    for (int i = 0; i < n1; i++) {
                        res[i] = data_res + i * m1;
                    }
                    mul(pointers_1, pointers_2, res, n1, m1, m2);
                    output(res, n1, m1);
                    free(res); free(data_res);
                }
                free(pointers_1); free(data_1);
                free(pointers_2); free(data_2);
            }
        }
    }
    return flag;
}

int C3() {
    // printf("C3()\n");
    int flag = 0, n, m;
    flag = size_input(&n, &m);
    if (!flag) {
        int **pointers = malloc(n * sizeof(int*));
        int *data = malloc(m * n * sizeof(int));
        int **res = malloc(m * sizeof(int*));
        int *data_res = malloc(m * n * sizeof(int));
        for (int i = 0; i < m; i++) {
            res[i] = data_res + i * n;
        }
        for (int i = 0; i < n; i++) {
            pointers[i] = data + i * m;
        }
        flag = input(pointers, n, m);
        if (!flag) {
            transpose(pointers, res, n, m);
            output(res, m, n);
        }
    }
    return flag;
}

void sum(int **a1, int **a2, int **res, int n, int m) {
    // printf("sum()\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[i][j] = a1[i][j] + a2[i][j];
        }
    }
}

void mul(int **a1, int **a2, int **res, int n1, int m1, int m2) {
    // printf("mul()\n");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < m2; j++) {
            res[i][j] = res_calc(a1, a2, i, j, m1);
        }
    }
}

int res_calc(int **a1, int **a2, int I, int J, int m1) {
    // printf("res_calc()\n");
    int sum_ = 0;
    for (int i = 0; i < m1; i++) {
        sum_ += (a1[I][i] * a2[i][J]);
    }
    return sum_;
}

void transpose(int **a, int**res, int n, int m) {
    // printf("transpose()\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            res[j][i] = a[i][j];
        }
    }
}
