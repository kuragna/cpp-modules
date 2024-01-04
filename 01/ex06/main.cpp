#include "Harl.hpp"

int getIndex(const char *name)
{
    const char    *names[4] = {
        "DEBUG",
        "INFO",
        "WARNING",
        "ERROR",
    };
    for (int i = 0; i < 4; i += 1)
    {
        if (std::strcmp(names[i], name) == 0)
            return i + 1;
    }
    return -1;
}

void    harlFilter(int index)
{
    Harl harl;
    
    switch(index)
    {
        case 1:
            harl.complain(index);
            index += 1;
        case 2:
            harl.complain(index);
            index += 1;
        case 3:
            harl.complain(index);
            index += 1;
        case 4:
            harl.complain(index);
            index += 1;
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]\n";
    }
}

int main(int argc, char **argv)
{
    (void) argv;
    if (argc != 2)
    {
        std::cerr << "Error: invalid argument\n";
        return 1;
    }
    int index = getIndex(argv[1]);
    harlFilter(index);
    return 0;
}