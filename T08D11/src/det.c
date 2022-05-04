#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double det(double **matrix, int n, int col);
int input(double **matrix, int n, int m);
int size_input(int *n, int *m);
void output(double det);


int main() {
    int n, m, flag = 0;
    flag = size_input(&n, &m);
    if (!flag) {
        double **matrix = malloc(n * sizeof(double*));
        double *data = malloc(m * n * sizeof(double));
        for (int i = 0; i < n; i++) {
            matrix[i] = data + i * m;
        }
        flag = input(matrix, n, m);
        if (!flag) {
            output(det(matrix, n, -1));
        }
        free(matrix);
        free(data);
    }
    if (flag)
        printf("n/a");
    return flag;
}

double det(double **matrix, int n, int col) {
    double det_ = 0;
    if (n == 1) {
        det_ = matrix[0][0];
    } else if (n == 2) {
        det_ = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    } else if (n == 3) {
        det_ = matrix[0][0] * matrix[1][1] * matrix[2][2] -
               matrix[0][0] * matrix[1][2] * matrix[2][1] -
               matrix[0][1] * matrix[1][0] * matrix[2][2] +
               matrix[0][1] * matrix[1][2] * matrix[2][0] +
               matrix[0][2] * matrix[1][0] * matrix[2][1] -
               matrix[0][2] * matrix[1][1] * matrix[2][0];
    } else if (n > 3) {
        for (int i = 0; i < n; i++) {
            double **matrix_min = malloc((n - 1) * sizeof(double*));
            double *data_min = malloc((n - 1) * (n - 1) * sizeof(double));
            for (int L = 0; L < n - 1; L++) {
                matrix_min[L] = data_min + L * n - 1;
            }
            for (int j = 1; j < n; j++) {
                for (int k = 0, p = 0; k < n; k++) {
                    if (k != i) {
                        matrix_min[j - 1][p] = matrix[j][k];
                        p++;
                    }
                }
            }
            det_ -= pow(-1, 1 + i) * matrix[0][i] * det(matrix_min, n - 1, i);
            free(matrix_min);
            free(data_min);
        }
    }
    return det_;
}

int input(double **matrix, int n, int m) {
    // printf("input()\n");
    char dummy;
    int flag = 0;
    for (int i = 0; i < n; i++) if (!flag) {
        for (int j = 0; j < m; j++) if (!flag) {
            if (j < m - 1) {
                if (scanf("%lf%c", &matrix[i][j], &dummy) != 1 && dummy != ' ') {
                    flag = 1;
                }
            } else {
                if (scanf("%lf%c", &matrix[i][j], &dummy) != 2 || dummy != '\n') {
                    flag = 1;
                }
            }
        }
    }
    return flag;
}

int size_input(int *n, int *m) {
    int flag = 0;
    char dummy;
    if (scanf("%d%c", n, &dummy) != 2
            || (dummy != '\n' && dummy != ' ')
            || *n <= 0) {
                flag = 1;
            }
    if (!flag) {
        if (scanf("%d%c", m, &dummy) != 2
                || (dummy != '\n' && dummy != ' ')
                || *m <= 0) {
                    flag = 1;
                }
        if (*n != *m)
            flag = 1;
    }
    return flag;
}

void output(double det) {
    printf("%.6lf", det);
}
