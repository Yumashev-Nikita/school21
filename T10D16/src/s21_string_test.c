#include "s21_string.h"
#include <stdio.h>

#ifdef STRLEN_TEST
void s21_strlen_test();
#endif  //  STRLEN_TEST
#ifdef STRCMP_TEST
void s21_strcmp_test();
#endif  //  STRCMP_TEST
#ifdef STRCPY_TEST
void s21_strcpy_test();
#endif  //  STRCPY_TEST
#ifdef STRCAT_TEST
void s21_strcat_test();
#endif  //  STRCAT_TEST
#ifdef STRCHR_TEST
void s21_strchr_test();
#endif  //  STRCHR_TEST
#ifdef STRSTR_TEST
void s21_strstr_test();
#endif  //  STRSTR_TEST

int main() {
    #ifdef STRLEN_TEST
    s21_strlen_test();
    #endif  //  STRLEN_TEST
    #ifdef STRCMP_TEST
    s21_strcmp_test();
    #endif  //  STRCMP_TEST
    #ifdef STRCPY_TEST
    s21_strcpy_test();
    #endif  //  STRCPY_TEST
    #ifdef STRCAT_TEST
    s21_strcat_test();
    #endif  //  STRCAT_TEST
    #ifdef STRCHR_TEST
    s21_strchr_test();
    #endif  //  STRCHR_TEST
    #ifdef STRSTR_TEST
    s21_strstr_test();
    #endif  //  STRSTR_TEST
    return 0;
}

#ifdef STRLEN_TEST
void s21_strlen_test() {
    printf("STRLEN TEST\n");
    char str1[14] = "1 2 3 4 5 6 7";
    if (s21_strlen(str1) == 13)
        printf("str[14] = \"1 2 3 4 5 6 7\" %d SUCCESS\n", s21_strlen(str1));
    else
        printf("str[14] %d FAIL\n", s21_strlen(str1));
    char str2[0] = "";
    if (s21_strlen(str2) == 0)
        printf("str[0] %d SUCCESS\n", s21_strlen(str2));
    else
        printf("str[0] %d FAIL\n", s21_strlen(str2));
    char str3[5] = "123";
    if (s21_strlen(str3) == 3)
        printf("str[5] = \"123\" %d SUCCESS\n", s21_strlen(str3));
    else
        printf("str[5] = \"123\" %d FAIL\n", s21_strlen(str3));
}
#endif  //  STRLEN_TEST

#ifdef STRCMP_TEST
void s21_strcmp_test() {
    printf("STRCMP TEST\n");
    char str1[14] = "124";
    char str2[14] = "123";
    if (s21_strcmp(str1, str2) == 1)
        printf("str1 > str2 %d SUCCESS\n", s21_strcmp(str1, str2));
    else
        printf("str1 > str2 %d FAIL\n", s21_strcmp(str1, str2));
    if (s21_strcmp(str1, str1) == 0)
        printf("EQUAL %d SUCCESS\n", s21_strcmp(str1, str1));
    else
        printf("EQUAL %d FAIL\n", s21_strcmp(str1, str1));
    if (s21_strcmp(str2, str1) == -1)
        printf("str2 < str1 %d SUCCESS\n", s21_strcmp(str2, str1));
    else
        printf("str2 < str1 %d FAIL\n", s21_strcmp(str2, str1));
}
#endif  //  STRCMP_TEST

#ifdef STRCPY_TEST
void s21_strcpy_test() {
    printf("STRCPY TEST\n");
    char str1[14] = "123";
    char str2[5] = "456";
    char str3[5];
    s21_strcpy(str1, str2);
    if (s21_strcmp(str1, str2) == 0)
        printf("str2 -> str1 %s SUCCESS\n", str1);
    else
        printf("str2 -> str1 %s FAIL\n", str1);
    s21_strcpy(str2, str1);
    if (s21_strcmp(str2, str1) == 0)
        printf("str1 -> str2 %s SUCCESS\n", str2);
    else
        printf("str1 -> str2 %s FAIL\n", str2);
    s21_strcpy(str3, str1);
    if (s21_strcmp(str3, str1) == 0)
        printf("str1 -> str3 %s SUCCESS\n", str3);
    else
        printf("str1 -> str3 %s FAIL\n", str3);
}
#endif  //  STRCPY_TEST

#ifdef STRCAT_TEST
void s21_strcat_test() {
    printf("STRCAT TEST\n");
    char str1[14] = "123";
    char str2[5] = "456";
    s21_strcat(str1, str2);
    if (!s21_strcmp(str1, "123456"))
        printf("str1 + str2 %s SUCCESS\n", str1);
    else
        printf("str1 + str2 %s FAIL\n", str1);
    s21_strcat(str1, "123");
    if (!s21_strcmp(str1, "123456123"))
        printf("str1 + \"123\" %s SUCCESS\n", str1);
    else
        printf("str1 + \"123\" %s FAIL\n", str1);
    s21_strcat(str1, "");
    if (!s21_strcmp(str1, "123456123"))
        printf("str1 + \"\" %s SUCCESS\n", str1);
    else
        printf("str1 + \"\" %s FAIL\n", str1);
}
#endif  //  STRCAT_TEST

#ifdef STRCHR_TEST
void s21_strchr_test() {
    printf("STRCHR TEST\n");
    char str1[14] = "123";
    char* ch = s21_strchr(str1, '3');
    if (str1[2] == *ch)
        printf("str1[2] = %c SUCCESS\n", str1[2]);
    else
        printf("str1[2] = %c FAIL\n", str1[2]);
    ch = s21_strchr(str1, '0');
    if (ch == NULL)
        printf("NULL_TEST SUCCESS\n");
    else
        printf("NULL_TEST FAIL\n");
    ch = s21_strchr(str1, '1');
    if (str1[0] == *ch)
        printf("str1[2] = %c SUCCESS\n", str1[0]);
    else
        printf("str1[2] = %c FAIL\n", str1[0]);
}
#endif  //  STRCHR_TEST

#ifdef STRSTR_TEST
void s21_strstr_test() {
    printf("STRSTR TEST\n");
    char str1[14] = "123456";
    char str2[5] = "456";
    char str3[5] = "128";
    char *ch = s21_strstr(str1, str2);
    if (!s21_strcmp(ch, str2))
        printf("%s = %s SUCCESS\n", ch, str2);
    else
        printf("%s = %s FAIL\n", ch, str2);
    ch = s21_strstr(str3, "28");
    if (!s21_strcmp(ch, "28"))
        printf("%s = %s SUCCESS\n", ch, str3 + 1);
    else
        printf("%s = %s FAIL\n", ch, str3 + 1);
    ch = s21_strstr(str1, "\0");
    if (!s21_strcmp(ch, "\0"))
        printf("%s =  SUCCESS\n", ch);
    else
        printf("%s =  FAIL\n", ch);
}
#endif  //  STRSTR_TEST
