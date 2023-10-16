#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	public:   
		Fixed();
		Fixed(const int n);
		Fixed(const Fixed& f);
		Fixed(const float n);
		Fixed &operator=(const Fixed &other);
	
		bool operator<(const Fixed &other) const;
		bool operator>(const Fixed &other) const;
		bool operator>=(const Fixed &other) const;
		bool operator<=(const Fixed &other) const;
		bool operator==(const Fixed &other) const;
		bool operator!=(const Fixed &other) const;

		Fixed operator+(const Fixed &other) const;
		Fixed operator-(const Fixed &other) const;
		Fixed operator*(const Fixed &other) const;
		Fixed operator/(const Fixed &other) const;

		Fixed &operator++(void);
		Fixed operator++(int);
		Fixed &operator--(void);
		Fixed operator--(int);

		~Fixed();

		int 	toInt(void) const;
		float 	toFloat(void) const;
		int 	getRawBits( void ) const;
		void 	setRawBits( int const raw );
		static Fixed 		&min(Fixed &fixed1, Fixed &fixed2);
		const static Fixed 	&min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed		&max(Fixed &fixed1, Fixed &fixed2);
		const static Fixed 	&max(const Fixed &fixed1, const Fixed &fixed2);

	private:
		int				 _val;
		static const int _fb = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

#endif