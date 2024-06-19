#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
	private:
		struct
		{
			float		value;
			std::string	date;
		} LineData;
		std::map<std::string, float> btcData;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		BitcoinExchange &operator=(const BitcoinExchange &src);
		~BitcoinExchange();
		void	fillData(std::string str);
		void	validateInput(std::string fileName);
		bool	checkLeapYear(int year);
		void	checkContents(float value);
		void	checkContents(int year, int month, int day);
		void	findClosestDate();
};