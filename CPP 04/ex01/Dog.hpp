#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
	private:
		Brain	*brain;
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		void		makeSound() const;
		std::string	getType() const;
		void		getIdea(int ideaCount);
		void		setIdea(int i, std::string idea);
};