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

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called." << std::endl;
	this->value_ = roundf(value * 256);
}

Fixed& Fixed::operator=(const Fixed &rhs)
{
	std::cout << "Copy assignment operator called." << std::endl;
	this->value_ = rhs.getRawBits();
	return (*this);
}

Fixed	Fixed::operator+(Fixed const &copy) const
{
	Fixed	result(this->toFloat() + copy.toFloat());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &copy) const
{
	Fixed	result(this->toFloat() - copy.toFloat());
	return (result);
}

Fixed	Fixed::operator*(Fixed const &copy) const
{
	Fixed	result(this->toFloat() * copy.toFloat());
	return (result);
}

Fixed	Fixed::operator/(Fixed const &copy) const
{
	Fixed	result(this->toFloat() / copy.toFloat());
	return (result);
}

bool	Fixed::operator==(const Fixed &copy) const
{
	return (this->toFloat() == copy.toFloat());
}

bool	Fixed::operator!=(const Fixed &copy) const
{
	return (this->toFloat() != copy.toFloat());
}

bool	Fixed::operator<=(const Fixed &copy) const
{
	return (this->toFloat() <= copy.toFloat());
}

bool	Fixed::operator>=(const Fixed &copy) const
{
	return (this->toFloat() >= copy.toFloat());
}

bool	Fixed::operator<(const Fixed &copy) const
{
	return (this->toFloat() < copy.toFloat());
}

bool	Fixed::operator>(const Fixed &copy) const
{
	return (this->toFloat() > copy.toFloat());
}

Fixed&	Fixed::operator++(void)
{
	// Prefix increment operator (++x)
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}

Fixed&	Fixed::operator--(void)
{
	// Prefix increment operator (--x)
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

const Fixed	Fixed::operator++(int value)
{
	// Postfix increment operator (x++)
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() + value);
	return (aux);
}

const Fixed	Fixed::operator--(int value)
{
	// Postfix increment operator (x--)
	Fixed	aux;

	aux = *this;

	if (!value)
		value = 1;
	this->setRawBits(this->getRawBits() - value);
	return (aux);
}

const Fixed	&Fixed::min(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1 < copy2)
		return (copy1);
	return (copy2);

}

/* const Fixed	&Fixed::min(Fixed &copy1, Fixed &copy2)
{
	if (copy1 < copy2)
		return (copy1);
	return (copy2);
} */

const Fixed	&Fixed::max(const Fixed &copy1, const Fixed &copy2)
{
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
}

/* const Fixed	&Fixed::max(Fixed &copy1, Fixed &copy2)
{
	if (copy1 > copy2)
		return (copy1);
	return (copy2);
} */

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

float	Fixed::toFloat() const
{
	return ((float)this->value_ / 256);
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    return (os << fixed.toFloat());
}
