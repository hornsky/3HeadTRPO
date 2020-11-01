all: hello

hello: main.o test.o

main.o:
	gcc main.c -o main

test.o:
	gcc ./test/test.c -o ./test/test

test:
	./test/test

run:
	./prog

.PHONY: clean

clean:
	rm -rf *.o