#include "Point.hpp"
#include "cmath"

Point::Point() : _x(0), _y(0) {}

Point::Point(const Fixed &x, const Fixed &y) : _x(x), _y(y) {}

Point::Point(Point &point) : _x(point._x), _y(point._y) {} 

Point &Point::operator=(const Point &other){
	const_cast<Fixed&>(_x) = other._x;
	const_cast<Fixed&>(_y) = other._y;
	return *this;
}

float Point::area(Point &A, Point &B, Point &C){
   	return abs(A._x * (B._y-C._y) + B._x * (C._y-A._y)+ C._x * (A._y-B._y) / 2.0);
	//return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool Point::isInside(Point &A, Point &B, Point &C, Point &toCheck)
{   
   /* Calculate area of triangle ABC */
   float A = area (A, B, C);
  
   /* Calculate area of triangle PBC */ 
   float A1 = area (x, y, x2, y2, x3, y3);
  
   /* Calculate area of triangle PAC */ 
   float A2 = area (x1, y1, x, y, x3, y3);
  
   /* Calculate area of triangle PAB */  
   float A3 = area (x1, y1, x2, y2, x, y);
    
   /* Check if sum of A1, A2 and A3 is same as A */
   return (A == A1 + A2 + A3);
}

bool bsp( Point const a, Point const b, Point const c, Point const point){


}

Fixed &Point::getX() const
{
	return _x;
}

Fixed &Point::getY() const
{
	return _y;
}


