#ifndef HUMANB_HPP
# define HUMANB_HPP
#include "Weapon.hpp"
#include <string>

class HumanB {
public:
	void	attack();
	void	setWeapon(Weapon& weapon);
	HumanB(std::string name);
private:
	std::string name;
	Weapon* weapon;
};

#endif