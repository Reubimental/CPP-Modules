#include "BitcoinExchange.hpp"
#include <iostream>
#include <string>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error: Please provide an input file." << std::endl;
		return (1);
	}
	try
	{
		if (argc > 2)
			throw static_cast<std::string>("Please provide only one input file as an argument.");
		BitcoinExchange bitcoin;
		bitcoin.validateInput(argv[1]);
	}
	catch (std::string error)
	{
		std::cerr << "Error: " << error << std::endl;
	}
}