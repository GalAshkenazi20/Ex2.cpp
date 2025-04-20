#ifndef _MATRIX_HPP
#include <iostream> 
#include <stdexcept>

namespace Matrix {
class SquareMat {
    private:
        double** matrix;
        int size;
    public:
        SquareMat(int size);
        SquareMat(const SquareMat& matrix);
        ~SquareMat();
        friend SquareMat operator+(const SquareMat& mat1, const SquareMat& mat2);
        friend SquareMat operator-(const SquareMat& mat1, const SquareMat& mat2);

};
}
#endif

