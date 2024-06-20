#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

Animal::Animal(): type("Animal")
{
	std::cout << "Default Animal Constructor called." << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Constructor called for " << type << "." << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called." << std::endl;
}

void	Animal::makeSound() const
{
}

std::string	Animal::getType() const
{
	return(type);
}