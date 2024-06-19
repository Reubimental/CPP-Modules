#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("Default"), _grade(150)
{
	std::cout << "Default Bureaucrat created with name " << this->getName() << " and grade " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &src): _name(src.getName() + "_copy"), _grade(src.getGrade())
{
	std::cout << "Bureaucrat " << this->getName() << " copied from " << src.getName() << std::endl;
	*this = src;
}

Bureaucrat::Bureaucrat(int grade): _name("Default")
{
	this->setGrade(grade);
	std::cout << "Setting Grade of " << this->getName() << " to " << this->getGrade() << std::endl;
}

Bureaucrat::Bureaucrat(const std::string name): _name(name), _grade(150)
{
	std::cout << "Creating Bureaucrat with the name of " << this->getName() << " with grade " << this->getGrade() << std::endl;

}

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << "Creating Bureaucrat with the name of " << this->getName() << " with grade " << this->getGrade() << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat " << this->getName() << " has been destroyed." << std::endl;
}

void	Bureaucrat::incrementGrade()
{
	std::cout << "Incrementing Grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade - 1);
}

void	Bureaucrat::decrementGrade()
{
	std::cout << "Decrementing Grade of " << this->getName() << std::endl;
	this->setGrade(this->_grade + 1);
}

const std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

size_t	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade = grade;
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src)
{
	std::cout << "Assignment Operator Called" << std::endl;
	if (this == &src)
		return (*this);
	this->_grade = src.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &o, Bureaucrat *a)
{
	o << a->getName() << ", bureaucrat grade " << a->getGrade() << std::endl;
	return (o);
}

void	Bureaucrat::signForm(Form &f)
{
	std::cout << this->getName() << " signing Form " << f.getName() << std::endl;
	f.beSigned(*this);
}

void	Bureaucrat::executeForm(Form &form) const
{
	form.execute(*this);
}