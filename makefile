CC = gcc
CFLAGS = -Wall -Werror
EXECUTABLE = 3HeadTRPO

all: src/$(EXECUTABLE)

src/$(EXECUTABLE): src/code.o
	$(CC) $(CFLAGS) $^ -o $@

src/code.o: src/code.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean

clean:
	rm -rf src/*.o