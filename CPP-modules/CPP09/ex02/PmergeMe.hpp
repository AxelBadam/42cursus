#ifndef __PMERGEME_HPP__
#define __PMERGEME_HPP__

#include <iostream>
#include <sstream>
#include <iterator>
#include <cctype>
#include <vector>
#include <deque>
#include <sys/time.h>
#include <unistd.h>
#include <algorithm>

class PmergeMe 
{
	public:
		static void mergeInsertionSort(std::string &sequenceuence);

	private:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		~PmergeMe();
		PmergeMe& operator=(const PmergeMe &other);

		static void createPairs(const std::vector<unsigned long>& vec);

		template<typename T>
		static bool isValidNumber(const std::string& str)
		{
			std::istringstream iss(str);
			typename T::value_type temp;
			iss >> temp;
			return iss.eof() && !iss.fail();
		}

		template<typename T>
		static T parseSequence(const std::string& sequence) 
		{
			std::istringstream sequenceStream(sequence);
			std::string token;
			T res;

			while (sequenceStream >> token) 
			{
				if (isValidNumber<T>(token)) 
				{
					std::istringstream tokenStream(token);
					typename T::value_type number;
					tokenStream >> number;
					res.insert(res.end(), number);
				}
				else
				{
					std::cout << "Error: invalid input" << std::endl;
					exit(1);
				}
			}
			return res;
		}

		template<typename T>
		static void printContainer(const T& container) 
		{
			for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
				std::cout << *it << " ";
			std::cout << std::endl;
		}

		template<typename T>
		static void mergeSort(T &sequence)
		{
			if (sequence.size() <= 1)
				return;	
			typename T::iterator middle = sequence.begin() + (sequence.size() / 2);
			T leftHalf(sequence.begin(), middle);
			T rightHalf(middle, sequence.end());
			
			mergeSort(leftHalf);
			mergeSort(rightHalf);

			typename T::iterator rightHalf_it = rightHalf.begin();
			typename T::iterator sequence_it = sequence.begin();
			typename T::iterator leftHalf_it = leftHalf.begin();


			while (leftHalf_it < leftHalf.end() && rightHalf_it < rightHalf.end()) 
			{
				if (*leftHalf_it < *rightHalf_it) 
				{
					*sequence_it = *leftHalf_it;
					leftHalf_it++;
				} 
				else 
				{
					*sequence_it = *rightHalf_it;
					rightHalf_it++;
				}
				sequence_it++;
			}

			while (leftHalf_it < leftHalf.end()) 
			{
				*sequence_it = *leftHalf_it;
				leftHalf_it++;
				sequence_it++;
			}

			while (rightHalf_it < rightHalf.end()) 
			{
				*sequence_it = *rightHalf_it;
				rightHalf_it++;
				sequence_it++;
			}
		}
    
};

#endif
