#pragma once

#include <string>

class	ClapTrap
{
	protected: // like private, but child classes can also access
		std::string	name_;
		int			hit_points_;
		int			energy_points_;
		int			attack_damage_;
	public:
		ClapTrap();
		ClapTrap(const std::string& name);
		~ClapTrap();
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};