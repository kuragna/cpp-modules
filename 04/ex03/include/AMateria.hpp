#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
class ICharacter;
#include <iostream>

class AMateria
{
protected:
	std::string type;
public:
	AMateria(void);
	AMateria(std::string const &type);
	AMateria(const AMateria &aMateria);
	AMateria	&operator=(const AMateria &aMateria);
	std::string const &getType() const;

	virtual ~AMateria(void);
	virtual AMateria  *clone() const = 0;
	virtual void use(ICharacter &target);
};
#endif // AMATERIA_HPP
