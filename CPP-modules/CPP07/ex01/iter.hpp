#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>


template <typename T>
void func(T &arg)
{
	arg = 'a';
}

template <typename T>
void funcC(T const &arg)
{
	std::cout << arg << std::endl;
}

template <typename T, typename F>
void iter(T *arr, int lenght, F f)
{
	for (int i = 0; i < lenght; i++){
		f(arr[i]);
	}
}

#endif
