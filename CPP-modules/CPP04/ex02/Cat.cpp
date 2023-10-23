#include "Cat.hpp"
#include <iostream>

Cat::Cat()
{
	std::cout << "Cat constructor called" << std::endl;
	type = "Cat";
	c = new Brain();
}

Cat::~Cat(){
	std::cout << "Cat destructor called" << std::endl;	
	delete c;
}

Cat &Cat::operator=(const Cat &Cat){
	std::cout << "Cat copy assignment operator called" << std::endl;
	type = Cat.type;
	delete c;
	c = new Brain(*Cat.c);
	return *this;
}

Cat::Cat(const Cat &Cat){
	std::cout << "Cat copy constructor called" << std::endl;
	c = new Brain(*Cat.c);
	type = Cat.type;
}

void Cat::makeSound() const{
	std::cout << "Woof." << std::endl;
}

std::string Cat::getType() const{
	return type;
}

std::string Cat::getIdea(int i) const{
	return c->getIdea(i);
}

void Cat::setIdea(std::string idea, int i){
	c->setIdea(idea, i);
}

Brain &Cat::getBrain(){
	return *c;
}