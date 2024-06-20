#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {}

BitcoinExchange::BitcoinExchange(const char *filename)
{
	this->loadDB();
	inFile.open(filename, std::ifstream::in);
	if (!inFile.is_open())
	{
		throw InvalidFile();
	}
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &btc)
{
	operator=(btc);
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &btc)
{
	if (this != &btc)
	{
		this->db = btc.db;
	}
	return *this;
}

const char *BitcoinExchange::InvalidFile::what(void) const throw()
{
	return "InvalidFile";	
}

double BitcoinExchange::getClosestValue(std::string const &key)
{
	std::string value;
	std::map<std::string, std::string>::iterator lower;
	std::map<std::string, std::string>::iterator prev;

	lower = db.lower_bound(key);
	if (lower != db.end() && lower->first == key)
		value = lower->second;
	else if (lower == db.end())
	{
		lower--;
		value = lower->second;
	}
	else if (lower != db.begin())
	{
		prev = lower--;
		if (key.compare(prev->first) > 0)
			value = prev->second;
		else
			value = lower->second;
	}
	else
		value = lower->second;
	return std::atof(value.c_str());
}

bool BitcoinExchange::isDecimal(std::string const &value)
{
	size_t pos = value.find(".");
	std::string::const_iterator it = value.begin();

	if (*it == '-')
		it++;
	if (*it == '.') return false;
	while (it != value.end())
	{
		if (pos != std::string::npos && *it == '.')
		{
			pos = -1;
			it++;
			continue;
		}
		else if (!std::isdigit(*it)) return false;
		it++;
	}
	return true;
}

void	BitcoinExchange::loadDB(void)
{
	std::ifstream	dbFile;
	std::string 	line;
	size_t pos;

	dbFile.open("data.csv", std::ifstream::in);
	if (!dbFile.is_open()) throw InvalidFile();
	std::getline(dbFile, line);
	while (std::getline(dbFile, line))
	{
		pos 			  = line.find(",");
		if (pos != 10 || pos == std::string::npos)
			throw InvalidFile();
		std::string key   = line.substr(0, pos);
		std::string value = line.substr(pos + 1, line.size());
		db.insert(std::make_pair(key, value));
	}
}

bool BitcoinExchange::isLeapYear(int year)
{
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

bool BitcoinExchange::isDateValid(std::string const &key)
{
	int lastDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	std::istringstream is(key);
	char delimiter;
	int date[3];

	for (int i = 0; i < 3; i += 1)
	{
		is >> date[i] >> delimiter;
		if (delimiter != '-') return false;
	}
	if ((date[1] < 1 || date[1] > 12) || date[0] < 1900 || date[0] > 2100)
		return false;
	if (date[1] == 2 && isLeapYear(date[0]))
		lastDay[1] = 29;
	if (date[2] < 1 || date[2] > lastDay[date[1] - 1])
		return false;
	return true;
}

void	BitcoinExchange::evalInput(void)
{
	std::string line;
	char delimiter;
	double val;

	std::getline(inFile, line);
	while (std::getline(inFile, line))
	{
		std::stringstream ss(line);
		std::string key;

		ss >> key >> delimiter;
		if (key.size() == 0) continue;
		std::string value;
		ss >> value;
		std::stringstream ss2(value);
		
		ss2 >> val;
		if (delimiter != '|' || ss2.fail() || !isDateValid(key) || !isDecimal(value))
		{
			std::cout << "Error: bad input => " << key << "." << std::endl;
		}
		else if (val > 1000)
		{
			std::cout << "Error: too large a number." << std::endl;
		}
		else if (val < 0)
		{
			std::cout << "Error: not a positive number." << std::endl;
		}
		else
		{
			const double closestValue = getClosestValue(key);
			std::cout << key << " => " << val << " = " << (closestValue * val) << std::endl;
		}
	}
}

BitcoinExchange::~BitcoinExchange(void)
{
	this->inFile.close();
}
