#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"

class DiamondTrap : public ScavTrap, FragTrap
{
	std::string name;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &dt);
	DiamondTrap	&operator=(const DiamondTrap &dt);
	~DiamondTrap(void);
	void	whoAmI();

};
#endif // DIAMONDTRAP_HPP
