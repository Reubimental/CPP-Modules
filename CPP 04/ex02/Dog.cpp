#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

Dog::Dog(): Animal()
{
	std::cout << "Dog Default constructer called." << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(const Dog &copy): Animal()
{
	std::cout << "Dog Copy constructer called." << std::endl;
	this->brain = new Brain(*copy.brain);
}

Dog::~Dog()
{
	std::cout << "Dog destructer called." << std::endl;
	delete(this->brain);
}

void	Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}

std::string	Dog::getType() const
{
	return (type);
}

void	Dog::getIdea(int ideaCount)
{
	for (int i = 0; i < ideaCount; i++)
	{
		std::cout << "Idea " << i + 1 << " of Dog is : " << this->brain->getIdea(i) << std::endl;
	}
}

void	Dog::setIdea(int i, std::string idea)
{
		this->brain->setIdea(i, idea);
}