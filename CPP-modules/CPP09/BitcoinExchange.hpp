#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>


class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange();
    BitcoinExchange& operator=(const BitcoinExchange &other);

	void parseData(const std::string &inputValues, const std::string &interestRates) const;
	void printResults() const;
private:
    std::map<std::string, double> _inputValues;
	std::map<std::string, double> _exchangeRates;
	void parseRates(const std::string &rates) const;
	void parseInput(const std::string &input) const;
};

#endif
