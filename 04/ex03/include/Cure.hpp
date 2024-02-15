#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : virtual public AMateria
{
public:
	Cure(void);
	Cure(const std::string &type);
	Cure(const Cure &cure);
	Cure &operator=(const Cure &cure);
	~Cure(void);

	std::string const &getType() const;
	void use(ICharacter &target);
 	Cure *clone(void) const;
};
#endif // CURE_HPP
