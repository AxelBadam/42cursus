#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() : type("WrongAnimal"){
	std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal)
{
	std::cout << "WrongAnimal copy assignment operator called" << std::endl;
	type = WrongAnimal.type;
	return *this;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	type = WrongAnimal.type;
	std::cout << "WrongAnimal copy constructor called" << std::endl;	
}

void WrongAnimal::makeSound() const{
	std::cout << "Undefined WrongAnimal noises" << std::endl;
}

std::string WrongAnimal::getType() const{
	return type;
}