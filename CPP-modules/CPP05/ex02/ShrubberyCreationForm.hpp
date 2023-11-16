#ifndef __SHRUBBERYCREATIONFORM_HPP__
#define __SHRUBBERYCREATIONFORM_HPP__

#include "AForm.hpp"

class ShrubberyCreationForm : protected AForm
{
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm &other);
    
	void execute(Bureaucrat const & executor) const;
private:
	std::string target;
};

#endif
