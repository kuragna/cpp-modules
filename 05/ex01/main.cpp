#include "Form.hpp"

int main(void)
{
#if 1
	// valid grades
	try {
		Form f("foo", 1, 150);
		std::cout << f << std::endl;

		Form ff("baz", 150, 1);
		std::cout << ff << std::endl;

	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	// invalid grades
	try {
		Form f("form", -1, 33);
		std::cout << f << std::endl;

		Form ff("fform", 200, 42);
		std::cout << ff << std::endl;
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	
	// form doesn't sign
	try {
		Bureaucrat b(1, "foo");
		Form f("form", 42, 1);
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	// signed form
	try {
		Bureaucrat b(42, "baz");
		Form f("test", 43, 43);

		f.beSigned(b);
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	std::cout << "-------------------------" << std::endl;
	// Bureaucrat's grade is low then form's grade
	try
	{
		// Bureaucrat's grade is low then form's grade
		Bureaucrat b(150, "foo");
		Form f("form6", 1, 1);
		f.beSigned(b);
		b.signForm(f);
	} catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
#endif
	return 0;
}