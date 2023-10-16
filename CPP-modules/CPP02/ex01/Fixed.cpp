#include <cmath>

#include "Fixed.hpp"

Fixed::Fixed() : _val(0){
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) : _val(n << _fb){
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float n) : _val(std::roundf(n * (1 << _fb))){
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _val(other._val){
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	_val = other._val;
	return *this;
}

float Fixed::toFloat(void) const{
	return static_cast<float>(_val) / (1 << _fb); 
}

int Fixed::toInt(void) const{
	return roundf(toFloat());
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed){
	return out << fixed.toFloat();
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}
