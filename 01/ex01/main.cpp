#include "Zombie.hpp"

void    leaks(void)
{
    system("leaks -q zombie");
}




int main(void)
{
    atexit(leaks);

    Zombie *xs = zombieHorde(5, "zomba");

    for (int i = 0; i < 5; i += 1)
    {
        xs[i].announce();
    }
    delete[] xs;
    return 0;
}