#ifndef MAT_LIST_HPP
#define MAT_LIST_HPP

#include "AMateria.hpp"

class MatList
{
	public:
		MatList();
		~MatList();
		MatList(AMateria *mat);
		MatList(const MatList &list);

		MatList &operator=(const MatList &list);

		AMateria *mats;
		MatList *next;

};


#endif