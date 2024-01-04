#include <iostream>

class   Harl
{
    void    debug(void)
    {
        std::cout << "[ DEBUG ]\n";
        std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n";
        std::cout << "I really do!\n";
    };
    void    info(void)
    {
        std::cout << "[ INFO ]\n";
        std::cout << "I cannot believe adding extra bacon costs more money.\n";
        std::cout << "You didn't putenough bacon in my burger! If you did, I wouldn't be asking for more!\n";
    };
    void    warning(void)
    {
        std::cout << "[ WARNING ]\n";
        std::cout << "I think I deserve to have some extra bacon for free.\n";
        std::cout << "I've been coming for years whereas you started working here since last month.\n";
    };
    void    error(void)
    {
        std::cout << "[ ERROR ]\n";
        std::cout << "This is unacceptable! I want to speak to the manager now.\n";
    };
    public:
    void    complain(int level);
};