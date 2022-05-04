#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n)) {
        printf("n/a");
        return 0;
    }
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
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
            printf("%d\n", a[i]);
    }
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
                       printf("%d %d %.6lf %.7lf", max_v, min_v, mean_v, variance_v);
                   }

int max(int *a, int n) {
    int max = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

int min(int *a, int n) {
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
    }
    return min;
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
