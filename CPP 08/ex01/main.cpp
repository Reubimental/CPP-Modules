#include "Span.hpp"

int	main()
{
	Span span1 = Span(5);

	try
	{
		span1.addNumber(5);
		span1.addNumber(4);
		span1.addNumber(16000);
		span1.addNumber(10);
		span1.addNumber(15);
		std::cout << "span1 shortest span: " << span1.shortestSpan() << std::endl;
		std::cout << "span1 longest span: " << span1.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span span2 = Span(10000);
	try
	{
		span2.fill();
		std::cout << "span2 shortest span: " << span2.shortestSpan() << std::endl;
		std::cout << "span2 longest span: " << span2.longestSpan() << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}