
all: strlen_test strcmp_test strcpy_test strcat_test strchr_test strstr_test

strlen_test: Quest_1
strcmp_test: Quest_2
strcpy_test: Quest_3
strcat_test: Quest_4
strchr_test: Quest_5
strstr_test: Quest_6

Quest_1: s21_string_test1.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_1

s21_string_test1.o: s21_string_test.c s21_string.o
	gcc -c -DSTRLEN_TEST s21_string_test.c -o s21_string_test.o

Quest_2: s21_string_test2.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_2

s21_string_test2.o: s21_string_test.c s21_string.o
	gcc -c -DSTRCMP_TEST s21_string_test.c -o s21_string_test.o

Quest_3: s21_string_test3.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_3

s21_string_test3.o: s21_string_test.c s21_string.o
	gcc -c -DSTRCPY_TEST s21_string_test.c -o s21_string_test.o

Quest_4: s21_string_test4.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_4

s21_string_test4.o: s21_string_test.c s21_string.o
	gcc -c -DSTRCAT_TEST s21_string_test.c -o s21_string_test.o

Quest_5: s21_string_test5.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_5

s21_string_test5.o: s21_string_test.c s21_string.o
	gcc -c -DSTRCHR_TEST s21_string_test.c -o s21_string_test.o

Quest_6: s21_string_test6.o s21_string.o
	gcc s21_string_test.o s21_string.o -o ../build/Quest_6

s21_string_test6.o: s21_string_test.c s21_string.o
	gcc -c -DSTRSTR_TEST s21_string_test.c -o s21_string_test.o

s21_string.o: s21_string.c
	gcc -c s21_string.c -o s21_string.o

clean:
	rm -rf ../build/* *.o

rebuild: clean all