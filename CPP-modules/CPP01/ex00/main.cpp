#include <iostream>
#include "Zombie.hpp"

int main(void)
{
	randomChump("Jounimarkus");
	Zombie *z = newZombie("Esamarko");
	z->announce();
	delete z;
	return (0);
}
