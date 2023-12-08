#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./btc input_file" << std::endl;
		return 1;
	}
	
	const std::string interestRates = "data.csv";
	const std::string inputValues = av[1];
	BitcoinExchange obj;
	obj.parseData(inputValues, interestRates);
	obj.printResults();
	
    return 0;
}
