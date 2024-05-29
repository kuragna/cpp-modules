#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <limits>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cstring>

class Data
{
	std::string str;
	int	countDecimalNumber;
public:
	enum Type { CHAR, INT, FLOAT, DOUBLE, NONE };
	Type type;
	Data(const std::string &str);

	void Decimal(double d, const std::string &s, bool isF);

	bool isInteger(void);
	Type isFloat(void);
	Type getType(void);
	char getChar(void);
	long getIntegr(void);
	double getFloat(void);

	void	Char(long chr);
	void	Double(double d);
	void	Int(long n);
	void	Float(float f);
};

#endif  // DATA_HPP
