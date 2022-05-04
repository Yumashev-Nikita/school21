#include "shared.h"

ENTITY *SELECT(db name, int id) {
    if (name == 0)
        id--;
    FILE* fp = file_sw(name);
    void* entity = ent_sw(name);
    fseek(fp, size_sw(name) * id, SEEK_SET);
    fread(entity, size_sw(name), 1, fp);
    return entity;
}

int DELETE(db name, int id) {
    if (name == 0)
        id--;
    int flag = 0;
    if (id >= db_count(name))
       flag = 1;
    if (!flag) {
        FILE *fp = file_sw(name);
        int count = db_count(name);
        for (int i = id; i < count - 1; i++) {
            void* entity1 = get_by_id(name, i);
            void* entity2 = get_by_id(name, i + 1);
            write_by_id(name, entity2, i);
            write_by_id(name, entity1, i + 1);
        }
        fseek(fp, 0, SEEK_END);
        ftruncate(fileno(fp), size_sw(name) * (count - 1));
    }
    return flag;
}

int INSERT(db name, ENTITY *entity) {
    int flag = 0;
    FILE* fp = file_sw(name);
    int count = db_count(name);
    if (fp == NULL || entity == NULL) {
        flag = 1;
    } else {
        write_by_id(name, entity, count);
        fseek(fp, -size_sw(name), SEEK_END);
    }
    if (!flag) {
        if (name == 0)
            count++;
        fwrite(&count, sizeof(int), 1, fp);
        fclose(fp);
    }
    return flag;
}

int UPDATE(db name, int id, ENTITY *entity) {
    if (name == 0)
        id--;
    int flag = 0;
    FILE* fp = file_sw(name);
    int count = db_count(name);
    if ((fp == NULL || entity == NULL) && id < count) {
        flag = 1;
    } else {
        write_by_id(name, entity, id);
        fclose(fp);
    }
    return flag;
}

void db_output(db name) {
    logcat("DB_OUTPUT INIT", info);
    FILE *fp = file_sw(name);
    void* entity = ent_sw(name);
    if (fp == NULL || entity == NULL) {
        logcat("WRONG DB_OUTPUT INIT", error);
    } else {
        int size = db_count(name);
        for (int i = 0; i < size; i++) {
            entity = get_by_id(name, i);
            ent_output_sw(name, entity);
        }
        fclose(fp);
    }
}

void* get_by_id(db name, int id) {
    FILE *fp = file_sw(name);
    void* entity = ent_sw(name);
    if (fp == NULL || entity == NULL) {
        logcat("WRONG GET_DATA INIT", error);
    } else {
        fseek(fp, size_sw(name) * id, SEEK_SET);
        if (!fread(entity, size_sw(name), 1, fp))
            entity = NULL;
        fclose(fp);
    }
    return entity;
}

void write_by_id(db name, void* entity, int id) {
    FILE* fp = file_sw(name);
    fseek(fp, size_sw(name) * id, SEEK_SET);
    fwrite(entity, size_sw(name), 1, fp);
    fclose(fp);
}

int db_count(db name) {
    FILE *fp = file_sw(name);
    void* entity = ent_sw(name);
    int count = 0;
    if (fp == NULL || entity == NULL) {
        logcat("WRONG DB_COUNT INIT", error);
    } else {
        while (fread(entity, size_sw(name), 1, fp))
            count++;
        free(entity);
        fclose(fp);
    }
    return count;
}

void ent_output_sw(db name, void* entity) {
    switch (name) {
        case 0: loutput(entity);  break;
        case 1: moutput(entity);  break;
        case 2: seoutput(entity); break;
    }
}

FILE* file_sw(db name) {
    FILE *fp = NULL;
    switch (name) {
        case 0: fp = fopen(_LEVELS_ROOT_PATH_, "r+b");        break;
        case 1: fp = fopen(_MODULES_ROOT_PATH_, "r+b");       break;
        case 2: fp = fopen(_STATUS_EVENTS_ROOT_PATH_, "r+b"); break;
    }
    return fp;
}

void* ent_sw(db name) {
    void* ent = NULL;
    switch (name) {
        case 0: ent = (level*)malloc(sizeof(level));                break;
        case 1: ent = (module*)malloc(sizeof(module));              break;
        case 2: ent = (status_event*)malloc(sizeof(status_event));  break;
    }
    return ent;
}

unsigned long size_sw(db name) {
    int size = 0;
    switch (name) {
        case 0: size = sizeof(level); break;
        case 1: size = sizeof(module); break;
        case 2: size = sizeof(status_event); break;
    }
    return size;
}
