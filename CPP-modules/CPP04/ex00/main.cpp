#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* g = new WrongCat();
	const WrongCat *q = new WrongCat();

	std::cout << std::endl;

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << g->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;
	std::cout << q->getType() << " " << std::endl;
	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound(); //dog
	g->makeSound(); //wrong animal
	q->makeSound(); //wrongcat
	meta->makeSound(); // animal

	std::cout << std::endl;

	delete g;
	delete meta;
	delete j;
	delete i;
	delete q;

	return 0;
}
