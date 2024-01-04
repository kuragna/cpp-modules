#include <iostream>

class   Harl
{
    void    debug(void)
    {
        std::cout << "DEBUG: dont call me if you dont have error\n";
    };
    void    info(void)
    {
        std::cout << "INFO: just need to tell you\n";
    };
    void    warning(void)
    {
        std::cout << "WARNING: it's just warning don't panic\n";
    };
    void    error(void)
    {
        std::cout << "ERROR: if you got me call debuger\n";
    };
    public:
    void    complain(std::string level);
};