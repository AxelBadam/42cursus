#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <vector>
#include <array>
#include <iostream>

template<typename T>
int easyfind(T cont, int i)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end()) 
		throw std::exception();
	return *it;
}

#endif
