#include "SquareMat.hpp"

namespace Matrix

{
    SquareMat helperToDet(const SquareMat &mat, int n, int row_to_remove, int col_to_remove);
    double det(const SquareMat &m, int size);

    SquareMat::SquareMat(int s)
    {
        if (s <= 0)
        {
            throw std::invalid_argument("invalid size");
        }
        size = s;
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

    int SquareMat::getSize() const
    {
        return size;
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
                result.matrix[i][j] = -this->matrix[i][j];
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
                    sum += this->matrix[i][n] * mat1.matrix[n][j];
                }
                result.matrix[i][j] = sum;
            }
        }
        return result;
    }

    SquareMat SquareMat::operator*(double scalar)
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.matrix[i][j] = matrix[i][j] * scalar;
        return result;
    }

    SquareMat operator*(double scalar, const SquareMat &mat)
    {
        SquareMat result(mat.size);
        for (int i = 0; i < mat.size; ++i)
        {
            for (int j = 0; j < mat.size; ++j)
            {
                result.matrix[i][j] = scalar * mat.matrix[i][j];
            }
        }
        return result;
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

    SquareMat SquareMat::operator/(double scalar)
    {
        if (scalar == 0)
        {
            throw std::logic_error("cannot divide by 0");
        }
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result.matrix[i][j] = matrix[i][j] / scalar;
            }
        }
        return result;
    }
    SquareMat SquareMat::operator^(int n)
    {
        if (n < 0)
        {
            throw std::invalid_argument("cannot get negative number");
        }
        SquareMat result = (*this);
        if (n == 1)
        {
            for (int i = 0; i < size; i++)
            {
                for (int j = 0; j < size; j++)
                {
                    if (i == j)
                    {
                        result.matrix[i][j] = 1;
                    }
                    else
                    {
                        result.matrix[i][j] = 0;
                    }
                }
            }
            return result;
        }

        while (n > 1)
        {
            result = result * (*this);
            n--;
        }
        return result;
    }
    SquareMat SquareMat::operator++()
    {

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] += 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator--()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= 1;
            }
        }
        return *this;
    }

    SquareMat SquareMat::operator++(int)
    {
        SquareMat result = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] += 1;
            }
        }
        return result;
    }
    SquareMat SquareMat::operator--(int)
    {
        SquareMat result = *this;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] -= 1;
            }
        }
        return result;
    }
    SquareMat SquareMat::operator~()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                double temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return *this;
    }
    double *SquareMat::operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[i];
    }

    const double *SquareMat::operator[](int i) const
    {
        if (i < 0 || i >= size)
        {
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[i];
    }
    bool SquareMat::operator==(const SquareMat &mat)
    {
        double count0 = 0;
        double count1 = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                count0 += this->matrix[i][j];
            }
        }
        for (int i = 0; i < mat.size; i++)
        {
            for (int j = 0; j < mat.size; j++)
            {
                count1 += mat[i][j];
            }
        }
        return (count0 == count1);
    }

    bool SquareMat::operator!=(const SquareMat &mat)
    {
        return !(*this == mat);
    }
    bool SquareMat::operator<(const SquareMat &mat)
    {
        double count0 = 0;
        double count1 = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                count0 += this->matrix[i][j];
            }
        }
        for (int i = 0; i < mat.size; i++)
        {
            for (int j = 0; j < mat.size; j++)
            {
                count1 += mat[i][j];
            }
        }
        return (count0 < count1);
    }
    bool SquareMat::operator>(const SquareMat &mat)
    {
        return !(*this < mat);
    }

    bool SquareMat::operator<=(const SquareMat &mat)
    {
        return !(*this > mat && *this == mat);
    }

    bool SquareMat::operator>=(const SquareMat &mat)
    {
        return (*this > mat && *this == mat);
    }
    SquareMat helperToDet(const SquareMat &mat, int n, int row_to_remove, int col_to_remove)
    {
        int subRow = 0;

        SquareMat result(n);
        for (int i = 0; i < mat.getSize(); i++)
        {
            if (i == row_to_remove)
            {
                continue;
            }
            int subCol = 0;
            for (int j = 0; j < mat.getSize(); j++)
            {
                if (!(j == col_to_remove))
                {
                    result[subRow][subCol] = mat[i][j];
                    subCol++;
                }
                else
                {
                    continue;
                }
            }
            subRow++;
        }

        return result;
    }
    double det(const SquareMat &m, int size)
    {
        if (size == 0)
        {
            throw std::invalid_argument("Cannot use with size 0");
        }
        if (size == 1)
        {
            return m[0][0];
        }

        if (size == 2)
        {
            return (m[0][0] * m[1][1]) - (m[0][1] * m[1][0]);
        }

        double sum = 0.0;
        int subIndex = size - 1;
        for (int i = 0; i < size; i++)
        {
            sum += (pow(-1, i) * m[0][i]) * det(helperToDet(m, subIndex, 0, i), subIndex);
        }
        return sum;
    }

    double SquareMat::operator!()
    {
        return det(*this, size);
    }

    std::ostream &operator<<(std::ostream &os, const SquareMat &mat)
    {
        for (int i = 0; i < mat.size; i++)
        {
            for (int j = 0; j < mat.size; j++)
            {
                os << mat[i][j] << " ";
            }
            os << "\n";
        }
        return os;
    }

}
