#ifndef SRC_DATA_DATA_H_
#define SRC_DATA_DATA_H_

#include <stdio.h>

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int min;
    int sec;
    int status;
    int code;
}data;

int dcmp(data* D1, data* D2);
void doutput(data* date);

#endif  //  SRC_DATA_DATA_H_
