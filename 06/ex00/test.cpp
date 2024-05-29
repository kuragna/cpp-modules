
#include <iostream>

class Test
{
	int	index;
	static const char *types[4];
	enum Type {CHAR, INT, FLOAT, DOUBLE};
public:
	Test() : index(0) {}
	void print(void)
	{
		std::cout << "type -> " << types[index % DOUBLE] << std::endl;
		this->index += 1;
	}
};

const char *Test::types[4] = {"char", "int", "float", "double"};

int main()
{

	Test t;

	while (true)
	{
		t.print();
	}


	return 0;
}