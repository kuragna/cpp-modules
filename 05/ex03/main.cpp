
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;

	// exists
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	delete rrf;
	rrf = someRandomIntern.makeForm("shrubbery creation", "home");
	delete rrf;
	rrf = someRandomIntern.makeForm("presidential pardon", "target");
	delete rrf;
	// doesnt exist
	rrf = someRandomIntern.makeForm("test", "test2");

	(void) rrf;

	return 0;
}