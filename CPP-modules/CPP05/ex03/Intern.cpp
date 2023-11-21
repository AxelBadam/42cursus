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
			std::cout << "Intern makes " << args[i] << " form" << std::endl;
			return new PresidentialPardonForm(formTarget);
		case 1:
			std::cout << "Intern makes " << args[i] << " form" << std::endl;		
			return new RobotomyRequestForm(formTarget);
		case 2:
			std::cout << "Intern makes " << args[i] << " form" << std::endl;
			return new ShrubberyCreationForm(formTarget);
		case 3:
			std::cout << "invalid parameter to makeForm" << std::endl;
	}
	return NULL;
}