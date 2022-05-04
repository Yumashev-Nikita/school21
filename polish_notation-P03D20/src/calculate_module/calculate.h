#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "../defs.h"
#include "../stack_module/stack.h"

double evaluate(stack** polish_notation, double x);
void calculate(stack** output, int sign);

void calc_plus(stack** output);
void calc_minus(stack** output);
void calc_div(stack** output);
void calc_mult(stack** output);
void calc_sin(stack** output);
void calc_cos(stack** output);
void calc_tg(stack** output);
void calc_ctg(stack** output);
void calc_sqrt(stack** output);
void calc_ln(stack** output);
void calc_grade(stack** output);
void calc_unary_minus(stack** output);
