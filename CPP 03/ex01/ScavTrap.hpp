#pragma once

#include "ClapTrap.hpp"

class	ScavTrap : public ClapTrap
{
	private:
		ScavTrap();
	public:
		ScavTrap(const std::string& name);
		~ScavTrap();
		void	attack(const std::string& target);
		void	guardGate();
};