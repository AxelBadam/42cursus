#include <iostream>

#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::~Cure() {}

Cure &Cure::operator=(const Cure &other){
	(void) other;
	return *this;
}

Cure::Cure(const Cure &copy) : AMateria(copy.type) {}

Cure* Cure::clone() const{
	return new Cure();
}

void Cure::use(ICharacter &target){
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
