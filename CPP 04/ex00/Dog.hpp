#pragma once

#include "Animal.hpp"
#include <string>

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog &copy);
		~Dog();
		void		makeSound() const;
		std::string	getType() const;
};