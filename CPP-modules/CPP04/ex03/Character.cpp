#include "Character.hpp"

Character::Character(std::string name) : name(name) 
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const Character &character){
	name = character.name;
}
Character::~Character() {}

Character &Character::operator=(const Character &character){
	name = character.name;
	return *this;
}

std::string const &Character::getName() const{
	return name;
}

void Character::equip(AMateria* mats)
{
	for (int i = 0; i < 4; i++)
	{
		if (mats != NULL && slot[i] == NULL)
			slot[i] = mats;
	}
}

void Character::unequip(int idx){

}

void Character::use(int idx, ICharacter& target){

}

const AMateria AMateria::*getItem(int idx) const{

}
