#ifndef SRC_LOG_LOGGER_H_
#define SRC_LOG_LOGGER_H_

#include <stdio.h>
#include <time.h>
#include "log_levels.h"

#define _LOG_PATH_ "logs/LOGS"

void log_init();
void logcat(char* message, log_level level);
void log_close();

#endif  //  SRC_LOG_LOGGER_H_
