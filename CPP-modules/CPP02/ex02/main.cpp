#include "Fixed.hpp"
#include <iostream>


int main(void) 
{

	Fixed a(5.5f);
	Fixed b(5);

	std::cout << a.getRawBits() << "\n";
	a++;
	std::cout << a.getRawBits() << "\n";
	std::cout << a.toFloat() << "\n";

	if (a < b)
		std::cout << a << " is smaller than " << b << std::endl;
	if (a > b)
		std::cout << a << " is larger than " << b << std::endl;
	a = 0;
	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << c.getRawBits() << "\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << c << std::endl;
	std::cout << Fixed::max( a, c ) << std::endl;
	
	Fixed d(2);
	Fixed g(0.0129f);
	std::cout << g / d << std::endl;
	return 0;
}
