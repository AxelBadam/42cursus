#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int main()
{
	Intern intern;

	AForm *ShrubForm = intern.makeForm("shrubbery creation", "backyard");
	AForm *RoboForm = intern.makeForm("robotomy request", "Teemu");
	AForm *PardonForm = intern.makeForm("presidential pardon", "Chad");
	AForm *random = intern.makeForm("random", "say what");

	Bureaucrat GigaChad("GigaChad", 2);
	GigaChad.signForm(*RoboForm);
	GigaChad.executeForm(*RoboForm);
	GigaChad.signForm(*ShrubForm);
	GigaChad.executeForm(*ShrubForm);
	GigaChad.signForm(*PardonForm);
	GigaChad.executeForm(*PardonForm);
	GigaChad.signForm(*random);
	GigaChad.executeForm(*random);

	std::cout << "------------------------" << std::endl;

	Bureaucrat GigaLad("GigaLad", 149);
	GigaLad.signForm(*PardonForm);
	GigaLad.executeForm(*PardonForm);
	GigaLad.signForm(*RoboForm);
	GigaLad.executeForm(*RoboForm);
	GigaLad.signForm(*ShrubForm);
	GigaLad.executeForm(*ShrubForm);

	std::cout << "------------------------" << std::endl;

	delete ShrubForm;
	delete RoboForm;
	delete PardonForm;
}
