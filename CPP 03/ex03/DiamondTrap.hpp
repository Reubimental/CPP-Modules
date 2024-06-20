#pragma once

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap : public FragTrap, public ScavTrap
{
	private:
		std::string	name_;
		DiamondTrap();
	public:
		DiamondTrap(const std::string& name);
		~DiamondTrap();
		void	attack(const std::string& target);
		void	whoAmI();
};