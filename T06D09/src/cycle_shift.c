#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void cyclic(int *a, int n, int c);
void swap(int *a, int i1, int i2);

int main() {
    int n, data[NMAX], c, flag = 0;
    char dummy;
    if (input(data, &n)) {
        printf("n/a");
        flag = 1;
    }
    if (scanf("%d%c", &c, &dummy) != 2 || dummy != '\n') {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        cyclic(data, n, c);
        output(data, n);
    }
    return flag;
}

int input(int *a, int *n) {
    char dummy;
    int flag = 0;
    if (scanf("%d%c", n, &dummy) == 2 && dummy == '\n' && *n > 0 && *n <= NMAX) {
        for (int i = 0; i < *n; i++) {
            if (i < *n - 1) {
                if (scanf("%d%c", &a[i], &dummy) != 1 && dummy != ' ') {
                    flag = 1;
                }
            } else {
                if (scanf("%d%c", &a[i], &dummy) != 2 || dummy != '\n') {
                    flag = 1;
                }
            }
        }
    } else {
        flag = 1;
    }
    return flag;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

void cyclic(int *a, int n, int c) {
    if (c / n > 1)
        c = c % n;
    if (c > 0) {
        while (c != 0) {
            for (int i = 0; i < n - 1; i++) {
                swap(a, i, i + 1);
            }
            c--;
        }
    } else if (c < 0) {
        while (c != 0) {
            for (int i = n - 1; i > 0; i--) {
                swap(a, i, i - 1);
            }
            c++;
        }
    }
}

void swap(int *a, int i1, int i2) {
    *(a + i1) = *(a + i1) + *(a + i2);
    *(a + i2) = *(a + i1) - *(a + i2);
    *(a + i1) = *(a + i1) - *(a + i2);
}
