
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

// long int		Span::shortestSpan()
// {

// }

// long int		Span::longestSpan()
// {

// }

unsigned int	Span::size() {
	return (_size);
}

int				Span::getNum(int i)
{
	if (i < (int)_size)
		return (_numbers[i]);
	else
		return 0;
}