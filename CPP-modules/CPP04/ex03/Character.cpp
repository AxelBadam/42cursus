#include "Character.hpp"
#include "MatList.hpp"
#include <iostream>

Character::Character(std::string name) : name(name) 
{
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
}

Character::Character(const Character &character)
{
	name = character.name;
	for (int i = 0; i < 4; i++)
			slot[i] = character.slot[i]->clone();	
	list = character.list ? new MatList(*character.list) : NULL;
}
Character::~Character() {
	int i = 0;
	while (i < 4)
	{
		if (slot[i])
			delete slot[i];
		i++;
	}
	if (list)
		delete list;
}

Character &Character::operator=(const Character &character)
{
	name = character.name;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i])
			delete slot[i];
	}
	for (int i = 0; i < 4; i++)
			slot[i] = character.slot[i]->clone();
	if (list)
		delete list;
	list = character.list ? new MatList(*character.list) : NULL;
	return *this;
}

std::string const &Character::getName() const{
	return name;
}

void Character::equip(AMateria* mats)
{
	if (mats == NULL)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = mats;
			return;
		}		
	}
    // If all slots are occupied, add 'mats' to the linked list.
	if (!list)
    	list = new MatList(mats); // Create a new node with 'mats'
	else
	{
		MatList *tmp = list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new MatList(mats);
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx > -1 && idx < 4 && slot[idx] != NULL)
		slot[idx]->use(target);
}

void Character::unequip(int idx)
{
	if (idx > -1 && idx < 4 && slot[idx] != NULL)
	{
		if (!list)
    		list = new MatList(slot[idx]);
		else
		{
			MatList *tmp = list;
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new MatList(slot[idx]);
		}
	slot[idx] = NULL;
	}
}
