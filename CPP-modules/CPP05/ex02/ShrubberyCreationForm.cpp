#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &cpy)
: AForm(cpy.getName(), cpy.getGradeS(), cpy.getGradeE())
{
	_target = cpy._target;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
    if (this != &rhs)
    {
        _target = rhs._target;
	}
    return (*this);
}

void ShrubberyCreationForm::executeConcrete() const
{
    std::ofstream out;
    try
    {
        out.open(_target + "_shrubbery");
    }
    catch (std::exception &e)
    {
        std::cout << "Failed to open file " << _target << std::endl;
        return;
    }
	std::string tree = 
		"               ,@@@@@@@,\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n"
		"   `&%\\ ` /%&'    |.|        \\ '|8'\n"
		"       |o|        | |         | |\n"
		"       |.|        | |         | |\n"
		"    \\/ ._/\\_/__/  ,\\_/\\__/\\/.  \\_/\\__/_";
    out << tree << std::endl;
    out.close();
	std::cout << "Shubbery got planted in " << _target << std::endl;
}
