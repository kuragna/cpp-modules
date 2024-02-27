#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie
{
    std::string name;
public:
	Zombie(void) {};
	Zombie(std::string _name);
	~Zombie(void);
    void    announce(void);
};

Zombie  *zombieHorde(int N, std::string name);

#endif //ZOMBIE_HPP