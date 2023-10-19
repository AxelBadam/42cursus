#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP
#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal &operator=(const WrongAnimal &WrongAnimal);
		WrongAnimal(const WrongAnimal &WrongAnimal);
		void makeSound() const;
		std::string getType() const;

	protected:
		std::string type;

};

#endif
