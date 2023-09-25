#include "Phonebook.hpp"

int	main(void)
{
	Phonebook 	pb;
	std::string	str;

	while (str != "EXIT")
	{
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			pb.add();	
		else if (str == "SEARCH")
			pb.search();
		if (std::cin.eof())
		{
			std::cout << "\nThanks!" << std::endl;
			return (0);
		}
	}
	std::cout << "Thanks!" << std::endl;
	return (0);
}
