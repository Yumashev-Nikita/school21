#include "data_io.h"
#include <stdlib.h>
#include <stdio.h>

void input(double **data, int *n) {
    scanf("%d", n);
    *data = malloc(*n * sizeof(double));
    for (int i = 0; i < *n; i++) {
        scanf("%lf", *data + i);
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i != n - 1)
            printf("%0.2lf ", data[i]);
        else
            printf("%0.2lf", data[i]);
    }
}