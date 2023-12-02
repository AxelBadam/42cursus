#include "easyfind.hpp"

int main()
{
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	std::cout << easyfind(arr, 3) << std::endl;
	try	{
		easyfind(arr, 9);
	}
	catch (std::exception &e) {
		std::cout << "Number not found." << std::endl;
	}

    return 0;
}
