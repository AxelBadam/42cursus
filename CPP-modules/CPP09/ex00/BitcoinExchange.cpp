#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    _exchangeRates = cpy._exchangeRates;
	_inputValues = cpy._inputValues;
}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        _exchangeRates.clear();
		_exchangeRates = rhs._exchangeRates;
    }
    return (*this);
}


static bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

static int getDaysInMonth(int month, int year) 
{
    switch (month) 
	{
        case 2:
            return isLeapYear(year) ? 29 : 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

static bool isDateValid(const std::string &date)
{

    if (date.length() != 10)
	{
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}
        
    for (size_t i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
		{
            if (date[i] != '-')
            {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
        } 
		else
		{
            if (!std::isdigit(date[i]))
            {
				std::cout << "Error: bad input => " << date << std::endl;
				return false;
			}
        }
    }

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    if (month < 1 || month > 12)
    {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

    if (day < 1 || day > getDaysInMonth(month, year))
    {
		std::cout << "Error: bad input => " << date << std::endl;
		return false;
	}

	const std::string startDate = "2009-01-02";
    const std::string endDate = "2022-03-29";
    if (date < startDate || date > endDate)
    {
		std::cout << "Error: bad input => " << date << ", date must be between " 
								<< startDate << " and " << endDate << std::endl;
		return false;
	}
	return true;
}

static bool isValueValid(const float &value){
	if (value < 0 || value > 1000)
	{
		std::cout << "Error: value must be between 0-1000" << std::endl;
		return false;
	}
	return true;
}

static std::string rtrim(const std::string& str)
{
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

static void checkFirstLine(std::ifstream &file)
{
	std::string line, date;
	std::string value;
	if (std::getline(file, line)) 
	{
        std::istringstream iss(line);
        if (std::getline(iss, date, '|') && (iss >> value)) 
		{
			if (rtrim(date) == "date" && rtrim(value) == "value")
				return;
		}
	}
	std::cout << "Empty file or incorrect format in first line: " << line << std::endl;
    return;
}

void BitcoinExchange::parseRates(const std::string &rates)
{
    std::ifstream file(rates.c_str());
    if (!file.is_open())
	{
        std::cout << "Failed to open file: " << rates << std::endl;
		throw std::exception();
    }
    std::string line, date;
	float value;                  
    while (std::getline(file, line)) 
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ','))
		{
			iss >> value;
			_exchangeRates.insert(std::make_pair(date, value));
		}
    }
    file.close();
}

void BitcoinExchange::parseInput(const std::string &input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << input << std::endl;
		throw std::exception();
    }
	checkFirstLine(file);
    std::string line, date;
	float value;
    while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, '|'))
		{
			date = rtrim(date);
			iss >> value;
    		_inputValues.insert(std::make_pair(date, value));
		}
    }
    file.close();
}

void BitcoinExchange::parseAllData(const std::string &inputValues, const std::string &exchangeRates)
{	
	try {
		parseInput(inputValues);
	}
	catch (std::exception &e){
		std::cout << "Invalid input" << std::endl;
	}
	try {
		parseRates(exchangeRates);
	}
	catch (std::exception &e){
		std::cout << "Invalid input" << std::endl;
	}
}

std::multimap<std::string, float>::const_iterator BitcoinExchange::findDate(const std::string &date) const
{
	std::multimap<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
	const std::string higherOrEqualRate = it->first;

	while (it != _exchangeRates.begin() && it->first == higherOrEqualRate && higherOrEqualRate != date)
		it--;
	return it;
}

void BitcoinExchange::printResults() const
{
	std::multimap<std::string, float>::const_iterator itRates;
	std::multimap<std::string, float>::const_iterator itInput = _inputValues.begin();

	while (itInput != _inputValues.end())
	{
		itRates = findDate(itInput->first);
		if (itInput != _inputValues.end() && isDateValid(itInput->first)
		 && isValueValid(itInput->second) && isDateValid(itRates->first)
		 && isValueValid(itRates->second))
		{
			std::cout << "Key: " << itInput->first << ", Value: " << itInput->second <<
			 				" => " << itInput->second * itRates->second << std::endl;
		}
		itInput++;
    }
}
