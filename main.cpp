#include "SquareMat.hpp"
using namespace Matrix;

int main()
{
    SquareMat A(4);
    SquareMat B(2);

    A[0][0] = 2;
    A[0][1] = 1;
    A[0][2] = 3.0;
    A[0][3] = 4.0;
    A[1][0] = 0;
    A[1][1] = -1;
    A[1][2] = 2.0;
    A[1][3] = 1.0;
    A[2][0] = 5;
    A[2][1] = 0;
    A[2][2] = 1.0;
    A[2][3] = -2.0;
    A[3][0] = 3;
    A[3][1] = 2;
    A[3][2] = 0;
    A[3][3] = 1.0;
    double mm = !A;
    std::cout << "Det result = "<< mm << "\n";
    B[0][0] = 5.0;
    B[0][1] = 6.0;
    B[1][0] = 7.0;
    B[1][1] = 8.0;

    // SquareMat C = A * B;
    // SquareMat D = 2 * A;
    // SquareMat E = B * 3;

    // std::cout << C;
    // std::cout << D;
    // std::cout << E;
    return 0;
}
