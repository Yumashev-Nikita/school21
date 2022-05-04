#include <stdio.h>
#include <stdlib.h>
#define NMAX 10

int* input(int *n);
void output(int *a, int n);
void bubble_sort(int *a, int n);

int main() {
    int n, *data, flag = 0;
    data = input(&n);
    if (!data) {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        bubble_sort(data, n);
        output(data, n);
    }
    free(data);
    if (flag)
        printf("n/a");
    return flag;
}

int* input(int *n) {
    char dummy;
    int *a;
    if (scanf("%d%c", n, &dummy) == 2 && dummy == '\n' && *n > 0 && *n <= NMAX) {
        a = malloc(*n * sizeof(int));
        for (int i = 0; i < *n; i++) {
            if (i < *n - 1) {
                if (scanf("%d%c", &a[i], &dummy) != 1 && dummy != ' ') {
                    a = NULL;
                    break;
                }
            } else {
                if (scanf("%d%c", &a[i], &dummy) != 2 || dummy != '\n') {
                    a = NULL;
                    break;
                }
            }
        }
    } else {
        a = NULL;
    }
    return a;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", *(a + i));
        else
            printf("%d", *(a + i));
    }
}

void bubble_sort(int *a, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (a[j] < a[j - 1]) {
                a[j] = a[j] + a[j - 1];
                a[j - 1] = a[j] - a[j - 1];
                a[j] = a[j] - a[j - 1];
            }
        }
    }
}
