#include "Harl.hpp"

int main(int ac, char **av) 
{
	if (ac != 2)
	{
		std::cerr << "Usage: ./harlFilter <filter_lvl>\n";
		return 1;
	}
    Harl harl;
	int filter_lvl = 0;
	const std::string lvl(av[1]);
	const std::string strs[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	while (lvl.compare(strs[filter_lvl]) && filter_lvl < 4)
		filter_lvl++;
	//std::cout << filter_lvl << "\n";
	switch (filter_lvl)
	{
		case DEBUG:
			harl.complain("DEBUG");
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case INFO:
			harl.complain("INFO");
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case WARNING:
			harl.complain("WARNING");
			harl.complain("ERROR");
			break;
		case ERROR:
			harl.complain("ERROR");
			break;
		default:
			std::cerr << "Invalid filter level" << std::endl;
	}
    return 0;
}