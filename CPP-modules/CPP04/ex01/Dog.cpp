#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &Dog){
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = Dog.type;
	return *this;
}

Dog::Dog(const Dog &Dog){
	type = Dog.type;
	std::cout << "Dog copy constructor called" << std::endl;	
}

void Dog::makeSound() const{
	std::cout << "Woof." << std::endl;
}

std::string Dog::getType() const{
	return type;
}