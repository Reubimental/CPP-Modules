#pragma once

#include "AForm.hpp"
#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
	private:
		const std::string	_name;
		size_t				_grade;
		void				setGrade(int grade);
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &src);
		Bureaucrat(int grade);
		Bureaucrat(const std::string name);
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat &operator=(const Bureaucrat &src);
		void				incrementGrade();
		void				decrementGrade();
		const std::string	getName() const;
		size_t				getGrade() const;
		void				signForm(Form &f);
		void				executeForm(Form &form) const;

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

std::ostream &operator<<(std::ostream &o, Bureaucrat *a);