#include <stdio.h>
#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

int main() {
    int length, buffer[NMAX], flag = 0;
    if (input(buffer, &length)) {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        int sum = sum_numbers(buffer, length);
        printf("%d\n", sum);
        int numbers[NMAX];
        output(numbers, find_numbers(buffer, length, sum, numbers));
    }
    return flag;
}

int sum_numbers(int *buffer, int length) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) % 2 == 0) {
            sum += *(buffer + i);
        }
    }
    return sum;
}

int input(int *buffer, int *length) {
    char dummy;
    int flag = 0;
    if (scanf("%d%c", length, &dummy) == 2 && dummy == '\n' && *length > 0 && *length <= NMAX) {
        for (int i = 0; i < *length; i++) {
            if (i < *length - 1) {
                if (scanf("%d%c", &buffer[i], &dummy) != 1 && dummy != ' ') {
                    flag = 1;
                }
            } else {
                if (scanf("%d%c", &buffer[i], &dummy) != 2 || dummy != '\n') {
                    flag = 1;
                }
            }
        }
    } else {
        flag = 1;
    }
    return flag;
}

void output(int *buffer, int length) {
    for (int i = 0; i < length; i++) {
        if (i != length - 1)
            printf("%d ", buffer[i]);
        else
            printf("%d", buffer[i]);
    }
}

int find_numbers(int *buffer, int length, int number, int *numbers) {
    int l2 = 0;
    for (int i = 0; i < length; i++) {
        if (*(buffer + i) != 0 && number % *(buffer + i) == 0) {
            *(numbers + l2) = *(buffer + i);
            l2++;
        }
    }
    return l2;
}
