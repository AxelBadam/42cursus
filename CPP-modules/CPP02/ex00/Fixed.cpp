#include "Fixed.hpp"

Fixed::Fixed() : _val(0) {}

Fixed::Fixed(const Fixed& f) {
	std::cout << "CC called" << std::endl;
}


