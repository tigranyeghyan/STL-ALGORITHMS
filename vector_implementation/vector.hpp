#ifndef __VECTOR__HPP__
#define __VECTOR__HPP__
#include "vector.h"

// Ctonstructors

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
		delete[] m_ptr;
		m_size = rhs.m_size;
		m_capacity = m_size;
		for (size_t i = 0; i < m_size; ++i)
		{
			m_ptr[i] = rhs.m_ptr[i];
		}
	}
	else
	{
		m_size = rhs.m_size;
		m_capacity = m_size;
		m_ptr = new value_type[m_capacity];
		for (size_t i = 0; i < m_size; ++i)
		{
			m_ptr[i] = rhs.m_ptr[i];
		}
	}
	return *this;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept
{
	delete[]m_ptr;
	m_size = rhs.m_size;
	m_capacity = m_size;
	m_ptr = rhs.m_ptr;
	rhs.m_ptr = nullptr;
	rhs.m_size = 0;
	rhs.m_capacity = 0;
	return *this;
}

//Destructors

template <typename T>
Vector<T>::~Vector()
{
	if (m_ptr != nullptr)
	{
		delete m_ptr;
		m_ptr = nullptr;
	}
}

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

template <typename T>
typename Vector<T>::size_type Vector<T>::insert(size_type idx, const_reference value)
{
	if(idx > m_size)
	{
        throw std::out_of_range("Index out of range for insert");	
	}
	if(idx == m_size)
	{
		reserve(m_capacity == 0 ? 1 : m_capacity * 2);
	}
	for (size_type i = m_size; i > idx; --i) 
	{
        m_ptr[i] = m_ptr[i - 1];
    }
	m_ptr[idx++] = value;
    ++m_size;
	return idx;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::insert(size_type idx, std::initializer_list<value_type> init)
{
	size_t size = init.size();
	auto it = idx;
	for(size_t i = 0; i < size; ++i)
	{
		auto it = this -> insert(it, init[i]);
	}
    return it; 
}

template <typename T>
typename Vector<T>::size_type Vector<T>::erase(size_type idx)
{
	for (size_t i = 0; i < m_size - idx - 1; ++i)
	{
		m_ptr[idx + i] = m_ptr[idx + i + 1];
	}
	m_size--;
	return idx + 1;
}

template <typename T>
typename Vector<T>::size_type Vector<T>::erase(size_type first, size_type last)
{
	for(size_t i = first; i < last; ++i)
	{
		this -> erase(i);
	}
    return last + 1;
}

template <typename T>
void Vector<T>::reserve(size_type capacity)
{
	if(capacity > m_capacity)
	{
		value_type *temp = new value_type[capacity];
		for(size_t i = 0; i < m_size; ++i)
		{
			temp[i] = m_ptr[i];
		}
		delete[]m_ptr;
		m_ptr = temp;
		temp = nullptr;
		m_capacity = capacity;
	}
}

template <typename T>
void Vector<T>::resize(size_type size)
{
	if(size < m_size)
	{
		m_size = size;
	}
	if(size > m_size)
	{
		if(m_capacity > size)
		{
			m_size = size; 
		}
		else
		{
			value_type *temp = new value_type[size];
			for (size_t i = 0; i < size; ++i)
			{
				temp[i] = m_ptr[i];
			}
			delete[] m_ptr;
			m_ptr = temp;
			temp = nullptr;
			m_size = size;
			m_capacity = size;
		}
	}
}

template <typename T>
void Vector<T>::resize(size_type size, const_reference value)
{
	if(size < m_size)
	{
		m_size = size;
	}
	if(size > m_size)
	{
		if(m_capacity > size)
		{
			for(; m_size < size; ++m_size)
			{
				m_ptr[m_size] = value;
			}
		}
		else
		{
			value_type *temp = new value_type[size];
			for (size_t i = 0; i < m_size; ++i)
			{
				temp[i] = m_ptr[i];
			}
			for(; m_size < size; ++m_size)
			{
				m_ptr[m_size] = value;
			}
			delete[] m_ptr;
			m_ptr = temp;
			temp = nullptr;
			m_capacity = m_size;
		}
	}
}

#endif