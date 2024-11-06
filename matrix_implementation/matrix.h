#ifndef __MATRIX__H__
#define __MATRIX__H__

template <typename T>
class Matrix
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t;

    Matrix();
    Matrix(size_type rows, size_type cols);
    Matrix(const Matrix& other);
    Matrix(Matrix&& other);
    Matrix& operator=(const Matrix& rhs) noexcept;
    Matrix& operator=(Matrix&& rhs) noexcept;

    size_type rows() const;
    size_type cols() const;
    void transpose();

    Matrix operator+(const Matrix& other);
    Matrix& operator+=(const Matrix& other);
    Matrix operator*(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    std::ostream operator<<(std::ostream os, const Matrix& matrix);
    value_type operator()(size_type rows, size_type cols);
    std::vector<value_type>& operator[](size_t rows);

private:
    std::vector<std::vector<value_type>> matrix(0, std::vector<value_type>(0));
    size_type rows_;
    size_type cols_;
};

#include "matrix.hpp"

#endif

