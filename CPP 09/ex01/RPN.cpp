#include "RPN.hpp"

bool	isNumber(const std::string &s)
{
	char	*end;

	std::strtod(s.c_str(), &end);
	return (end != s.c_str() && *end == '\0');
}

bool	performOperation(const std::string &operation, std::stack<double> &stack)
{
	double operand1, operand2, result;

	if (stack.size() < 2)
	{
		std::cerr << "Error: Not enough operands" << std::endl;
		return (false);
	}

	operand2 = stack.top();
	stack.pop();
	operand1 = stack.top();
	stack.pop();

	if (operation == "+")
	{
		result = operand1 + operand2;
	}
	else if (operation == "-")
	{
		result = operand1 - operand2;
	}
	else if (operation == "*")
	{
		result = operand1 * operand2;
	}
	else if (operation == "/")
	{
		if (operand2 == 0)
		{
			std::cerr << "Error: Division by zero" << std::endl;
			return (false);
		}
		result = operand1 / operand2;
	}
	else {
		std::cerr << "Error: Unknown operation" << std::endl;
		return (false);
	}

	stack.push(result);
	return (true);
}
