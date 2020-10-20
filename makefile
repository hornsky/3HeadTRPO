code.exe: code.o
	gcc -Wall -Werror code.o -o code

code.o: code.c
	gcc -Wall -Werror code.c -c

.PHONY: clean

clean:
	rm -rf *.o