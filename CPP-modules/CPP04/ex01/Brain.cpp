#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain destructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &Brain)
{		
	std::cout << "Brain copy assignment operator called" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = Brain.ideas[i];
	return *this;
}

Brain::Brain(const Brain &Brain)
{
	for (int i = 0; i < 100; i++)
		ideas[i] = Brain.ideas[i];
	std::cout << "Brain copy constructor called" << std::endl;	
}
std::string Brain::getIdea(int i) const{
	return ideas[i];
}

void Brain::setIdea(std::string idea, int i){
	ideas[i] = idea;
}