all: cipher logging_cipher

logging_cipher: cipher_D.o io.o file.o logger.o
	gcc bin/cipher_D.o bin/io.o bin/file.o bin/logger.o -o ../build/logging_cipher

cipher: cipher.o io.o file.o logger.o
	gcc bin/cipher.o bin/io.o bin/file.o bin/logger.o -o ../build/cipher

cipher.o: cipher.c io_module/io.c
	gcc -c cipher.c -o bin/cipher.o

cipher_D.o: cipher.c io_module/io.c
	gcc -c -DDEBUG_ cipher.c -o bin/cipher_D.o

io.o: io_module/io.c io_module/io.h
	gcc -c io_module/io.c -o bin/io.o

file.o:	file_module/file.c file_module/file.h
	gcc -c file_module/file.c -o bin/file.o

logger.o: log_module/logger.c log_module/logger.h
	gcc -c log_module/logger.c -o bin/logger.o

clean: 
	rm -rf bin/* ../build/*

rebuild: clean all

run: 
	../build/cipher

run_debug:
	../build/logging_cipher