#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
	public:
		WrongCat();
		virtual ~WrongCat();
		WrongCat &operator=(const WrongCat &WrongCat);
		WrongCat(const WrongCat &WrongCat);
		void makeSound() const;
		std::string getType() const;
};

#endif