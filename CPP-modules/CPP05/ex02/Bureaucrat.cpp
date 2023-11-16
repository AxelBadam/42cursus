#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &cpy){
	_grade = cpy._grade;
}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const &rhs)
{
    if (this != &rhs)
		_grade = rhs._grade;
    return (*this);
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat &bur){
	return out << bur.getName() << ", bureaucrat grade " << bur.getGrade();
}

const std::string Bureaucrat::getName() const{
	return _name;
}

int Bureaucrat::getGrade() const{
	return _grade;
}

void Bureaucrat::incrementG(){
	_grade++;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

void Bureaucrat::decrementG (){
	_grade--;
	if (_grade < 1) throw GradeTooHighException();
	if (_grade > 150) throw GradeTooLowException();
}

void Bureaucrat::signAForm(AForm &form)
{
	try
	{
		AForm.beSigned(*this);
		std::cout << _name << " signed " << AForm.getName() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << AForm.getName()
		<< " because their rating wasn't sufficient" << std::endl;
	}		
}

void Bureaucrat::executeForm(AForm const &form) const
{
	try
	{
		form.execute(*this);
		std::cout << name << " executed " << form.getName() << std::endl;
	}
	catch (AForm::FormNotSigned &e)
	{
		std::cout << name << " couldn't execute " << form.getName()
			<< " as it is not signed." << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << name << " couldn't execute " << form.getName()
			<< " due to their insufficient ranking." << std::endl;
	}
}
