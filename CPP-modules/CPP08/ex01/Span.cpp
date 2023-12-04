
#include "Span.hpp"

Span::Span(): _size(0) {}

Span::Span( const Span &other ): _numbers(other._numbers), _size(other._size) {}

Span::Span( unsigned int n ): _size(n) {}

Span::~Span() {}

Span	&Span::operator=(const Span &rhs)
{
	if (this != &rhs)
	{
		_numbers = rhs._numbers;
		_size = rhs._size;
	}
	return (*this);
}

void	Span::addNumber(int n)
{
    if (_numbers.size() < _size)
        _numbers.push_back(n);
    else 
        throw std::exception();
}

unsigned int	Span::size() {
	return (_size);
}

int				Span::getNum(int i)
{
	if (i < (int)_size)
		return (_numbers[i]);
	return 0;
}

unsigned int Span::shortestSpan() const
{	
	if (_size < 2)
		throw std::exception();
	std::vector<int> tmp(_numbers);
	std::sort(tmp.begin(), tmp.end());
	unsigned int tmp_size = tmp.size();
	unsigned int span_stored = *std::max_element(_numbers.begin(), _numbers.end());
	for (unsigned int i = 0; i < tmp_size - 1; i++)
	{
		unsigned int span = std::abs(tmp[i] - tmp[i + 1]);
		if (span < span_stored)
			span_stored = span;
	}
	return span_stored;
}

unsigned int Span::longestSpan() const
{
	if (_size < 2)
		throw std::exception();
	return *std::max_element(_numbers.begin(), _numbers.end()) 
		- *std::min_element(_numbers.begin(), _numbers.end());
}
