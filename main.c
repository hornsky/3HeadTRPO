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
			case '1': input(); break;
			case '2': print(); break;
			case '3': add(); break;
			case '4': find2(); break;
			case '0': return(0);
			default : puts("WRONG MODE"); getch();
		}
	}
}
