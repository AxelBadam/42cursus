#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "please provide a single argument: char, int, float or double (or inf/nan)" << std::endl; 
		return 1;
	}
	const std::string str = av[1];
	ScalarConverter::convert(str);
    return 0;
}
