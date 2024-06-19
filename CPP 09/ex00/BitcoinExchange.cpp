#include "BitcoinExchange.hpp"
#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
	std::ifstream data("./data.csv");
	if (!data.is_open())
		throw((std::string) "Error: Cannot Open Database.");
	std::string line;
	getline(data, line);
	while (getline(data, line))
	{
		fillData(line);
	}
	data.close();
};

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->LineData.value = src.LineData.value;
	this->LineData.date = src.LineData.date;

	std::map<std::string, float>::const_iterator it;
	for (it = src.btcData.begin(); it != src.btcData.end(); ++it)
	{
		this->btcData[it->first] = it->second;
	}
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->LineData.value = src.LineData.value;
		this->LineData.date = src.LineData.date;

		this->btcData.clear();
		std::map<std::string, float>::const_iterator it;
		for (it = src.btcData.begin(); it != src.btcData.end(); ++it)
		{
			this->btcData[it->first] = it->second;
		}
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange()
{
}

void	BitcoinExchange::fillData(std::string str)
{
	int					i = 0;
	std::stringstream	ss(str);
	std::string			token;

	while (getline(ss, token, ','))
	{
		if (i == 0)
		{
			LineData.date = token;
			i = 1;
		}
		else
			LineData.value = atof(token.c_str());
	}
	this->btcData.insert(std::make_pair(LineData.date, LineData.value));
}

void	BitcoinExchange::validateInput(std::string fileName)
{
	int		year;
	int		month;
	int		day;
	float	value;
	char	extra;

	std::ifstream file(fileName.c_str());
	if (!file.is_open())
		throw((std::string) "Could not open input file.");
	std::string line;
	getline(file, line);
	if (line != "date | value")
		throw((std::string) "Invalid first line. Expected 'date | value'.");
	
	bool	firstLine = true;
	while (getline(file, line))
	{
		if (firstLine)
			firstLine = false;
		if (line.length() < 14)
			std::cerr << "Error: bad input => " << line << std::endl;
		else if (sscanf((line.c_str()), "%d-%d-%d | %f%c", &year, &month, &day, &value, &extra) == 4)
		{
			if (std::isspace(line[13]) || line[11] != '|' || line[line.length() - 1] == '.')
				std::cerr << "Error: bad input => " << line << std::endl;
			try
			{
				checkContents(value);
				checkContents(year, month, day);
			}
			catch (std::string error)
			{
				std::cerr << "Error: " << error << std::endl;
			}
		}
		else
			std::cerr << "Error: bad input => " << line << std::endl;
		size_t	pos;

		pos = line.find(' ');
		LineData.date = line.substr(0, pos);
		LineData.value = value;
		findClosestDate();
	}
	if (firstLine)
		throw((std::string) "File Contents Not Found.");
}

bool	BitcoinExchange::checkLeapYear(int year)
{
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

void	BitcoinExchange::checkContents(float value)
{
	if (value > 1000)
		throw ((std::string) "Value is too large.");
	if (value < 0)
		throw ((std::string) "Value is not a positive number.");
}

void	BitcoinExchange::checkContents(int year, int month, int day)
{
	if (month < 1 || month > 12 || day < 1)
		throw((std::string) "Invalid Date");

	int	months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2 && (checkLeapYear(year)))
		months[1] = 29;
	if (day > months[month - 1])
		throw((std::string) "Invalid Day");
	if (year < 2009 || (year == 2009 && month == 1 && day < 2))
		throw((std::string) "Min Starting Date: (2009-01-02)");
}

void	BitcoinExchange::findClosestDate()
{
	std::map<std::string, float>::iterator it;
	it = this->btcData.lower_bound(LineData.date);
	if (it == this->btcData.end())
	{
		it--;
		std::cout << std::setw(10) << LineData.date << " => " << std::setprecision(8) << LineData.value << " = " << LineData.value * (*it).second << std::endl;
		return;
	}
	if (it == this->btcData.begin())
	{
		std::cerr << "Cannot find any data prior to this date." << std::endl;
		return;
	}
	else
	{
		if ((*it).first != LineData.date)
			it--;
		std::cout << std::setw(10) << LineData.date << " => " << std::setprecision(8) << LineData.value << " = " << std::setprecision(8) << (float)(LineData.value * (*it).second) << std::endl;
	}
}
