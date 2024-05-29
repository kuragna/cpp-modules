#include "Data.hpp"
#include <cmath>

const char *typess[] = {"char", "int", "float", "double", "none"};

Data::Data(const std::string &str) : str(str), countDecimalNumber(1) {}

char Data::getChar(void)
{
	return str[0];
}

long int Data::getIntegr(void)
{
	return atol(str.c_str());
}

double Data::getFloat(void)
{
	return atof(str.c_str());
}


bool Data::isInteger(void)
{
	std::string::const_iterator it = str.begin();
	if (*it == '+' || *it == '-')
		it += 1;
	for (; it != str.end(); it += 1)
	{
		if (!std::isdigit(*it)) return false;
	}
	return true;
}

Data::Type Data::isFloat(void)
{
	Type type = NONE;
	size_t pos = str.find(".");
	if (std::string::npos != pos)
	{
		countDecimalNumber = str.size() - (pos + 1);
		size_t _pos = str.find("f");
		if (_pos != std::string::npos)
		{
			countDecimalNumber -= 1;
			type = FLOAT;
		}
		else
			type = DOUBLE;
	}
	return type;
}

Data::Type Data::getType(void)
{
	double d;

	if (std::isprint(str[0]) && str.length() == 1)
		return CHAR;
	d = std::atof(str.c_str());
	if (std::isnan(d) || std::isinf(d))
		type = DOUBLE;
	else if (isInteger())
		type = INT;
	else
		type = isFloat();
	return type;
}


void Data::Char(long chr)
{
	const int max = std::numeric_limits<unsigned char>::max();
	const int min = std::numeric_limits<unsigned char>::min();
	
	std::string str = "impossible";

	if (chr >= min && chr <= max)
	{
		str = "Non displayable";
		if (std::isprint(chr))
		{
			str = "'";
			str += static_cast<char>(chr);
			str += "'";
		}
	}
	std::cout << "char: " << str << std::endl;
}

void	Data::Double(double d)
{
	double max = std::numeric_limits<double>::max();
	double min = std::numeric_limits<double>::min();
	
	std::cout << "double: ";
	if (std::isnan(d) || d <= max || d >= min)
	{
		if (this->str.size() < 7)
		{
			std::cout << std::setprecision(countDecimalNumber) << std::fixed;
		}
		std::cout << d << std::endl;
		return;
	}
	std::cout << "impossible" << std::endl;
}

void	Data::Int(long n)
{
	const int max = std::numeric_limits<int>::max();
	const int min = std::numeric_limits<int>::min();

	std::cout << "int: ";
	if (n <= (long)max && n >= (long)min)
	{
		std::cout << n << std::endl;
		return;
	}
	std::cout << "impossible" << std::endl;
}

void	Data::Decimal(double d, const std::string &s, bool isF)
{
	double max = std::numeric_limits<double>::max();
	double min = std::numeric_limits<double>::min();

	if (isF)
	{
		max = std::numeric_limits<float>::max();
		min = std::numeric_limits<float>::min();
	}
	std::cout << s << ": ";
	if (std::isinf(d) ||std::isnan(d) || d >= min || d <= max)
	{
		if (this->str.size() < 7)
		{
			std::cout << std::setprecision(countDecimalNumber) << std::fixed;
		}
		std::cout << d;
		if (isF)
			std::cout << "f";
		std::cout << std::endl;
	}
	else
	{
		std::cout << "impossible" << std::endl;
	}
}

void	Data::Float(float f)
{
	const double max = std::numeric_limits<float>::max();
	const double min = std::numeric_limits<float>::min();
	
	std::cout << "float: ";
	if (std::isinf(f) ||std::isnan(f) ||f >= min || f <= max)
	{
		if (this->str.size() < 7)
		{
			std::cout << std::setprecision(countDecimalNumber) << std::fixed;
		}
		std::cout << f << "f" << std::endl;
		return;
	}
	std::cout << "impossible"<< std::endl;
}
