#include "Fixed.hpp"
#include <iostream>
#include <limits>

int main(void) 
{

	Fixed a(1.01f);
	Fixed b(1.02f);

	if (a < b)
		std::cout << a << " is smaller than " << b << std::endl;
	if (a > b)
		std::cout << a << " is larger than " << b << std::endl;
	std::cout << "Epsilon for float: " << std::numeric_limits<float>::epsilon() << std::endl;
	a = b++;
	std::cout << "value of a is " << a << "\nvalue of b is " << b << std::endl;
	a = ++b;
	std::cout << "value of a is " << a << std::endl;
	//Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	/*std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;*/
	return 0;
}
