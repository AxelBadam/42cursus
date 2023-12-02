#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
   // std::cout << numbers << std::endl;

	//assigment / copy constr.
    Array<int> tmp(3);
	for (int i = 0; i < 3; i++)
    {
        const int value = rand() % 10;
        tmp[i] = value;
    }
    Array<int>  test = tmp;
	std::cerr << "printing tmp : " << std::endl;
	std::cerr << tmp << std::endl;
	std::cerr << "printing test : " << std::endl;
	std::cerr << test << std::endl;
	tmp[0] = 0;
	std::cerr << "printing test : " << std::endl;
	std::cerr << test << std::endl;
	Array<int> cpy(tmp);
	std::cerr << "printing cpy " << std::endl;
	std::cerr << cpy << std::endl;
	

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "-2: " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "exception: " <<  e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}