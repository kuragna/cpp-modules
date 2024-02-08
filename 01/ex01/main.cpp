#include "Zombie.hpp"

int main(void)
{
	int	size = 5;

	Zombie *xs = zombieHorde(size, "zombaie");
	
	for (int i = 0; i < size; i += 1)
	{
		xs[i].announce();
	}

	delete[] xs;

	size = 10;
	Zombie *xs2 = zombieHorde(size, "foo");

	for (int i = 0; i < size; i += 1)
	{
		xs2[i].announce();
	}

	delete[] xs2;

	return 0;
}
