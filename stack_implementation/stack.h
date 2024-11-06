#ifndef __STACK__H__
#define __STACK__H__
#include <vector>
#include <initializer_list>

template <typename T>
class Stack
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t;

    Stack() = default;
    Stack(std::initializer_list<T> init);
    Stack(const Stack& other);
    Stack(Stack&& other);
    Stack& operator=(const Stack& rhs) noexcept;
    Stack& operator=(Stack&& rhs) noexcept;
    ~Stack() = default;
    
    void push(const_reference item);
    void pop();
    reference peek();
    bool isEmpty() const;
    size_type size() const;
    
private:
    std::vector<T> vec;
};

#include "stack.hpp"

#endif