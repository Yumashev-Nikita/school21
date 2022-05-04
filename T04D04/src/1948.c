#include <stdio.h>

int prime(int n);
int div_check(int n, int d);

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        if (n == 0)
            return 0;
        if (n < 0)
            n = 0 - n;
        printf("\n%d", prime(n));
    } else {
        printf("n/a");
    }
    return 0;
}

int prime(int n) {
    int p = 0, r = 6, i = 0;
    if (n >= 41) {
        while (p * 2 <= n) {
            p = i * i + i + 41;
            if (div_check(n, p) == 1)
                return p;
            i++;
        }
    }
    while (r > 0) {
        p = 6 * r + 1;
        if (div_check(n, p) == 1 && p != 25)
            return p;
        p = 6 * r - 1;
        if (div_check(n, p) == 1 && p != 35)
            return p;
        r -= 1;
    }
    if (div_check(n, 3) == 1)
        return 3;
    if (div_check(n, 2) == 1)
        return 2;
    return 0;
}
int div_check(int n, int d) {
    while (n > 0) {
        n -= d;
    }
    if (n == 0) {
        return 1;
    } else {
        return 0;
    }
}
