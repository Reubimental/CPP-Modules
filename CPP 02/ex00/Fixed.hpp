#pragma once

#include <iostream>

class	Fixed
{
	private:
		int					value_;
		static const int	fraction_ = 8;
	public:
		Fixed();
		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& rhs);
		~Fixed();
		int	getRawBits(void) const;
		void	setRawBits(const int raw);
};

/*
• Public members:
◦ A default constructor that initializes the fixed-point number value to 0.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ A member function int getRawBits( void ) const;
that returns the raw value of the fixed-point value.
◦ A member function void setRawBits( int const raw );
that sets the raw value of the fixed-point number.
*/