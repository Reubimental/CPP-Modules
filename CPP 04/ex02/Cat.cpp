#include "Cat.hpp"
#include "Brain.hpp"
#include <iostream>

Cat::Cat(): Animal()
{
	std::cout << "Cat Default constructer called." << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::Cat(const Cat &copy): Animal()
{
	std::cout << "Cat Copy constructer called." << std::endl;
	this->brain = new Brain(*copy.brain);
}

Cat::~Cat()
{
	std::cout << "Cat destructer called." << std::endl;
	delete(this->brain);
}

void	Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}

std::string	Cat::getType() const
{
	return (type);
}

void	Cat::getIdea(int ideaCount)
{
	for (int i = 0; i < ideaCount; i++)
	{
		std::cout << "Idea " << i + 1 << " of Cat is : " << this->brain->getIdea(i) << std::endl;
	}
}

void	Cat::setIdea(int i, std::string idea)
{
		this->brain->setIdea(i, idea);
}