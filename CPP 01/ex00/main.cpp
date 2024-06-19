#include "Zombie.hpp"

Zombie	*newZombie(std::string name);

void	randomChump(std::string name);

int	main(void)
{
	Zombie	*hzombie = newZombie("Heap");
	hzombie->announce();
	randomChump("Stack");
	delete hzombie;
}

// stack is used for local variables, and is managed automatically.
// heap is used for dynamic memory allocation, and needs to be allocated and deallocated manually.