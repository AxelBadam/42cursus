#include "iter.hpp"



int main()
{
	char arr[4] = "acb";
	int length = 3;

	std::cout << arr << std::endl;
	::iter(arr, length, func);
	std::cout << arr << std::endl;

	std::cout << "-----------------" << std::endl;

	int arr_i[4] = {1, 2, 3, 4};
	int length_i = 4;

	for (int i = 0; i < length_i; i++)
		std::cout << arr_i[i] << std::endl;

	::iter(arr_i, length_i, func);

	for (int i = 0; i < length_i; i++)
		std::cout << arr_i[i] << std::endl;

	std::cout << "-----------------" << std::endl;

	float arr_f[4] = {1.3f, 2.2f, -3.f, 4.0f};
	int lenght_f = 4;

	for (int i = 0; i < length_i; i++)
		std::cout << arr_f[i] << std::endl;

	::iter(arr_f, lenght_f, func);

	for (int i = 0; i < lenght_f; i++)
		std::cout << arr_f[i] << std::endl;    
	return 0;
}
