
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

void	leaks(void)
{
	system("leaks -q a.out");
}

int	main(void)
{
	atexit(leaks);

	const Animal *j = new Dog("Dog");
	const Animal *i = new Cat("Cat");

	delete j;
	delete i;

	const int size = 20;
	const Animal *objs[size];
	for (int i = 0; i < size; i += 1)
	{
		if (i % 2 == 0)
			objs[i] = new Dog("Dog");
		else
			objs[i] = new Cat("Cat");
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
