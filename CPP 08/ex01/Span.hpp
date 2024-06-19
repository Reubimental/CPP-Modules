#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

class Span
{
	private:
		std::vector<int>	_span;
		unsigned int	_maximum;
	public:
		Span();
		Span(unsigned int N);
		Span(const Span &src);
		~Span();
		Span &operator=(const Span &src);
		void	addNumber(int N);
		int		shortestSpan();
		int		longestSpan();
		void	fill();

	class TooManyNumbers : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("Too Many Numbers. Cannot add more.");
			}
	};

	class NotEnoughNumbers : public std::exception
	{
		public:
			virtual const char *what() const throw()
			{
				return("Not Enough Numbers. No span found.");
			}
	};
};