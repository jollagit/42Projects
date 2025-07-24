#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP
#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& value);
	FragTrap &operator=(const FragTrap& val);
	~FragTrap(void);
	void	highFivesGuys(void);
	void	attack(const std::string& target);
private:
};

#endif