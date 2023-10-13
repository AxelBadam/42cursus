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
	
	b.setRawBits(0);
	std::cout << a / b << std::endl;
	Fixed d(2);
	Fixed g(0.0129f);

	std::cout << g / d << std::endl;

	Fixed const c( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << c.getRawBits() << "\n";
	std::cout << "a is " << a << std::endl;
	std::cout << "pre-inc a " << ++a << std::endl;
	std::cout << "post-inc a " << a++ << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "larger is " << Fixed::max( a, c ) << std::endl;

	return 0;
}
