
#include "../include/ScavTrap.hpp"

int main()
{
	/* example 1 */
	ScavTrap ct("foo");

	ct.attack("bar");
	ct.takeDamage(12);
	ct.attack("bar");
	ct.beRepaired(5);

	std::cout << std::endl;

	/* example 2 */
	ScavTrap st2;
	st2 = ct;

	for (int i = 0; i < 10; i += 1)
	{
		st2.attack("barfoo");
		st2.beRepaired(3);
	}

	/* example 3 */
	ScavTrap st("test");

	st.attack("test2");
	st.guardGate();

	/* example 4 */
	for (int i = 0; i < 10; i += 1)
	{
		st.attack("test2");
	}
	st.beRepaired(42);

	return 0;
}
