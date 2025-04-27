//Galashkena1@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "SquareMat.hpp"
using namespace Matrix;

TEST_CASE("Matrix + Matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    SquareMat B(3);
    B[0][0] = 9;
    B[0][1] = 8;
    B[0][2] = 7;
    B[1][0] = 6;
    B[1][1] = 5;
    B[1][2] = 4;
    B[2][0] = 3;
    B[2][1] = 2;
    B[2][2] = 1;

    SquareMat C = A + B;

    CHECK(C[0][0] == 10);
    CHECK(C[0][1] == 10);
    CHECK(C[0][2] == 10);
    CHECK(C[1][0] == 10);
    CHECK(C[1][1] == 10);
    CHECK(C[1][2] == 10);
    CHECK(C[2][0] == 10);
    CHECK(C[2][1] == 10);
    CHECK(C[2][2] == 10);
}

TEST_CASE("Matrix - Matrix")
{
    SquareMat A(3);
    A[0][0] = 9;
    A[0][1] = 8;
    A[0][2] = 7;
    A[1][0] = 6;
    A[1][1] = 5;
    A[1][2] = 4;
    A[2][0] = 3;
    A[2][1] = 2;
    A[2][2] = 1;

    SquareMat B(3);
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 3;
    B[1][0] = 4;
    B[1][1] = 5;
    B[1][2] = 6;
    B[2][0] = 7;
    B[2][1] = 8;
    B[2][2] = 9;

    SquareMat C = A - B;

    CHECK(C[0][0] == 8);
    CHECK(C[0][1] == 6);
    CHECK(C[0][2] == 4);
    CHECK(C[1][0] == 2);
    CHECK(C[1][1] == 0);
    CHECK(C[1][2] == -2);
    CHECK(C[2][0] == -4);
    CHECK(C[2][1] == -6);
    CHECK(C[2][2] == -8);
}

TEST_CASE("Unary Minus")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = -2;
    A[0][2] = 3;
    A[1][0] = -4;
    A[1][1] = 5;
    A[1][2] = -6;
    A[2][0] = 7;
    A[2][1] = -8;
    A[2][2] = 9;

    SquareMat B = -A;

    CHECK(B[0][0] == -1);
    CHECK(B[0][1] == 2);
    CHECK(B[0][2] == -3);
    CHECK(B[1][0] == 4);
    CHECK(B[1][1] == -5);
    CHECK(B[1][2] == 6);
    CHECK(B[2][0] == -7);
    CHECK(B[2][1] == 8);
    CHECK(B[2][2] == -9);
}

TEST_CASE("Matrix * scalar and scalar * Matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    SquareMat B = A * 2;
    SquareMat C = 2 * A;

    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            CHECK(B[i][j] == A[i][j] * 2);
            CHECK(C[i][j] == A[i][j] * 2);
        }
}

TEST_CASE("Matrix * Matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 0;
    A[1][1] = 1;
    A[1][2] = 4;
    A[2][0] = 5;
    A[2][1] = 6;
    A[2][2] = 0;

    SquareMat B(3);
    B[0][0] = 7;
    B[0][1] = 8;
    B[0][2] = 9;
    B[1][0] = 0;
    B[1][1] = 1;
    B[1][2] = 2;
    B[2][0] = 3;
    B[2][1] = 4;
    B[2][2] = 5;

    SquareMat C = A * B;

    CHECK(C[0][0] == 16);
    CHECK(C[0][1] == 22);
    CHECK(C[0][2] == 28);
    CHECK(C[1][0] == 12);
    CHECK(C[1][1] == 17);
    CHECK(C[1][2] == 22);
    CHECK(C[2][0] == 35);
    CHECK(C[2][1] == 46);
    CHECK(C[2][2] == 57);
}
TEST_CASE("Power matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 0;
    A[0][2] = 0;
    A[1][0] = 0;
    A[1][1] = 2;
    A[1][2] = 0;
    A[2][0] = 0;
    A[2][1] = 0;
    A[2][2] = 3;

    SquareMat res = A ^ 3;

    CHECK(res[0][0] == 1);
    CHECK(res[0][1] == 0);
    CHECK(res[0][2] == 0);

    CHECK(res[1][0] == 0);
    CHECK(res[1][1] == 8);
    CHECK(res[1][2] == 0);

    CHECK(res[2][0] == 0);
    CHECK(res[2][1] == 0);
    CHECK(res[2][2] == 27);
}

TEST_CASE("Matrix % scalar")
{
    SquareMat A(3);
    A[0][0] = 5;
    A[0][1] = 10;
    A[0][2] = 15;
    A[1][0] = 20;
    A[1][1] = 25;
    A[1][2] = 30;
    A[2][0] = 35;
    A[2][1] = 40;
    A[2][2] = 45;

    SquareMat B = A % 7;

    CHECK(B[0][0] == 5);
    CHECK(B[0][1] == 3);
    CHECK(B[0][2] == 1);
    CHECK(B[1][0] == 6);
    CHECK(B[1][1] == 4);
    CHECK(B[1][2] == 2);
    CHECK(B[2][0] == 0);
    CHECK(B[2][1] == 5);
    CHECK(B[2][2] == 3);
}

