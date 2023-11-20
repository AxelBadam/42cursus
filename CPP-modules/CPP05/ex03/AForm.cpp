#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _signed(0), _gradeSign(150), _gradeExec(150) {}

AForm::AForm(std::string name, int gradeSign, int gradeExec) 
: _name(name)
, _signed(0)
, _gradeSign(gradeSign)
, _gradeExec(gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1) throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150) throw GradeTooLowException();
}

AForm::AForm(const AForm &cpy)
: _name(cpy._name)
, _signed(cpy._signed)
, _gradeSign(cpy._gradeSign)
, _gradeExec(cpy._gradeExec)
{
	if (_gradeSign < 1 || _gradeExec < 1) throw GradeTooHighException();
	if (_gradeSign > 150 || _gradeExec > 150) throw GradeTooLowException();
}

AForm& AForm::operator=(AForm const &rhs)
{
    if (this != &rhs)
	{
		_signed = rhs._signed;
    }
    return (*this);
}

AForm::~AForm(){}

int AForm::getGradeS() const{
	return _gradeSign;
}

int AForm::getGradeE() const{
	return _gradeExec;
}

std::string AForm::getName() const {
	return _name;
}

bool AForm::getSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeSign)
		throw GradeTooLowException();
	_signed = true;
}


std::ostream& operator<<(std::ostream &out, AForm &AForm)
{
	out << AForm.getName() << " with grade " << AForm.getGradeS();
	if (AForm.getSigned())
		out << " is signed,";
	else
		out << " is not signed,";
	out << " exec grade is " << AForm.getGradeE();
	
	return out;
}

void AForm::execute(Bureaucrat const &executor) const
{
	if (getSigned() && executor.getGrade() < _gradeExec) executeConcrete();
	if (executor.getGrade() > _gradeExec) throw GradeTooLowException();
	if (!getSigned()) throw FormNotSignedException();
}
