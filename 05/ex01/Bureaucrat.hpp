#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cassert>
#include "Form.hpp"

class Form;

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

		void		signForm(Form &f);
};

std::ostream &operator<<(std::ostream &os, Bureaucrat &obj);

#endif  // BUREAUCRAT_HPP