#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		virtual ~Ice();
		Ice &operator=(const Ice &type);
		Ice(const Ice &type);
		
		virtual Ice* clone() const;
		virtual void use(ICharacter &target);
};

#endif
