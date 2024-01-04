#include "Harl.hpp"


typedef void    (Harl::*fptr)(void);

void    Harl::complain(int level)
{
    Harl    harl;
    
    fptr    methods[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    if (level >= 1 && level <= 4)
        (harl.*methods[level - 1])();
}