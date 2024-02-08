#include "Zombie.hpp"

Zombie::Zombie(std::string _name)
{
    name = _name;
}

void    Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << name << ": has been destroyed" << std::endl;;
}