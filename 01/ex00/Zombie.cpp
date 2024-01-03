#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
    name = _name;
}
Zombie::~Zombie(void)
{
    std::cout << name << ": has been destroyed\n";
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
}