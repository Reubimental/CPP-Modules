#include "WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal(): type("Wrong Animal")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

void WrongAnimal::makeSound(void)const
{
	std::cout << this->getType() << " says: **WrongAnimal sounds**" << std::endl;
}

std::string	WrongAnimal::getType(void)const
{
	return (type);
}