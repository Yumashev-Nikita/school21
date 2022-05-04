#ifndef SRC_MODULES_H_
#define SRC_MODULES_H_

#include <stdio.h>
#include <stdlib.h>

#include "io/io.h"

typedef struct {
    int id;
    char name[31];
    int level_id;
    int cell_id;
    int flag;
}module;

void moutput(module* entity);
module* mblueprint();

#endif  //  SRC_MODULES_H_
