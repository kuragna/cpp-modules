#include "PmergeMe.hpp"

#include <ctime>
#include <unistd.h>

#if 1
int main(int argc, char **argv)
{
	std::cout << std::boolalpha;
	if (argc <= 1)
	{
		std::cout << "Error: invalid arguments" << std::endl;
		return 1;
	}

// 	time_t prevTime = time(NULL);

// 	for (;;)
// 	{
// 		sleep(1);
// 		time_t currTime = time(NULL) - prevTime;
// 		std::cout << "currTime -> " << currTime << std::endl;
// 	}

// 	return 0;

	try
	{
		PmergeMe pm(argv + 1);
		pm.info();
		//pm.mergeInsertionSort();
	} catch (std::exception &e)
	{
		std::cout << "Error" << std::endl;
		return 1;
	}
	return 0;
}

#else 

int	main2()
{
	std::vector<int> vec = {1, 2, 3, 4};
	
	std::vector<int>::iterator it = vec.begin();

	while (it != vec.end())
	{
		int	first  = *std::next(it, 0);
		int	second = *std::next(it, 1);
		it = std::next(it, 2);
		std::cout << "first  -> " << first << std::endl;
		std::cout << "second -> " << second << std::endl;
	}

	return 0;	
}
#endif

