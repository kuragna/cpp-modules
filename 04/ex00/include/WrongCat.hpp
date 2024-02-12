#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "../include/WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat &wc);
	WrongCat &operator=(const WrongCat &wc);
	~WrongCat(void);
	void	makeSound(void);
};

#endif //WrongCat_HPP
