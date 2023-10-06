#include "Point.hpp"
#include <iostream>


int main( void ) 
{
	Point a(Fixed(0), Fixed(0));
	Point b(Fixed(0.7f), Fixed(10));
	Point c(Fixed(5.3f), Fixed(0.0f));
	Point inside(Fixed(3.42f), Fixed(3.13f));
	Point online(Fixed(0), Fixed(3.7f));
	Point vertex(a);
	Point outside(Fixed(5), Fixed(6));	

	bool inside1 = bsp(a, b, c, inside);
	bool inside2 = bsp(a, b, c, online);
	bool inside3 = bsp(a, b, c, vertex);
	bool inside4 = bsp(a, b, c, outside);

	std::cout << "a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
	
	std::cout << "inside: (" << inside.getX() << ", " << inside.getY() << ")" << std::endl;
	std::cout << "online: (" << online.getX() << ", " << online.getY() << ")" << std::endl;
	std::cout << "vertex: (" << vertex.getX() << ", " << vertex.getY() << ")" << std::endl;
	std::cout << "outside: (" << outside.getX() << ", " << outside.getY() << ")" << std::endl;
	
	std::cout << "inside: bool " << inside1 << std::endl;
	std::cout << "online: bool " << inside2 << std::endl;
	std::cout << "vertex: bool " << inside3 << std::endl;
	std::cout << "outside: bool " << inside4 << std::endl;
	return 0;
}
