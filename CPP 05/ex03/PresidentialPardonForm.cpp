#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): Form("PresidentialPardonForm", 25, 5), _target("Default")
{
	std::cout << "Default PresidentialPardonForm Created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): Form("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm Created for Target " << this->getTarget() << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): Form("PresidentialPardonForm_copy", 145, 137), _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm " << this->getName() << " copied from " << src.getName() << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm " << this->getName() << " Destroyed." << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == 0)
		throw (Form::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream&output, PresidentialPardonForm *form)
{
	std::string	issigned = "No!";

	if (form->getSigned() == 1)
		issigned = "Yes!";
	output << "Form " << form->getName() << ":\n\tGrade needed to Sign:\t\t" << form->getGradeToSign() << std::endl <<
	"\tGrade needed to Execute:\t" << form->getGradeToExecute() << std::endl <<
	"\tIs Signed:\t\t\t" << issigned << std::endl;
	return (output);
}