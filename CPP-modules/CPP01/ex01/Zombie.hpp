#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		void annouce(void);
		void nameGiver(std::string name);
	private:
		std::string _name;
};

Zombie* zombieHorde( int N, std::string name );

#endif