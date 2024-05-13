#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	const std::string name;
	const int gradeS;
	const int gradeX;
	bool	_signed;
public:
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};

	Form(void);
	Form(const std::string &, int, int);
	Form(const Form &obj);
	Form &operator=(const Form &obj);
	~Form();

	const std::string &getName(void) const;
	int		getGradeS(void) const;
	int		getGradeX(void) const;
	bool	isSigned(void) const;
	void	beSigned(Bureaucrat &b);
};

std::ostream	&operator<<(std::ostream &os, const Form &obj);

#endif  // FORM_HPP
