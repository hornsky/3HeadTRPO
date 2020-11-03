CC = gcc
CFLAGS = -c -Wall

all: hello

hello: main.o test.o
	$(CC) main.o test.o -o 

main.o: main.c
	$(CC) $(CFLAGS) main.c

test.o: test.c
	$(CC) $(CFLAGS) test.c

test:
	./test/test

run:
	./prog

.PHONY: clean

clean:
	rm -rf *.o