TEST_CASE("Transpose")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    SquareMat B = ~A;

    CHECK(B[0][0] == 1);
    CHECK(B[0][1] == 4);
    CHECK(B[0][2] == 7);
    CHECK(B[1][0] == 2);
    CHECK(B[1][1] == 5);
    CHECK(B[1][2] == 8);
    CHECK(B[2][0] == 3);
    CHECK(B[2][1] == 6);
    CHECK(B[2][2] == 9);
}

TEST_CASE("Determinant")
{
    SquareMat A(3);
    A[0][0] = 6;
    A[0][1] = 1;
    A[0][2] = 1;
    A[1][0] = 4;
    A[1][1] = -2;
    A[1][2] = 5;
    A[2][0] = 2;
    A[2][1] = 8;
    A[2][2] = 7;

    double detA = !A;
    CHECK(detA == -306);
    SquareMat B(3);
    for (int i = 0; i < 3; ++i)
        B[i][i] = 1;
    double detB = !B;
    CHECK(detB == 1);
}

TEST_CASE("Increment and Decrement")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 1;
    A[0][2] = 1;
    A[1][0] = 1;
    A[1][1] = 1;
    A[1][2] = 1;
    A[2][0] = 1;
    A[2][1] = 1;
    A[2][2] = 1;

    SquareMat B = A++;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            CHECK(B[i][j] == 1);
            CHECK(A[i][j] == 2);
        }
}

TEST_CASE("Matrix == and !=")
{
    SquareMat A(3), B(3);
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
        {
            A[i][j] = 1;
            B[i][j] = 1;
        }
    CHECK(A == B);
    B[0][0] = 2;
    CHECK(A != B);
}
TEST_CASE("Check operators >, <, >=, <=") {
    SquareMat A(3), B(3), C(3);
    

    A[0][0] = 1; A[0][1] = 1; A[0][2] = 1;
    A[1][0] = 1; A[1][1] = 1; A[1][2] = 1;
    A[2][0] = 1; A[2][1] = 1; A[2][2] = 1;
    

    B[0][0] = 2; B[0][1] = 2; B[0][2] = 2;
    B[1][0] = 2; B[1][1] = 2; B[1][2] = 2;
    B[2][0] = 2; B[2][1] = 2; B[2][2] = 2;
    

    C[0][0] = 3; C[0][1] = 0; C[0][2] = 0;
    C[1][0] = 0; C[1][1] = 3; C[1][2] = 0;
    C[2][0] = 0; C[2][1] = 0; C[2][2] = 3;


    CHECK(A < B);      
    CHECK(B > A); 
    CHECK(A == C);     
    CHECK(A <= C);     
    CHECK(A >= C);    
    CHECK_FALSE(A > C); 
    CHECK_FALSE(A < C); 
}
TEST_CASE("Matrix += Matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    SquareMat B(3);
    B[0][0] = 9;
    B[0][1] = 8;
    B[0][2] = 7;
    B[1][0] = 6;
    B[1][1] = 5;
    B[1][2] = 4;
    B[2][0] = 3;
    B[2][1] = 2;
    B[2][2] = 1;

    A += B;

    CHECK(A[0][0] == 10);
    CHECK(A[0][1] == 10);
    CHECK(A[0][2] == 10);
    CHECK(A[1][0] == 10);
    CHECK(A[1][1] == 10);
    CHECK(A[1][2] == 10);
    CHECK(A[2][0] == 10);
    CHECK(A[2][1] == 10);
    CHECK(A[2][2] == 10);
}

TEST_CASE("Matrix -= Matrix")
{
    SquareMat A(3);
    A[0][0] = 9;
    A[0][1] = 8;
    A[0][2] = 7;
    A[1][0] = 6;
    A[1][1] = 5;
    A[1][2] = 4;
    A[2][0] = 3;
    A[2][1] = 2;
    A[2][2] = 1;

    SquareMat B(3);
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 3;
    B[1][0] = 4;
    B[1][1] = 5;
    B[1][2] = 6;
    B[2][0] = 7;
    B[2][1] = 8;
    B[2][2] = 9;

    A -= B;

    CHECK(A[0][0] == 8);
    CHECK(A[0][1] == 6);
    CHECK(A[0][2] == 4);
    CHECK(A[1][0] == 2);
    CHECK(A[1][1] == 0);
    CHECK(A[1][2] == -2);
    CHECK(A[2][0] == -4);
    CHECK(A[2][1] == -6);
    CHECK(A[2][2] == -8);
}

