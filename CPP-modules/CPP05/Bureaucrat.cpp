#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	if (_grade < 1) throw HighException();
	if (_grade > 150) throw LowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (_grade < 1) throw HighException();
	if (_grade > 150) throw LowException();
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
	if (_grade < 1) throw HighException();
	if (_grade > 150) throw LowException();
}

void Bureaucrat::decrementG (){
	_grade--;
	if (_grade < 1) throw HighException();
	if (_grade > 150) throw LowException();
}
