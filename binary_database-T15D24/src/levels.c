#include "levels.h"

void loutput(level* entity) {
    printf("%d ", entity->id);
    printf("%d ", entity->cells);
    printf("%d\n", entity->flag);
}

level* lblueprint() {
    printf("Write level:");
    level* entity = malloc(sizeof(level));
    scanf("%d%d%d", &entity->id, &entity->cells, &entity->flag);
    return entity;
}
