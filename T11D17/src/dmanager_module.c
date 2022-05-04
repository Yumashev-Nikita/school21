#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"
#ifdef POLYNOMIAL
#include "polynomial.h"
#endif  //  POLYNOMIAL

#define DOORS_COUNT 15
#define MAX_ID 100000

void initialize_doors(struct door* doors);
void output(struct door* doors);
void bubble_sort(struct door* doors);
void close_all(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    close_all(doors);
    bubble_sort(doors);
    output(doors);
    #ifdef POLYNOMIAL
    char line[255];
    scanf("%254s", line);
    struct polinomial polis[25];
    init_poli(line, polis);
    int i = result(polis);
    doors[i - 1].status = 1;
    printf("%d, %d", doors[i - 1].id, doors[i - 1].status);
    #endif  //  POLYNOMIAL
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));
    int seed = rand() % MAX_ID;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % MAX_ID;
        doors[i].status = rand() % 2;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        printf("%d, %d\n", doors[i].id, doors[i].status);
    }
}

void bubble_sort(struct door* doors) {
    for (int i = 1; i <= DOORS_COUNT; i++) {
        for (int j = i - 1; j > 0; j--) {
            if (doors[j].id < doors[j - 1].id) {
                doors[j].id = doors[j].id + doors[j - 1].id;
                doors[j - 1].id = doors[j].id - doors[j - 1].id;
                doors[j].id = doors[j].id - doors[j - 1].id;
            }
        }
    }
}

void close_all(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
    }
}
