#ifndef SRC_LOG_MODULE_LOGGER_H_
#define SRC_LOG_MODULE_LOGGER_H_

#include <stdio.h>
#include <time.h>
#include "log_levels.h"

FILE* log_init(char* filename);
void logcat(char* message, log_level level, FILE* fp);
void log_close();

#endif  //  SRC_LOG_MODULE_LOGGER_H_
