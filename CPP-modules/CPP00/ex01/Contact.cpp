#include "Contact.hpp"

int		Contact::hasData() const
{
	return !_fname.empty();
}

void	Contact::set_fname(std::string str)
{
	_fname = str;
}
void	Contact::set_lname(std::string str)
{
	_lname = str;
}
void	Contact::set_nname(std::string str)
{
	_nname = str;
}
void	Contact::set_phone(std::string str)
{
	_phone = str;
}
void	Contact::set_secret(std::string str)
{
	_secret = str;
}
std::string	Contact::get_fname(void) const
{
	return _fname;
}

std::string	Contact::get_lname(void) const
{
	return _lname;
}

std::string	Contact::get_nname(void) const
{
	return _nname;
}

std::string	Contact::get_phone(void) const
{
	return _phone;
}

std::string	Contact::get_secret(void) const
{
	return _secret;
}
