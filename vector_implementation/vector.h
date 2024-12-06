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

    class const_iterator {
        friend Vector<value_type>;
    protected:
        pointer ptr;
        explicit const_iterator(pointer p) : ptr {p} { }
    public:
        using iterator_category = std::random_access_iterator_tag;

        const_iterator() : ptr {nullptr} {}
        const_iterator(const const_iterator& rhv) : ptr{rhv.ptr} {}
        const_iterator(const_iterator&& rhv) : ptr{rhv.ptr} {rhv.ptr{nullptr};}
        const const_iterator& operator=(const const_iterator& rhv) noexcept
        {
            ptr = rhv.ptr;
            return *this;
        }
        const const_iterator& operator=(const_iterator&& rhv) noexcept
        {
            ptr = rhv.ptr;
            rhv.ptr = nullptr;
            return *this;
        }
        bool operator==(const const_iterator& rhv) const
        {
            return ptr == rhv.ptr;
        }
        bool operator!=(const const_iterator& rhv) const
        {
            return ptr != rhv.ptr;
        }
        bool operator<(const const_iterator& rhv) const 
        {
            return ptr < rhv.ptr;
        }
        bool operator>(const const_iterator& rhv) const
        {
            return ptr > rhv.ptr;
        }
        bool operator<=(const const_iterator& rhv) const
        {
            return ptr <= rhv.ptr;
        }
        bool operator>=(const const_iterator& rhv) const
        {
            return ptr >= rhv.ptr;
        }
        const_reference operator*() const
        {
            assert(ptr != nullptr);
            return *ptr;
        }
        const const_pointer operator->() const
        {
            assert(ptr != nullptr);
            return ptr;
        }
        const const_iterator operator+(ssize_t count)
        {
            assert(ptr != nullptr);
            return const_iterator(ptr + count);
        }
        size_t operator-(const const_iterator& other)
        {
            assert(ptr != nullptr);
            assert(other.ptr != nullptr);
            return ptr - other.ptr;
        }
        const const_iterator& operator+=(ssize_t count)
        {
            assert(ptr != nullptr);
            ptr += count;
            return *this;
        }
        const const_iterator& operator-=(ssize_t count)
        {
            assert(ptr != nullptr);
            ptr -= count;
            return *this;
        }
        const const_iterator& operator++()
        {
            assert(ptr != nullptr);
            ptr++;
            return *this;
        }
        const const_iterator operator++(value_type)
        {
            assert(ptr != nullptr);
            const_iterator old(ptr++);
            return tmp;
        }
        const const_iterator& operator--()
        {
            assert(ptr != nullptr);
            ptr--;
            return *this;
        }
        const const_iterator operator--(value_type)
        {
            assert(ptr != nullptr);
            const_iterator old(ptr--);
            return old;
        }
    };


    class iterator : public const_iterator {
        friend Vector<value_type>;
    public:
        using iterator_category = std::random_access_iterator_tag;
        iterator() : ptr{} { }
        iterator(const iterator& rhv) : ptr{rhv.ptr} {}
        iterator(iterator&& rhv) : ptr{rhv.ptr} {rhv.ptr{nullptr};}
        reference operator*() const 
        {
            assert(ptr != nullptr);
            return *ptr;
        }
        pointer operator->() const
        {
            assert(ptr != nullptr);
            return ptr;
        }
    protected:
        explicit iterator(pointer p) : ptr{} { }
    };


    class const_reverse_iterator {
        friend Vector<value_type>;
    protected:  
        pointer ptr;
        explicit const_reverse_iterator(pointer p) : ptr{p} {}
    public:
        using iterator_category = std::random_access_iterator_tag;
        const_reverse_iterator() : ptr{} { }
        const_reverse_iterator(const const_reverse_iterator& rhv) : ptr{rhv.ptr} { }
        const_reverse_iterator(const_reverse_iterator&& rhv) : ptr{rhv.ptr} {rhv.ptr{nullptr};}
        const const_reverse_iterator& operator=(const const_reverse_iterator& rhv) noexcept
        {
            if(*this == rhv)
            {
                return *this;
            }
            ptr = rhv.ptr;
            return *this;
        } 
        const const_reverse_iterator& operator=(const_reverse_iterator&& rhv) noexcept
        {
            if(*this == rhv)
            {
                return *this;
            }
            ptr = rhv.ptr;
            rhv.ptr = nullptr;
            return *this;
        }
        const_reference operator*() const 
        {
            assert(ptr != nullptr);
            return *ptr;
        }
        const_pointer operator->() const
        {
            assert(ptr != nullptr);
            return ptr;
        } 
        const const_reverse_iterator& operator++()
        {
            assert(ptr != nullptr);
            ptr--;
            return *this;
        }
        const const_reverse_iterator operator++(value_type)
        {
            assert(ptr != nullptr);
            const_reverse_iterator old(ptr--);
            return old; 
        }
        const const_reverse_iterator& operator--()
        {
            assert(ptr != nullptr);
            ptr++;
            return *this;
        }
        const const_reverse_iterator operator--(value_type)
        {
            assert(ptr != nullptr);
            const_reverse_iterator old(ptr++);
            return old; 
        }
        const const_iterator operator+=(ssize_t i)
        {
            assert(ptr != nullptr);
            ptr -= i;
            return *this; 
        }
        const const_iterator operator-=(ssize_t i)
        {   
            assert(ptr != nullptr);
            ptr += i;
            return *this;
        }
        const const_reverse_iterator operator+(ssize_t i) const
        {
            assert(ptr != nullptr);
            return const_reverse_iterator(ptr - i);
        }
        const const_reverse_iterator operator-(ssize_t i) const
        {
            assert(ptr != nullptr);
            return const_reverse_iterator(ptr + i);
        }
        bool operator==(const const_reverse_iterator& rhv) const
        {
            return ptr == rhv.ptr;
        }
        bool operator!=(const const_reverse_iterator& rhv) const
        {
            return ptr != rhv.ptr;
        }
        bool operator<(const const_reverse_iterator& rhv) const 
        {
            return ptr > rhv.ptr;
        }
        bool operator>(const const_reverse_iterator& rhv) const
        {
            return ptr < rhv.ptr;
        }
        bool operator<=(const const_reverse_iterator& rhv) const
        {
            return ptr >= rhv.ptr;
        }
        bool operator>=(const const_reverse_iterator& rhv) const
        {
            return ptr <= rhv.ptr;
        }
    };


    class reverse_iterator : public const_reverse_iterator {
        friend Vector<value_type>;
    protected:
        reverse_iterator(pointer p) : ptr{p} { }
    public:
        using iterator_category = std::random_access_iterator_tag;
        reverse_iterator() : ptr{} { }
        reverse_iterator(const iterator& rhv) : ptr{rhv.ptr} {}
        reverse_iterator(iterator&& rhv) : ptr{rhv.ptr} {rhv.ptr{nullptr};}
        reference operator*() const 
        {
            assert(ptr != nullptr);
            return *ptr;
        }
        pointer operator->() const
        {
            assert(ptr != nullptr);
            return ptr;
        }
    };


    iterator begin();
    iterator end();
    const_iterator begin() const;
    const_iterator end() const;
    constexpr const_iterator cbegin() const noexcept;
    constexpr const_iterator cend() const noexcept;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator rbegin() const;
    constexpr const_reverse_iterator crbegin() const noexcept;
    constexpr const_reverse_iterator crend() const noexcept;


    Vector();
    Vector(size_type size);
    Vector(size_type size, const_reference value);
    Vector(std::initializer_list<value_type> init);
    Vector(const Vector& other);
    Vector(Vector&& other);
    Vector& operator=(const Vector& rhs) noexcept;
    Vector& operator=(Vector&& rhs) noexcept;
    ~Vector();

    void clear();
    void reserve(size_type cap);
    void resize(size_type size);
    void resize(size_type size, const_reference value);
    
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

    iterator insert(const_iterator pos, const_reference value);
    iterator insert(const_iterator pos, std::initializer_list<value_type> init);
    iterator erase(const_iterator pos);
    iterator erase(const_iterator first, const_iterator last);

private:
    void reallocate(size_type cap);

private:
    size_type m_size;
    size_type m_capacity;
    value_type* m_ptr;
};

#include "vector.hpp"

#endif