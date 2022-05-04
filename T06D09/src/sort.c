#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void bubble_sort(int *a);

int main() {
    int data[NMAX], flag = 0;
    if (input(data)) {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        bubble_sort(data);
        output(data);
    }
    return flag;
}

int input(int *a) {
    char dummy;
    int flag;
    for (int i = 0; i < NMAX; i++) {
        if (i < NMAX - 1) {
            if (scanf("%d%c", &a[i], &dummy) != 1 && dummy != ' ') {
                flag = 1;
            }
        } else {
            if (scanf("%d%c", &a[i], &dummy) != 2 || dummy != '\n') {
                flag = 1;
            }
        }
    }
    return flag;
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        if (i != NMAX - 1)
            printf("%d ", *(a + i));
        else
            printf("%d", *(a + i));
    }
}

void bubble_sort(int *a) {
    for (int i = 1; i <= NMAX; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (*(a + j) < *(a + j - 1)) {
                *(a + j) = *(a + j) + *(a + j - 1);
                *(a + j - 1) = *(a + j) - *(a + j - 1);
                *(a + j) = *(a + j) - *(a + j - 1);
            }
        }
    }
}
