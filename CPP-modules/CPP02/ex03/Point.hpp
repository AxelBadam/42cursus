#ifndef POINT_HPP
#define POINT_HPP
#include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const Fixed &x, const Fixed &y);
		Point(Point &point);
		Point &operator=(const Point &other);
		~Point();
		bool isInside(Point &A, Point &B, Point &C, Point &toCheck);
		float Point::area(Point &A, Point &B, Point &C);

		Fixed &getX() const;
		Fixed &getY() const;



	private:
		const Fixed _x;
		const Fixed _y;

};

#endif