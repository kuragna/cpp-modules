#include "../include/FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap defualt constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 100;
	attackDamage	= 30;
}

FragTrap::FragTrap(std::string name) :  ClapTrap(name)
{
	std::cout << "FragTrap constructor called" << std::endl;
	hitPoints		= 100;
	energyPoints	= 100;
	attackDamage	= 30;
}

FragTrap::FragTrap(const FragTrap &ft) : ClapTrap(ft)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	operator=(ft);
}

FragTrap	&FragTrap::operator=(const FragTrap &ft)
{
	ClapTrap::operator=(ft);
	std::cout << "FragTrap assignment copy operator called" << std::endl;
	name			= ft.name;
	hitPoints		= ft.hitPoints;
	energyPoints	= ft.energyPoints;
	attackDamage	= ft.attackDamage;
	return *this;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap high fives guys" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called" << std::endl;
}
