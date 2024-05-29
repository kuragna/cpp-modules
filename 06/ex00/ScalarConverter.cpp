#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string const &str)
{
	Data data(str);
	long int	integer;
	long double decimal;

	int	type = data.getType();
	std::cout << "t -> " << data.getType()<< std::endl;
	switch (type)
	{
	case 0: integer = data.getChar();
			data.Char(integer);
			data.Int(static_cast<int>(integer));
			data.Float(static_cast<float>(integer));
			data.Double(static_cast<double>(integer));
			break;
	case 1: integer = data.getIntegr();
			data.Char(static_cast<int>(integer));
			data.Int(integer);
			data.Float(static_cast<float>(integer));
			data.Double(static_cast<double>(integer));
			break;
	case 2: decimal = data.getFloat();
			data.Char(static_cast<int>(decimal));
			data.Int(static_cast<int>(decimal));
			data.Float(decimal);
			data.Double(static_cast<double>(decimal));
			break;
	case 3: decimal = data.getFloat();
			data.Char(static_cast<int>(decimal));
			data.Int(static_cast<int>(decimal));
			data.Float(static_cast<float>(decimal));
			data.Double(decimal);
			break;
	default: Data::noOne();
	}
}
