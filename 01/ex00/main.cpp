
#include "Zombie.hpp"

int main()
{
    Zombie	*z = newZombie("bar");
    z->announce();

	Zombie *z2 = newZombie("foo");
	z2->announce();


	delete z;
	delete z2;

    randomChump("test");
    randomChump("test2");

    return 0;
}