#include "ScalarConverter.hpp"

const char *types[] = {"char", "int", "float", "double", "none"};

void ScalarConverter::convert(std::string const &str)
{
	Data data(str);
	long int	integer;
	long double decimal;

	Data::Type type = data.getType();
	std::cout << "type -> " << types[type] << std::endl;
	switch (type)
	{
	case Data::CHAR: integer = data.getChar();
					 data.Char(integer);
					 data.Int(static_cast<int>(integer));
					 data.Float(static_cast<float>(integer));
					 data.Double(static_cast<double>(integer));
					 break;
	case Data::INT: integer = data.getIntegr();
					data.Char(static_cast<int>(integer));
					data.Int(integer);
					data.Float(static_cast<float>(integer));
					data.Double(static_cast<double>(integer));
					break;
	case Data::FLOAT: decimal = data.getFloat();
					  data.Char(static_cast<int>(decimal));
					  data.Int(static_cast<int>(decimal));
					  data.Float(decimal);
					  data.Double(static_cast<double>(decimal));
					  break;
	case Data::DOUBLE: decimal = data.getFloat();
					   data.Char(static_cast<int>(decimal));
					   data.Int(static_cast<int>(decimal));
					   data.Float(static_cast<float>(decimal));
					   data.Double(decimal);
					   break;
	default: std::cout << "char: impossible" << std::endl;
			 std::cout << "int: impossible" << std::endl;
			 std::cout << "float: impossible" << std::endl;
			 std::cout << "double: impossible" << std::endl;
	}
}
