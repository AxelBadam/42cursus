#ifndef __AForm_HPP__
#define __AForm_HPP__

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm 
{
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
    AForm(const AForm &cpy);
    virtual ~AForm();
    AForm& operator=(const AForm &other);

	bool getSigned() const;
	int getGradeS() const;
	int getGradeE() const;
	std::string getName() const;

	virtual void execute(Bureaucrat const &executor) const;
	
	void beSigned(const Bureaucrat &bureaucrat);

	class FormNotSignedException : public std::exception {};
	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

protected:
	virtual void executeConcrete() const = 0;

private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExec;
};

std::ostream& operator<<(std::ostream &out, AForm &AForm);

#endif
