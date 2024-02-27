
#include "../include/DiamondTrap.hpp"


int main()
{
	/* example 1 */
	DiamondTrap dt("foo");
	dt.whoAmI();

	/* example 2 */
	DiamondTrap dt2("bar");

	dt2.attack("foofoo");
	dt2.beRepaired(12);
	dt2.takeDamage(100);
	dt2.beRepaired(42);

	/* example 3 */
	DiamondTrap dt3("vim");

	dt3.attack("emacs");
	dt3.takeDamage(1000);
	dt3.beRepaired(42);

	/* example 4 */
	DiamondTrap dt4;

	dt4 = dt3;
	dt4.attack("vscode");

	return 0;
}
