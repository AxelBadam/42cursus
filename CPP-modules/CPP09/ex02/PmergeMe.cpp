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

void PmergeMe::createPairs(const std::vector<unsigned long>& vec) 
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
	for (i = 0; i < large.size(); i++)
		std::cout << large[i] << " ";
	
	//print vectors
	// for (i = 0; i < small.size(); i++)
	// 	std::cout << small[i] << " ";
	// 	std::cout << std::endl;

	// print pairs
 	// for (i = 0; i < pairs.size(); i += 1) {
	// 	std::cout << pairs[i].first << " - " << pairs[i].second << " | ";
}

void PmergeMe::mergeInsertionSort(std::string &sequence)
{
	const int sec_to_usec = 1000000;
	struct timeval			tv;
	time_t					before;
	time_t					timeVec;
	time_t					timeDeque;

	// Vector
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
// ------------------
	std::vector<unsigned long> vector = parseSequence<std::vector<unsigned long int> >(sequence);
	printContainer(vector);
	createPairs(vector);

	//printContainer(vector);

//--------------------
	gettimeofday(&tv, NULL);
	timeVec = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	// Deque
	gettimeofday(&tv, NULL);
	before = tv.tv_sec * sec_to_usec + tv.tv_usec;
// ------------------
	std::deque<unsigned long> numbersDeque = parseSequence<std::deque<unsigned long int> >(sequence);
	std::vector<unsigned long> sortedDeque;
	//printContainer(numbersDeque);

//--------------------	
	gettimeofday(&tv, NULL);
	timeDeque = (tv.tv_sec * sec_to_usec + tv.tv_usec) - before;

	//std::cout << "Before: " << sequence << std::endl;	
	
	//std::cout << "After: ";

	//std::cout << std::endl;

}
