#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	type = "WrongCat";
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat){
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	type = WrongCat.type;
	return *this;
}

WrongCat::WrongCat(const WrongCat &WrongCat){
	type = WrongCat.type;
	std::cout << "WrongCat copy constructor called" << std::endl;	
}

void WrongCat::makeSound() const{
	std::cout << "Wrong Meow." << std::endl;
}

std::string WrongCat::getType() const{
	return type;
}