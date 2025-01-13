#ifndef __FORWARD_LIST__
#define __FORWARD_LIST__
#include <iterator>

template <typename T>
class forward_list
{

public:
    using value_type = T;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const value_type*;
    using size_type = size_t;
    using difference_type = size_t;
private:
    class Node
    {
    public:
        value_type value;
        Node *next;
        Node() : value{value_type{}}, next{nullptr} {}
        Node(value_type val) : value{val}, next{nullptr} {}
        Node(value_type val, Node *nxt) : value{val}, next{nxt} {}
    };
public:
    class const_iterator
    {
        friend class forward_list<value_type>;
        using category = std::forward_iterator_tag;
        
    };
    class iterator : public const_iterator
    {
        friend class forward_list<value_type>;
        using category = std::forward_iterator_tag;

    };
private:
    Node *head;
    size_type size;
};

#include "forward_list.cpp"
#endif