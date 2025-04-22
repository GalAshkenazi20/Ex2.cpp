#ifndef _MATRIX_HPP
#include <iostream> 
#include <stdexcept>
#include <cmath>

namespace Matrix {
class SquareMat {
    private:
        double** matrix;
        int size;
    public:
        SquareMat(int size);
        SquareMat(const SquareMat& matrix);
        ~SquareMat();
        SquareMat operator+(const SquareMat& mat1);
        SquareMat operator-(const SquareMat& mat1);
        SquareMat operator-();
        SquareMat operator*(const SquareMat& mat1);
        SquareMat operator*(double scalar);
        friend SquareMat operator*(double scalar, const SquareMat& mat);
        SquareMat operator%(const SquareMat& mat1);
        SquareMat operator%(int scalar);
        
};  
}
#endif

