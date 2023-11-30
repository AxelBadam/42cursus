#include "Array.hpp"

int main()
{
	int *a = new int();
	std::cout << *a << std::endl;
	delete a;

	
	Array<int> asd[3];
	asd[0] = 1;
	asd[1] = 3;
	Array<int> kek(*asd);
	
	std::cout << *asd << std::endl;

		
	return 0;
}
