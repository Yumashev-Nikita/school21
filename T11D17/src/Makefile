all: polynomial door_struct

polynomial: dmanager_module_POLY.o polynomial.o
	gcc dmanager_module_POLY.o polynomial.o -o ../build/Quest_2

door_struct: dmanager_module.o
	gcc dmanager_module.o -o ../build/Quest_1

dmanager_module_POLY.o: dmanager_module.c
	gcc -c -DPOLYNOMIAL dmanager_module.c -o dmanager_module_POLY.o

dmanager_module.o: dmanager_module.c
	gcc -c dmanager_module.c

polynomial.o: polynomial.c polynomial.h
	gcc -c polynomial.c

clean:
	rm -rf ../build/* *.o

rebuild: clean all