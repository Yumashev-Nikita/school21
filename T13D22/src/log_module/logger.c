#include "logger.h"

FILE* log_init(char* filename) {
    FILE* fp = fopen(filename, "a+");
    fprintf(fp, "----------------------------------------------------------------\n");
    return fp;
}

void logcat(char* message, log_level level, FILE* fp) {
    time_t t; struct tm * timeinfo;
    time(&t); timeinfo = localtime(&t);
    switch (level) {
        case 0: fprintf(fp, "DEBUG   : %02d:%02d:%02d : %s",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message); break;
        case 1: fprintf(fp, "TRACE   : %02d:%02d:%02d : %s",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message); break;
        case 2: fprintf(fp, "INFO    : %02d:%02d:%02d : %s",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message); break;
        case 3: fprintf(fp, "WARNING : %02d:%02d:%02d : %s",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message); break;
        case 4: fprintf(fp, "ERROR   : %02d:%02d:%02d : %s",
            timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message); break;
    }
}

void log_close(FILE* fp) {
    fprintf(fp, "----------------------------------------------------------------\n");
    fclose(fp);
}
