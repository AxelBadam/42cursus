#include "Dog.hpp"
#include <iostream>

Dog::Dog()
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
	d = new Brain();
}

Dog::~Dog(){
	std::cout << "Dog destructor called" << std::endl;	
	delete d;
}

Dog &Dog::operator=(const Dog &Dog){
	std::cout << "Dog copy assignment operator called" << std::endl;
	type = Dog.type;
	delete d;
	d = new Brain(*Dog.d);
	return *this;
}

Dog::Dog(const Dog &Dog){
	std::cout << "Dog copy constructor called" << std::endl;
	d = new Brain(*Dog.d);
	type = Dog.type;
}

void Dog::makeSound() const{
	std::cout << "Woof." << std::endl;
}

std::string Dog::getType() const{
	return type;
}

std::string Dog::getIdea(int i) const{
	return d->getIdea(i);
}

void Dog::setIdea(std::string idea, int i){
	d->setIdea(idea, i);
}

Brain &Dog::getBrain(){
	return *d;
}
