
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongCat.hpp"

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

	delete meta;
	delete j;
	delete i;


	/* ---------------------------------------------------- */
	std::cout << "-------------------------------" << std::endl;


	WrongAnimal *wAnimal = new WrongAnimal();
	WrongAnimal *w = new WrongCat();

	wAnimal->makeSound();
	w->makeSound();

	delete wAnimal;
	delete w;


	return 0;
}
