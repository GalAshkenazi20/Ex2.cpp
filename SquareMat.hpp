#ifndef _MATRIX_HPP
#define _MATRIX_HPP
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace Matrix
{
    class SquareMat
    {
    private:
        double **matrix;
        int size;

    public:
        SquareMat(int size);
        SquareMat(const SquareMat &matrix);
        ~SquareMat();
        int getSize() const;
        SquareMat operator+(const SquareMat &mat1);
        SquareMat operator-(const SquareMat &mat1);
        SquareMat operator-();
        SquareMat operator*(const SquareMat &mat1);
        SquareMat operator*(double scalar);
        friend SquareMat operator*(double scalar, const SquareMat &mat);
        SquareMat operator%(const SquareMat &mat1);
        SquareMat operator%(int scalar);
        SquareMat operator/(double scalar);
        SquareMat operator^(int n);
        SquareMat operator++();
        SquareMat operator--();
        SquareMat operator++(int);
        SquareMat operator--(int);
        SquareMat operator~();
        double *operator[](int i);
        const double *operator[](int i) const;
        friend std::ostream &operator<<(std::ostream &os, const SquareMat &mat);
        bool operator==(const SquareMat &mat);
        bool operator!=(const SquareMat &mat);
        bool operator<(const SquareMat &mat);
        bool operator>(const SquareMat &mat);
        bool operator<=(const SquareMat &mat);
        bool operator>=(const SquareMat &mat);
        double operator!();
    };

}
#endif
