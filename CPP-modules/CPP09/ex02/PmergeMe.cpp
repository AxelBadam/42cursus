#include "PmergeMe.hpp"

struct MyPair 
{
    unsigned long first;
    unsigned long second;

    MyPair(unsigned long a, unsigned long b) 
	{
        if (a <= b) 
		{
            first = a;
            second = b;
        } 
		else 
		{
            first = b;
            second = a;
        }
    }
};

void PmergeMe::mergeInsertionSort(std::vector<unsigned long>& vec)
{
    std::vector<MyPair> pairs;
	std::vector<unsigned long> large;
	std::vector<unsigned long> small;
	size_t vecSize = vec.size();
	bool isUnEven = vecSize % 2; 
	size_t i;

    for (i = 0; i + 1 < vecSize; i += 2)
        pairs.push_back(MyPair(vec[i], vec[i + 1]));
	if (i < vec.size() && isUnEven)
		 pairs.push_back(MyPair(vec[i], vec[i]));
	for (i = 0; i < pairs.size(); i++)
		{
			if (isUnEven && i + 1 == pairs.size())
				break;
			large.push_back(pairs[i].second);
		}
	for (i = 0; i < pairs.size(); i++)
		small.push_back(pairs[i].first);
	mergeSort<std::vector<unsigned long> > (large);
	insertWithBinarySearch(small, large);
	vec = large;
	// print pairs, for example
 	// for (i = 0; i < pairs.size(); i += 1)
	// 	std::cout << pairs[i].first << " - " << pairs[i].second << " | ";
}

void PmergeMe::mergeInsertionSort(std::deque<unsigned long>& deque)
{
    std::deque<MyPair> pairs;
	std::deque<unsigned long> large;
	std::deque<unsigned long> small;
	size_t dequeSize = deque.size();
	bool isUnEven = dequeSize % 2; 
	size_t i;

    for (i = 0; i + 1 < dequeSize; i += 2)
        pairs.push_back(MyPair(deque[i], deque[i + 1]));
	if (i < deque.size() && isUnEven)
		 pairs.push_back(MyPair(deque[i], deque[i]));
	for (i = 0; i < pairs.size(); i++)
		{
			if (isUnEven && i + 1 == pairs.size())
				break;
			large.push_back(pairs[i].second);
		}
	for (i = 0; i < pairs.size(); i++)
		small.push_back(pairs[i].first);
	mergeSort<std::deque<unsigned long> > (large);
	insertWithBinarySearch(small, large);
	deque = large;
}


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

void PmergeMe::timeAndSort(int ac, char **av)
{
	const int sec_to_usec = 1000000;
	struct timeval			tv;
	time_t					before;
	time_t					timeVec;
	time_t					timeDeque;

	// Vector
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
	std::vector<unsigned long> vector = parseSequence<std::vector<unsigned long int> >(createSequence(ac, av));
	mergeInsertionSort(vector);
	gettimeofday(&tv, NULL);
	timeVec = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	// Deque
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
	std::deque<unsigned long> deque = parseSequence<std::deque<unsigned long int> >(createSequence(ac, av));
	mergeInsertionSort(deque);
	gettimeofday(&tv, NULL);
	timeDeque = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	std::cout << "Before: " << createSequence(ac, av) << std::endl;	
	std::cout << "Vector after: ";
	printContainer(vector);
	std::cout << "Deque after: ";
	printContainer(deque);
	std::cout << "Time to process a range of " << vector.size()
		<< " elements with std::vector:\t" << timeVec << " microseconds" << std::endl;
	std::cout << "Time to process a range of " << deque.size()
	<< " elements with std::deque: \t" << timeDeque << " microseconds" << std::endl;
	// std::cout << std::endl;
}
