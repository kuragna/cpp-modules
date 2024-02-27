#include "../include/DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ScavTrap(), FragTrap()
{
	std::cout << "DiamondTrap defualt constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 50;
	attackDamage	= 30;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name + "_clap_name"), FragTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 50;
	attackDamage	= 30;
	this->name		= name;
}

DiamondTrap::DiamondTrap(const DiamondTrap &dt) : ScavTrap(dt), FragTrap(dt)
{
	std::cout << "DiamondTrap copy constructor called" << std::endl;
	operator=(dt);
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &dt)
{
	ScavTrap::operator=(dt);
	FragTrap::operator=(dt);
	std::cout << "DiamondTrap assignment copy operator called" << std::endl;
	hitPoints		= dt.hitPoints;
	energyPoints	= dt.energyPoints;
	attackDamage	= dt.attackDamage;
	name 			= dt.name;
	return *this;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << name << std::endl;
	std::cout << ClapTrap::name << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap destructor called" << std::endl;
}
