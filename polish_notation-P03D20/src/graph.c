#include "graph.h"

#define PI 3.14159265359878

int main() {
    _ATLAS_();
    return 0;
}

void _ATLAS_() {
    char* expr = read_line();
    if (expr) {
        stack* output = parse(expr);
        if (output) {
            draw(output);
        }
    }
}

void st_copy(stack* from, stack** to) {
    while (1) {
        int prec = from->Prec;
        if (!from->next)
            break;
        push(to, from->item, prec);
        from = from->next;
    }
}

char* read_line() {
    char* line = calloc(sizeof(char), 1);
    int i = 0, flag = 0;
    do {
        char* tmp = realloc(line, sizeof(char) * (i + 1));
        if (!tmp) {
            flag = 1;
        } else {
            line = tmp;
            line[i] = getchar();
            if (line[i] == EOF)
                line[i] = '\n';
            if (strchr(_VALID_INPUT_, line[i]) == NULL && line[i] != EOF)
                flag = 1;
        }
        i++;
    }while (line[i - 1] != '\n' && line[i - 1] != EOF && !flag);
    if (flag || line[i - 1] == EOF) {
        printf("line nulled\n");
        line = NULL;
    }
    if (flag) {
        printf("_NON_VALID_INPUT_\n");
    }
    return line;
}

stack* parse(char* line) {
    stack* rev_output = malloc(sizeof(stack));
    stack* output = malloc(sizeof(stack));
    stack* operas = malloc(sizeof(stack));
    operas->next = NULL;
    int flag = 0;
    for (int i = 0; i < (int)strlen(line) && !flag; i++) {
        switch (line[i]) {
            case '+': flag = C01(&rev_output, &operas, line[i]);            break;
            case '-': flag = C02(&rev_output, &operas, line, line[i], &i);  break;
            case '*': flag = C03(&rev_output, &operas, line[i]);            break;
            case '/': flag = C04(&rev_output, &operas, line[i]);            break;
            case '(': flag = C05(&operas, line[i]);                         break;
            case ')': flag = C06(&rev_output, &operas);                     break;
            case '^': flag = C07(&operas, line[i]);                         break;
            case 's': flag = C08(&operas, &line, &i);                       break;
            case 'c': flag = C09(&operas, &line, &i);                       break;
            case 't': flag = C10(&operas, &line, &i);                       break;
            case 'l': flag = C11(&operas, &line, &i);                       break;
            case 'x': flag = C12(&rev_output, line[i]);                     break;
            default : flag = C13(&rev_output, line, line[i], &i);           break;
        }
    }
    if (!flag) {
        if (operas == NULL) {
            do {
                int prec = operas->Prec;
                int item = pop(&operas);
                push(&rev_output, item, prec);
            }while (operas->next != NULL);
            reverse(&rev_output, &output);
            free(operas);
            free(rev_output);
        } else {
            reverse(&rev_output, &output);
            free(rev_output);
        }
    } else {
        output = NULL;
    }
    return output;
}

void print_switch(int code) {
    switch (code) {
        case 0: printf("sin");  break;
        case 1: printf("cos");  break;
        case 2: printf("tg");   break;
        case 3: printf("ctg");  break;
        case 4: printf("sqrt"); break;
        case 5: printf("ln");   break;
        case 6: printf("^");    break;
        case 7: printf("-");    break;
        case 8: printf("x");    break;
    }
}

void binary_parse(stack** output, stack** operas, char symb) {
    // printf("binary_parse(%c)\n", symb);
    switch (symb) {
        case '+': binary_while(output, operas, symb); break;
        case '-': binary_while(output, operas, symb); break;
        case '*': binary_while(output, operas, symb); break;
        case '/': binary_while(output, operas, symb); break;
        case '^': binary_while(output, operas, symb); break;
        default : printf("_BIN_PARSE_ERROR_\n");      break;
    }
}

void binary_while(stack** output, stack** operas, char symb) {
    // printf("binary_while()\n");
    int prec1 = switcheroo(symb);
    while ((*operas)->item != '(' && ((*operas)->Prec > prec1 || ((*operas)->Prec == prec1 && prec1 != 4))) {
        int prec2 = (*operas)->Prec;
        int item = pop(operas);
        push(output, item, prec2);
    }
    push(operas, symb, switcheroo(symb));
}

int switcheroo(char symb) {
    int prec = 0;
    switch (symb) {
        case '+': prec = _SD_PREC_;  break;
        case '-': prec = _SD_PREC_;  break;
        case '*': prec = _MDI_PREC_; break;
        case '/': prec = _MDI_PREC_; break;
        case '^': prec = _GR_PREC_;  break;
    }
    return prec;
}

