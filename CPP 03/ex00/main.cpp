#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("TrapClap");

	a.attack("FakeTrap");
	a.takeDamage(9);
	a.beRepaired(5);
}
