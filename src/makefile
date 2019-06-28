
CC=gcc
CFLAGS=-c -Wall

all: todolist

todolist: main.o functions.o
	$(CC) main.o functions.o -o todolist

main.o: main.c
	$(CC) $(CFLAGS) main.c

functions.o: functions.c
	$(CC) $(CFLAGS) functions.c

clean:
	rm *o todolist
