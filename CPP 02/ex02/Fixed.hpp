#pragma once

#include <iostream>
#include <cmath>

class	Fixed
{
	private:
		int					value_;
		static const int	fraction_ = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed(const int value);
		Fixed(const float value);
		Fixed& 			operator=(const Fixed& rhs);
		Fixed 			operator+(const Fixed& copy) const;
		Fixed 			operator-(const Fixed& copy) const;
		Fixed 			operator*(const Fixed& copy) const;
		Fixed 			operator/(const Fixed& copy) const;
		bool			operator==(const Fixed &copy) const;
		bool			operator!=(const Fixed &copy) const;
		bool			operator<=(const Fixed &copy) const;
		bool			operator>=(const Fixed &copy) const;
		bool			operator<(const Fixed &copy) const;
		bool			operator>(const Fixed &copy) const;
		Fixed&			operator--(void);
		Fixed&			operator++(void);
		const Fixed		operator++(int value);
		const Fixed		operator--(int value);
		static Fixed&	min(Fixed &copy1, Fixed &copy2);
		static const Fixed&	min(Fixed const &copy1, Fixed const &copy2);
		static Fixed&	max(Fixed &copy1, Fixed &copy2);
		static const Fixed&	max(Fixed const &copy1, Fixed const &copy2);
		float			toFloat(void) const;
		int				toInt(void) const;
		int				getRawBits(void) const;
		void			setRawBits(const int raw);
		~Fixed();
};

std::ostream&	operator<<(std::ostream &out, const Fixed &fix);


/*
Add the following public constructors and public member functions to your class:
	• A constructor that takes a constant integer as a parameter.
	It converts it to the corresponding fixed-point value. The fractional bits value is
	initialized to 8 like in exercise 00.

	• A constructor that takes a constant floating-point number as a parameter.
	It converts it to the corresponding fixed-point value. The fractional bits value is
	initialized to 8 like in exercise 00.

	• A member function float toFloat( void ) const;
	that converts the fixed-point value to a floating-point value.

	• A member function int toInt( void ) const;
	that converts the fixed-point value to an integer value.

And add the following function to the Fixed class files:
	• An overload of the insertion («) operator that inserts a floating-point representation
	of the fixed-point number into the output stream object passed as parameter.
*/