#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &Brain){
	std::cout << "Brain copy assignment operator called" << std::endl;
	return *this;
}

Brain::Brain(const Brain &Brain){
	std::cout << "Brain copy constructor called" << std::endl;	
}
