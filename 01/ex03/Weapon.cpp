#include "Weapon.hpp"

Weapon::Weapon(std::string _type)
{
    type = _type;
}
std::string Weapon::getType() const
{
    return type;
}

void    Weapon::setType(std::string _type)
{
    type = _type;
}