#include <stdlib.h>
#include <stdio.h>
#include "stack.h"

void push(stack **root, double num, int prec) {
    stack* tmp = malloc(sizeof(stack));
    if (tmp != NULL) {
        tmp->next = *root;
        tmp->item = num;
        tmp->Prec = prec;
        *root = tmp;
        // printf("Pushed %lf and %d\n", (*root)->item, (*root)->Prec);
    }
}

double pop (stack **root) {
    double num = 0;
    if (root != NULL) {
        num = (*root)->item;
        free(*root);
        *root = (*root)->next;
    } else {
        printf("NOTHING TO POP\n");
        num = 0;
    }
    return num;
}
