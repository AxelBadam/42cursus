#ifndef __BUREAUCRAT_HPP__
#define __BUREAUCRAT_HPP__

#include <iostream>
#include <exception>

class Bureaucrat 
{
public:
    Bureaucrat();
	Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    ~Bureaucrat();
    Bureaucrat& operator=(const Bureaucrat &other);

	const std::string getName() const;
	int getGrade() const;
	void incrementG();
	void decrementG();

	class GradeTooHighException : public std::exception {};
	class GradeTooLowException : public std::exception {};

private:
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);


#endif
