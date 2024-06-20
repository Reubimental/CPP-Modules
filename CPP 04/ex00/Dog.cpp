#include "Dog.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	this->type = "Dog";
	std::cout << "Dog constructer called." << std::endl;
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog Copy constructer called." << std::endl;
	*this = copy;
}

Dog::~Dog()
{
	std::cout << "Dog destructer called." << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (type);
}