#ifndef __VECTOR__HPP__
#define __VECTOR__HPP__
#include "vector.h"

// Ctonstructors

template <typename T>
Vector<T>::Vector() : Size{size_type{}}, Capacity{size_type{}}, ptr{ nullptr }
{
}

template <typename T>
Vector<T>::Vector(size_type size) : Size{ size }, Capacity{ size }, ptr{ new value_type[size] }
{
}
	
template <typename T>
Vector<T>::Vector(size_type size, const_reference value) : Size{ size }, Capacity{ size }, ptr{ new value_type[Size] }
{
	for (size_type i = 0; i < Size; ++i)
	{
		ptr[i] = value;
	}
}

template <typename T>
Vector<T>::Vector(std::initializer_list<value_type> init) : Size{init.size()}, Capacity{size}, ptr{ new value_type[Size] }
{
	size_type i = 0;
	for (value_type val : init)
	{
		ptr[i++] = val;
	}
}

template <typename T>
Vector<T>::Vector(const Vector& other) : Size{ other.Size() }, Capacity{ Size }, ptr{ new value_type[Size] }
{
	for (size_type i = 0; i < Size; ++i)
	{
		ptr[i] = other.ptr[i];
	}
}

template <typename T>
Vector<T>::Vector(Vector&& other) : Size{ other.Size() }, capacity{ Size }, ptr{ other.ptr }
{
	other.Size = 0;
	other.Capacity = 0;
	other.ptr = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& rhs) noexcept
{
	delete[]ptr;
	Size = rhs.size();
	Capacity = Size;
	for (size_t i = 0; i < Size; ++i)
	{
		ptr[i] = othe.ptr[i];
	}
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& rhs) noexcept
{
	delete[]ptr;
	Size = rhs.Size();
	Capacity = Size;
	ptr = rhs.ptr;
	rhs.ptr = nullptr;
	rhs.Size = 0;
	rhs.Capacity = 0;
}

//Destructors

template <typename T>
Vector<T>::~Vector()
{
	if (ptr != nullptr)
	{
		delete ptr;
		ptr = nullptr;
	}
}

template <typename T>
Vector<T>::size_type Vector<T>::size() const
{
	return Size;
}

template <typename T>
Vector<T>::size_type Vector<T>::capacity() const
{
	return Capacity;
}

template <typename T>
bool Vector<T>::empty() const
{
	return ptr == nullptr;
}

template <typename T>
void Vector<T>::assign(size_type count, const_reference value)
{
	if (count != 0)
	{
		this -> resize(count);
		for (size_type i = 0; i < count; ++i)
		{
			ptr[i] = value;
		}
	}
}


template<typename T>
void Vector<T>::push_back(const_reference value)
{
	if(!ptr)
	{
		ptr = new value_type[1];
		Size = 1;
		Capacity = 1;
		ptr[Size - 1] = value; 
	}
	else
	{
		if(Capacity > Size)
		{
			ptr[Size++] = value;
		}
		else
		{
			this -> resize(Capacity * 2);
			ptr[Size++] = value;
		}
	}
}

template <typename T>
void Vector<T>::pop_back()
{
	if(ptr)
	{
		Size--;
	}
}

template <typename T>
Vector<T>::reference Vector<T>::front()
{
	if(ptr)
	{
    	return *ptr;
	}
}

template <typename T>
Vector<T>::const_reference Vector<T>::front() const
{	
	if(ptr)
	{
    	return *ptr;
	}
}

template <typename T>
Vector<T>::reference Vector<T>::back()
{
	if(ptr)
	{
		return *(ptr + size - 1);
	}
}

template <typename T>
Vector<T>::const_reference Vector<T>::back() const
{
	if(ptr)
	{
    	return *(ptr + size - 1);
	}
}

template <typename T>
Vector<T>::reference Vector<T>::at(size_type idx)
{
	if(idx >= 0 && ptr)
	{
		return *(ptr + idx);
	}
	else
	{
		throw std::out_of_range;
	}
}

template <typename T>
Vector<T>::const_reference Vector<T>::at(size_type idx) const
{
    if(idx >= 0 && ptr)
	{
		return *(ptr + idx);
	}
	else
	{
		throw std::out_of_range;
	}
}

template <typename T>
Vector<T>::reference Vector<T>::operator[](size_type idx)
{
	return *(ptr + idx);
}

template <typename T>
Vector<T>::const_reference Vector<T>::operator[](size_type idx) const
{
    return *(ptr + idx);
}

template <typename T>
void Vector<T>::reserve(size_type capacity)
{
	if(capacity > Capacity)
	{
		value_type *temp = new value_type[capacity];
		for(size_t i = 0; i < Size; ++i)
		{
			temp[i] = ptr[i];
		}
		delete[]ptr;
		ptr = temp;
		temp = nullptr;
	}
}

template <typename T>
void Vector<T>::resize(size_type size)
{
	if(size < Size)
	{
		size = Size;
	}
	if(size > Size)
	{
		if(Capacity > size)
		{
			Size = size; 
		}
		else
		{
			value_type *temp = new value_type[size];
			for (size_t i = 0; i < Size; ++i)
			{
				temp[i] = ptr[i];
			}
			delete[] ptr;
			ptr = temp;
			temp = nullptr;
			Size = size;
			Capacity = size;
		}
	}
}

template <typename T>
void Vector<T>::resize(size_type size, const_reference value)
{
	if(size < Size)
	{
		size = Size;
	}
	if(size > Size)
	{
		if(Capacity > size)
		{
			for(; Size < size; ++Size)
			{
				ptr[Size] = value;
			}
		}
		else
		{
			value_type *temp = new value_type[size];
			for (size_t i = 0; i < size; ++i)
			{
				temp[i] = ptr[i];
			}
			for(;Size < size; ++Size)
			{
				ptr[Size] = valuel;
			}
			delete[] ptr;
			ptr = temp;
			temp = nullptr;
			Capacity = size;
		}
	}
}



#endif