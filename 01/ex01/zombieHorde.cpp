#include "Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
	Zombie	*zombies = new Zombie[N];

	for (int i = 0; i < N; i += 1)
	{
		zombies[i] = Zombie(name);
	}
    return zombies;
}