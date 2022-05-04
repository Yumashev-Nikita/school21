#include "modules.h"

void moutput(module* entity) {
    printf("%d ",  entity->id);
    printf("%s ",  entity->name);
    printf("%d ",  entity->level_id);
    printf("%d ",  entity->cell_id);
    printf("%d\n", entity->flag);
}

module* mblueprint() {
    printf("Write module:");
    module* entity = malloc(sizeof(module));
    input(entity->name);
    scanf("%d%d%d%d", &entity->id,
        &entity->level_id, &entity->cell_id, &entity->flag);
    return entity;
}
