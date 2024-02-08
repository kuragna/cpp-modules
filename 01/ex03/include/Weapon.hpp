#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class   Weapon
{
    std::string type;
public:
    Weapon(std::string _type);
    const std::string &getType(void);
    void setType(std::string _type);
};

#endif //WEAPON_HPP