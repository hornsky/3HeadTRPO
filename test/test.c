#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <string.h>

#include "../func.c"

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#define testfilepath "./test/jurnal.dat"

TEST_CASE("testfind2")
{
    REQUIRE(find2(testfilepath));    
}