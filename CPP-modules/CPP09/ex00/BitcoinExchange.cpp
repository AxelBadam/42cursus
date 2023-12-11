#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &cpy)
{
    (void)cpy;
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const &rhs)
{
    if (this != &rhs)
    {
        _exchangeRates.clear();
		_exchangeRates = rhs._exchangeRates;
    }
    return (*this);
}


static std::string rtrim(const std::string& str)
{
    size_t end = str.find_last_not_of(" \t\n\r\f\v");
    return (end == std::string::npos) ? "" : str.substr(0, end + 1);
}

void BitcoinExchange::parseRates(const std::string &rates)
{
    std::ifstream file(rates.c_str()); // Open the file
    if (!file.is_open())
	{
        std::cout << "Failed to open file: " << rates << std::endl;
        return;
    }
    std::string line, date;
	double value;
    while (std::getline(file, line)) 
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, ','))
		{
			
			std::cout << "date before parse " << date << std::endl;
			iss >> value;
			_exchangeRates.insert(std::make_pair(date, value));
		}
    }
    file.close();
}

std::string BitcoinExchange::checkDate(std::string &date)
{

	// std::multimap<std::string, double>::iterator itDateA = _exchangeRates.begin();
	// std::cout << itDateA->first << std::endl;
	// std::multimap<std::string, double>::iterator itDate = _exchangeRates.lower_bound(date);
	
	// std::cout << "input date is " << date << std::endl;
	// std::cout << "iterator =  " << itDate->first << std::endl;
	// if (itDate == _exchangeRates.end())
	// {

	//  	if (itDate == _exchangeRates.begin() || itDate == _exchangeRates.end()) 
	// 	{
    //         std::cout << "No earlier date available" << std::endl;
    //         return date;
    //     }	
	// 	std::cout << itDate->first << std::endl;
	// 	while (itDate != _exchangeRates.begin() && itDate->first == date)
	// 		itDate--;
	// 	return itDate->first;
	// }
	
	return date;
}

void BitcoinExchange::parseInput(const std::string &input)
{
    std::ifstream file(input.c_str());
    if (!file.is_open()) {
        std::cout << "Failed to open file: " << input << std::endl;
        return;
    }
    std::string line, date;
	double value;
    while (std::getline(file, line))
	{
		std::istringstream iss(line);
		if (std::getline(iss, date, '|'))
		{
			date = rtrim(date);
			date = checkDate(date);
			std::cout << "Inputdate before parse " << date << std::endl;
			iss >> value;
    		_inputValues.insert(std::make_pair(date, value));
		}
    }
    file.close();
}

void BitcoinExchange::findClosestDate()
{

}

void BitcoinExchange::multiplyMapData()
{
	
}

void BitcoinExchange::parseData(const std::string &inputValues, const std::string &exchangeRates)
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

void BitcoinExchange::printResults() const
{
	std::map<std::string, double>::const_iterator itRates = _exchangeRates.begin();
	std::map<std::string, double>::const_iterator itInput = _inputValues.begin();

	itInput++;
	itRates++;
	while (itInput != _inputValues.end())
	{
		// std::cout << itInput->first << std::endl;
		// std::cout << itRates->first << std::endl;
		itRates = _exchangeRates.find(itInput->first);

		if (itRates != _exchangeRates.end())
		{
			std::cout << "Key: " << itInput->first << ", Value: " << itInput->second << " => " << itInput->second * itRates->second << std::endl;
		}
		else
			std::cout << "find closest" << std::endl;
		itInput++;
    }

	// std::cout << "Rates from database: " << std::endl;
	// for (std::map<std::string, double>::const_iterator it = _exchangeRates.begin(); it != _exchangeRates.end(); ++it) {
    //     std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    // }
}
