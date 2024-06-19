#pragma once

#include <string>
#include <stack>
#include <iostream>

#include <iostream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

class RPN {
private:
    std::stack<double> operands;

public:
    // Constructor
    RPN() {}

    // Evaluate RPN expression
    double eval(const std::vector<std::string>& tokens)
	{
        for (const auto& token : tokens)
		{
            if (token == "+" && operands.size() >= 2)
			{
                double b = operands.top(); operands.pop();
                double a = operands.top(); operands.pop();
                operands.push(a + b);
            }
			else if (token == "-" && operands.size() >= 2)
			{
                double b = operands.top(); operands.pop();
                double a = operands.top(); operands.pop();
                operands.push(a - b);
            }
			else if (token == "*" && operands.size() >= 2)
			{
                double b = operands.top(); operands.pop();
                double a = operands.top(); operands.pop();
                operands.push(a * b);
            }
			else if (token == "/" && operands.size() >= 2)
			{
                double b = operands.top(); operands.pop();
                double a = operands.top(); operands.pop();
                if (b!= 0.0)
				{
                    operands.push(a / b);
                }
				else
				{
                    throw std::runtime_error("Division by zero");
                }
            }
			else
			{
                operands.push(std::stod(token));
            }
        }

        if (operands.size()!= 1)
		{
            throw std::runtime_error("Invalid RPN expression");
        }

        return operands.top();
    }

    // Utility function to split command line arguments into tokens
    static std::vector<std::string> tokenize(const std::string& expr)
	{
        std::istringstream iss(expr);
        std::vector<std::string> tokens{std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
        return tokens;
    }
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: RPN <expression>" << std::endl;
        return 1;
    }

    try {
        RPN rpn;
        std::vector<std::string> tokens = RPN::tokenize(argv[1]);
        double result = rpn.eval(tokens);
        std::cout << std::fixed << std::setprecision(2) << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
