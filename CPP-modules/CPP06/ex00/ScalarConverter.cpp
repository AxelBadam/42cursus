#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>
#include <limits>

ScalarConverter::ScalarConverter()
{
    
}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy)
{
    (void)cpy;
}

ScalarConverter::~ScalarConverter()
{
    
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &rhs)
{
    if (this != &rhs)
    {
        
    }
    return (*this);
}

enum Type { CHAR, INT, FLOAT, DOUBLE, INVALID };

static Type getType(const std::string& arg) 
{
    if (arg.length() == 1) {
        return CHAR;
    }
    if (arg.find('.') != std::string::npos && arg.back() == 'f')
	{
        try {
			std::stof(arg);
			return FLOAT;
		}
		catch (std::exception &ia)
		{

		}
    } 
	else if (arg.find('.') != std::string::npos)
	{
        try 
		{
			std::stod(arg);
			return DOUBLE;
		}
		catch (std::exception &ia)
		{

		}
    }
	try 
	{
		std::stoi(arg);
		return INT;
	}	
	catch (std::exception &ia)
	{

	}
	return INVALID;
    }

   


void ScalarConverter::convert(const std::string &arg)
{
	int 	i = 0;
	double 	d = 0;
	float 	f = 0;
	char 	c = 0;

	Type argType = getType(arg);
	std::cout << argType << std::endl;

	// try 
	// {
	// 	i = std::stoi(arg);
	// 	c = static_cast<char>(i);
	// 	d = static_cast<double>(i);
	// 	f = static_cast<float>(i);
	// }
	// catch (const std::invalid_argument &ia)
	// {
	// 	std::cout << "int: not suitable for conversion" << std::endl;
	// }
	// try 
	// {
	// 	f = std::stof(arg);
	// 	i = static_cast<int>(c);
	// 	d = static_cast<double>(c);
	// 	c = static_cast<char>(c);
	// }
	// catch (const std::invalid_argument &ia)
	// {
	// 	std::cout << "float: not suitable for conversion" << std::endl;
	// }
	// if (arg.length() == 1)
	// {
	// 	c = arg[0];
	// 	i = static_cast<int>(c);
	// 	d = static_cast<double>(c);
	// 	f = static_cast<float>(c);
	// }
	// else
	// 	std::cout << "char: not suitable for conversion" << std::endl;
	
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "char: " << c << std::endl;





}
