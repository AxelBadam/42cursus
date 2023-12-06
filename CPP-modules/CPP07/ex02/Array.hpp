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
    T &operator[](unsigned int index) const;
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
	arr_size = other.arr_size;
	arr = new T[other.arr_size];
	for (size_t i = 0; i < arr_size; i++)
		arr[i] = other.arr[i];
}

template <typename T>
Array<T>::~Array() {
    if (arr)
		delete[] arr;
}

template <typename T>
size_t Array<T>::size() const{
	return arr_size;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &rhs) {
    if (this != &rhs)
	{
        if (arr)
            delete[] arr;
		arr_size = rhs.arr_size;
        arr = new T[arr_size];
        for (size_t i = 0; i < arr_size; i++)
            arr[i] = rhs.arr[i];
    }
    return *this;
}

template<typename T>
T &Array<T>::operator[](unsigned int index) const
{
    if (index >= arr_size || index < 0)
        throw std::out_of_range("Index out of range");
    return arr[index];
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& array)
{
    os << "{";
    for (size_t i = 0; i < array.size(); i++)
    {
        os << array[i];
        if (i < array.size() - 1)
            os << ", ";
    }
    os << "}";
    return os;
}

#endif
