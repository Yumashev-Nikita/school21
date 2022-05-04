#include <stdio.h>
#include "decision.c"
#include "../data_libs/data_io.c"

int main() {
    double *data;
    int n;
    input(data, &n);
    if (make_decision(data, n))
        printf("YES"); 
    else
        printf("NO");
    return 0;
}
