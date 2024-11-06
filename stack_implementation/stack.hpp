#ifndef __STACK__HPP__
#define __STACK__HPP__
#include "stack.h"

template <typename T>
Stack<T>::Stack(std::initializer_list<T> init)
{
    vec = init;
}

template <typename T>
Stack<T>::Stack(const Stack &other)
{
    vec(other.vec);
}

template <typename T>
Stack<T>::Stack(Stack &&other)
{
    vec = std::move(other.vec);
}

template <typename T>
Stack<T>& Stack<T>::operator=(const Stack &rhs) noexcept
{
    vec = rhs.vec;
    return *this;
}

template <typename T>
Stack<T>& Stack<T>::operator=(Stack &&rhs) noexcept
{
    vec = std::move(rhs.vec);
    return *this;
}

template <typename T>
void Stack<T>::push(const_reference item)
{
    vec.push_back(item);
}

template <typename T>
void Stack<T>::pop()
{
    vec.pop_back();
}

template <typename T>
typename Stack<T>::reference Stack<T>::peek()
{
    return vec.back();
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return vec.empty();
}

template <typename T>
typename Stack<T>::size_type Stack<T>::size() const
{
    return vec.size();
}


#endif