#include "draw.h"
#include <math.h>

#define PI 3.14159265359878

void draw(stack* output) {
    for (int i = N - 1; i >= 0; i--) {
        for (int j = 0; j < M; j++) {
            double x = j * 4 * PI / 79;
            stack* copy1 = malloc(sizeof(stack));
            copy1->next = NULL;
            stack* copy2 = malloc(sizeof(stack));
            copy2->next = NULL;
            st_copy(output, &copy1);
            reverse(&copy1, &copy2);
            int y = 13 + 12.5 * evaluate(&copy2, x);
            if (i == y)
                printf("*");
            else
                printf(".");
            free(copy1); free(copy2);
        }
        printf("\n");
    }
}