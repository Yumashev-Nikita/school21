/*
    Search module for the desired value from data array.

    Returned value must be:
        - "even"
        - ">= mean"
        - "<= mean + 3 * sqrt(variance)"
        - "!= 0"

        OR

        0
*/

#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int search(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 0;
    }
    printf("%d", search(data, n));
    return 0;
}

int input(int *a, int *n) {
    char dummy;
    if (scanf("%d%c", n, &dummy) == 2 && dummy == '\n' && *n > 0 && *n < NMAX) {
        for (int i = 0; i < *n; i++) {
            if (i < *n - 1) {
                if (scanf("%d%c", &a[i], &dummy) != 1 && dummy != ' ') {
                    return 1;
                }
            } else {
                if (scanf("%d%c", &a[i], &dummy) != 2 || dummy != '\n') {
                    return 1;
                }
            }
        }
    } else {
        return 1;
    }
    return 0;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

int search(int *a, int n) {
    double mean_ = mean(a, n);
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0
            && a[i] <= mean_ + 3 * sqrt(variance(a, n))
            && a[i] >= mean_
            && a[i] != 0) {
            return a[i];
        }
    }
    return 0;
}

double mean(int *a, int n) {
    double sum;
    for (int i = 0; i < n; i++) {
        sum += a[i];
    }
    return sum / n;
}

double variance(int *a, int n) {
    double mean_ = mean(a, n);
    double var;
    for (int i = 0; i < n; i++) {
        var += ((a[i] - mean_) * (a[i] - mean_)) / n;
    }
    return var;
}
