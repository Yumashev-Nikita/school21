state_sort: state_sort.o io.o file.o data.o
	gcc bin/state_sort.o bin/io.o bin/file.o bin/data.o -o ../build/state_sort

state_sort.o: state_sort.c
	gcc -c state_sort.c -o bin/state_sort.o

io.o: io/io.c io/io.h
	gcc -c io/io.c -o bin/io.o

file.o:	file/file.c file/file.h
	gcc -c file/file.c -o bin/file.o

data.o: data/data.c data/data.h
	gcc -c data/data.c -o bin/data.o

run: state_sort
	../build/state_sort

clean:
	rm -rf bin/* ../build/*