void reverse(stack** rev_output, stack** output) {
    do {
        int prec = (*rev_output)->Prec;
        int item = pop(rev_output);
        push(output, item, prec);
    }while ((*rev_output)->next != NULL);
}

int C01(stack** output, stack** operas, char symb) {
    int flag = 0;
    binary_parse(output, operas, symb);
    return flag;
}

int C02(stack** output, stack** operas, char* line, char symb, int *i) {
    int flag = 0;
    if (line[*i - 1] >= '0' && line[*i - 1] <= '9') {
        binary_parse(output, operas, symb);
    } else {
        push(operas, _MINUS_, _FUNC_PREC_);
    }
    return flag;
}

int C03(stack** output, stack** operas, char symb) {
    int flag = 0;
    binary_parse(output, operas, symb);
    return flag;
}

int C04(stack** output, stack** operas, char symb) {
    int flag = 0;
    binary_parse(output, operas, symb);
    return flag;
}

int C05(stack** operas, char symb) {
    int flag = 0;
    push(operas, symb, _FUNC_PREC_);
    return flag;
}

int C06(stack** output, stack** operas) {
    int flag = 0;
    while ((*operas)->item != '(' && !flag) {
        int prec = switcheroo((*operas)->item);
        int num = pop(operas);
        push(output, num, prec);
        if (!(*operas)->next)
            flag = 1;
    }
    if (!(*operas)->next) {
        printf("_MISMATCHED_PARENTHESIS_\n");
        flag = 1;
    }
    if (!flag) {
        pop(operas);
        if ((*operas)->Prec == _FUNC_PREC_) {
            int dummy = pop(operas);
            push(output, dummy, _FUNC_PREC_);
        }
    }
    return flag;
}

int C07(stack** operas, char symb) {
    int flag = 0;
    push(operas, _GRADE_, _GR_PREC_);
    return flag;
}

int C08(stack** operas, char** line, int *i) {
    int flag = 0;
    if (*(*line + *i + 1) == 'i' && *(*line + *i + 2) == 'n') {
        push(operas, _SIN_, _FUNC_PREC_);
        *i += 2;
    } else if (*(*line + *i + 1) == 'q' && *(*line + *i + 2) == 'r' 
                    && *(*line + *i + 3) == 't') {
        push(operas, _SQRT_, _FUNC_PREC_);
        *i += 3;
    } else {
        printf("_INPUT_ERROR_ON_C8_\n");
        flag = 1;
    }
    return flag;
}

int C09(stack** operas, char** line, int *i) {
    int flag = 0;
    if (*(*line + *i + 1) == 'o' && *(*line + *i + 2) == 's') {
        push(operas, _COS_, _FUNC_PREC_);
        *i += 2;
    } else if (*(*line + *i + 1) == 't' && *(*line + *i + 2) == 'g') {
        push(operas, _CTG_, _FUNC_PREC_);
        *i += 2;
    } else {
        printf("_INPUT_ERROR_ON_C9_\n");
        flag = 1;
    }
    return flag;
}

int C10(stack** operas, char** line, int *i) {
    int flag = 0;
    if (*(*line + *i + 1) == 'g') {
        push(operas, _TG_, _FUNC_PREC_);
        *i += 1;
    } else {
        printf("_INPUT_ERROR_ON_C10_\n");
        flag = 1;
    }
    return flag;
}

int C11(stack** operas, char** line, int *i) {
    int flag = 0;
    if (*(*line + *i + 1) == 'n') {
        push(operas, _LN_, _FUNC_PREC_);
        *i += 1;
    } else {
        printf("_INPUT_ERROR_ON_C11_\n");
        flag = 1;
    }
    return flag;
}

int C12(stack** output, char symb) {
    int flag = 0;
    push(output, symb, _X_PREC_); //x is a num
    return flag;
}

int C13(stack** output, char* line, char symb, int *i) {
    int flag = 0;
    if (symb >= '0' && symb <= '9') {
        int num = strtol(line + *i, &line, 10), nmc = num, count = 0;
        while (nmc > 0) {
            nmc /= 10;
            count++;
        }
        *i += count - 1;
        push(output, num, 0);
    } else if (symb != EOF && symb != '\n') {
        printf("_%c_NON_VALID_INPUT_ON_PARSE_\n", symb);
        flag = 1;
    }
    return flag;
}
