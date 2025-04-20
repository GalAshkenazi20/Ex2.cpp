#include "SquareMat.hpp"

using namespace Matrix; 

    SquareMat::SquareMat(int size)
    {
        if (size <= 0) 
    {
        throw std::invalid_argument("invalid size");
    }
        matrix = new double*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = 0.0;
            }
        }
    }

    SquareMat::SquareMat(const SquareMat& copyMat) {
        size = copyMat.size;
        matrix = new double*[size];
        for (int i = 0; i < size; ++i) {
            matrix[i] = new double[size];
            for (int j = 0; j < size; ++j) {
                matrix[i][j] = copyMat.matrix[i][j];
            }
        }
    }

    Matrix::SquareMat::~SquareMat()
    {
        for(int i = 0; i < size; i++)
        {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

    SquareMat Matrix::operator+(const SquareMat &mat1, const SquareMat &mat2)
    {
        if(mat1.size != mat2.size){
            throw std::invalid_argument("Matrix size do not match");
        }
        SquareMat result(mat1.size);
        for (int i = 0; i < mat1.size; i++)
        {
            for (int j = 0; j < mat1.size; j++)
            {
                result.matrix[i][j] = mat1.matrix[i][j] + mat2.matrix[i][j];
            }
        }
        return result;
    }

    SquareMat Matrix::operator-(const SquareMat &mat1, const SquareMat &mat2)
    {
        if(mat1.size != mat2.size){
            throw std::invalid_argument("Matrix size do not match");
        }
        SquareMat result(mat1.size);
        for (int i = 0; i < mat1.size; i++)
        {
            for (int j = 0; j < mat1.size; j++)
            {
                result.matrix[i][j] = mat1.matrix[i][j] - mat2.matrix[i][j];
            }
        }
        return result;
    }