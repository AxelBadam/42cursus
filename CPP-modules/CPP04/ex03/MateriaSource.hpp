#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
public:
	MateriaSource();
	MateriaSource(const MateriaSource &source);
    ~MateriaSource();
    MateriaSource &operator=(const MateriaSource &source);

	void learnMateria(AMateria*);

	AMateria* createMateria(std::string const & type);
	AMateria* getMats(int i) const;

private:
	AMateria *mats[4];
};

#endif
