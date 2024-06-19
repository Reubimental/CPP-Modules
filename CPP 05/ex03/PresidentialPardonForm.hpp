#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class	Bureaucrat;
class	Form;

class	PresidentialPardonForm: public Form
{
	private:
		const std::string _target;
		PresidentialPardonForm();
	public:
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(PresidentialPardonForm &src);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &output, PresidentialPardonForm *form);