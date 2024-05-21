#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>

int main(void)
{
	// ShrubberyCreationForm
	try {
		// valid grade to execute form
		Bureaucrat b(150, "foo");
		ShrubberyCreationForm s("home");
		s.beSigned(b); // sign form
		s.execute(b);
		// bureaucrat didn't sign form
		{
			Bureaucrat b(42, "baz");
			ShrubberyCreationForm s("home");
			s.execute(b);
		}
		// invalid grade to execute form
		{
			Bureaucrat b(150, "baz");
			ShrubberyCreationForm s("home");
			s.beSigned(b);
			s.execute(b);
		}
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// RobotomyRequestForm
	try {
		Bureaucrat b(42, "foo");
		RobotomyRequestForm r("tar");
		r.beSigned(b);
		r.execute(b);

		{
			Bureaucrat b(42, "baz");
			RobotomyRequestForm s("home");
			s.execute(b);
		}
		// invalid grade to execute form
		{
			Bureaucrat b(1, "baz");
			RobotomyRequestForm s("home");
			s.beSigned(b);
			s.execute(b);
		}
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	// PresidentialPardonForm
	try {
		Bureaucrat b(5, "foo");
		PresidentialPardonForm r("tar");
		r.beSigned(b);
		r.execute(b);

		{
			Bureaucrat b(42, "baz");
			PresidentialPardonForm s("home");
			s.execute(b);
		}
		// invalid grade to execute form
		{
			Bureaucrat b(1, "baz");
			PresidentialPardonForm s("home");
			s.beSigned(b);
			s.execute(b);
		}
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	return 0;
}