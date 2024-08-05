#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Error: Please execute using only 1 argument with quotation marks." << std::endl;
		return (1);
	}

	std::stack<double>	stack;
	std::string input = argv[1];
	int	precision = 0;

	std::istringstream iss(input);
	std::string token;

	while (iss >> token)
	{
		if (isNumber(token))
		{
			stack.push(std::strtod(token.c_str(), NULL));
		}
		else if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (!performOperation(token, stack)) {
				return (1);
			}
		}
		else
		{
			std::cerr << "Error: Invalid input '" << token << "'" << std::endl;
			return (1);
		}
	}

	if (stack.size() == 1)
	{
		/*std::cout << "Please set Precision." << std::endl;
		std::cout << "Example:" << std::endl;
		std::cout << "0 = 0" << std::endl;
		std::cout << "1 = 0.0" << std::endl;
		std::cout << "2 = 0.00" << std::endl;
		std::cout << "3 = 0.000" << std::endl;
		std::cout << "and so on..." << std::endl;
		std::cin >> precision;*/
		std::cout << std::fixed << std::setprecision(precision) << "Result: " << stack.top() << std::endl;
	}
	else
	{
		std::cerr << "Error: Incorrect input. Stack size: " << stack.size();
		if (stack.size() > 1)
		{
			std::cerr << ". Please reduce stack size to 1 by increasing operators." << std::endl;
		}
		else
		{
			std::cerr << ". Please execute with an equation to calculate in Reverse Polish Notation." << std::endl;
		}
		return (1);
	}

	return (0);
}
