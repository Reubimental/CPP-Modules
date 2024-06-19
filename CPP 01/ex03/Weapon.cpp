#include "Weapon.hpp"

// The thing at the end of the constructor input is known as the Constructor Initialization List.
// It is standard practice to use it, and it initializes the elements of a class with the inputs upon construction.
// in this case, Weapon::_type, or this->_type, would be initialized to type.
Weapon::Weapon(std::string type): _type(type)
{
}

Weapon::~Weapon()
{
}

const std::string	&Weapon::getType()
{
	return (this->_type);
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}