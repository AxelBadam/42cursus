#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cpy) 
: AForm(cpy.getName(), cpy.getGradeS(), cpy.getGradeE())
{
    _target = cpy._target;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
  	if (this != &rhs)
    {
        _target = rhs._target;
	}
    return (*this);
}

void PresidentialPardonForm::executeConcrete() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
