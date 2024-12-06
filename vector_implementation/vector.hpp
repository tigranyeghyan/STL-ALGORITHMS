#ifndef __VECTOR__HPP__
#define __VECTOR__HPP__
#include "vector.h"
#include <utility>

template<typename T>
Vector<T>::iterator Vector<T>::begin()
{
	return iterator(m_ptr);
}

template<typename T>
Vector<T>::const_iterator Vector<T>::begin() const 
{
	return const_iterator(m_ptr);
}

template <typename T>
constexpr Vector<T>::const_iterator Vector<T>::cbegin() const noexcept
{
	return const_iterator(m_ptr);
}

template<typename T> 
Vector<T>::iterator Vector<T>::end()
{
	return iterator(nullptr);
}

template <typename T>
Vector<T>::const_iterator Vector<T>::end() const
{
	return const_iterator(nullptr);
}

template <typename T>
constexpr Vector<T>::const_iterator Vector<T>::cend() const noexcept
{
	return const_iterator(nullptr);
}

template <typename T>
Vector<T>::reverse_iterator Vector<T>::rbegin()
{
	return reverse_iterator(m_ptr + m_size - 1);
}

template <typename T>
Vector<T>::const_reverse_iterator Vector<T>::rbegin() const
{
	return const_reverse_iterator(m_ptr + m_size - 1);
}

template <typename T>
constexpr Vector<T>::const_reverse_iterator Vector<T>::crbegin() const noexcept
{
	return const_reverse_iterator(m_ptr + m_size - 1);
}

template <typename T>
Vector<T>::reverse_iterator Vector<T>::rend()
{
	return reverse_iterator(m_ptr);
}

template <typename T>
Vector<T>::const_reverse_iterator Vector<T>::rend() const
{
	return reverse_iterator(m_ptr);
}

template <typename T>
constexpr Vector<T>::const_reverse_iterator Vector<T>::crend() const noexcept
{
	return const_reverse_iterator(m_ptr);
}

////////////// vector manip /////////////////// 
template <typename T>
void Vector<T>::clear()
{
	if(m_ptr)
	{
		delete m_ptr;
		m_size = 0;
		m_ptr = new value_type(m_capacity);
	}
}

template <typename T>
void Vector<T>::reallocate(size_type cap)
{
	value_type* new_ptr = new value_type[cap];
    for (size_t i = 0; i < m_size; ++i) 
	{
        new_ptr[i] = m_ptr[i];
    }
    delete[] m_ptr;
    m_ptr = new_ptr;
    m_capacity = cap;
}


template <typename T>
void Vector<T>::resize(size_type size)
{
	if (size > m_capacity) 
	{
        size_t cap = std::max(size, capacity_ * 2);
        reallocate(cap);
    }

    if (size > m_size) 
	{
        for (size_t i = m_size; i < size; ++i) 
		{
            m_ptr[i] = T(); 
        }
    }
    m_size = size;
}

template <typename T>
void Vector<T>::resize(size_type size, const_reference value)
{
	if (size > m_capacity) 
	{
        size_t cap = std::max(size, capacity_ * 2);
        reallocate(cap);
    }

    if (size > m_size) 
	{
        for (size_t i = m_size; i < size; ++i) 
		{
            m_ptr[i] = value; 
        }
    }
    m_size = size;
}

template <typename T>
void Vector<T>::reserve(size_type cap)
{
	if(cap > m_capacity)
	{
		reallocate(cap)
	}
}

/////// Constructors and assignment operators /////////// 

template <typename T>
Vector<T>::Vector() : m_size{size_type{}}, m_capacity{size_type{}}, m_ptr{ nullptr }
{
}

template <typename T>
Vector<T>::Vector(size_type size) : m_size{ size }, m_capacity{ m_size }, m_ptr{ new value_type[m_size] }
{
}
	
template <typename T>
Vector<T>::Vector(size_type size, const_reference value) : m_size{ size }, m_capacity{ m_size }, m_ptr{ new value_type[m_size] }
{
	for (size_type i = 0; i < m_size; ++i)
	{
		m_ptr[i] = value;
	}
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> init) : m_size{init.size()}, m_capacity{m_size}, m_ptr{ new value_type[m_size] }
{
	size_type i = 0;
	for (value_type val : init)
	{
		m_ptr[i++] = val;
	}
}

