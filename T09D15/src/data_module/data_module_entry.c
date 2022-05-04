#include "../data_libs/data_io.c"
#include <stdio.h>
#include "data_process.c"

int main() {
    double *data;
    int n;
    input(&data, &n);
    if (normalization(data, n))
        output(data, n);
    else
        printf("ERROR");
    return 0;
}
