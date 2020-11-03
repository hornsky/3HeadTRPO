#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#include "func.c"

int input();
int print();
int add();
int find2();

int main()
{
	FILE *dv;
	char c;

	while(1)
	{
		system("CLS");

		puts("1 - New jutnal.");
		puts("2 - Check jurnal.");
		puts("3 - Add in jurnal.");
		puts("4 - Find 2 and change.");
		puts("0 - exit.");

		c = getch();

		switch(c)
		{
			case '1': input(dv); break;
			case '2': print(dv); break;
			case '3': add(dv); break;
			case '4': find2(dv); break;
			case '0': return(0);
			default : puts("WRONG MODE"); getch();
		}
	}
}
