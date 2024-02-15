#ifndef Ice_HPP
#define Ice_HPP

#include <iostream>
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : virtual public AMateria
{
public:
	Ice(void);
	Ice(const std::string &type);
	Ice(const Ice &ice);
	Ice &operator=(const Ice &ice);
	~Ice(void);

	std::string const &getType() const;
	void use(ICharacter &target);
	Ice *clone() const;
};
#endif // ICE_HPP
