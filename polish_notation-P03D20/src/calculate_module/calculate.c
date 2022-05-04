#include "calculate.h"

double evaluate(stack** polish_notation, double x) {
    stack* output = malloc(sizeof(stack));

    while((*polish_notation)->next) {
        if ((*polish_notation)->Prec == 0) {
            push(&output, pop(polish_notation), 0);
        } else if ((*polish_notation)->Prec == 6) {
            push(&output, x, 0);
            pop(polish_notation);
        } else {
            calculate(&output, pop(polish_notation));
            // pop(&polish_notation);
        }
        
    }
    return pop(&output);
}

void calculate(stack** output, int sign) {
    switch (sign) {
        case '+':       calc_plus(output);         break;
        case '-':       calc_minus(output);        break;
        case '*':       calc_mult(output);         break;
        case '/':       calc_div(output);          break;
        case _SIN_:     calc_sin(output);          break;
        case _COS_:     calc_cos(output);          break;
        case _TG_:      calc_tg(output);           break;
        case _CTG_:     calc_ctg(output);          break;
        case _SQRT_:    calc_sqrt(output);         break;
        case _LN_:      calc_ln(output);           break;
        case _GRADE_:   calc_grade(output);        break;
        case _MINUS_:   calc_unary_minus(output);  break;
    }
}

void calc_plus(stack** output) {
    push(output, pop(output) + pop(output), 0);
}

void calc_minus(stack** output) {
    double tmp = pop(output);
    push(output, pop(output) - tmp, 0);    
}

void calc_div(stack** output) {
    printf("grade()\n");
    double tmp = pop(output);
    if (tmp != 0)
        push(output, pop(output) / tmp, 0);
}

void calc_mult(stack** output) {
    push(output, pop(output) * pop(output), 0);
}

void calc_sin(stack** output) {
    push(output, sin(pop(output)), 0);
}

void calc_cos(stack** output) {
    push(output, cos(pop(output)), 0);
}

void calc_tg(stack** output) {
    push(output, tan(pop(output)), 0);
}

void calc_ctg(stack** output) {
    push(output, 1. / tan(pop(output)), 0);
}

void calc_sqrt(stack** output) {
    push(output, sqrt(pop(output)), 0);
}

void calc_ln(stack** output) {
    push(output, log(pop(output)), 0);
}

void calc_grade(stack** output) {
    double tmp = pop(output);
    push(output, pow(pop(output), tmp), 0);   
}

void calc_unary_minus(stack** output) {
    push(output, -1 * pop(output), 0);
}
