#ifndef BRAIN_HPP
#define BRAIN_HPP
#include <iostream>
#include "Animal.hpp"

class Brain
{
	public:
		Brain();
		virtual ~Brain();
		Brain &operator=(const Brain &Brain);
		Brain(const Brain &Brain);

	private:
		std::string ideas[100];
	
		

};

#endif