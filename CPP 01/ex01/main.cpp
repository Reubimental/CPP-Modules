#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	int	size;

	size = 10;
	Zombie	*myHorde = zombieHorde(size, "Walker");
	for (int i = 0; i < size; i++)
		myHorde[i].announce();
	delete [] myHorde;
}

// delete [] deletes an array stored on the heap.