#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	_hp = 100;
	_e = 50;
	_atck = 20;
	std::cout << _name << " ScavTrap was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &SC) : ClapTrap(SC._name)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	_hp = SC._hp;
	_e = SC._e;
	_atck = SC._atck;
	_name = SC._name;
}
ScavTrap::~ScavTrap(){
	std::cout << _name << " ScavTrap was destroyed" << std::endl;
}

void  ScavTrap::attack(const std::string& target)
{
	if (_e > 0 && _hp > 0)
	{
		_e -= 1;
		std::cout << "ScavTrap: " << _name  << " attacks " << target <<
		" causing " << _atck << " damage!" << std::endl;
	}
	else
		std::cout << "ScavTrap: " << _name << ": Can't attack!" << std::endl;
}

void ScavTrap::guardGate()
{
	if (_hp > 0)
		std::cout << _name << " ScavTrap is in Gate keeper mode" << std::endl;
}