#include <stdio.h>
#include "io.h"

void input(char line[_SIZE_]) {
    while ((*line = getc(stdin)) != '\n')
        line++;
    *line = '\0';
}
