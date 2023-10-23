#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MateriaTrash.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character &character);
    	virtual ~Character();
    	Character &operator=(const Character &character);

	private:
};

#endif
