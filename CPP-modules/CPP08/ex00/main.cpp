#include "easyfind.hpp"

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	try	{
		std::cout << "Found number " << easyfind(vec, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Number not found." << std::endl;
	}

	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);

	try	{
		std::cout << "Found number " << easyfind(lst, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Number not found." << std::endl;
	}
	
	const int arr[] = {1, 2, 3, 4, 5};
    const std::vector<int> vecC(arr, arr + 5);

	try	{
		std::cout << "Found number " << easyfind(vecC, 3) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << "Number not found." << std::endl;
	}


    return 0;
}
