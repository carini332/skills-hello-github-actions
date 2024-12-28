CC = gcc -Wall

all: library

acces.o: acces.c acces.h
	$(CC) -c acces.c

database.o: database.c database.h
	$(CC) -c database.c

library: library.c acces.o database.o
	$(CC) acces.o database.o library.c -o library

clean:
	rm -f library *.o *.bak *~
