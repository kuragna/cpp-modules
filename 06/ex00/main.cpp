#include "ScalarConverter.hpp"

// TODO: fix non output


int main(int argc, char **argv)
{
	(void) argc; (void) argv;
	std::cout << std::boolalpha;
#if 0
#else

	if (argc != 2)
	{
		std::cerr << "Error: no input is provided" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
#endif
	return 0;
}