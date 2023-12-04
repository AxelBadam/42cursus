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

        template <typename Iterator>
		void myAssign(Iterator begin, Iterator end) 
		{
    		for (Iterator it = begin; it != end; ++it)
       			addNumber(*it);
   		}

        void		addNumber(int n);
       	unsigned int	shortestSpan() const;
        unsigned int	longestSpan() const;

        unsigned int	size( void );
        int				getNum( int i );
    private:
	    std::vector<int>	_numbers;
	    unsigned int		_size; 
};

#endif