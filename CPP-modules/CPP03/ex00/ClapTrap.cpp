#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(std::string name) 
{
	_name = name;
	std::cout << _name << " was created\n";
	_hp = 10;
	_e = 10;
	_atck = 0;
}

ClapTrap::~ClapTrap(){}

void  ClapTrap::attack(const std::string& target)
{
	
}

