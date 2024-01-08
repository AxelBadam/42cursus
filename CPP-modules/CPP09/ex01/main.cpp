#include "RPN.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./RPN <expression>" << std::endl;
		return 1;
	}

	RPN obj;
	double res;
	try {
		res = obj.calculate(av[1]);
		std::cout << res << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error" << std::endl;
	}
    return 0;
}
