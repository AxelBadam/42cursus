#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; i++)
		mats[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
		mats[i] = source.getMats(i)->clone();
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (mats[i])
			delete mats[i];
		mats[i] = NULL;
	}
}

MateriaSource &MateriaSource::operator=(const MateriaSource &source)
{
	for (int i = 0; i < 4; i++)
	{
		delete mats[i];
		mats[i] = source.getMats(i)->clone();
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++)
	{
		if (mats[i] == NULL)
		{
			mats[i] = materia;
			return;
		}
	}
	if (materia)
		delete materia;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++)
	{
		if (mats[i] != NULL && mats[i]->getType() == type)
			return mats[i]->clone();
	}
	return 0;
}

AMateria* MateriaSource::getMats(int i) const{
	return mats[i];
}