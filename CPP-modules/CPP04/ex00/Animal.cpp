#include "Animal.hpp"
#include <iostream>

Animal::Animal() : type("Animal"){
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal(){
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &animal)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	type = animal.type;
	return *this;
}

Animal::Animal(const Animal &animal)
{
	type = animal.type;
	std::cout << "Animal copy constructor called" << std::endl;	
}

void Animal::makeSound() const{
	std::cout << "Undefined animal noises" << std::endl;
}

std::string Animal::getType() const{
	return type;
}



