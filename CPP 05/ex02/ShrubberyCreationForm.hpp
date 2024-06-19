#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	Bureaucrat;
class	Form;

class	ShrubberyCreationForm: public Form
{
	private:
		const std::string	_target;
		ShrubberyCreationForm();
	public:
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		void	execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &output, ShrubberyCreationForm *form);