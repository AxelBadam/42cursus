#include "MatList.hpp"

MatList::MatList() : mats(NULL), next(NULL) {}

MatList::MatList(AMateria *mat)
{
	mats = mat;
	next = NULL;
}

MatList::~MatList() 
{
	delete mats;
	delete next;
	mats = NULL;
	next = NULL;
}

MatList::MatList(const MatList &list) : mats(list.mats), next(list.next) {}

MatList &MatList::operator=(const MatList &list)
{
	delete mats;
	delete next;
	mats = list.mats;
	next = list.next;
	return *this;
}
