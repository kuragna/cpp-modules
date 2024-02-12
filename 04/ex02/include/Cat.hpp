#ifndef CAT_HPP
#define CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : public Animal
{
	Brain *brain;
public:
	Cat(void);
	Cat(const std::string &type);
	Cat(const Cat &cat);
	Cat	&operator=(const Cat &cat);
	~Cat(void);

	void	makeSound(void) const;
};
#endif // CAT_HPP
