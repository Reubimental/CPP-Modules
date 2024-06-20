#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap(): FragTrap("Default"), ScavTrap("Default")
{
	std::cout << "DiamondTrap created as Default." << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name_(name)
{
	hit_points_ = FragTrap::hit_points_;
	energy_points_ = ScavTrap::energy_points_;
	attack_damage_ = FragTrap::attack_damage_;
	std::cout << "DiamondTrap " << name_ << " has entered the chat." << std::endl;
}

DiamondTrap::~DiamondTrap() 
{
	std::cout << "DiamondTrap " << name_ << " out." << std::endl;
}

void	DiamondTrap::whoAmI()
{
	std::cout << "My name is " << name_ << " and my clap name is " << ClapTrap::name_ << std::endl;
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}
