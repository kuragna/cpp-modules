
#include "Bureaucrat.hpp"

#include <iostream>
#include <cstring>


int main(void)
{
    try {
        // valid argument
        Bureaucrat b(150);
        std::cout << b << std::endl;

        b.decrement();
        std::cout << b << std::endl;
        b.increment();
        b.increment();
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}