#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "./Weapon.hpp"

class   HumanA
{
    Weapon      &weapon;
    std::string name;
    public:
    HumanA(std::string _name, Weapon &_weapon);
    void    attack(void);
};

#endif //HUMAN_A_HPP