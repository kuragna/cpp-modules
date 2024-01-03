#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>

class Zombie
{
    std::string name;
    public:
    void    setName(std::string _name)
    {
        name = _name;
    };
    void    announce(void);
};

Zombie  *zombieHorde(int N, std::string name);

#endif //ZOMBIE_H