#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"
#include "MatList.hpp"

class Character : public ICharacter
{
	public:
		Character(std::string name);
		Character(const Character &character);
    	virtual ~Character();
    	Character &operator=(const Character &character);

		virtual std::string const &getName() const;
		virtual void equip(AMateria *m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter &target);

	private:
		AMateria *slot[4];
		std::string name;
		MatList *list;
};

#endif
