#ifndef SRC_SHARED_H_
#define SRC_SHARED_H_

#define ENTITY void

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "io/io.h"
#include "log/logger.h"
#include "levels.h"
#include "modules.h"
#include "status_events.h"

#define _LEVELS_ROOT_PATH_ "tables/LEVELS"
#define _MODULES_ROOT_PATH_ "tables/MODULES"
#define _STATUS_EVENTS_ROOT_PATH_ "tables/STATUS_EVENTS"

typedef enum {
    levels,
    modules,
    status_events
}db;

ENTITY *SELECT(db name, int id);
int DELETE(db name, int id);
int INSERT(db name, ENTITY *entity);
int UPDATE(db name, int id, ENTITY *entity);

int cmd_sw();
void db_sw(int cmd);
void switch_cmd(int cmd, db name);
void* input_switch(db name);

void db_output(db name);
void* get_by_id(db name, int id);
void write_by_id(db name, void* entity, int id);
int db_count(db name);
void db_output(db name);
void ent_output_sw(db name, void* entity);
FILE* file_sw(db name);
void* ent_sw(db name);
unsigned long size_sw(db name);

#endif  //  SRC_SHARED_H_
