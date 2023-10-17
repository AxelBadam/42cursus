#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP
#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap &ST);
		~ScavTrap();
		ScavTrap &operator=(const ClapTrap &ST);

		void attack(const std::string& target);
		void guardGate();
};

#endif