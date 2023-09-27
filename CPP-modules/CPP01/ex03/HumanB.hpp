#ifndef HUMAN_B_H
#define HUMAN_B_H
#include "Weapon.hpp"
#include <iostream>

class HumanB
{
	public:
		HumanB(std::string name);
		void setWeapon(Weapon &weapon);
		void attack() const;

	private:
		std::string _name;
		Weapon *_weapon;
};

#endif