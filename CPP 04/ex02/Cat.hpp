#pragma once

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public Animal
{
	private:
		Brain	*brain;
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		void		makeSound() const;
		std::string	getType() const;
		void		getIdea(int ideaCount);
		void		setIdea(int i, std::string idea);
};