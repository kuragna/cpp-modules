#include "Zombie.hpp"

int main()
{

    Zombie *z = newZombie("ahmed");
    z->announce();

    delete z;

    randomChump("foo");
    randomChump("bar");
    randomChump("baz");

    return 0;
}