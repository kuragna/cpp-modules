
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>

template<class T>
class Base
{
	std::deque<T> list;
public:
	Base() { std::cout << "constructor" << std::endl;}
	void	push(const T &value)
	{
		this->list.push_back(value);
	}
	Base(const Base &base)
	{
		this->list = base.list;
	}
};



int main()
{
	Base<int> stack;
	stack.push(42);
	stack.push(1337);

	std::stack<int> mstack(stack);
	return 0;
}
