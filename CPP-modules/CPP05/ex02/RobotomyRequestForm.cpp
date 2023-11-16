#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string &target)
: AForm("RobotomyRequestForm", 25, 5), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
{
    
}

RobotomyRequestForm::~RobotomyRequestForm()
{
    
}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
    {
        
    }
    return (*this);
}

void RobotomyRequestForm::executeConcrete() const
{
	std::cout << "DRILLING SO HARD!!!\n";
	srand(time(NULL));

	if (rand() % 2)
		std::cout << target << " was successfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy failed.. No refunds!" << std::endl;	

}