#include "Harl.hpp"


typedef void    (Harl::*fptr)(void);

void    Harl::complain(std::string level)
{
    int     idx;
    Harl    harl;
    fptr    methods[4] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error,
    };
    
    idx = stoi(level);
    if (idx >= 1 && idx <= 4)
        (harl.*methods[idx - 1])();
}