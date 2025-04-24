#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace Matrix;

TEST_CASE("Matrix + Matrix"){
    SquareMat A(2);
    CHECK(A.getSize() == 2);
    A[0][0] = 5.0;
    A[0][1] = 6.0;
    A[1][0] = 7.0;
    A[1][1] = 8.0;
    SquareMat c(2);
    c[0][0] = 2;
    c[0][1] = 2;
    c[1][0] = 2;
    c[1][1] = 2;
    CHECK_FALSE(c.getSize() == 4);
    CHECK(c.getSize() == 2);
    CHECK(c.getSize() == A.getSize());
    SquareMat b(2);
    b = A + c;
    CHECK(b[0][0] == 7);
    CHECK(b[0][1] == 8);
    CHECK(b[1][0] == 9);
    CHECK(b[1][1] == 10);
}