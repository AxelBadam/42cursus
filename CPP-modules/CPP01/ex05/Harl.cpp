#include "Harl.hpp"
#include <iostream>

void Harl::debug(void) const
{
	std::cout
		<< "I love having extra bacon for my "
		<< "7XL-double-cheese-triple-pickle-special-ketchup burger. "
		<< "I really do!"
		<< std::endl;
}

void Harl::info(void) const
{
	std::cout
		<< "I cannot believe adding extra bacon costs more money. "
		<< "You didn't put enough bacon in my burger! "
		<< "If you did, I wouldn't be asking for more!"
		<< std::endl;
}

void Harl::warning(void) const
{
	std::cout
		<< "I think I deserve to have some extra bacon for free. "
		<< "I've been coming for years whereas you started working here since last month."
		<< std::endl;
}

void Harl::error(void) const
{
	std::cout
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void Harl::complain(std::string level)
{
	const	t_func complaint[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (levels[i] == level)
		{
			(this->*complaint[i])();
			return ;
		}
	}
	std::cerr << "Enter a valid level: DEBUG / INFO / WARNING / ERROR" << std::endl;
}