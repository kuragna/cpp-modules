#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	Animal(const std::string type);
	Animal(const Animal &animal);
	Animal	&operator=(const Animal &animal);
	const std::string &getType(void) const;
	virtual ~Animal(void);
	virtual void	makeSound(void) const = 0;
};
#endif // ANIMAL_HPP
