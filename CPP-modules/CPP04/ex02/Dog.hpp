#ifndef DOG_HPP
#define DOG_HPP
#include <iostream>
#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog();
		virtual ~Dog();
		Dog &operator=(const Dog &Dog);
		Dog(const Dog &Dog);
		void makeSound() const;
		std::string getType() const;
		std::string getIdea(int i) const;
		void setIdea(std::string idea, int i);
		Brain& getBrain();

	private:
		Brain *d;
};

#endif
