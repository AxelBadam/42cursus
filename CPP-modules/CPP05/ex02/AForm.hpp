#ifndef __AForm_HPP__
#define __AForm_HPP__

#include <string>
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Bureaucrat;

class AForm {
public:
	AForm();
	AForm(std::string name, int gradeSign, int gradeExec);
    AForm(const AForm &cpy);
    ~AForm();
    AForm& operator=(const AForm &other);

	bool getSigned();
	int getGradeS();
	int getGradeE();
	std::string getName();
	
	void beSigned(const Bureaucrat &bureaucrat);
	void execute (Bureaucrat const & executor) const;

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
