#include "Zombie.hpp"

Zombie	*newZombie(std::string name)
{
	return (new Zombie(name));
}

// using the 'new' keyword assigns this instance of the class on the Heap because it is declared as a Local Variable.
// A class allocated this way must be manually deallocated with the 'delete' keyword, as seen at the end of the int main().