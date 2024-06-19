#include "ScalarConversion.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc == 1)
	{
		std::cout << "Error: No Parameters" << std::endl << "Usage: ./<program> <literal>" << std::endl;
		return (1);
	}
	ScalarConversion::convert(argv[1]);
	return (0);
}