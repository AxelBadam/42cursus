#ifndef CAT_HPP
#define CAT_HPP
#include <iostream>
#include "Animal.hpp"

class Cat: public Animal
{
	public:
		Cat();
		virtual ~Cat();
		Cat &operator=(const Cat &Cat);
		Cat(const Cat &Cat);
		void makeSound() const;
		std::string getType() const;
		

};

#endif