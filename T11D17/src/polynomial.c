#include "polynomial.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

void init_poli(char* line, struct polinomial* polis) {
    char** tokens = malloc(25 * sizeof(char*));
    int* signs = malloc(25 * sizeof(int));
    char** st = tokens;
    char* lst = line;
    make_signs(line, signs);
    line = lst;
    *tokens = strtok(line, "+-");
    while (*tokens) {
        tokens++;
        *tokens = strtok(NULL, "+-");
    }
    tokens = st;
    char* token = strtok(*tokens, "*x^");
    int i = 0;
    while (token) {
        polis[i].coeff = strtol(token, NULL, 10);
        token = strtok(NULL, "*x^");
        if (token)
            polis[i].degree = strtol(token, NULL, 10);
        tokens++;
        token = strtok(*tokens, "*x^");
        i++;
    }
    for (int j = 0; j < LIST_SIZE && polis[j].coeff; j++) {
        if (signs[j] == 0)
            polis[j].coeff *= -1;
    }
    void linker(struct polinomial* polis);
}

void make_signs(char* line, int* signs) {
    int i = 0;
    if (*line == '-') {
        signs[i] = 0;
        i++;
        line++;
    } else {
        signs[i] = 1;
        i++;
        line++;
    }
    while (*line) {
        if (*line == '-') {
            signs[i] = 0;
            i++;
        }
        if (*line == '+') {
            signs[i] = 1;
            i++;
        }
        line++;
    }
}

void linker(struct polinomial* polis) {
    for (int i = 0; i < LIST_SIZE; i++) {
        if (i != LIST_SIZE - 1)
            polis[i].pointer = polis[i + 1].pointer;
        else
            polis[i].pointer = NULL;
    }
}

int result(struct polinomial* polis) {
    int res = 0;
    for (int i = 0; i < 4; i++) {
        res += polis[i].coeff * pow(X, polis[i].degree);
        if (polis[i].degree == 0)
            break;
    }
    return res;
}
