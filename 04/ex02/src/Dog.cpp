#include "../include/Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Dog defualt constructor called" << std::endl;
	brain = new Brain();
}

Dog::Dog(const std::string &type) : Animal(type)
{
	std::cout << "Dog constructor called" << std::endl;
	this->type = type;
	brain = new Brain();
}

Dog::Dog(const Dog &dog) : Animal(dog)
{
	std::cout << "Dog constructor called" << std::endl;
	type	= dog.type;
	brain	= new Brain(*dog.brain);
}

Dog	&Dog::operator=(const Dog &dog)
{
	Animal::operator=(dog);
	std::cout << "Dog assignemnt operator called" << std::endl;
	type 	= dog.type;
	*brain	= *dog.brain;
	return *this;
}

void	Dog::makeSound(void) const
{
	std::cout << "[sound]: Woof.. Woof.. Woof..!" << std::endl;
}

Dog::~Dog(void)
{
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

