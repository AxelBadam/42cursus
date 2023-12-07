#ifndef __EASYFIND_HPP__
#define __EASYFIND_HPP__

#include <vector>
#include <list>
#include <iostream>

template<typename T>
typename T::value_type easyfind(T &cont, int i)
{
	typename T::iterator it = std::find(cont.begin(), cont.end(), i);
	if (it == cont.end())
		throw std::exception();
	return *it;
}

template<typename T>
typename T::value_type easyfind(const T &cont, int i)
{
    typename T::const_iterator it = std::find(cont.begin(), cont.end(), i);
    if (it == cont.end())
        throw std::exception();
    return *it;
}


#endif
