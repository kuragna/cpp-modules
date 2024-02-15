#include "../include/Character.hpp"

Character::Character(void)
{
	std::cout << "Character defualt constructor called" << std::endl;
	for (int i = 0; i < 4; i += 1)
	{
		slots[i] = 0;
	}
}

Character::Character(const std::string &name)
{
	std::cout << "Character constructor called" << std::endl;
	for (int i = 0; i < slots_size; i += 1)
	{
		slots[i] = 0;
	}
	this->name = name;
}

Character::Character(const Character &ch)
{
	std::cout << "Character copy constructor called" << std::endl;
	name = ch.name;
	for (int i = 0; i < slots_size; i += 1)
	{
		slots[i] = ch.slots[i];
	}
}

Character	&Character::operator=(const Character &ch)
{
	std::cout << "Character assigment operator called" << std::endl;
	name = ch.name;
	for (int i = 0; i < slots_size; i += 1)
	{
		slots[i] = ch.slots[i];
	}
	return *this;
}

std::string const &Character::getName(void) const
{
	return name;
}

void	Character::equip(AMateria *m)
{
	int i;

	for (i = 0; i < slots_size; i += 1)
	{
		if (!slots[i]) break ;
	}
	if (i != slots_size) slots[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx <= slots_size)
	{
		if (!slots[idx]) return ;
		// TODO: logic of unequip materia
	}
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < slots_size)
	{
		if (slots[idx]) slots[idx]->use(target);
	}
}

Character::~Character(void)
{
	for (int i = 0; i < slots_size; i += 1)
	{
		if (slots[i])
			delete slots[i];
	}
	std::cout << "Character destructor called" << std::endl;
}

