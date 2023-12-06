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
    // std::ccout << numbers << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "-2: " << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cout << "exception: " <<  e.what() << '\n';
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
	
	// assigment / copy constr.
    Array<int> tmp(3);
	for (int i = 0; i < 3; i++)
    {
        const int value = rand() % 10;
        tmp[i] = value;
    }
    Array<int>  test = tmp;
	// << is overloaded
	std::cout << "printing tmp : " << tmp << std::endl;
	std::cout << "printing test : " << test << std::endl;
	tmp[0] = 0;
	std::cout << "printing test after changing tmp : " << test << std::endl;
	Array<int> cpy(tmp);
	std::cout << "printing cpy " << cpy << std::endl;
    return 0;
}