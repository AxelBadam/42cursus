#include <iostream>

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MatList.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	// learning more than 4 does nothing
	src->learnMateria(new Ice());
	
	ICharacter* me = new Character("me");

	AMateria* tmp;
	
	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

	tmp = src->createMateria("ice");
	me->equip(tmp);

	tmp = src->createMateria("cure");
	me->equip(tmp);

//  equip over slot, goes in list

	tmp = src->createMateria("ice");
		me->equip(tmp);
	tmp = src->createMateria("cure");
		me->equip(tmp);

//  unequip, goes in list
	me->unequip(0);
	me->unequip(1);

	ICharacter* bob = new Character("bob");

//  using
	me->use(0, *bob);
	me->use(1, *bob);
	me->use(2, *bob);
	me->use(3, *bob);
	me->use(-1, *bob);

	delete bob;
	delete me;
	delete src;
	
	return 0;
}
