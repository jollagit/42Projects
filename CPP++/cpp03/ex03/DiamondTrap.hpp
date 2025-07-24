#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& value);
	DiamondTrap &operator=(const DiamondTrap& val);
	~DiamondTrap(void);
	void	whoAmI();
	void	attack(const std::string& target);
private:
	std::string name;
};

#endif