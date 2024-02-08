
#include "../include/HumanB.hpp"

void    HumanB::attack(void)
{
	if (weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void    HumanB::setWeapon(Weapon &_weapon)
{
    weapon = &_weapon;
}