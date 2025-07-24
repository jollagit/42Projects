#ifndef HUMANA_HPP
# define HUMANA_HPP
#include "Weapon.hpp"
#include <string>

class HumanA {
public:
	void	attack();
	HumanA(std::string name, Weapon& weapon);
private:
	std::string name;
	Weapon& weapon;
};

#endif
