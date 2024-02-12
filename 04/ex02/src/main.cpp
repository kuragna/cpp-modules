
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


	/* NOTE: we cant instantiate animal object because Animal class is has a pure virtual function, 
	 * we call it  'Abstract class' in cpp but some language they call it an interface..*/
	// const Animal *animal = new Animal();
	const Animal *j = new Dog();
	const Animal *i = new Cat();

	j->makeSound();
	i->makeSound();


	delete i;
	delete j;

	return 0;
}
