#include "logger.h"

void log_init() {
    FILE *fp = fopen(_LOG_PATH_, "a+");
    fprintf(fp, "----------------------------------------------------------------\n");
    fclose(fp);
}

void logcat(char* message, log_level level) {
    FILE* fp = fopen(_LOG_PATH_, "a+");
    time_t t; struct tm * timeinfo;
    time(&t); timeinfo = localtime(&t);
    switch (level) {
        case 0: fprintf(fp, "DEBUG   : "); break;
        case 1: fprintf(fp, "TRACE   : "); break;
        case 2: fprintf(fp, "INFO    : "); break;
        case 3: fprintf(fp, "WARNING : "); break;
        case 4: fprintf(fp, "ERROR   : "); break;
    }
    fprintf(fp, "%02d:%02d:%02d : %s\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec, message);
    fclose(fp);
}

void log_close() {
    FILE *fp = fopen(_LOG_PATH_, "a+");
    fprintf(fp, "----------------------------------------------------------------\n");
    fclose(fp);
}
