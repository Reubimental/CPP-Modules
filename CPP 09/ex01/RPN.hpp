#pragma once

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>
#include <cctype>
#include <sstream>
#include <iomanip>

bool	isNumber(const std::string &s);
bool	performOperation(const std::string &operation, std::stack<double> &stack);
