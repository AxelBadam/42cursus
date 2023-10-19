#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &Cat){
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = Cat.type;
	return *this;
}

Cat::Cat(const Cat &Cat){
	type = Cat.type;
	std::cout << "Cat copy constructor called" << std::endl;	
}

void Cat::makeSound() const{
	std::cout << "Meow." << std::endl;
}

std::string Cat::getType() const{
	return type;
}
