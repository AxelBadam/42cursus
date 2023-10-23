#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &source);
    virtual ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &source);

private:
	AMateria *materias[4];
};

#endif
