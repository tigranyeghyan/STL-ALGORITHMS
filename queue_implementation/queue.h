#ifndef __QUEUE__H__
#define __QUEUE__H__
#include <vector>
#include <initializer_list>

template <typename T>
class Queue
{
public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t;

    Queue() = default;
    Queue(std::initializer_list<value_type> init); 
    Queue(const Queue& other);
    Queue(Queue&& other);
    Queue& operator=(const Queue& rhs) noexcept;
    Queue& operator=(Queue&& rhs) noexcept;
    ~Queue() = default;

    void pop();
    const_reference front() const;
    reference front();
    const_reference back() const;
    reference back();
    void push(const value_type& value);
    void push(value_type&& value);
    bool empty() const;
	size_type size() const;
    
private:
    std::vector <value_type> vec; 
};

#include "queue.hpp"

#endif

