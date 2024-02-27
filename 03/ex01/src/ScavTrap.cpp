
#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << "ScavTrap defualt constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 50;
	attackDamage	= 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 50;
	attackDamage	= 20;
}

ScavTrap::ScavTrap(const ScavTrap &st) : ClapTrap(st)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	operator=(st);
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &st)
{
	ClapTrap::operator=(st);
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	hitPoints		= st.hitPoints;
	energyPoints	= st.energyPoints;
	attackDamage	= st.attackDamage;
	name			= st.name;
	return *this;
}

void	ScavTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ScavTrap " << name << " is dead" << std::endl;
		return ;
	}
	if (energyPoints <= 0)
	{
		std::cout << "ScavTrap has no energy to attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap "
			  << name 
			  << " attacks " 
			  << target 
			  << ", causing " 
			  << attackDamage 
			  << " points of damage!" 
			  << std::endl;
	energyPoints -= 1;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}	

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

