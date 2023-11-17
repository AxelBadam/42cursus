#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
	try{
		Bureaucrat bur("Jalmari", 151);
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << "Exception caught: Constructor" << std::endl;
	}
	try
	{
		Bureaucrat bur("Jalmari", 1);
		bur.decrementG();
	}
	catch(const	Bureaucrat::GradeTooHighException& e){
		std::cerr << "Exception caught: Decrement" << std::endl;
	}
	try{
		Bureaucrat bur("Jalmari", 150);
		bur.incrementG();
	}
	catch(const Bureaucrat::GradeTooLowException& e){
		std::cerr << "Exception caught: Increment" << std::endl;
	}

	Bureaucrat G("Gangsta", 42);
	std::cout << G << std::endl;

	RobotomyRequestForm RoboForm("RoboForm");

	Bureaucrat GigaChad("GigaChad", 2);
	GigaChad.signForm(RoboForm);
	GigaChad.executeForm(RoboForm);
}
