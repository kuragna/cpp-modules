
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"

int	main(void)
{
	const Animal *j = new Dog("dog");
	const Animal *i = new Cat("cat");

	j->makeSound();
	i->makeSound();

	delete i;
	delete j;

	return 0;
}
