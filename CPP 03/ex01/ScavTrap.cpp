#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap(): ClapTrap()
{
	std::cout << "ScavTrap created as Default." << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 50;
	attack_damage_ = 20;
	std::cout << "ScavTrap " << name_ << " has entered the chat." << std::endl;
}

ScavTrap::~ScavTrap() 
{
	std::cout << "ScavTrap " << name_ << " out." << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if (energy_points_ <= 0 || hit_points_ <= 0)
	{
		return;
	}
	energy_points_--;
	std::cout << "ScavTrap " << name_ << " attacked " << target << ", causing " << attack_damage_ << " points of damage!" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name_ << " has entered Gate Keeping mode." << std::endl;
}