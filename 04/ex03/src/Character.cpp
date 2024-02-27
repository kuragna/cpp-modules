#include "../include/Character.hpp"

Character::Character(void)
{
	for (int i = 0; i < slots_size; i += 1)
	{
		slots[i] = 0;
	}
	slots_len = 0;
}

Character::Character(const std::string &name)
{
	for (int i = 0; i < slots_size; i += 1)
	{
		slots[i] = 0;
	}
	slots_len = 0;
	this->name = name;
}

Character::Character(const Character &ch)
{
	name = ch.name;
	slots_len = ch.slots_len;
	for (int i = 0; i < ch.slots_len && i < slots_size; i += 1)
	{
		slots[i] = ch.slots[i]->clone();
	}
}

Character	&Character::operator=(const Character &ch)
{
	name = ch.name;
	slots_len = ch.slots_len;
	for (int i = 0; i < ch.slots_len && i < slots_size; i += 1)
	{
		slots[i] = ch.slots[i]->clone();
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

	if (slots_len < slots_size)
	{
		slots[slots_len++] = m;
		return ;
	}
	for (i = 0; i < slots_size; i += 1)
	{
		if (!slots[i]) break ;
	}
	slots[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < slots_len)
	{
		slots[idx] = 0;
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
	for (int i = 0; i < slots_len && i < slots_size; i += 1)
	{
		delete slots[i];
	}
}
