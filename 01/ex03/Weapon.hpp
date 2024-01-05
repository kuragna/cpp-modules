#ifndef WEAPON_H
#define WEAPON_H

#include <iostream>

class   Weapon
{
    std::string type;
    public:
    Weapon(std::string _type);
    std::string getType() const;
    void        setType(std::string _type);
};

#endif //WEAPON_H