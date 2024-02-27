
#include "../include/FragTrap.hpp"

int main(void)
{
	/* example 1 */
	FragTrap ft("foo");

	ft.takeDamage(100);
	ft.attack("foofoo");

	/* example 2 */
	FragTrap ft2("spider");
	ft2.takeDamage(50);
	ft2.beRepaired(20);
	ft2.attack("snake");

	/* example 3 */
	FragTrap ft3("lion");
	ft3.highFivesGuys();

	/* example 4 */
	FragTrap ft4("bee");
	for (int i = 0; i < 100; i += 1)
	{
		ft4.attack("flower");
	}
	ft4.attack("flower");
	return 0;
}
