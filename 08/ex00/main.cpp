#include "easyfind.hpp"
#include <vector>
#include <list>
#include <queue>
#include <algorithm>

void	print(const int &e)
{
	std::cout << e << std::endl;
}

int main(void)
{
	// Vector 
	std::vector<int> vec;
	vec.push_back(42);
	vec.push_back(1337);
	vec.push_back(1010);

	std::for_each(::easyfind(vec, 1337), vec.end(), print);
	std::cout << "--------------------" << std::endl;

	// List
	std::list<int> list;
	list.push_back(1);
	list.push_back(2);

	std::for_each(::easyfind(list, 1), list.end(), print);
	std::cout << "--------------------" << std::endl;

	// Deque
	std::deque<int> deque;
	deque.push_back(10);
	deque.push_back(0xff);

	std::for_each(::easyfind(deque, -1), deque.end(), print);

	return 0;
}