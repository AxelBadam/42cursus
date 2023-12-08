#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    (void)cpy;
}

BitcoinExchange::~BitcoinExchange()
{
    
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

void BitcoinExchange::parseRates(const std::string &rates)
{
    std::ifstream file(rates.c_str()); // Open the file
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << rates << std::endl;
        return;
    }
    std::string line, date;
	std::getline(file, line);
	double value;
    while (std::getline(file, line)) 
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ','))
		{
			iss >> value;
			_inputValues.insert(std::make_pair(date, value));
		}
    }
    file.close();
}

void BitcoinExchange::parseInput(const std::string &input)
{
    std::ifstream file(input.c_str()); // Open the file
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << input << std::endl;
        return;
    }
    std::string line, date;
	std::getline(file, line);
	double value;
    while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, '|'))
		{
			iss >> value;
			 _inputValues.insert(std::make_pair(date, value)); // whats up with the print??
		}
    }
    file.close();
}

void BitcoinExchange::parseData(const std::string &inputValues, const std::string &exchangeRates)
{
	parseInput(inputValues);
	parseRates(exchangeRates);
}

void BitcoinExchange::printResults() const
{
	std::cout << "Input values: " << std::endl;
	for (std::map<std::string, double>::const_iterator it = _inputValues.begin(); it != _inputValues.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
	// std::cout << "Rates from database: " << std::endl;
	// for (std::map<std::string, double>::const_iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }
}
