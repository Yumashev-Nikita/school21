stack.o: stack_module/stack.c
	gcc -c stack_module/stack.c -o bin/stack.o

draw.o: draw_module/draw.c
	gcc -c draw_module/draw.c -o bin/draw.o

graph.o: graph.c
	gcc -c graph.c -o bin/graph.o

calculate.o: calculate_module/calculate.c
	gcc -c calculate_module/calculate.c -o bin/calculate.o

main: graph.o stack.o draw.o calculate.o
	gcc bin/graph.o bin/stack.o bin/draw.o bin/calculate.o -o main

clean:
	rm -rf bin/* main