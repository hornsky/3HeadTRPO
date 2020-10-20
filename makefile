code.exe: code.o
	gcc code.o -o code

code.o: code.c
	gcc code.c -c

.PHONY: clean

clean:
	rm -rf *.o