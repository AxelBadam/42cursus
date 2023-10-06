#include "Point.hpp"

static Fixed my_abs(Fixed const&x)
{
	if (x < 0.0f) 
		return x * -1;
	return x;
}

static bool point_on_line(Point const&a, Point const&b, Point const&point)
{
	if (a.getX() == b.getX() && a.getY() == b.getY()) // check if same point
		return false;
	if ((b.getX() - a.getX()) == 0) // vertical line, either on the line or off limits
		return point.getX() == a.getX(); 
	const Fixed slope = (b.getY() - a.getY()) / (b.getX() - a.getX());
	const Fixed intercept = a.getY() - slope * a.getX();
	return point.getY() == slope * point.getX() + intercept;
}

static Fixed area(Point const&a, Point const&b, Point const&c)
{
   return my_abs(a.getX() * (b.getY()-c.getY())
	+ b.getX() * (c.getY()-a.getY())
	+ c.getX() * (a.getY()-b.getY())) / 2;
	
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	const float acc = 0.01f;
    /* Calculate area of triangle abc, pbc, pac, pab */
  	Fixed tri = area (a, b, c);
   	Fixed a1 = area (point, b, c);
   	Fixed a2 = area (point, a, c); 
   	Fixed a3 = area (point, a, b);

	if (point_on_line(a, b, point) || point_on_line(b, c, point) || point_on_line(c, a, point))
		return false;
   	return my_abs(tri - (a1 + a2 + a3)) < acc;
}