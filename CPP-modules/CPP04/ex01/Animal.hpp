#ifndef ANIMAL_HPP
#define ANIMAL_HPP
#include <iostream>
#include "Brain.hpp"

class Animal
{
	public:
		Animal();
		virtual ~Animal();
		Animal &operator=(const Animal &animal);
		Animal(const Animal &animal);
		virtual void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;
};

#endif
