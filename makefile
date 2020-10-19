CC = gcc
CFLAGS = -Wall -Werror
EXECUTABLE = 3HeadTRPO

all: bin/$(EXECUTABLE) bin/$(EXETEST)

$(EXECUTABLE): code.o
	$(CC) $(CFLAGS) $^ -o $@

code.o: code.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf *.o