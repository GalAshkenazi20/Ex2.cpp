#include "SquareMat.hpp"

namespace Matrix

{
    SquareMat::SquareMat(int size)
    {
        if (size <= 0)
        {
            throw std::invalid_argument("invalid size");
        }
        matrix = new double *[size];
        for (int i = 0; i < size; ++i)
        {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] = 0.0;
            }
        }
    }

    SquareMat::SquareMat(const SquareMat &copyMat)
    {
        size = copyMat.size;
        matrix = new double *[size];
        for (int i = 0; i < size; ++i)
        {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] = copyMat.matrix[i][j];
            }
        }
    }

    SquareMat::~SquareMat()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    SquareMat SquareMat::operator+(const SquareMat &mat1)
    {
        if (mat1.size != size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = mat1.matrix[i][j] + this->matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-(const SquareMat &mat1)
    {
        if (mat1.size != size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = this->matrix[i][j] - mat1.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator-()
    {
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = - this->matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(const SquareMat &mat1)
    {
        if (mat1.size != size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                double sum = 0;
                for (int n = 0; n < size; n++)
                {
                    sum += this->matrix[n][j] * mat1.matrix[i][n];
                }
                result.matrix[i][j] = sum;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(double scalar)
    {
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return result;
    }

    SquareMat Matrix::operator*(double scalar, const SquareMat &mat)
    {
        return scalar * mat;
    }

    SquareMat SquareMat::operator%(const SquareMat &mat1)
    {
        if (mat1.size != size)
        {
            throw std::invalid_argument("Matrix do not match");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = mat1.matrix[i][j] * matrix[i][j];
            }
        }
        return result;
    }

    SquareMat SquareMat::operator%(int scalar)
    {
        if (scalar <= 0)
        {
            throw std::invalid_argument("cannot get negative scalar");
        }
        SquareMat result(this->size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
            result.matrix[i][j] = fmod(matrix[i][j], scalar);
            }
        }
        return result;
    }
}

