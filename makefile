CC = gcc
CFLAGS = -Wall -Werror
EXECUTABLE = 3HeadTRPO

all: 3HeadTRPO

code.exe: code.o
	gcc -Wall -Werror code.c -o code

code.o: code.c
	gcc -Wall -Werror code.c -c

.PHONY: clean

clean:
	rm -rf *.o