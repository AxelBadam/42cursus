#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP
#include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap &CT);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap &CT);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		int  getAtck();
		int  getE();

	private:
		std::string _name;
		int			_hp;
		int			_e;
		int			_atck;
};

#endif
