#pragma once

#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class	Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const size_t		_gradeToSign;
		const size_t		_gradeToExecute;
	public:
		Form();
		Form(const Form &src);
		Form(const std::string name);
		Form(const size_t gradeToSign, const size_t gradeToExecute);
		Form(const std::string name, const size_t gradeToSign, const size_t gradeToExec);
		~Form();
		Form &operator=(const Form &src);
		const std::string	getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat &a);

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
};

std::ostream &operator<<(std::ostream &o, Form *a);