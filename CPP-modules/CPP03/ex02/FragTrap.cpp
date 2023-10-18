#include <iostream>

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << _name << " FragTrap was created" << std::endl;
	_hp = 100;
	_e = 100;
	_atck = 30;
}

FragTrap::FragTrap(const std::string name) : ClapTrap(name)
{
	std::cout << _name << " FragTrap was created" << std::endl;
	_hp = 100;
	_e = 100;
	_atck = 30;
}

FragTrap::FragTrap(const FragTrap &FT) : ClapTrap(FT._name)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	_hp = FT._hp;
	_e = FT._e;
	_atck = FT._atck;
	_name = FT._name;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &FT)
{	
	std::cout << "FragTrap copy assignment operator called" << std::endl;
	_name = FT._name;
	_hp = FT._hp;
	_e = FT._e;
	_atck = FT._atck;
	return *this;
}

void FragTrap::attack(const std::string &target)
{
	if (_e > 0 && _hp > 0)
	{
		_e -= 1;
		std::cout << "FragTrap: " << _name  << " attacks " << target <<
		" causing " << _atck << " damage!" << std::endl;
	}
	else
		std::cout << "FragTrap: " << _name << ": Can't attack!" << std::endl;

}

void FragTrap::highFivesGuys()
{
	if (_hp > 0)
		std::cout << "FragTrap: " << _name << ": high five! (super positive)" << std::endl;
}
