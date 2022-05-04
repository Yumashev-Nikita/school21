#include "data.h"
#include <time.h>

//  1 if D1 < D2
int dcmp(data* D1, data* D2) {
    int flag = 0;
    struct tm date1, date2;
    date1.tm_year = D1->year;  date2.tm_year = D2->year;
    date1.tm_mon =  D1->month; date2.tm_mon =  D2->month;
    date1.tm_mday = D1->day;   date2.tm_mday = D2->day;
    date1.tm_hour = D1->hour;  date2.tm_hour = D2->hour;
    date1.tm_min =  D1->min;   date2.tm_min =  D2->min;
    date1.tm_sec =  D1->sec;   date2.tm_sec =  D2->sec;
    if (difftime(mktime(&date1), mktime(&date2)) < 0) {
        flag = 1;
    } else if (difftime(mktime(&date1), mktime(&date2)) == 0) {
        if (D1->status < D2->status) {
            flag = 1;
        } else if (D1->status == D2->status) {
            if (D1->code < D2->code) {
                flag = 1;
            }
        }
    }
    return flag;
}

void doutput(data* date) {
    printf("%d ",  date->year);
    printf("%d ",  date->month);
    printf("%d ",  date->day);
    printf("%d ",  date->hour);
    printf("%d ",  date->min);
    printf("%d ",  date->sec);
    printf("%d ",  date->status);
    printf("%d\n", date->code);
}
