#include "HumanB.hpp"

HumanB::HumanB(std::string _name) : _name(_name) {}

void HumanB::setWeapon(Weapon &weapon)
{
	_weapon = &weapon;
}

void HumanB::attack(void) const
{
	std::cout << _name << " attacks with their " << _weapon->getType() << "\n";
}
