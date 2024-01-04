#include "Harl.hpp"

int main(void)
{
    Harl harl;

    harl.complain("1"); // 0
    harl.complain("1"); // 0
    harl.complain("2"); // 1
    harl.complain("3"); // 2
    harl.complain("4"); // 3
    harl.complain("5"); // 3
    harl.complain("6"); // 3
    return 0;
}