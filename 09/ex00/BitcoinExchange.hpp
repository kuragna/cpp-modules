#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <map>

class BitcoinExchange
{
	std::ifstream inFile;
	std::map<std::string, std::string> db;

public:

	BitcoinExchange(void);
	BitcoinExchange	&operator=(BitcoinExchange const &btc);
	BitcoinExchange(const char *filename);
	BitcoinExchange(BitcoinExchange const &btc);
	~BitcoinExchange(void);

	class InvalidFile : public std::exception
	{
		const char *what(void) const throw();
	};

	void	loadDB(void);
	void	evalInput(void);
	double getClosestValue(std::string const &key);


	bool isDecimal(std::string const &value);
	bool isLeapYear(int year);
	bool isDateValid(std::string const &date);

};

#endif  // BITCOIN_EXCHANGE_HPP
