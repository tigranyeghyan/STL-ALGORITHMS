#ifndef __VECTOR__H__
#define __VECTOR__H__
#include <initializer_list>
#include <stdexcept>

template <typename T>
class Vector
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t;

    Vector();
    Vector(size_type size);
    Vector(size_type size, const_reference value);
    Vector(std::initializer_list<value_type> init);
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector& operator=(const Vector& rhs) noexcept;
    Vector& operator=(Vector&& rhs) noexcept;
    ~Vector();

    bool empty() const;
    size_type capacity() const;
    size_type size() const;
    void assign(size_type count, const_reference value);
    void push_back(const_reference value);
    void pop_back();
    reference front();
    const_reference front() const;
    reference back();
    const_reference back() const;
    reference at(size_type idx);
    const_reference at(size_type idx) const;
    reference operator[](size_type idx);
    const_reference operator[](size_type idx) const;
    size_type insert(size_type idx, const_reference value);
    size_type insert(size_type idx, std::initializer_list<value_type> init);
    size_type erase(size_type idx);
    size_type erase(size_type first, size_type last);
    void reserve(size_type capacity);
    void resize(size_type size);
    void resize(size_type size, const_reference value);

private:
    size_type m_size;
    size_type m_capacity;
    value_type* m_ptr;
};

#include "vector.hpp"

#endif