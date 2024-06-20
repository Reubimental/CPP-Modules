#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(): 
	name_("Default"),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap created as Default." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
	name_(name),
	hit_points_(10),
	energy_points_(10),
	attack_damage_(0)
{
	std::cout << "ClapTrap " << name_ << " has entered the chat." << std::endl;
}

ClapTrap::~ClapTrap() 
{
	std::cout << "ClapTrap " << name_ << " out." << std::endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (energy_points_ <= 0 || hit_points_ <= 0)
	{
		return;
	}
	energy_points_--;
	std::cout << "ClapTrap " << name_ << " attacked " << target << ", causing " << attack_damage_ << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name_ << " has taken " << amount << " damage ";
	if (hit_points_ > (int)amount)
	{
		hit_points_ -= (int)amount;
		std::cout << "and survived!" << std::endl;
	}
	else
	{
		hit_points_ = 0;
		std::cout << "and died!" << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (energy_points_ <= 0 || hit_points_ <= 0)
	{
		return;
	}
	energy_points_--;
	hit_points_ += amount;
	std::cout << "ClapTrap " << name_ << " repaired " << amount << " hitpoints!" << std::endl;
}