#include "PmergeMe.hpp"

//divide in to pairs
//sort pairs according the bigger number
//use binary search to find the right spot to insert the smaller numbers

//https://en.wikipedia.org/wiki/Merge-insertion_sort
//https://www.geeksforgeeks.org/recursive-insertion-sort/


int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage: ./PmergeMe number_sequence" << std::endl;
		return 1;
	}
	PmergeMe::timeAndSort(ac, av);
    return 0;
}
