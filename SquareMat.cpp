// Galashkena1@gmail.com
#include "SquareMat.hpp"

namespace Matrix

{
    // Constructor: Creates a new empty square matrix with the given size.
    // Initializes all elements to 0. Throws an exception if size is invalid.
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
    // Copy Constructor: Creates a deep copy of another matrix.
    // Allocates new memory and copies each element individually.
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
    // Destructor: Releases the allocated memory for the matrix.
    // Deletes each row and then deletes the array of pointers.
    SquareMat::~SquareMat()
    {
        for (int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }
    // This return the size of the matrix.
    int SquareMat::getSize() const
    {
        return size;
    }
    // Adds two matrices of the same size and returns a new matrix with the result.
    // Throws an exception if the matrices have different sizes.
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
                result[i][j] = mat1[i][j] + matrix[i][j];
            }
        }
        return result;
    }
    // Subtracts one matrix from another and returns a new matrix with the result.
    // Throws an exception if the matrices have different sizes.
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
    // Unary minus: Returns a new matrix where each element is negated.
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
    // Multiplies two matrices using standard matrix multiplication rules.
    // Throws an exception if matrix sizes do not match.
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
    // Multiplies the matrix by a scalar value and returns a new matrix.
    // Each element is multiplied by the scalar.
    SquareMat SquareMat::operator*(double scalar)
    {
        SquareMat result(size);
        for (int i = 0; i < size; ++i)
            for (int j = 0; j < size; ++j)
                result.matrix[i][j] = matrix[i][j] * scalar;
        return result;
    }
    // Multiplies a scalar by a matrix. (friend function for commutative behavior)
    // Each element of the matrix is multiplied by the scalar.
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
    // Performs element-wise multiplication between two matrices.
    // Both matrices must have the same size. Throws an exception if sizes do not match.
    // Returns a new matrix with the result.
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
    // Performs modulo operation for each element in the matrix with a scalar value.
    // Throws an exception if the scalar is non-positive.
    // Returns a new matrix with the result.
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
    // Divides each element of the matrix by a scalar value.
    // Throws an exception if the scalar is zero (division by zero not allowed).
    // Returns a new matrix with the result.
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
    // Raises the matrix to the power of n.
    // If n == 1, returns the identity matrix. If n > 1, multiplies the matrix by itself n times.
    // Throws an exception if n is negative.
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
    // Prefix increment: Adds 1 to every element in the matrix and returns the updated matrix.
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
    // Prefix decrement: Subtracts 1 from every element in the matrix and returns the updated matrix.
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
    // Postfix increment: Adds 1 to every element, but returns a copy of the matrix before the increment.
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
    // Postfix decrement: Subtracts 1 from every element, but returns a copy of the matrix before the decrement.
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
    // Transposes the matrix (switches rows with columns) and returns the result.
    SquareMat SquareMat::operator~()
    {
        SquareMat result(size);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result[i][j] = matrix[j][i];
            }
        }
        return result;
    }
    // Returns a pointer to the row at index i.
    // Allows both reading and writing elements. Throws exception if index is invalid.
    double *SquareMat::operator[](int i)
    {
        if (i < 0 || i >= size)
        {
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[i];
    }
    // Returns a const pointer to the row at index i.
    // Allows only reading elements. Throws exception if index is invalid.
    const double *SquareMat::operator[](int i) const
    {
        if (i < 0 || i >= size)
        {
            throw std::out_of_range("Row index out of bounds");
        }
        return matrix[i];
    }
    // Compares two matrices by summing all elements and checking if the sums are equal.
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
    // Checks if two matrices are not equal based on the sum of their elements.
    bool SquareMat::operator!=(const SquareMat &mat)
    {
        return !(*this == mat);
    }
    // Checks if the sum of this matrix is smaller than the sum of another matrix.
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
    // Checks if the sum of this matrix is greater than the sum of another matrix.
    bool SquareMat::operator>(const SquareMat &mat)
    {
        return !(*this < mat || *this == mat);
    }
    // Checks if the sum of this matrix is smaller or equal to the sum of another matrix.
    bool SquareMat::operator<=(const SquareMat &mat)
    {
        return (*this < mat || *this == mat);
    }
    // Checks if the sum of this matrix is greater or equal to the sum of another matrix.
    bool SquareMat::operator>=(const SquareMat &mat)
    {
        return (*this > mat || *this == mat);
    }
    // Helper function: creates a smaller matrix by removing a specified row and column.
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
    // Recursively calculates the determinant of a matrix.
    // Expands along the first row.
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
    // Calculates and returns the determinant of the matrix (using the ! operator).
    double SquareMat::operator!()
    {
        return det(*this, size);
    }
    // Adds another matrix into this matrix (element-wise).
    // Throws exception if sizes do not match.
    // After I used the = operator for the tests, I could write (*this = *this+ mat;
    // return *this;)
    // but this is less efficient because I create a new object in the temporary variable (+) and then copy all the contents back to *this,
    // meaning a double operation of appending + copying.
    SquareMat &SquareMat::operator+=(const SquareMat &mat)
    {
        if (size != mat.size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] += mat[i][j];
            }
        }

        return *this;
    }
    // Subtracts another matrix from this matrix (element-wise).
    // Throws exception if sizes do not match.
    // Same explanation as in the method above (why I don't use line abbreviations)
    SquareMat &SquareMat::operator-=(const SquareMat &mat)
    {
        if (size != mat.size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }

        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] -= mat[i][j];
            }
        }

        return *this;
    }
    // Multiplies this matrix by another matrix and stores the result.
    // Throws exception if sizes do not match.
    SquareMat &SquareMat::operator*=(const SquareMat &mat)
    {
        if (mat.size != size)
        {
            throw std::invalid_argument("Matrix size do not match");
        }

        double **result = new double *[size];
        for (int i = 0; i < size; i++)
        {
            result[i] = new double[size];
            for (int j = 0; j < size; j++)
            {
                result[i][j] = 0;
                double sum = 0;

                for (int n = 0; n < size; n++)
                {
                    sum += this->matrix[i][n] * mat.matrix[n][j];
                }
                result[i][j] = sum;
            }
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                matrix[i][j] = result[i][j];
            }
            delete[] result[i];
        }
        delete[] result;

        return *this;
    }
    // Multiplies this matrix by a scalar value.
    SquareMat &SquareMat::operator*=(double scalar)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = this->matrix[i][j] * scalar;
            }
        }
        return *this;
    }
    // Divides this matrix by a scalar value.
    // Throws an exception if the scalar is 0.
    SquareMat &SquareMat::operator/=(double scalar)
    {
        if (scalar == 0)
        {
            throw std::logic_error("Cannot divide by 0\n");
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = this->matrix[i][j] / scalar;
            }
        }
        return *this;
    }
    // Performs element-wise modulo operation with another matrix.
    // Throws exception if sizes do not match or if modulo by zero occurs.
    SquareMat &SquareMat::operator%=(const SquareMat &mat)
    {
        if (size != mat.size)
        {
            throw std::invalid_argument("Size of Matrix do not match");
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (mat[i][j] == 0)
                {
                    throw std::logic_error("Cant mod 0!");
                }
            }
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = fmod(this->matrix[i][j], mat[i][j]);
            }
        }
        return *this;
    }
    // Performs modulo operation on each element with a scalar.
// Throws exception if the scalar is non-positive.
    SquareMat &SquareMat::operator%=(int scalar)
    {
        if (scalar <= 0)
        {
            throw std::logic_error("cant mod with this argument");
        }
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                this->matrix[i][j] = fmod(this->matrix[i][j], scalar);
            }
        }
        return *this;
    }
    // Assignment operator: Copies another matrix into this matrix (deep copy).
    SquareMat &SquareMat::operator=(const SquareMat &other)
    {
        if (this == &other)
            return *this;

        for (int i = 0; i < size; ++i)
            delete[] matrix[i];
        delete[] matrix;

        size = other.size;
        matrix = new double *[size];
        for (int i = 0; i < size; ++i)
        {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j)
            {
                matrix[i][j] = other.matrix[i][j];
            }
        }

        return *this;
    }
    // Prints the matrix to an output stream (e.g., cout).
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
