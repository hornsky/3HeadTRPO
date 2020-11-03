#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "../func.c"

void testinput()
{
	FILE *dv;
	dv = fopen("jurnal.dat", "wb");

	assert(input(dv) == 0);
	printf("input is correct.");
}

int main()
{
	testinput();
	return (0);
}