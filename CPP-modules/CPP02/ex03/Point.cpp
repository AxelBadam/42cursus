#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point(Point &point) : _x(point._x), _y(point._y) {}

Point::~Point() {}

Point &Point::operator=(const Point &other)
{
	const_cast<Fixed&>(_x) = other._x;
	const_cast<Fixed&>(_y) = other._y;
	return *this;
}

Fixed const&Point::getX() const{
	return _x;
}

Fixed const&Point::getY() const{
	return _y;
}
