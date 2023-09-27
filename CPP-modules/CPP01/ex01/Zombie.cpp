#include "Zombie.hpp"

Zombie::Zombie() {}

Zombie::~Zombie(){
	std::cout << _name << " was decimated.\n";
}

void Zombie::annouce(void){
	std::cout << _name << ": At your service.\n";
}

void Zombie::nameGiver(std::string str){
	_name = str;
}
