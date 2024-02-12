
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

// TODO: check for memory leaks

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *j = new Dog("Dog");
	const Animal *i = new Cat("Cat");


	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();


	/* ---------------------------------------------------- */

	WrongAnimal *wa  = new WrongAnimal();
	WrongAnimal *wa2 = new WrongCat();

	wa->makeSound();
	wa2->makeSound();


	return 0;
}
