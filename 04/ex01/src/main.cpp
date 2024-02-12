
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

void	leaks(void)
{
	system("leaks -q a.out");
}

// TODO: shallow copy and deep copy

int	main(void)
{
	atexit(leaks);
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	delete j;
	delete i;

	const int size = 20;
	const Animal *objs[size];
	for (int i = 0; i < size; i += 1)
	{
		if (i % 2 == 0)
			objs[i] = new Dog();
		else
			objs[i] = new Cat();
	}

	for (int i = 0; i < size; i += 1)
	{
		objs[i]->makeSound();
	}
	for (int i = 0; i < size; i += 1)
	{
		delete objs[i];
	}
	return 0;
}
