#ifndef A_MATERIA_HPP
#define A_MATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class AMateria
{
	public:
		AMateria(std::string const & type);
		virtual ~AMateria() = 0;
		AMateria(const AMateria &amateria);
		AMateria &operator=(const AMateria &other);

		std::string const &getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	protected:
		std::string type;
};

#endif
