#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class	Form
{
	protected:
		const std::string	_name;
		bool				_signed;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
		Form();
		Form(const std::string name);
		Form(const size_t gradeToSign, const size_t gradeToExecute);
		Form(const std::string name, const size_t gradeToSign, const size_t gradeToExec);
	public:
		Form(const Form &src);
		virtual ~Form();
		Form &operator=(const Form &src);
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &signer);
		virtual void		execute(Bureaucrat const &executor) const = 0;

	class GradeTooLowException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};
	class GradeTooHighException : public std::exception
	{
		public:
				virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
		public:
				virtual const char * what() const throw();
	};
};

std::ostream &operator<<(std::ostream &o, Form *a);