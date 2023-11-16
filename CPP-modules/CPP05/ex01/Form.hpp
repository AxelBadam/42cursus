#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
	Form();
	Form(std::string name, int gradeSign, int gradeExec);
    Form(const Form &cpy);
    ~Form();
    Form& operator=(const Form &other);

	bool getSigned();
	int getGradeSign();
	int getGradeExec();
	std::string getName();
	
	void beSigned(const Bureaucrat &bureaucrat);

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};
    
private:
	const std::string _name;
	bool _signed;
	const int _gradeSign;
	const int _gradeExec;
};

std::ostream& operator<<(std::ostream &out, Form &form);

#endif
