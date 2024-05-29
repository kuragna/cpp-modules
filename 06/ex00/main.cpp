#include "ScalarConverter.hpp"
#include <limits>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cstring>

// TODO: float  -> +inff,
// TODO: double -> +inf, 
// TODO: can we use void*?

int main(int argc, char **argv)
{
	(void) argc; (void) argv;
	std::cout << std::boolalpha;
#if 1

	std::string str = "4233636";
	int	i = std::atof(str.c_str());

	Data data(str);

	data.Decimal(static_cast<double>(i), "double", false);
	data.Decimal(static_cast<float>(i), "float", true);

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