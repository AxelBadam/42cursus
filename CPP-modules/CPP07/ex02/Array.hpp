#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

#include <iostream>

template <typename T>
class Array {
public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array &operator=(const Array &rhs);
    ~Array();
	size_t size() const;

private:
    T* arr;
	size_t arr_size;
};

template <typename T>
Array<T>::Array() : arr(NULL), arr_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr(new T[n]), arr_size(n) {}

template <typename T>
Array<T>::Array(const Array& other)
{	
	if (arr_size > 0)
	{
		this->arr_size = other.arr_size;
		this->arr = new T[arr_size];
		for (size_t i = 0; i < arr_size; i++)
			arr[i] = other.arr[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &rhs) {
    if (this != &rhs) 
	{
        // assignment operator implementation
        // Remember to handle self-assignment and deep copy
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] arr;
}

template <typename T>
size_t Array<T>::size() const
{
	return arr_size;
}

#endif
