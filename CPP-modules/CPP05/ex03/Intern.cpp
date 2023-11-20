#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const &cpy) {
	(void)cpy;
}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const &rhs)
{
    (void)rhs;
    return (*this);
}

AForm* Intern::makeForm(std::string formName, std::string formTarget)
{
	static std::string args[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	int i;
	for (i = 0; i < 3; i++)
	{
		if(!formName.compare(args[i]))
			break;
	}
	switch (i)
	{
		case 0:
			return new PresidentialPardonForm(formTarget);
		case 1:
			return new RobotomyRequestForm(formTarget);
		case 2:
			return new ShrubberyCreationForm(formTarget);
	}
	return NULL;
}