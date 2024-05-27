#include "Form.hpp"

int main(void)
{
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

	// bureaucrat can't sign form
	try {
		Form f("ff", 1, 1);
		Bureaucrat b(42, "bab");
		b.signForm(f);
	} catch (std::exception &e) {
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	std::cout << "-------------------------" << std::endl;
	
	// form it's signed
	try {
		Bureaucrat b(1, "foo");
		Bureaucrat b2(1, "baz");
		Form f("form", 42, 1);
		
		b.signForm(f);
		b2.signForm(f);
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
	return 0;
}