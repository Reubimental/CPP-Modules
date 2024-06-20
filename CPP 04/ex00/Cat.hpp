#pragma once

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &copy);
		~Cat();
		void		makeSound() const;
		std::string	getType() const;
};