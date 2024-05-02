#include "Bureaucrat.hpp"

int main(void)
{
	// NOTE: to make sure for increment and decrement functions. see the subject
	try {
		// pass valid grade
		Bureaucrat b(42, "foo");
		std::cout << b << std::endl;
		
		// pass invalid grade
		Bureaucrat b2(-1, "bar");
		Bureaucrat b3(200, "bar");

		// increment a grade
		Bureaucrat b4(0, "john");
		std::cout << b4 << std::endl;
		b4.increment();

		// decrement a grade
		Bureaucrat b5(150, "doe");
		std::cout << b5 << std::endl;
		b5.decrement();
	}
	catch (std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
		return 1;
	}
	return 0;
}