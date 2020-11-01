#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#include "../func.c"

#define CATCH_CONFIG_MAIN
#include "ctest.h"

#define testfilepath "./test/jurnal.dat"

CTEST(testfilepath, find2) //Поиск символа в строке
{
	struct vot {char surname[10]; int grade_book; int grade[3];} pp1;
	pp1.surname = "Hornsky";
	pp1.grade_book = 2342342;
	pp1.grade[0] = "3";
	pp1.grade[1] = "2";
	pp1.grade[2] = "4";
	pp1.grade[3] = "5";
	
	void real = find2(pp1);

	ASSERT_EQUAL(real);
}