TEST_CASE("Matrix *= Matrix")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 0;
    A[1][1] = 1;
    A[1][2] = 4;
    A[2][0] = 5;
    A[2][1] = 6;
    A[2][2] = 0;

    SquareMat B(3);
    B[0][0] = 7;
    B[0][1] = 8;
    B[0][2] = 9;
    B[1][0] = 0;
    B[1][1] = 1;
    B[1][2] = 2;
    B[2][0] = 3;
    B[2][1] = 4;
    B[2][2] = 5;

    A *= B;

    CHECK(A[0][0] == 16);
    CHECK(A[0][1] == 22);
    CHECK(A[0][2] == 28);
    CHECK(A[1][0] == 12);
    CHECK(A[1][1] == 17);
    CHECK(A[1][2] == 22);
    CHECK(A[2][0] == 35);
    CHECK(A[2][1] == 46);
    CHECK(A[2][2] == 57);
}

TEST_CASE("Matrix *= scalar")
{
    SquareMat A(3);
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[1][0] = 4;
    A[1][1] = 5;
    A[1][2] = 6;
    A[2][0] = 7;
    A[2][1] = 8;
    A[2][2] = 9;

    A *= 2;

    CHECK(A[0][0] == 2);
    CHECK(A[0][1] == 4);
    CHECK(A[0][2] == 6);
    CHECK(A[1][0] == 8);
    CHECK(A[1][1] == 10);
    CHECK(A[1][2] == 12);
    CHECK(A[2][0] == 14);
    CHECK(A[2][1] == 16);
    CHECK(A[2][2] == 18);
}

TEST_CASE("Matrix /= scalar")
{
    SquareMat A(3);
    A[0][0] = 2;
    A[0][1] = 4;
    A[0][2] = 6;
    A[1][0] = 8;
    A[1][1] = 10;
    A[1][2] = 12;
    A[2][0] = 14;
    A[2][1] = 16;
    A[2][2] = 18;

    A /= 2;

    CHECK(A[0][0] == 1);
    CHECK(A[0][1] == 2);
    CHECK(A[0][2] == 3);
    CHECK(A[1][0] == 4);
    CHECK(A[1][1] == 5);
    CHECK(A[1][2] == 6);
    CHECK(A[2][0] == 7);
    CHECK(A[2][1] == 8);
    CHECK(A[2][2] == 9);
}

TEST_CASE("Matrix %= scalar")
{
    SquareMat A(3);
    A[0][0] = 5;
    A[0][1] = 10;
    A[0][2] = 15;
    A[1][0] = 20;
    A[1][1] = 25;
    A[1][2] = 30;
    A[2][0] = 35;
    A[2][1] = 40;
    A[2][2] = 45;

    A %= 7;

    CHECK(A[0][0] == 5);
    CHECK(A[0][1] == 3);
    CHECK(A[0][2] == 1);
    CHECK(A[1][0] == 6);
    CHECK(A[1][1] == 4);
    CHECK(A[1][2] == 2);
    CHECK(A[2][0] == 0);
    CHECK(A[2][1] == 5);
    CHECK(A[2][2] == 3);
}
TEST_CASE("Invalid Matrix Size")
{
    CHECK_THROWS_AS(SquareMat(0), std::invalid_argument);
    CHECK_THROWS_AS(SquareMat(-3), std::invalid_argument);
}

TEST_CASE("Addition with different sizes throws")
{
    SquareMat A(3), B(2);
    CHECK_THROWS_AS(A + B, std::invalid_argument);
}

TEST_CASE("Subtraction with different sizes throws")
{
    SquareMat A(3), B(2);
    CHECK_THROWS_AS(A - B, std::invalid_argument);
}

TEST_CASE("Multiplication with different sizes throws")
{
    SquareMat A(3), B(2);
    CHECK_THROWS_AS(A * B, std::invalid_argument);
}

TEST_CASE("Modulo Matrix with different sizes throws")
{
    SquareMat A(3), B(2);
    CHECK_THROWS_AS(A % B, std::invalid_argument);
}

TEST_CASE("Division by zero throws")
{
    SquareMat A(3);
    CHECK_THROWS_AS(A / 0, std::logic_error);
}

TEST_CASE("Invalid scalar modulo throws")
{
    SquareMat A(3);
    CHECK_THROWS_AS(A % 0, std::invalid_argument);
    CHECK_THROWS_AS(A % -5, std::invalid_argument);
}

TEST_CASE("Modulo by matrix with zero element throws")
{
    SquareMat A(3), B(3);
    A[0][0] = 5;
    A[0][1] = 5;
    A[0][2] = 5;
    A[1][0] = 5;
    A[1][1] = 5;
    A[1][2] = 5;
    A[2][0] = 5;
    A[2][1] = 5;
    A[2][2] = 5;
    B[0][0] = 1;
    B[0][1] = 2;
    B[0][2] = 3;
    B[1][0] = 4;
    B[1][1] = 0;
    B[1][2] = 6;
    B[2][0] = 7;
    B[2][1] = 8;
    B[2][2] = 9;
    CHECK_THROWS_AS(A %= B, std::logic_error);
}

TEST_CASE("Out of bounds access throws")
{
    SquareMat A(3);
    CHECK_THROWS_AS(A[-1], std::out_of_range);
    CHECK_THROWS_AS(A[3], std::out_of_range);
}
