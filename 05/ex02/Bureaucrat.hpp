#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <cassert>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    std::string name;
    int grade;
public:
    Bureaucrat(int grade, const std::string &name);
    const 	std::string &getName(void) const;
    int 	getGrade(void) const;
    void    increment(void);
    void    decrement(void);
    void    GradeTooHighException(void) const;
    void    GradeTooLowException(void) const;
	void	signForm(AForm &f);

	void	executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif  // BUREAUCRAT_HPP