#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	szombie = Zombie(name);
	szombie.announce();
}

// The Zombie class here is declared as a local variable, and thus is created on the Stack.
// It will be deleted when it goes out of scope.

// This means that, when the function has ended, this zombie will no longer exist, so should only be used for temporary variables.