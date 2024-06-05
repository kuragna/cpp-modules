
#include <deque>
#include <stack>
#include <iostream>

class Test : public std::stack<int>
{
public:
	void print()
	{
		std::cout << this->c.front() << std::endl;
	}
};

int main(void)
{
	Test t;

	t.push(1);
	t.print();

	return 0;
}