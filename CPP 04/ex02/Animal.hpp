#pragma once

#include <string>

class Animal
{
	protected:
		std::string	type;
		Animal();
	public:
		Animal(const Animal &copy);
		virtual ~Animal();
		virtual  void	makeSound() const = 0;
		std::string		getType() const;
};
