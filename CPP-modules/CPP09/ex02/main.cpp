#include "PmergeMe.hpp"

//divide in to pairs
//sort pairs according the bigger number
//use binary search to find the right spot to insert the smaller numbers

//https://en.wikipedia.org/wiki/Merge-insertion_sort
//https://www.geeksforgeeks.org/recursive-insertion-sort/


static std::string createSequence(int ac, char **av)
{
	std::string sequence;
	if (ac == 2)
		sequence = av[1];
	else
	{
		for (int i = 1; i < ac; i++)
		{
			sequence += av[i];
			sequence += " ";
		}
		sequence.erase(sequence.size() - 1);
	}
	return sequence;
}
 
int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << "Usage: ./PmergeMe number_sequence" << std::endl;
		return 1;
	}
	std::string sequence = createSequence(ac, av);
	PmergeMe::mergeInsertionSort(sequence);
    return 0;
}
