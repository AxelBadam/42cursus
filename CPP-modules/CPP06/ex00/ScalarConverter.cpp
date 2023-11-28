#include "ScalarConverter.hpp"
#include <iomanip>
#include <string>
#include <limits>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &cpy){
    (void)cpy;
}

ScalarConverter::~ScalarConverter(){}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
    return (*this);
}

enum Type { CHAR, INT, FLOAT, DOUBLE, INFNAN, INVALID };

static bool isValidString(const std::string &arg)
{
    int count_dot = 0;

    for (size_t i = 0; i < arg.length(); ++i) 
	{
        if (arg[i] == '.')
            ++count_dot;
	}
    int count_f = 0;
    for (size_t i = 0; i < arg.length(); ++i) 
	{
        if (arg[i] == 'f')
            ++count_f;
	}
	if (count_dot > 1 || count_f > 1)
		return false;

	if (arg[0] >= '0' && arg[0] <= '9')
	{	
		int i = 1;
		while (arg[i])
		{
			if (arg[i] == '.' && arg[i + 1])
				i++;
			if ((arg[i] < '0' || arg[i] > '9') && arg[i] != 'f')
				return false;
			i++;
		}
	}
	return true;
}

static Type getType(const std::string& arg) 
{
	bool isValid = isValidString(arg);

    if (arg.length() == 1 && (arg[0] < '0' || arg[0] > '9'))
        return CHAR;
    if (arg.find('.') != std::string::npos && arg.back() == 'f' && isValid)
	{
        try 
		{
			std::stof(arg);
			return FLOAT;
		}
		catch (std::exception &ia){}
    }
	else if (arg.find('.') != std::string::npos && isValid)
	{
        try 
		{
			std::stod(arg);
			return DOUBLE;
		}
		catch (std::exception &ia) {}
    }
	else if (isValid)
	{
		try 
		{
			std::stoi(arg);
			return INT;
		}	
		catch (std::exception &ia) {}
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
	if (arg.compare("-inff") == 0 || arg.compare("-inf") == 0)
	{
		f = -std::numeric_limits<float>::infinity();
		d = -std::numeric_limits<double>::infinity();
		argType = INFNAN;
	}
	else if (arg.compare("+inff") == 0 || arg.compare("+inf") == 0)
	{
		f = std::numeric_limits<float>::infinity();
		d = std::numeric_limits<double>::infinity();
		argType = INFNAN;
	}
	else if (arg.compare("nanf") == 0 || arg.compare("nan") == 0)
	{
		f = std::numeric_limits<float>::quiet_NaN();
		d = std::numeric_limits<double>::quiet_NaN();
		argType = INFNAN;
	}
	//std::cout << argType << std::endl;
	// CHAR, INT, FLOAT, DOUBLE, INFNAN, INVALID
	switch (argType)
	{
		case 0:
			c = arg.at(0);
			d = static_cast<double>(c);
			f = static_cast<float>(c);
			i = static_cast<int>(c);
			break;
		case 1:
			i = std::stoi(arg);
			d = static_cast<double>(i);
			f = static_cast<float>(i);
			c = static_cast<char>(i);
			break;
		case 2:
			f = std::stof(arg);
			d = static_cast<double>(f);
			i = static_cast<int>(f);
			c = static_cast<char>(f);
			break;
		case 3:
			d = std::stod(arg);
			f = static_cast<float>(d);
			i = static_cast<int>(d);
			c = static_cast<char>(d);
			break;
		case 4:
			break;
		case 5:
			std::cout << "invalid input" << std::endl;
			break;
	}

	if (argType == INFNAN || i < 0 || i > 127)
		std::cout << "char: impossible" << std::endl;
	else if (c < 33 || c >= 127)
		std::cout << "char: non displayable" << std::endl;
	else if (c > 32 && c < 127)
		std::cout << "char: '" << c << "'" << std::endl;

	
	if (argType != INFNAN)
		std::cout << "int: " << i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
