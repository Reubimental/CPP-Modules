#pragma once

#include <string>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain &brain);
		~Brain();
		const std::string	getIdea(int i) const;
		void				setIdea(int i, std::string idea);
};
