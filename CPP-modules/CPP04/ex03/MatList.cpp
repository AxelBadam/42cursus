#include "MatList.hpp"

MatList::MatList() : mats(NULL), next(NULL) {}

MatList::MatList(AMateria *mat)
{
	mats = mat;
	next = NULL;
}

MatList::~MatList() 
{
	if (mats)
		delete mats;
	if (next)
		delete next;
	mats = NULL;
	next = NULL;
}

MatList::MatList(const MatList &list)
{
	mats = list.mats ? list.mats->clone() : NULL; 
	next = list.next ? new MatList(*list.next) : NULL;
}

MatList &MatList::operator=(const MatList &list)
{
	if (mats)
		delete mats;
	if (next)
		delete next;
	mats = list.mats ? list.mats->clone() : NULL; 
	next = list.next ? new MatList(*list.next) : NULL;
	return *this;
}
