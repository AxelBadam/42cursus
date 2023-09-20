#include "Contact.hpp"
#include "Phonebook.hpp"

static std::string truncate(std::string const&str, int max_width)
{
	if (str.length() > 10)
		return str.substr(0, max_width - 1) + ".";
	return str;
}

void	Phonebook::view_contacts(Contact contacts[8])
{
	std::string	str;
	
	if (_i > 7)
		_count = 8;
	else
		_count = _i;
	for (int i = 0; i < _count; i++)
	{
		const int width = 10;
		std::cout << std::setw(width) << std::right << i << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_fname(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_lname(), width) << '|'
			<< std::setw(width) << std::right << truncate(contacts[i].get_nname(), width) << std::endl;
	}
}

void	Phonebook::print(Contact contact)
{
	std::cout << "First name: " << contact.get_fname() << std::endl;
	std::cout << "Last name: " << contact.get_lname() << std::endl;
	std::cout << "Nickname: " << contact.get_nname() << std::endl;
	std::cout << "Phone number: " << contact.get_phone() << std::endl;
	std::cout << "Darkest secret " << contact.get_secret() << std::endl;
}

void	Phonebook::search(void)
{
	std::string str;
	int i;
	
	view_contacts(_contacts);
	std::cout << "Enter index: ";
	if (std::getline(std::cin, str) && str >= "0" && str <= "7")
		{
			i = std::atoi(str.c_str());
   			if (i >= 0 && i <= 7 && _contacts[i].hasData())
       			print(_contacts[i]);
		}
	else
		std::cout << "Invalid or empty index!" << std::endl;
}

void	Phonebook::add(void)
{
	std::string str;
	
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter first name: ";
		if (std::getline(std::cin, str) && str != "")
			_contacts[_i % 8].set_fname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter last name: ";
		if (std::getline(std::cin, str) && str != "")
			_contacts[_i % 8].set_lname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter nickname: ";
		if (std::getline(std::cin, str) && str != "")
			_contacts[_i % 8].set_nname(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter phone number ";
		if (std::getline(std::cin, str) && str != "")
			_contacts[_i % 8].set_phone(str);
	}
	str = "";
	while (!std::cin.eof() && str == "")
	{
		std::cout << "Enter darkest secret: ";
		if (std::getline(std::cin, str) && str != "")
			_contacts[_i % 8].set_secret(str);
	}
	_i++;
}
