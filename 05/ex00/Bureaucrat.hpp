#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>


class Bureaucrat
{
	// TODO: try to intialize const variable in assignment operator
    const std::string name;
    int grade;

public:
	class GradeTooLowException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
		public:
			const char *what() const throw();
	};

	Bureaucrat(void);
    Bureaucrat(int grade, const std::string &name);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator=(const Bureaucrat &obj);
	~Bureaucrat();

    const 	std::string &getName(void) const;
    int		getGrade(void) const;
    void    increment(void);
    void    decrement(void);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);

#endif  // BUREAUCRAT_HPP
