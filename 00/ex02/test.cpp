#include <iostream>
#include <ctime>
#include <iostream>
#include <iterator>
#include <locale>


void    displayTime(void)
{
    const size_t size = sizeof("[yyyymmdd_hhmmss]");
    std::time_t time = std::time(nullptr);

    char    timeString[size];

    //std::size_t strftime( char* str, std::size_t count, const char* format, const std::tm* tp );
    
    std::strftime(timeString, size, "[%Y%m%d_%H%M%S]", std::gmtime(&time));
    std::cout << timeString << std::endl;
}


int main()
{
    
    return 0;
}