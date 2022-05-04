#ifndef STACK_MODULE_STACK_H_
#define STACK_MODULE_STACK_H_

typedef struct stack {
  double item;
  int Prec;
  struct stack *next;
}stack;

void push(stack **root, double num, int prec);
double pop(stack **root);

#endif  //  STACK_MODULE_STACK_H_
