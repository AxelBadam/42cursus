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

	virtual void learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const & type);
	AMateria* getMats(int i) const;

private:
	AMateria *mats[4];
};

#endif
