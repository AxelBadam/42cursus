#ifndef ZOMBIE_H
#define ZOMBIE_H
#include <string>
#include <iostream>

class Zombie
{
	public:
		Zombie(std::string name);
		~Zombie(){
			std::cout << name << "'s remains cleaned up" << std::endl;
		}
		void announce(void) const {
			std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
		}
	private:
		std::string name;
};

Zombie *newZombie(std::string name);
void randomChump(std::string name);

#endif
