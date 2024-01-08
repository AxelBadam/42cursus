#include "PmergeMe.hpp"

//https://en.wikipedia.org/wiki/Merge-insertion_sort

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
