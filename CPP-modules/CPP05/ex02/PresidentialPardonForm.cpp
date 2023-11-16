#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
: AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &cpy)
{
    
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    
}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void PresidentialPardonForm::executeConcrete(Bureaucrat const & executor) const
{
	std::cout << target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}
