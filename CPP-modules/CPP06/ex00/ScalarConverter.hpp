#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <iostream>
#include <iomanip>
#include <limits>

class ScalarConverter 
{
	public:
		static void convert(const std::string &arg);
	private:
    	ScalarConverter();
    	ScalarConverter(const ScalarConverter &other);
    	~ScalarConverter();
    	ScalarConverter& operator=(const ScalarConverter &other); 
};

#endif
