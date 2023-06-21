#include "Fixed.hpp"

Fixed::Fixed(): value_(0)
{
	std::cout << "Default constructor called." << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	*this = copy;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called." << std::endl;
	this->value_ = value << this->fraction_;
}
/*
• A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
*/


Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->value_ = roundf(value * 256);
}
/* float can't do bitwise operations
Multiply value by 256 so that it moves 8 bits to the left like bitwise operation, as 256 in binary is 100000000, or 0b1 << 8
In order to solve the problem that the value is discarded during operation and the exact value does not come out, roundf is used.
*/
/*
• A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
*/


Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->value_ = rhs.getRawBits();
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called." << std::endl;
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called." << std::endl;
	return (this->value_);
}

void	Fixed::setRawBits(const int raw)
{
	std::cout << "setRawBits member function called." << std::endl;
	this->value_ = raw;
}

int	Fixed::toInt() const
{
	return (this->value_ >> this->fraction_);
}
/* 
• A member function int toInt(void) const;
that converts the fixed-point value to an integer value.s
*/

float	Fixed::toFloat() const
{
	return ((float)this->value_ / 256);
}
/* 	
• A member function float toFloat(void) const;
that converts the fixed-point value to a floating-point value. 
*/

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return (os << fixed.toFloat());
}
/*
This sets the default output when a Fixed object is called to be a float.
std::cout << "this is a float: " << fixedNum << std::endl;
would output, if fixedNum were already initialized to 1234.56
this is a float: 1234.56
*/

/*
• An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter. 
*/
