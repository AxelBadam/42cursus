#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(RPN const &cpy) {
	_numbers = cpy._numbers; 
}

RPN::~RPN() {}

RPN& RPN::operator=(RPN const &rhs)
{
    if (this != &rhs)
       _numbers = rhs._numbers;
	return *this;
}

static double multiply(double a, double b) { 
	return a * b; 
}

static double divide(double a, double b) { 
	return a / b; 
}

static double add(double a, double b) { 
	return a + b; 
}

static double subtract(double a, double b) { 
	return a - b; 
}

typedef double operation(double, double);

double RPN::calculate(const std::string &expr)
{
	const std::string operators("+-*/");
	operation *operations[] = {
		add, subtract, multiply, divide
	};

	std::string::const_iterator it(expr.begin());
	while (it != expr.end())
	{
		size_t operatorIndex = operators.find_first_of(*it);
		if (isdigit(*it))
			_numbers.push(*it - '0');
		else if (operatorIndex != std::string::npos && _numbers.size() >= 2)
		{
			double right_oper = _numbers.top();
			_numbers.pop();
			double left_oper = _numbers.top();
			_numbers.pop();
			double res = operations[operatorIndex](left_oper, right_oper);
			_numbers.push(res);
		}
		else if (*it != ' ')
			throw std::exception();
		it++;
	}
	if (_numbers.size() != 1)
		throw std::exception();
	return _numbers.top();
}
