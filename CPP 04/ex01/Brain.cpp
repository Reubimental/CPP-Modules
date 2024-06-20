#include "Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = "Something totally non-intrusive.";
	}
}

Brain::Brain(const Brain &brain)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
  	for (int i = 0; i < 100; i++)
	{
		this->ideas[i] = brain.ideas[i];
	}
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

const std::string	Brain::getIdea(int i) const
{
	if (i >= 0 && i < 100)
		return(this->ideas[i]);
	else
		return ("There is a maximum of 100 ideas stored in this brain.");
}

void	Brain::setIdea(int i, std::string idea)
{
	if (i >= 0 && i < 100)
		this->ideas[i] = idea;
	else
		std::cout << "There is a maximum of 100 ideas stored in this brain." << std::endl << "Cannot create any more ideas." << std::endl;
}