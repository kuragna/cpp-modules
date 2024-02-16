#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include "ICharacter.hpp"

class Character : virtual public ICharacter
{
	static const int   slots_size = 4;
	int			slots_len;
	AMateria	*slots[slots_size];
	std::string name;
public:
	Character(void);
	Character(const std::string &name);
	Character(const Character &ch);
	Character &operator=(const Character &ch);
	~Character(void);

	std::string const &getName(void) const;
	void	equip(AMateria *m);
	void	unequip(int idx);
	void	use(int idx, ICharacter &target);
};
#endif // CHARACTER_HPP