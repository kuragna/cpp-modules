#include "../include/Ice.hpp"
#include "../include/Cure.hpp"
#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"

#if 1
	#define LOG(ptr) std::cout << "[INFO]: address: `" << ptr << "` -> " << __FILE__ << ":" << __LINE__ << std::endl;
#endif

void	leaks(void)
{
	system("leaks -q a.out");
}


int main(void)
{
	atexit(leaks);

	IMateriaSource *s = new MateriaSource();
	s->learnMateria(new Ice());

	ICharacter *m = new Character("foo");

	AMateria *t;

	t = s->createMateria("ice");
	m->equip(t);

	t = s->createMateria("ice");
	m->equip(t);

	t = s->createMateria("ice");
	m->equip(t);

	t = s->createMateria("ice");
	m->equip(t);

	ICharacter *b = new Character("bar");
	m->unequip(4);

// 	m->use(0, *b);
// 	m->use(1, *b);
// 	m->use(2, *b);
// 	m->use(3, *b);

	delete b;
	delete s;
	delete m;
	return 0;

#if 1
	/* example from subject */
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;
#elif 0

	// TODO: equip same materia multiple time
	/* example unexisting */
	IMateriaSource *src2 = new MateriaSource();
	src2->learnMateria(new Ice());

	ICharacter	*me2 = new Character("me");

	AMateria *tmp2;

	tmp2 = src2->createMateria("ice");
	me2->equip(tmp2);
	me2->unequip(0);
	me2->unequip(1);
	me2->unequip(-1);


	ICharacter *bob2 = new Character("bob2");

	me2->use(0, *bob2);

	delete bob2;
	delete me2;
	delete src2;
	delete tmp2;
#else

#endif

	return 0;
}