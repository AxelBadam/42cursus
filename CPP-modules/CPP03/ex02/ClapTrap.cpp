#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) 
{
	_name = name;
	std::cout << _name << " ClapTrap was created\n";
	_hp = 100;
	_e = 50;
	_atck = 20;
}

ClapTrap::~ClapTrap(){
	std::cout << _name << " ClapTrap was destroyed" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &CT)
{
	_name = CT._name;
	_hp = CT._hp;
	_e = CT._e;
	_atck = CT._atck;
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	return *this;
}

ClapTrap::ClapTrap(const ClapTrap &CT)
{
	_name = CT._name;
	_atck = CT._atck;
	_e = CT._e;
	_hp = CT._hp;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

void  ClapTrap::attack(const std::string& target)
{
	if (_e > 0 && _hp > 0)
	{
		_e -= 1;
		std::cout << _name  << " attacks " << target <<
		" causing " << _atck << " damage!" << std::endl;
	}
	else
		std::cout << _name << ": Can't attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hp > 0)
	{
		std::cout << _name << " takes " << amount << " damage!" << std::endl;
		if (_hp - amount <= 0)
		{
			_hp = 0;
			std::cout << _name << " is done!" << std::endl;
		}
		else
			_hp -= amount;
	}
	else
		std::cout << _name << " is already dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_e > 0 && _hp > 0)
	{
		_hp += amount;
		_e -= 1;
		std::cout << _name << " is repaired for " << amount << std::endl;
	}
	else
		std::cout << _name << ": Can't repair!" << std::endl;
}

int ClapTrap::getAtck(){
	return _atck;
}

int ClapTrap::getE(){
	return _e;
}