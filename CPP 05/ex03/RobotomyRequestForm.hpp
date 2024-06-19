#pragma once

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class	Bureaucrat;
class	Form;

class RobotomyRequestForm: public Form
{
	private:
		const std::string _target;
		RobotomyRequestForm();
	public:
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(RobotomyRequestForm &src);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		void execute(Bureaucrat const &executor) const;
		std::string getTarget() const;
};

std::ostream	&operator<<(std::ostream &output, RobotomyRequestForm *form);