#ifndef __MATRIX__HPP__
#define __MATRIX__HPP__
#include "matrix.h"

template <typename T>
Matrix<T>::Matrix()
{
    rows_ = 0;
    cols_ = 0;
}

template <typename T>
Matrix<T>::Matrix(size_type rows, size_type cols)
{
    matrix = std::vector<std::vector<value_type>>(rows, std::vector<value_type>(0)); 
    rows_ = rows;
    cols_ = cols;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &other)
{
    
}

#endif