
#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
	hitPoints		= 10;
	energyPoints	= 10;
	attackDamage	= 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "ClapTrap constructor called" << std::endl;
	hitPoints		= 10;
	energyPoints	= 10;
	attackDamage	= 0;
	this->name		= name;
}

ClapTrap::ClapTrap(const ClapTrap &ct)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	operator=(ct);
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &ct)
{
	std::cout << "ClapTrap copy assignment operator called" << std::endl;
	hitPoints		= ct.hitPoints;
	energyPoints	= ct.energyPoints;
	attackDamage	= ct.attackDamage;
	name			= ct.name;
	return *this;
}

void	ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " id dead" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy to attack" << std::endl;
		return ;
	}
	std::cout << "ClapTrap "
			  << name 
			  << " attacks " 
			  << target 
			  << ", causing " 
			  << attackDamage 
			  << " points of damage!" 
			  << std::endl;
	energyPoints -= 1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " << name << " has taken " << amount << " of damage" << std::endl;
	hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap " << name << " can't be repaired" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " has repaired" << std::endl;
	hitPoints += amount;
	energyPoints -= 1;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap Destructor called" << std::endl;
}