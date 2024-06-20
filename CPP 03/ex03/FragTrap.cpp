#include <iostream>
#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap()
{
	std::cout << "FragTrap created as Default." << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	hit_points_ = 100;
	energy_points_ = 100;
	attack_damage_ = 30;
	std::cout << "FragTrap " << name_ << " has entered the chat." << std::endl;
}

FragTrap::~FragTrap() 
{
	std::cout << "FragTrap " << name_ << " out." << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name_ << " gave his friends a pleasant high-five" << std::endl;
}