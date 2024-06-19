#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Default Intern Created." << std::endl;
}

Intern::Intern(const Intern &src)
{
	std::cout << "Intern Copied." << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern Destroyed." << std::endl;
}

Intern &Intern::operator=(const Intern &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

static Form	*makePresident(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static Form *makeRobot(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static Form *makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(const std::string form, const std::string target)
{
	Form *(*all_forms[])(const std::string target) = {&makePresident, &makeRobot, &makeShrubbery};
	std::string forms[] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

	for (int i = 0; i < 3; i++)
	{
		if (form == forms[i])
		{
			std::cout << "The Intern has created " << form << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "Intern can't make the form " << form << std::endl;
	return (NULL);
}