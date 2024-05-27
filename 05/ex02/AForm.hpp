#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

// abstract class
class AForm
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


	AForm(void);
	AForm(const std::string &, int, int);
	AForm(const AForm &obj);
	AForm &operator=(const AForm &obj);

	const std::string &getName(void) const;
	int		getGradeS(void) const;
	int		getGradeX(void) const;
	bool	isSigned(void) const;
	void	beSigned(Bureaucrat &b);

	virtual ~AForm();
	virtual void execute(Bureaucrat const &executor) const = 0;
};

std::ostream	&operator<<(std::ostream &os, const AForm &obj);

#endif  // FORM_HPP
