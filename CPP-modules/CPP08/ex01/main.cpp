#include "Span.hpp"

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    try {
        sp.addNumber(12);
    }
    catch (std::exception &e)
    {
        std::cout << "Exception: out of range" << std::endl;
    }
	std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
	
	int size = 0;
	std::vector<int> biggie(size);
	srand(time(NULL));

	Span bigOne = Span(size);
	for (int i = 0; i < size; i++)
		biggie[i] = rand() % 100000;

	bigOne.myAssign(biggie.begin(), biggie.end());
	
	for (int i = 0; i < size; i++)
	{
		int j = bigOne.getNum(i);
		std::cout << "{" << j << "} ";

	std::cout << std::endl;
	try {
		std::cout << bigOne.shortestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: insufficient elements in vector" << std::endl;
	}
	try {
		std::cout << bigOne.longestSpan() << std::endl;
	}
	catch (std::exception &e){
		std::cout << "Exception: insufficient elements in vector" << std::endl;
	}
    return 0;
}