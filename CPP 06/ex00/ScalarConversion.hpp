#pragma once

#include <string>
#include <iostream>
#include <cstdlib>
#include <climits>

class ScalarConversion
{
	private:
		ScalarConversion();
		ScalarConversion(const ScalarConversion &src);
		ScalarConversion &operator=(const ScalarConversion &src);
	public:
		~ScalarConversion();
		static void convert(const std::string &literal);
};
