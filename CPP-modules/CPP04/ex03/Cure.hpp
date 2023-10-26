#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
public:
	Cure();
	virtual ~Cure();
	Cure &operator=(const Cure &type);
	Cure(const Cure &type);


	virtual Cure* clone() const;
	virtual void use(ICharacter &target);
};

#endif
