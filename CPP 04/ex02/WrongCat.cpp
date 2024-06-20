#include "WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat(): WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat Default Constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Deconstructor called" << std::endl;
}

void WrongCat::makeSound()const
{
	std::cout << this->getType() << " says: **WrongCat sounds**" << std::endl;
}