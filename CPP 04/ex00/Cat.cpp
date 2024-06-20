#include "Cat.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	this->type = "Cat";
	std::cout << "Cat constructer called." << std::endl;
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat Copy constructer called." << std::endl;
	*this = copy;
}

Cat::~Cat()
{
	std::cout << "Cat destructer called." << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return (type);
}