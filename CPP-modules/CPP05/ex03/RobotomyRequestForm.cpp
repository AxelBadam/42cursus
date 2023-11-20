#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &cpy)
: AForm(cpy.getName(), cpy.getGradeS(), cpy.getGradeE()){
	_target = cpy._target;
}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
    if (this != &rhs)
    {
        _target = rhs._target;
	}
    return (*this);
}

void RobotomyRequestForm::executeConcrete() const
{
	std::cout << "DRILLING SO HARD!!!\n";
	srand(time(NULL));

	if (rand() % 2)
		std::cout << _target << " was successfully robotomized!" << std::endl;
	else
		std::cout << "The robotomy failed..." << std::endl;
}