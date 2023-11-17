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

void Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} 
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.getName()
		<< " because their rating wasn't sufficient" << std::endl;
	}		
}

void Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() <<  std::endl;
	}
	catch (AForm::FormNotSignedException)
	{
		std::cout << "FormNotSignedException Caught" << std::endl;
	}
	catch (AForm::GradeTooLowException)
	{
			std::cout << "GradeTooLowException Caught" << std::endl;
	}
}
