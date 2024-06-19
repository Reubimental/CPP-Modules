#include "type_identify.hpp"

#include <cstdlib>

int	main()
{
	srand(time(NULL));
	for (int j = 0; j < 5; j++)
	{
		std::cout << "Test #" << j + 1 << std::endl;
		Base *Test = generate();
		if (Test == NULL)
			return (1);
		else
		{
			identify(Test);
			identify(*Test);
			delete (Test);
			std::cout << std::endl;
		}
	}
	return (0);
}