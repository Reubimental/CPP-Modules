#include "AForm.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _name("Default"), _signed(0), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Form Created." << std::endl;
}

Form::Form(const Form &src): _name(src.getName() + "_copy"), _signed(0), _gradeToSign(src.getGradeToSign()), _gradeToExecute(src.getGradeToExecute())
{
	std::cout << "Form " << this->getName() << " copied from " << src.getName() << std::endl;
	*this = src;
}

Form::Form(const std::string name): _name(name), _signed(0), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Default Form Created with name " << this->getName() << std::endl;
}

Form::Form(const size_t gradeToSign, const size_t gradeToExec): _name("Default"), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	std::cout << "Form Created with name " << this->getName() << " that needs at least grade " << this->getGradeToSign() <<
		" to sign, and at least grade " << this->getGradeToExecute() << " to execute." << std::endl;
	int	sign = (int)gradeToSign;
	int	exec = (int)gradeToExec;
	if (sign > 150 || exec > 150)
		throw (Form::GradeTooLowException());
	else if (sign < 1 || exec < 1)
		throw (Form::GradeTooHighException());
}

Form::Form(const std::string name, const size_t gradeToSign, const size_t gradeToExec): _name(name), _signed(0), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExec)
{
	std::cout << "Form Created with name " << this->getName() << " that needs at least grade " << this->getGradeToSign() <<
		" to sign, and at least grade " << this->getGradeToExecute() << " to execute." << std::endl;
	if (gradeToSign > 150 || gradeToExec > 150)
		throw (Form::GradeTooLowException());
	else if (gradeToSign < 1 || gradeToExec < 1)
		throw (Form::GradeTooHighException());
}

Form::~Form()
{
	std::cout << "Form " << this->getName() << " Has Been Destroyed." << std::endl;
}

Form &Form::operator=(const Form &src)
{
	std::cout << "Form Assignment Operator called." << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

const std::string Form::getName() const
{
	return (this->_name);
}

bool Form::getSigned() const
{
	return (this->_signed);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void	Form::beSigned(Bureaucrat &signer)
{
	if ((int)signer.getGrade() > this->getGradeToSign())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned())
		std::cout << this->getName() << " Form has Already Been Signed." << std::endl;
	else
	{
		std::cout << "Form " << this->getName() << " signed by " << signer.getName() << std::endl;
		this->_signed = 1;
	}
}

std::ostream	&operator<<(std::ostream &output, Form *form)
{
	std::string issigned = "No\n";

	if (form->getSigned())
		issigned = "Yes\n";
	output << form->getName() << ":\n\tSigned :\t\t\t" << issigned << "\tGrade Needed to Sign :\t\t" << form->getGradeToSign()
		<< "\n\tGrade Needed to Execute :\t" << form->getGradeToExecute() << std::endl;
	return (output);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char	*Form::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}

void	Form::execute(Bureaucrat const &executor) const
{
	(void)executor;
}