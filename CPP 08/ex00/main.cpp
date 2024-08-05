#include "easyfind.hpp"

int	main()
{
	std::vector<int>	container;
	int	prime = 1;

	for (int number = 0; number < 200000; number++)
	{
		try
		{
			for (int n = 2; n <= number / 2; n++)
			{
				if (number % n == 0)
				{
					prime = 0;
					break ;
				}
				prime = 1;
			}
			if (prime == 1)
				container.push_back(number);
			easyfind(container, number);
			std::cout << "Number is prime: " << number << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}