#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal(void);	
	WrongAnimal(const WrongAnimal &wa);	
	WrongAnimal &operator=(const WrongAnimal &wa);	
	~WrongAnimal(void);
	void	makeSound(void);
};

#endif // WRONG_ANIMAL_H