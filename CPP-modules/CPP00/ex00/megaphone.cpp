#include <iostream>

int main(int ac, char **av)
{
	int i = 0;
	int j = 1;

	if (ac < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			std::cout << (char)std::toupper(av[j][i]);
			i++;
		}
		j++;
	}
	std::cout << std::endl;
	return 0;
}