template <typename T>
Vector<T>::Vector(const Vector& other) : m_size{ other.m_size }, m_capacity{ m_size }, m_ptr{ new value_type[m_size] }
{
	for (size_type i = 0; i < m_size; ++i)
	{
		m_ptr[i] = other.m_ptr[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector&& other) : m_size{ other.m_size }, m_capacity{ m_size }, m_ptr{ other.m_ptr }
{
	other.m_size = 0;
	other.m_capacity = 0;
	other.m_ptr = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) noexcept
{
	if(m_ptr)
	{
		clear();
	}
	resize(rhs.m_capacity);
	for(size_t i = 0; i < m_size; ++i)
	{
		m_ptr[i] = rhs.m_ptr[i];
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept
{
	clear();
	resize(rhs.m_capacity);
	m_ptr = rhs.m_ptr;
	rhs.m_ptr = nullptr;
	rhs.m_size = 0;
	rhs.m_capacity = 0;
	return *this;
}

//Destructor

template <typename T>
Vector<T>::~Vector()
{
	if (m_ptr != nullptr)
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
}

/////// size manip //////////////

template <typename T>
typename Vector<T>::size_type Vector<T>::size() const
{
	return m_size;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::capacity() const
{
	return m_capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
	return m_ptr == nullptr;
}

template <typename T>
void Vector<T>::assign(size_type count, const_reference value)
{
	for (size_type i = 0; i < count; ++i)
	{
		m_ptr[i] = value;
	}
}

////// element manip /////////////

template<typename T>
void Vector<T>::push_back(const_reference value)
{
	if (m_size >= m_capacity) 
	{
        reserve(m_capacity == 0 ? 1 : m_capacity * 2);
    }
	m_ptr[m_size++] = value;
}

template <typename T>
void Vector<T>::pop_back()
{
	if(m_ptr)
	{
		m_size--;
	}
}

template <typename T>
typename Vector<T>::reference Vector<T>::front()
{
	return *m_ptr;
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::front() const
{	
    return *m_ptr;
}

template <typename T>
typename Vector<T>::reference Vector<T>::back()
{

	return *(m_ptr + m_size - 1);
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::back() const
{
	return *(m_ptr + m_size - 1);
}

template <typename T>
typename Vector<T>::reference Vector<T>::at(size_type idx)
{
	if(idx >= 0 && m_ptr)
	{
		return *(m_ptr + idx);
	}
	else
	{
		throw std::out_of_range("Index out of range");
	}
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::at(size_type idx) const
{
    if(idx >= 0 && m_ptr)
	{
		return *(m_ptr + idx);
	}
	else
	{
		throw std::out_of_range("Index out of range");
	}
}

template <typename T>
typename Vector<T>::reference Vector<T>::operator[](size_type idx)
{
	return *(m_ptr + idx);
}

template <typename T>
typename Vector<T>::const_reference Vector<T>::operator[](size_type idx) const
{
    return *(m_ptr + idx);
}


/////// operations with iterators//////


template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, const_reference value)
{
	size_type idx = pos.ptr - m_ptr;
	if(m_capacity == m_size)
	{
		reserve(m_capacity == 0 ? 1 : m_capacity * 2);
	}
	for (size_type i = m_size; i > idx; --i) 
	{
        m_ptr[i] = m_ptr[i - 1];
    }
	m_ptr[idx] = value;
    ++m_size;
	return iterator(m_ptr + idx);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::insert(const_iterator pos, std::initializer_list<value_type> init)
{
	size_type size = init.size();
	for(size_t i = 0; i < size; ++i)
	{
		pos = insert(pos, init[i]);
	}
    return pos;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator pos)
{
	size_type idx = pos.ptr - m_ptr; 
	if (idx >= m_size) 
	{
        throw std::out_of_range("Erase position out of range");
    }
	for (size_t i = idx; i < m_size - 1; ++i)
	{
		m_ptr[i] = m_ptr[i + 1];
	}
	--m_size;
	return iterator(m_ptr + idx);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::erase(const_iterator first, const_iterator last)
{
	while(first != last)
	{
		first = erase(first);
	}
    return first;
}

#endif