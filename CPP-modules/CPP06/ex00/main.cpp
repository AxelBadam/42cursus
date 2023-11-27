#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "please provide a single argument" << std::endl; 
		exit (0);
	}
	const std::string str = av[1];
	ScalarConverter::convert(str);
    return 0;
}
