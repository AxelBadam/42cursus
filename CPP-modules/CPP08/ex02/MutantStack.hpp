#ifndef __MUTANTSTACK_HPP__
#define __MUTANTSTACK_HPP__

#include <stack>
#include <list>
#include <iostream>
 
template<typename T>
class MutantStack : public std::stack<T>
{
	public:

		MutantStack();
		MutantStack(MutantStack const &instance);
		virtual ~MutantStack();
		MutantStack	&operator=(MutantStack const &instance);

		typedef typename std::stack<T>::container_type::iterator iterator;
    	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator begin(){ return this->c.begin(); }
		iterator end(){ return this->c.end(); }
};

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}
template<typename T>
MutantStack<T>::MutantStack(MutantStack const &instance) : std::stack<T>(instance) {}
template<typename T>
MutantStack<T>::~MutantStack() {}
template<typename T>
MutantStack<T>	&MutantStack<T>::operator=(MutantStack const &instance) 
{
	this->c = instance.c;	
	return *this;
}

#endif
