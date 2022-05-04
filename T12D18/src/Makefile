all: bst_create_test bst_insert_test bst_traverse_test print_module documentation_module

print_module: main_module_entry_point_PRINT_.o print_module.o documentation_module.o
	gcc bin/main_module_entry_point.o bin/print_module.o bin/documentation_module.o -o ../build/Quest_1

documentation_module: main_module_entry_point_DOC_.o documentation_module.o
	gcc bin/main_module_entry_point.o bin/print_module.o bin/documentation_module.o -o ../build/Quest_2

main_module_entry_point_PRINT_.o: main_module_entry_point.c
	gcc -Wall -Wextra -Werror -c -DPRINT_MODULE main_module_entry_point.c -o bin/main_module_entry_point.o

main_module_entry_point_DOC_.o: main_module_entry_point.c
	gcc -Wall -Wextra -Werror -c -DDOCUMENTATION_MODULE main_module_entry_point.c -o bin/main_module_entry_point.o

print_module.o: print_module.c print_module.h
	gcc -c print_module.c -o bin/print_module.o

documentation_module.o: documentation_module.c documentation_module.h
	gcc -c documentation_module.c -o bin/documentation_module.o

bst_create_test: bst_create_test.o bst.o
	gcc bin/bst_create_test.o bin/bst.o -o ../build/Quest_3

bst_create_test.o: bst_create_test.c
	gcc -Wall -Wextra -Werror -c bst_create_test.c -o bin/bst_create_test.o 

bst_insert_test: bst_insert_test.o bst.o
	gcc bin/bst_insert_test.o bin/bst.o -o ../build/Quest_4

bst_insert_test.o: bst_insert_test.c
	gcc -Wall -Wextra -Werror -c bst_insert_test.c -o bin/bst_insert_test.o

bst_traverse_test: bst_traverse.o bst.o
	gcc bin/bst_traverse.o bin/bst.o -o ../build/Quest_5

bst_traverse.o: bst_traverse.c
	gcc -Wall -Wextra -Werror -c bst_traverse.c -o bin/bst_traverse.o

bst.o: bst.c bst.h
	gcc -c bst.c -o bin/bst.o

clean:
	rm -rf ../build/* bin/*

rebuild: clean all