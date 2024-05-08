
#include <iostream>
#include <vector>
#include <cassert>
#include "Span.hpp"

int main(void)
{
	Span sp(2);
	std::vector<int> vec;
	vec.push_back(6);
	vec.push_back(3);
	vec.push_back(17);
	vec.push_back(9);
	vec.push_back(11);
	vec.push_back(2);

	sp.addNumber(vec.begin(), vec.end());




	return 0;
}