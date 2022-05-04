#include <stdio.h>

#define LEN 100

int input(int *a);
void output(int *buffer, int length);
int sum(int *buff1, int len1, int *buff2, int len2, int *result);
int sub(int *buff1, int len1, int *buff2, int len2, int *result);
int diff(int *buffer);

int main() {
    int n1, n2, num1[LEN], num2[LEN], res1[LEN], res2[LEN], nmax, diff_;
    int flag = 0;
    n1 = input(num1);
    if (n1 == -1) {
        printf("n/a");
        flag = 1;
    }
    if (!flag) {
        nmax = n1 + 1;
        diff_ = diff(num1);
        n2 = input(num2);
        if (n2 == -1) {
            printf("n/a");
            flag = 1;
        }
        if (!flag) {
            if (n2 > n1) {
                nmax = n2 + 1;
                diff_ = diff(num2);
            }
            res1[0] = 0;
            res2[0] = 0;
            if (sub(num1, n1, num2, n2, res2)) {
                printf("n/a");
                flag = 1;
            }
        }
    }
    if (!flag) {
        sum(num1, n1, num2, n2, res1);
        output(res1, nmax - diff_); printf("\n");
        output(res2, nmax - diff_); printf("\n");
    }
    return flag;
}

int input(int *a) {
    char dummy;
    int p = 0;
    do {
        if (scanf("%d%c", a + p, &dummy) == 2 && (dummy == ' ' || dummy == '\n')) {
            if (*(a + p) > 9 || *(a + p) < 0) {
                p = -1;
                break;
            }
            p++;
        } else {
            p = -1;
            break;
        }
    }while(dummy != '\n' && p < 100);
    return p;
}

void output(int *a, int n) {
    int i = 0;
    while (a[i] == 0)
        i++;
    if (i > 99) {
        printf("0");
        return;
    }
    for (; i < n; i++) {
        if (i != n - 1)
            printf("%d ", a[i]);
        else
            printf("%d", a[i]);
    }
}

int sum(int *buff1, int len1, int *buff2, int len2, int *result) {
    int diff1 = diff(buff1);
    int diff2 = diff(buff2);
    int trlen1 = len1 - diff1;
    int trlen2 = len2 - diff2;
    int maxlen = trlen1;
    int j = 0;
    if (trlen2 > maxlen) {
        maxlen = trlen2;
        for (int i = 0; i < maxlen; i++) {
            result[i + 1] = buff2[i + diff2];
        }
        for (int i = len1 - 1; i >= diff1; i--) {
            result[maxlen - j] += buff1[i];
            j++;
        }
        for (int i = maxlen; i >= 1; i--) {
            if (result[i] >= 10) {
                result[i] -= 10;
                result[i - 1]++;
            }
        }
    } else {
        for (int i = 0; i < maxlen; i++) {
            result[i + 1] = buff1[i + diff1];
        }
        for (int i = len2 - 1; i >= diff2; i--) {
            result[maxlen - j] += buff2[i];
            j++;
        }
        for (int i = maxlen; i >= 1; i--) {
            if (result[i] >= 10) {
                result[i] -= 10;
                result[i - 1]++;
            }
        }
    }
    return 0;
}

int sub(int *buff1, int len1, int *buff2, int len2, int *result) {
    int diff1 = diff(buff1);
    int diff2 = diff(buff2);
    int trlen1 = len1 - diff1;
    int trlen2 = len2 - diff2;
    int maxlen = trlen1;
    int flag = 0;
    if (trlen1 < trlen2 || (buff1[diff1] < buff2[diff2] && trlen1 == trlen2))
        flag = 1;
    if (!flag) {
        int j = 0;
        for (int i = 0; i < maxlen; i++) {
            result[i + 1] = buff1[i + diff1];
        }
        for (int i = len2 - 1; i >= diff2; i--) {
            result[maxlen - j] -= buff2[i];
            j++;
        }
        for (int i = maxlen; i >= 1; i--) {
            if (result[i] < 0) {
                result[i] = 10 + result[i];
                result[i - 1]--;
            }
        }
    }
    return flag;
}

int diff(int *buffer) {
    int diff = 0, i = 0;
    while (buffer[i] == 0) {
        diff++;
        i++;
    }
    return diff;
}
