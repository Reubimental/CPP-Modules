#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): Form("ShrubberyCreationForm", 145, 137), _target("Default")
{
	std::cout << "Default ShrubberyCreationForm Created." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm Created for Target: " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): Form("ShrubberyCreationForm_copy", 145, 137), _target(src.getTarget())
{
	std::cout << "Shrubbery Creation Form " << this->getName() << " copied from " << src.getName() << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm " << this->getName() << " destroyed." << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "Shrubbery Creation Form Assignment Operator called." << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if ((int)executor.getGrade() > this->getGradeToExecute())
		throw (Bureaucrat::GradeTooLowException());
	else if (this->getSigned() == 0)
		throw (Form::FormNotSignedException());
	else
	{
		std::ofstream outfile (this->getTarget().append("_shrubbery").c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile <<
			"       _-_" << std::endl <<
			"    /~~   ~~\\" << std::endl <<
			" /~~         ~~\\" << std::endl <<
			"{               }" << std::endl <<
			" \\  _-     -_  /" << std::endl <<
			"   ~  \\\\ //  ~" << std::endl <<
			"_- -   | | _- _" << std::endl <<
			"  _ -  | |   -_" << std::endl <<
			"      // \\\\" << std::endl <<
			std::endl;
		}
		outfile.close();
	}
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

std::ostream	&operator<<(std::ostream &output, ShrubberyCreationForm *form)
{
	std::string	issigned = "No!";

	if (form->getSigned() == 1)
		issigned = "Yes!";
	output << "Form " << form->getName() << ":\n\tGrade needed to Sign:\t\t" << form->getGradeToSign() << std::endl <<
	"\tGrade needed to Execute:\t" << form->getGradeToExecute() << std::endl <<
	"\tIs Signed:\t\t\t" << issigned << std::endl;
	return (output);
}