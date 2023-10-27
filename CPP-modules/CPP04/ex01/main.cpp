#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << "-----------------------------" << std::endl;

	delete j;//should not create a leak
	delete i;

	std::cout << "-----------------------------" << std::endl;

	Animal *arr[10];
	for (int i = 0; i < 10; i++)
		{
			if (i < 5)
				arr[i] = new Dog();
			else
				arr[i] = new Cat();
		}

	std::cout << "-----------------------------" << std::endl;

	for (int i = 0; i < 10; i++)
		delete arr[i];
	
	std::cout << "-----------------------------" << std::endl;

	Dog *dog = new Dog();
	dog->setIdea("I'm the best!", 0);
	Dog dog2(*dog);

	std::cout << dog << std::endl;
	std::cout << &dog2 << std::endl;
	std::cout << &dog->getBrain() << std::endl;
	std::cout << &dog2.getBrain() << std::endl;

	delete dog;

	std::cout << dog->getIdea(0) << std::endl;
	std::cout << dog2.getIdea(0) << std::endl;

	
	return 0;
}
