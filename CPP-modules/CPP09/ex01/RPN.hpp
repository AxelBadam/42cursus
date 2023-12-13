#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <algorithm>
#include <stack>
#include <iostream>

class RPN 
{
	public:
		RPN();
		RPN(const RPN &other);
		~RPN();
		RPN& operator=(const RPN &other);
		double calculate(const std::string &expr);
	private:
		std::stack<double> _numbers;
};

#endif
