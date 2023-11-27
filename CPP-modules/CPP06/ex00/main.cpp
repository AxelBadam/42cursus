#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		exit (1);
	const std::string str = av[1];
	ScalarConverter converter;
	converter.convert(str);
    return 0;
}
