#include <stdlib.h>
#include <ncurses.h>
#include <stdio.h>
#include <string.h>

#include "../func.c"

#define CATCH_CONFIG_MAIN
#include "ctest.h"

#define testfilepath "./test/jurnal.dat"

TEST_CASE(find2())
{
    REQUIRE(find2(testfilepath));    
}