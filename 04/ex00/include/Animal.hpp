#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	Animal(const Animal &animal);
	Animal	&operator=(const Animal &animal);
	~Animal(void);
	const std::string &getType(void) const;
	virtual void	makeSound(void) const;
};
#endif // ANIMAL_HPP
