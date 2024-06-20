#include "BitcoinExchange.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: no input is provided" << std::endl;
		std::cout << "Usage: ./btc filename" << std::endl;
		return 1;
	}
	try 
	{
		BitcoinExchange btc(argv[1]);
		btc.evalInput();
	} catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}