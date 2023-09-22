#include <iostream>

int main(void)
{
	std::string hi = "HI THIS IS BRAIN";
	std::string *stringPTR = &hi;
	std::string &stringREF = hi;

	std::cout << &hi << "\n";
	std::cout << stringPTR << "\n";
	std::cout << &stringREF << "\n";

	std::cout << hi << "\n";
	std::cout << *stringPTR << "\n";
	std::cout << stringREF << "\n";

	return 0;
}
