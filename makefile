all: hello

hello: main.c test.c

main.c:
	gcc main.c -c

main.o:
	gcc main.o -o main

test.c:
	gcc ./test/test.c -c

test.o:
	gcc ./test/test.o -o ./test/test

test:
	./test/test

run:
	./prog

.PHONY: clean

clean:
	rm -rf *.o