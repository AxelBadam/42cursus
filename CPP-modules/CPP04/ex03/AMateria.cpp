#include "AMateria.hpp"

AMateria::AMateria(std::string const &type) : type(type) {}

AMateria::~AMateria() {};

AMateria::AMateria(const AMateria &amateria){
	type = amateria.type;
}

AMateria &AMateria::operator=(const AMateria &other){
	(void) other;
	return *this;
}

std::string const &AMateria::getType() const{
	return type;
}

void AMateria::use(ICharacter& target){
	(void)target;
}