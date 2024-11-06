#ifndef __QUEUE__HPP__
#define __QUEUE__HPP__
#include "queue.h"

template <typename T>
Queue<T>::Queue(std::initializer_list<value_type> init)
{
    vec = std::vector<value_type>(init);
}

template <typename T>
Queue<T>::Queue(const Queue &other)
{
    vec = other.vec;
}

template <typename T>
Queue<T>::Queue(Queue &&other)
{
    vec = std::move(other.vec);
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue &rhs) noexcept
{
    vec = rhs.vec;
    return *this;
}

template <typename T>
Queue<T> &Queue<T>::operator=(Queue &&rhs) noexcept
{
    vec = std::move(rhs.vec);
    return *this;
}

template <typename T>
void Queue<T>::pop()
{
    vec.erase(vec.begin());
}

template <typename T>
typename Queue<T>::const_reference Queue<T>::front() const
{
    return vec.front();
}

template <typename T>
typename Queue<T>::reference Queue<T>::front()
{
    return vec.front();
}

template <typename T>
typename Queue<T>::const_reference Queue<T>::back() const
{
    return vec.back();
}

template <typename T>
typename Queue<T>::reference Queue<T>::back()
{
    return vec.back();
}

template <typename T>
void Queue<T>::push(const value_type &value)
{
    vec.push_back(value);
}

template <typename T>
void Queue<T>::push(value_type &&value)
{
    vec.push_back(value);
}

template <typename T>
bool Queue<T>::empty() const
{
    return vec.empty();
}

template <typename T>
typename Queue<T>::size_type Queue<T>::size() const
{
    return vec.size();
}

#endif