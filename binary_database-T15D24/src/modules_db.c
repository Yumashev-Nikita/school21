#include "shared.h"

int main() {
    log_init();
    int flag = 0;
    while (!flag) {
        flag = cmd_sw();
    }
    log_close();
    return 0;
}

int cmd_sw() {
    printf("Write command:\n");
    printf("SELECT\n");
    printf("INSERT\n");
    printf("UPDATE\n");
    printf("DELETE\n");
    printf("OUT\n");
    int Sk = _SIZE_;
    char line[Sk];
    input(line); int cmd = 0;
    if (!strcmp(line, "SELECT")) {
        db_sw(1);
    } else if (!strcmp(line, "INSERT")) {
        db_sw(2);
    } else if (!strcmp(line, "UPDATE")) {
        db_sw(3);
    } else if (!strcmp(line, "DELETE")) {
        db_sw(4);
    } else if (!strcmp(line, "OUT")) {
        printf("ENDING WORK\n");
        cmd = 1;
    } else {
        printf("WRONG COMMAND\n");
    }
    return cmd;
}

void db_sw(int cmd) {
    printf("Write table:\n");
    printf("LEVELS: 0\n");
    printf("MODULES: 1\n");
    printf("STATUS_EVENTS: 2\n");
    int db = 0; char dummy;
    scanf("%d%c", &db, &dummy);
    switch (db) {
        case 0: switch_cmd(cmd, levels);        break;
        case 1: switch_cmd(cmd, modules);       break;
        case 2: switch_cmd(cmd, status_events); break;
        default: printf("WRONG DB\n");          break;
    }
}

void switch_cmd(int cmd, db name) {
    void* entity = ent_sw(name);
    int id; char dummy;
    switch (cmd) {
        case 1: printf("Write id:"); scanf("%d%c", &id, &dummy); entity = SELECT(name, id);            break;
        case 2: INSERT(name, input_switch(name));                                                      break;
        case 3: printf("Write id:"); scanf("%d%c", &id, &dummy); UPDATE(name, id, input_switch(name)); break;
        case 4: printf("Write id:"); scanf("%d%c", &id, &dummy); DELETE(name, id);                     break;
    }
    if (cmd == 1)
        ent_output_sw(name, entity);
    else
        db_output(name);
}

void* input_switch(db name) {
    void* entity = ent_sw(name);
    switch (name) {
        case 0: entity = lblueprint();  break;
        case 1: entity = mblueprint();  break;
        case 2: entity = seblueprint(); break;
    }
    return entity;
}
