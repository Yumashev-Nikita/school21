#include <stdio.h>
#define NMAX 10

void input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    input(data, &n);
    if (n == -1) {
        printf("n/a");
        return 0;
    }
    squaring(data, n);
    output(data, n);
    return 0;
}

void input(int *a, int *n) {
    char dummy;
    if (scanf("%d%c", n, &dummy) == 2 && dummy == '\n' && *n > 0 && *n <= NMAX) {
        for (int *p = a; p - a < *n; p++) {
            if (p - a < *n - 1) {
                if (scanf("%d%c", p, &dummy) != 1 && dummy != ' ') {
                    *n = -1;
                }
            } else {
                if (scanf("%d%c", p, &dummy) != 2 || dummy != '\n') {
                    *n = -1;
                }
            }
        }
    } else {
        *n = -1;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

void squaring(int *a, int n) {
    for (int i = 0; i < n; i++) {
        a[i] *= a[i];
    }
}
