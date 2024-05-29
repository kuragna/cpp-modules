#ifndef DATA_HPP
#define DATA_HPP

#include <string>
#include <limits>
#include <iostream>
#include <iomanip>

#include <cmath>
#include <cstdlib>
#include <cstring>

class Data
{
	std::string str;
	int	countDecimalNumber;
	int	count;
	static const char *types[5];
	enum Type { CHAR, INT, FLOAT, DOUBLE, NONE };
	Type type;
public:
	Data(const std::string &str);

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

	static void	noOne(void);
};

#endif  // DATA_HPP
