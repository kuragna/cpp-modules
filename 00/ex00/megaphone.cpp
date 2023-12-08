#include <iostream>

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	}
	for (int i = 1; argv[i]; i += 1)
	{
		char	*str = argv[i];
		for (; *str ;)
		{
			*str = toupper(*str);
			std::cout << *str;
			str += 1;
		}
	}
	std::cout << std::endl;
	return 0;
}
