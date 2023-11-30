#ifndef __ITER_HPP__
#define __ITER_HPP__

#include <iostream>

template <typename T>
void func(T &arg)
{
	arg = 'a';
}

template <typename T>
void iter(T *arr, int lenght, void (*func)(T &))
{
	for (int i = 0; i < lenght; i++){
		func(arr[i]);
	}
}


#endif
