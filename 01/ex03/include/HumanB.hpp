#ifndef HUMAN_B_HPP
#define HUMAN_B_HPP

#include "./Weapon.hpp"

class   HumanB
{
    Weapon  *weapon;
    std::string name;
    public:
    HumanB(std::string _name)
    {
        name = _name;
		weapon = 0;
    };
    void    attack(void);
    void    setWeapon(Weapon &_weapon);
};
#endif //HUMAN_B_HPP