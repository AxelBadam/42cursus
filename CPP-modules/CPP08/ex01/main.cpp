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

	std::vector<int> biggie(10000);
	srand(time(NULL));
	
	Span bigOne(10000);
	for (int i = 0; i < 10000; i++)
	{
		biggie[i] = rand() % 100000;
	}

	bigOne.myAssign(biggie.begin(), biggie.end());
	for (int i = 0; i < 10000; i++)
	{
		int j = bigOne.getNum(i);
		std::cout << "{" << j << "}, ";
	}
	std::cout << std::endl;

	std::cout << bigOne.shortestSpan() << std::endl;
    std::cout << bigOne.longestSpan() << std::endl;

	



    return 0;
}