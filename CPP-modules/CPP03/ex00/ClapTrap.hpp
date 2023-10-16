#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap(std::string name);
		~ClapTrap();
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string _name;
		int			_hp;
		int			_e;
		int			_atck;
};

#endif
