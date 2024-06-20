#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main()
{
	ClapTrap a ("Clap1");
	a.attack("TrapClap");
	a.takeDamage(5);
	a.beRepaired(5);

	std::cout << std::endl;

	ScavTrap b ("Scav1");
	b.attack("TrapClap");
	b.takeDamage(5);
	b.beRepaired(5);
	b.guardGate();

	std::cout << std::endl;

	FragTrap c ("Frag1");
	c.attack("TrapClap");
	c.takeDamage(5);
	c.beRepaired(5);
	c.highFivesGuys();

	std::cout << std::endl;
}