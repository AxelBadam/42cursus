#include "HumanA.hpp"

HumanA::HumanA(std::string _name, Weapon &_weapon) : _weapon(_weapon), _name(_name) {}

void HumanA::attack(void) const {
	std::cout << _name << " attacks with their " << _weapon.getType() << "\n";
}
