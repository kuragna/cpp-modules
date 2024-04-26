
#include <iostream>
#include <string>
#include <cassert>

class Bureaucrat
{
    // TODO: make name as constant
    std::string name; // ?
    int grade;
public:
    Bureaucrat(int grade, const std::string &name); // ?
    std::string &getName(void);
    int getGrade(void);
    void    increment(void);
    void    decrement(void);
    void    GradeTooHighException(void);
    void    GradeTooLowException(void);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj);