#ifndef __FORM_HPP__
#define __FORM_HPP__

#include <string>

class Form {
public:
    Form(std::string name, int grade);
    Form(const Form &other);
    ~Form();
    Form& operator=(const Form &other);

	bool getSigned();
	int getGrade();
	std::string getName();
    
private:
	const std::string _name;
	bool _signed;
	const int _grade;

};

#endif
