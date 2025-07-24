#include "ClapTrap.hpp"

int main() {
	ClapTrap	robot2;

	std::cout << "\nATTACK Tests: " << std::endl;
	robot2.attack("Enemy1");
	robot2.attack("Enemy2");

	std::cout << "\nTAKE Damage Tests: " << std::endl;
	robot2.takeDamage(3);
	robot2.takeDamage(5);

	std::cout << "\nREPAIR Tests: " << std::endl;
	robot2.beRepaired(4);
	robot2.beRepaired(2);

	std::cout << "\nENERGY LIMIT Test: " << std::endl;
	ClapTrap energyTest("EnergyBot");
	for (int i = 0; i < 12; i++) {
		energyTest.attack("Target");
	}

	std::cout << "\nDEATH Test: " << std::endl;
	ClapTrap deathTest("DeathBot");
	deathTest.takeDamage(15);
	deathTest.attack("Someone");
	deathTest.beRepaired(5);
	
	return 0;
}
