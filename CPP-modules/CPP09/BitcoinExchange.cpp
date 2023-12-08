#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    
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





void BitcoinExchange::parseRates(const std::string &rates) const
{

}

void BitcoinExchange::parseInput(const std::string &input) const
{	
	std::ifstream file;
	try { file.open(input); } catch (std::exception()) {}
	std::string line;
	getline(file, line);
	// skip the first line ? 

	...
	std::istringstream iss(line);
    std::string date;
    double value;
    if (std::getline(iss, date, '|')) { // && isValidDate(date)
        iss >> value;
        if (!iss.fail()) {
            _inputValues[date] = value; // This will overwrite existing values for the same date
        }
    }

}

void BitcoinExchange::parseData(const std::string &inputValues, const std::string &exchangeRates) const
{
	parseInput(inputValues);
	parseRates(exchangeRates);
}

void BitcoinExchange::printResults() const
{
	std::cout << "Input values: " << std::endl;
	for (std::map<std::string, double>::const_iterator it = inputValues.begin(); it != inputValues.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
	std::cout << "Rates: " << std::endl;
	for (std::map<std::string, double>::const_iterator it = exchangeRates.begin(); it != exchangeRates.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }
}
