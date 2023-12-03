#ifndef	__SPAN_HPP__
# define __SPAN_HPP__

# include <iostream>
# include <exception>
# include <vector>
# include <algorithm>
# include <numeric>

class Span
{
    public:
        Span();
        Span(const Span &other);
        Span(unsigned int n);
        ~Span();
        Span	&operator=( const Span &s );

        void		fillNumbers();

        void		addNumber(int n);
        long int	shortestSpan();
        long int	longestSpan();

        unsigned int	size( void );
        int				getNum( int i );
    private:
	    std::vector<int>	_numbers;
	    unsigned int		_size; 
};

#endif