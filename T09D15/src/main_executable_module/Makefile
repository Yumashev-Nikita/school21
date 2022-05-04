BP = ../../build
DM = data_module
DL = data_libs
YADM = yet_another_decision_module
OBJS_3 = main_executable_module.o data_process.o data_stat.o data_io.o decision.o
OBJS_5 = main_executable_module.o data_process.o data_stat.a data_io.o decision.o

all: $(BP)/Quest_3 build_with_static 

./$(BP)/Quest_3: $(OBJS_3)
	gcc $(OBJS_3) -o $(BP)/Quest_3

build_with_static: $(BP)/Quest_5

./$(BP)/Quest_5: $(OBJS_5)
	gcc $(OBJS_5) -o $(BP)/Quest_5

clear:
	rm -rf $(BP)/* ./*.o ./*.a

main_executable_module.o: main_executable_module.c
	gcc -c main_executable_module.c -o main_executable_module.o

data_io.o: ../$(DL)/data_io.c
	gcc -c -o data_io.o ../$(DL)/data_io.c

data_stat.a: data_stat.o
	ar -rc data_stat.a data_stat.o

data_stat.o: ../$(DL)/data_stat.c
	gcc -c -o data_stat.o ../$(DL)/data_stat.c

data_process.o: ../$(DM)/data_process.c 
	gcc -c -o data_process.o ../$(DM)/data_process.c

decision.o: ../$(YADM)/decision.c
	gcc -c -o decision.o ../$(YADM)/decision.c

rebuild: clear all