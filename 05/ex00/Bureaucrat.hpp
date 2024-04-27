#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    // TODO: make name as constant
    std::string name; // ?
    int grade;
public:
    Bureaucrat(int grade, const std::string &name); // ?
		~Bureaucrat();
    const 	std::string &getName(void) const;
    int			getGrade(void) const;
    void    increment(void);
    void    decrement(void);
    void    GradeTooHighException(void);
    void    GradeTooLowException(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif  // BUREAUCRAT_HPP
