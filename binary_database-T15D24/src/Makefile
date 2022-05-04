modules_db: modules_db.o shared.o logger.o io.o level.o module.o status_events.o
	gcc bin/shared.o bin/logger.o bin/io.o bin/modules_db.o bin/level.o bin/module.o bin/status_events.o -o ../build/modules_db

modules_db.o: modules_db.c
	gcc -c modules_db.c -o bin/modules_db.o

#MODULE BINS
#-----------------------------------------------------------------------------------
shared.o: shared.c shared.h
	gcc -c shared.c -o bin/shared.o

io.o: io/io.c io/io.h
	gcc -c io/io.c -o bin/io.o

logger.o: log/logger.c log/logger.h
	gcc -c log/logger.c -o bin/logger.o
#-----------------------------------------------------------------------------------

#TABLE BINS
#-----------------------------------------------------------------------------------
level.o: levels.c levels.h
	gcc -c levels.c -o bin/level.o

module.o: modules.c modules.h
	gcc -c modules.c -o bin/module.o

status_events.o: status_events.c status_events.h
	gcc -c status_events.c -o bin/status_events.o
#-----------------------------------------------------------------------------------

remake_db:
	rm tables/*S
	cp ../materials/master_levels.db tables/LEVELS
	cp ../materials/master_modules.db tables/MODULES
	cp ../materials/master_status_events.db tables/STATUS_EVENTS

run: modules_db
	../build/modules_db

clean:
	rm -rf bin/* ../build/*

rebuild: clean all