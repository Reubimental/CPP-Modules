#include "Harl.hpp"

int	main(int ac, char **av)
{
	Harl 		h;

	if (ac != 2)
	{
		std::cout << "Invalid use of program." << std::endl;
		std::cout << "Usage:	" << av[0] << " DEBUG/INFO/WARNING/ERROR" << std::endl;
		std::cout << "Example:	" << av[0] << " WARNING" << std::endl;
	}
	h.complain(av[1]);
	return (0);
}