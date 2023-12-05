#include "MutantStack.hpp"

void more_test()
{
	MutantStack<int> testMStack;
	MutantStack<int> mStack(testMStack);
	mStack = testMStack;
	
	for (size_t i = 0; i < 4; i++)
		mStack.push(i);

	MutantStack<int>::iterator it_begin = mStack.begin();
	MutantStack<int>::iterator it_end = mStack.end();
	MutantStack<int>::iterator it(it_begin);
	it = it_begin;

	std::cout << "--------print by index------------" << std::endl;
	while (it != it_end)
	{
		std::cout << "mstack[" << std::distance(mStack.begin(), it) << "] = " << *it << std::endl;
		++it;
	}
	while (std::distance(mStack.begin(), it) > 0)
	{
		--it;
		std::cout << "mstack[" << std::distance(mStack.begin(), it) << "] = " << *it << std::endl;
	}
}

int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "---------list-----------" << std::endl;

	std::list<int> mstackList;
	mstackList.push_back(5);
	mstackList.push_back(17);
	std::cout << mstackList.back() << std::endl;
	mstackList.pop_back();
	std::cout << mstackList.size() << std::endl;
	mstackList.push_back(3);
	mstackList.push_back(5);
	mstackList.push_back(737);
	mstackList.push_back(0);
	std::list<int>::iterator itList = mstackList.begin();
	std::list<int>::iterator iteList = mstackList.end();
	++itList;
	--itList;
	while (itList != iteList)
	{
		std::cout << *itList << std::endl;
		++itList;
	}

	std::cout << "--------copy to std::stack------------" << std::endl;
	std::stack<int> s(mstack);
	std::cout << s.size() << std::endl;
	std::cout << mstack.size() << std::endl;
	
	std::cout << "--------find------------" << std::endl;
	MutantStack<int>::iterator foundIt = std::find(mstack.begin(), mstack.end(), 5);
	if (foundIt != mstack.end())
   	 	std::cout << "Element found: " << *foundIt << std::endl;
	more_test();

	return 0;
}
