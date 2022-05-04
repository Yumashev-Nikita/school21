#include <stdio.h>

int fibo(int n1, int n2, int i, int n);

int main() {
    int n;
    if (n < 3)
        printf("1");
    if (n == 3)
        printf("2");
    if (scanf("%d", &n) == 1 && n > 3) {
        printf("\n%d", fibo(0, 1, 2, n));
    } else {
        printf("n/a");
    }
    return 0;
}

int fibo(int n1, int n2, int i, int n) {
    int n3;
    n3 = n1 + n2;
    printf("|%d|\n", n3);
    if (i == n) return n3;
    return fibo(n2, n3, i+1, n);
}

