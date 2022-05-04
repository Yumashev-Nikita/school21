#ifndef SRC_POLYNOMIAL_H_
#define SRC_POLYNOMIAL_H_

#define LINE_SIZE 255
#define LIST_SIZE 25
#define X 3

struct polinomial {
    int coeff;
    int degree;
    struct polinomial* pointer;
};

void init_poli(char* line, struct polinomial* polis);
void make_signs(char* line, int* signs);
void linker(struct polinomial* polis);
int result(struct polinomial* polis);

#endif  // SRC_POLYNOMIAL_H_
