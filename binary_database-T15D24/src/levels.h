#ifndef SRC_LEVELS_H_
#define SRC_LEVELS_H_

#include <stdio.h>
#include <stdlib.h>

#include "io/io.h"

typedef struct {
    int id;
    int cells;
    int flag;
}level;

void loutput(level* lev);
level* lblueprint();

#endif  //  SRC_LEVELS_H_
