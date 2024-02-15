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



	
	return 0;
}
