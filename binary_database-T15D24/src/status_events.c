#include "status_events.h"

void seoutput(status_event* se) {
    printf("%d ",  se->id);
    printf("%d ",  se->module_id);
    printf("%d ",  se->module_status);
    printf("%s ",  se->ch_date);
    printf("%s\n", se->ch_time);
}

status_event* seblueprint() {
    printf("Write SE:");
    status_event* entity = malloc(sizeof(status_event));
    scanf("%d%d%d", &entity->id, &entity->module_id,
        &entity->module_status);
    input(entity->ch_date);
    input(entity->ch_time);
    return entity;
}
