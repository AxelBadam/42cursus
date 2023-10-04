#include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& f);
		Fixed &operator=(const Fixed &other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int _val;
		static const int _n = 8;
};