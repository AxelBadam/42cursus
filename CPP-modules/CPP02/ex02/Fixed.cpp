#include <cmath>
#include "Fixed.hpp"

Fixed::Fixed() : _val(0){}

Fixed::Fixed(const int n) : _val(n << _fb){}

Fixed::Fixed(const float n) : _val(std::roundf(n * (1 << _fb))){}

Fixed::Fixed(const Fixed& other) : _val(other._val){}

int Fixed::toInt(void) const{
	return roundf(toFloat());
}

float Fixed::toFloat(void) const{
	return (static_cast<float>(_val) / (1 << _fb)); 
}

std::ostream& operator<<(std::ostream &out, const Fixed &fixed){
	return out << fixed.toFloat();
}

Fixed &Fixed::operator=(const Fixed &other){
	_val = other._val;
	return *this;
}

Fixed Fixed::operator+(const Fixed &other) const{
	return toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed &other) const{
	return toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other) const{
	return toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other._val != 0)
		return toFloat() / other.toFloat();
	else
	{
		std::cout << "Error: division by zero" << std::endl;
		return Fixed();
	}
}

bool Fixed::operator<(const Fixed& other) const {
        return (_val < other._val);
}

bool Fixed::operator>(const Fixed& other) const {
        return (_val > other._val);
}

bool Fixed::operator>=(const Fixed& other) const {
        return (_val >= other._val);
}

bool Fixed::operator<=(const Fixed& other) const {
        return (_val <= other._val);
}

bool Fixed::operator==(const Fixed& other) const {
        return (_val == other._val);
}

bool Fixed::operator!=(const Fixed& other) const {
        return (_val != other._val);
}

Fixed &Fixed::operator++(){
	_val++;
	return *this;
}

Fixed Fixed::operator++(int){
	Fixed result(*this);
	_val++;
	return result;
}

Fixed &Fixed::operator--(){
	_val--;
	return *this;
}

Fixed Fixed::operator--(int){
	Fixed result(*this);
	_val--;
	return result;
}

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2){
	if (fixed1._val < fixed2._val)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1._val < fixed2._val)
		return fixed1;
	return fixed2;
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2){
	if (fixed1._val > fixed2._val)
		return fixed1;
	return fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2){
	if (fixed1._val > fixed2._val)
		return fixed1;
	return fixed2;
}

Fixed::~Fixed(){}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return _val;
}

void Fixed::setRawBits( int const raw ){
	std::cout << "setRawBits member function called" << std::endl;
	_val = raw;
}