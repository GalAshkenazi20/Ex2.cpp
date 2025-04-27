// Galashkena1@gmail.com
#ifndef _MATRIX_HPP
#define _MATRIX_HPP
#include <iostream>
#include <stdexcept>
#include <cmath>

namespace Matrix
{
    // This class is for square matrix. Not using STL things.
    class SquareMat
    {
    private:
        double **matrix; // matrix data
        int size;        // size of matrix

    public:
        // make new matrix with size
        SquareMat(int size);
        // copy matrix
        SquareMat(const SquareMat &matrix);
        // delete matrix memory(destructor)
        ~SquareMat();
        int getSize() const; // get the size of matrix(helper)
        // math operations
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
        SquareMat &operator+=(const SquareMat &mat);
        SquareMat &operator-=(const SquareMat &mat);
        SquareMat &operator*=(const SquareMat &mat);
        SquareMat &operator*=(double scalar);
        SquareMat &operator/=(double scalar);
        SquareMat &operator%=(const SquareMat &mat);
        SquareMat &operator%=(int scalar);
        SquareMat &operator=(const SquareMat &other);
    };

}
#endif
