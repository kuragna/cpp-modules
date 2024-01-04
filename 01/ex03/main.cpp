#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

void    leaks(void)
{
    system("leaks -q weapon");
}


int main(void)
{
    Weapon club = Weapon("crude spiked club");
    HumanA bob = HumanA("Bob", club);
    
    bob.attack();
    club.setType("some other type of club");
    bob.attack();

    {
        Weapon club = Weapon("crude spiked club");

        HumanB jim = HumanB("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }



    return 0;
}