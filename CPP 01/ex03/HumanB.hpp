#pragma once

#include "Weapon.hpp"

class	HumanB
{
	private:
		std::string	_name;
		Weapon		*_weapon;
	public:
		HumanB(std::string _name);
		~HumanB();
		void	attack();
		void	setWeapon(Weapon &weapon);
};