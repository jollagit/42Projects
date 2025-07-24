#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& value);
	ScavTrap &operator=(const ScavTrap& val);
	~ScavTrap(void);
	void	guardGate();
	void	attack(const std::string& target);
private:
};

#endif