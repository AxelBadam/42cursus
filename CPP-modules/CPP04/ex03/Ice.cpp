#include <iostream>

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::~Ice() {}

Ice* Ice::clone() const{
	return new Ice();
}

Ice &Ice::operator=(const Ice &other){
	type = other.type;
	return *this;
}

Ice::Ice(const Ice &copy) : AMateria(copy.type) {}

void Ice::use(ICharacter &target){
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
