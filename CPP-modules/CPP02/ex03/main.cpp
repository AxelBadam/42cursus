#include "Point.hpp"
#include <iostream>


int main()
{
	Point A(Fixed(0.0f), Fixed(1.1));
	Point B(6.7, 2.1);
	Point C(4.7, 3.1);

   if (isInside(A, B, C))
    	std::cout <<"Inside";
   else
    	std::cout <<"Not Inside";
  
   return 0;
}
