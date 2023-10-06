#include "Point.hpp"
#include <iostream>


static Fixed my_abs(Fixed const&x)
{
	if (x < 0.0f) 
		return x * -1;
	return x;
}

static bool point_on_line(Point const&a, Point const&b, Point const&point)
{
	if (a.getX() == b.getX() && a.getY() == b.getY()) 
		return false;
	if ((b.getX() - a.getX()) == 0) 
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
   /* Calculate area of triangle abC */
  	Fixed tri = area (a, b, c);

   /* Calculate area of triangle PbC */ 
   	Fixed a1 = area (point, b, c);
  
   /* Calculate area of triangle PaC */ 
   	Fixed a2 = area (point, a, c);
  
   /* Calculate area of triangle Pab */  
   	Fixed a3 = area (point, a, b);

	if (point_on_line(a, b, point) || point_on_line(b, c, point) || point_on_line(c, a, point))
		return false;
	const float acc = 0.01f;
	
   	return my_abs(tri - (a1 + a2 + a3)) < acc;
}

int main( void ) 
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(0.0f), Fixed(10));
	Point c(Fixed(5.3f), Fixed(0.0f));

	Point point1(Fixed(3.42f), Fixed(3.13f));	// Inside
	Point point2(Fixed(0), Fixed(3.7f));		// On line
	Point point3(a);							// On vertex
	Point point4(Fixed(5), Fixed(6));			// Outside

	const bool is_in_triangle1 = bsp(a, b, c, point1);
	const bool is_in_triangle2 = bsp(a, b, c, point2);
	const bool is_in_triangle3 = bsp(a, b, c, point3);
	const bool is_in_triangle4 = bsp(a, b, c, point4);

	std::cout << "a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	
	std::cout << "point1: (" << point1.getX() << ", " << point1.getY() << ")" << std::endl;
	std::cout << "point2: (" << point2.getX() << ", " << point2.getY() << ")" << std::endl;
	std::cout << "point3: (" << point3.getX() << ", " << point3.getY() << ")" << std::endl;
	std::cout << "point4: (" << point4.getX() << ", " << point4.getY() << ")" << std::endl;
	
	std::cout << "point1: " << (is_in_triangle1 ? "true" : "false") << std::endl;
	std::cout << "point2: " << (is_in_triangle2 ? "true" : "false") << std::endl;
	std::cout << "point3: " << (is_in_triangle3 ? "true" : "false") << std::endl;
	std::cout << "point4: " << (is_in_triangle4 ? "true" : "false") << std::endl;

	return 0;
}
