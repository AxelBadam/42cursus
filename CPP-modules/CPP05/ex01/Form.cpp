#include "Form.hpp"
#include <iostream>

Form::Form(std::string name, int grade) : _name(name), _grade(grade), _signed(0)
{
	
}

Form::Form(Form const &cpy)
{

}

Form::~Form()
{

}

Form& Form::operator=(Form const &rhs)
{
    if (this != &rhs)
	{

    }
    return (*this);
}

int Form::getGrade()
{
	return _grade;
}

std::string Form::getName()
{
	return _name;
}

bool Form::getSigned()
{
	return _signed;
}
	


std::ostream& operator<<(std::ostream &out, Form &form){
	return out << form.getName() << ", bureaucrat grade " << form.getGrade();
}