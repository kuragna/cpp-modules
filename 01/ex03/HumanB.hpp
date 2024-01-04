#ifndef HUMAN_B_H
#define HUMAN_B_H

#include "Weapon.hpp"

class   HumanB
{
    Weapon  *weapon;
    std::string name;
    public:
    HumanB(std::string _name)
    {
        name = _name;
    };
    void    attack(void);
    void    setWeapon(Weapon &_weapon);
};
#endif //HUMAN_B_H