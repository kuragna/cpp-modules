#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	static int count;
	std::string target;
public:
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &r);
	RobotomyRequestForm	&operator=(const RobotomyRequestForm &r);
	~RobotomyRequestForm(void);

	void execute(Bureaucrat const &executor) const;
};
#endif // ROBOTOMY_REQUEST_FORM_HPP
