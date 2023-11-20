#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	RobotomyRequestForm RoboForm("Teemu");
	PresidentialPardonForm PardonForm("Bob");
	ShrubberyCreationForm ShrubForm("backyard");

	Bureaucrat GigaChad("GigaChad", 2);
	GigaChad.signForm(PardonForm);
	GigaChad.executeForm(PardonForm);
	GigaChad.signForm(RoboForm);
	GigaChad.executeForm(RoboForm);
	GigaChad.signForm(ShrubForm);
	GigaChad.executeForm(ShrubForm);

	std::cout << "------------------------" << std::endl;

	Bureaucrat GigaLad("GigaLad", 149);
	GigaLad.signForm(PardonForm);
	GigaLad.executeForm(PardonForm);
	GigaLad.signForm(RoboForm);
	GigaLad.executeForm(RoboForm);
	GigaLad.signForm(ShrubForm);
	GigaLad.executeForm(ShrubForm);

	std::cout << "------------------------" << std::endl;

	Bureaucrat GigaBob("GigaBob", 12);
	RobotomyRequestForm RoboTest("Test");

	GigaBob.executeForm(RoboTest);

	PresidentialPardonForm cpy(PardonForm);
	std::cout << cpy << std::endl;

	ShrubberyCreationForm cpy1(ShrubForm);
	std::cout << cpy1 << std::endl;
}
