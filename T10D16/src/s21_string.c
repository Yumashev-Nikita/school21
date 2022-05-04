#include "./s21_string.h"
#include <stdio.h>

int s21_strlen(char *str) {
    int len = 0;
    while (*str) {
        str++;
        len++;
    }
    return len;
}

int s21_strcmp(char *str1, char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

void s21_strcpy(char *str1, char *str2) {
    while (*str1 && *str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
    *str1 = *str2;
}

void s21_strcat(char *str1, char *str2) {
    while (*str1)
        str1++;
    while (*str2) {
        *str1 = *str2;
        str1++;
        str2++;
    }
}

char* s21_strchr(char *str, int n) {
    char *ch = NULL;
    while (*str && *str != (char)n) {
        str++;
    }
    if (*str == (char)n)
        ch = str;
    return ch;
}

char* s21_strstr(char *str, char *token) {
    char *ch = NULL;
    int len = 0;
    while (*str) {
        if (*str == *token) {
            while (*str && *token) {
                if (*str == *token) {
                    str++;
                    token++;
                    len++;
                }
            }
        } else {
            str++;
        }
    }
    ch = str - len;
    return ch;
}
