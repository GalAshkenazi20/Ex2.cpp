//Galashkena1@gmail.com
#include <iostream>
#include "SquareMat.hpp"

using namespace Matrix;
using namespace std;

/* some Main file to example some functions*/
int main() {
        SquareMat A(3);
        A[0][0] = 1; A[0][1] = 2; A[0][2] = 3;
        A[1][0] = 0; A[1][1] = 4; A[1][2] = 5;
        A[2][0] = 1; A[2][1] = 0; A[2][2] = 6;

        cout << "Matrix A:" << endl;
        cout << A << endl;

        SquareMat B(3);
        B[0][0] = 7; B[0][1] = 8; B[0][2] = 9;
        B[1][0] = 0; B[1][1] = 1; B[1][2] = 2;
        B[2][0] = 3; B[2][1] = 4; B[2][2] = 5;

        cout << "Matrix B:" << endl;
        cout << B << endl;

        cout << "Adding A + B:" << endl;
        SquareMat C = A + B;
        cout << C << endl;

        cout << "Multiplying A * B:" << endl;
        SquareMat D = A * B;
        cout << D << endl;

        cout << "Transpose of A (~A):" << endl;
        SquareMat At = ~A;
        cout << At << endl;

        cout << "Determinant of A (!A): ";
        cout << !A << endl;

        cout << "Increasing all elements in A (++A):" << endl;
        ++A;
        cout << A << endl;

        cout << "Multiplying A by 2 (A * 2):" << endl;
        SquareMat E = A * 2;
        cout << E << endl;

        cout << "Comparing matrices: (A == B)? ";
        cout << (A == B ? "Yes" : "No") << endl;
    return 0;
}