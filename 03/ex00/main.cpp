
#include "ClapTrap.hpp"

int main(void)
{
	/* example 1 */
	ClapTrap ct("foo");

	ct.attack("bar");
	ct.beRepaired(2);
	ct.takeDamage(10);
	ct.attack("bar");

	/* example 2 */
	ClapTrap ct2("spiderman");

	for (int i = 0; i < 10; i += 1)
	{
		ct2.attack("batman");
	}
	ct2.attack("batman");

	/* example 3 */
	ClapTrap ct3("hulk");
	ct3.takeDamage(5);
	ct3.beRepaired(10);
	ct3.takeDamage(10);
	ct3.attack("spiderman");

	return 0;
}
