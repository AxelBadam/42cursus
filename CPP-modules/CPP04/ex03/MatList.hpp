#ifndef MAT_LIST_HPP
#define MAT_LIST_HPP

#include "AMateria.hpp"

class MatList
{
	public:
		AMateria *mats;
		MatList *next;
		
		MatList(AMateria *mat);
		MatList(const MatList &list);
		MatList();
		~MatList();
		MatList &operator=(const MatList &list);
};


#endif