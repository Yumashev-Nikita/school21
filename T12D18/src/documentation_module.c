#include "documentation_module.h"
#include <stdarg.h>
#include <math.h>

short check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    short mask = 0;
    for (int i = document_count; i > 0; i--)
        mask |= (validate(va_arg(args, char*)) << (document_count - i));
    va_end(args);
    return mask;
}

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

void output(short mask, int document_count, ...) {
    va_list args;
    va_start(args, document_count);
    for (int i = 0; i < document_count; i++) {
        if ((mask & (int)pow(2.0, (double)i)) == (int)pow(2.0, (double)i))
            printf("%d. %-15s: available\n", i + 1, va_arg(args, char*));
        else
            printf("%d. %-15s: unavailable\n", i + 1, va_arg(args, char*));
    }
    va_end(args);
}
