#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : _type(_type) {}

std::string const&Weapon::getType() const{
	return _type;
}

void Weapon::setType(std::string type){
	_type = type;
}
