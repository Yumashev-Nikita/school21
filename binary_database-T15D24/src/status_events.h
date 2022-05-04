#ifndef SRC_STATUS_EVENTS_H_
#define SRC_STATUS_EVENTS_H_

#include <stdio.h>
#include <stdlib.h>

#include "io/io.h"

typedef struct {
    int id;
    int module_id;
    int module_status;
    char ch_date[11];
    char ch_time[9];
}status_event;

void seoutput(status_event* entity);
status_event* seblueprint();

#endif  //  SRC_STATUS_EVENTS_H_
