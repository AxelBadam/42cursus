#ifndef __BITCOINEXCHANGE_HPP__
#define __BITCOINEXCHANGE_HPP__

#include <iostream>
#include <map>
#include <sstream>
#include <fstream>

class BitcoinExchange 
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		~BitcoinExchange();
		BitcoinExchange& operator=(const BitcoinExchange &other);

		void parseAllData(const std::string &inputValues, const std::string &interestRates);
		void printResults() const;

	private:
		void												parseRates(const std::string &rates);
		void												parseInput(const std::string &input);
		std::multimap<std::string, float>::const_iterator 	findDate(const std::string &date) const;

		std::multimap<std::string, float> 					_inputValues;
		std::multimap<std::string, float> 					_exchangeRates;
};

#endif
