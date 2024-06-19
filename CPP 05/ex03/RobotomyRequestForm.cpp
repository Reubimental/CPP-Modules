#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): Form("RobotomyRequestForm", 72, 45), _target("Default")
{
	std::cout << "Default RobotomyRequestForm Created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm Created for Target" << this->getTarget() << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): Form("RobotomyRequestForm_copy", 72, 45), _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm " << this->getName() << " copied from " << src.getName() << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm " << this->getName() << " Destroyed." << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

static int failrate = 0;

void	RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == 0)
		throw (Form::FormNotSignedException());
	else if (failrate++ % 2)
	{
		std::cout << "*- Drilling Noises -*" << std::endl;
		std::cout << this->getTarget() << " has been successfully robotomized!" << std::endl;
	}
	else
		std::cout << "ROBOTOMY FAILED. IT REMEMBERS EVERYTHING. GET TO SAFET- ksshhhhh" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &output, RobotomyRequestForm *form)
{
	std::string	issigned = "No!";

	if (form->getSigned() == 1)
		issigned = "Yes!";
	output << "Form " << form->getName() << ":\n\tGrade needed to Sign:\t\t" << form->getGradeToSign() << std::endl <<
	"\tGrade needed to Execute:\t" << form->getGradeToExecute() << std::endl <<
	"\tIs Signed:\t\t\t" << issigned << std::endl;
	return (output);
}