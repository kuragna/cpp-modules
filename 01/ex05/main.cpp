#include "Harl.hpp"

int main(void)
{
    Harl harl;

	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("ERROR");
	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("DEBUG");

    return 0;
}