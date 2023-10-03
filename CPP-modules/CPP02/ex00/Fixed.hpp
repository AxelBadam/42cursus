#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& f);
		

	private:
		int _val;
		static const int _fb = 8;
}