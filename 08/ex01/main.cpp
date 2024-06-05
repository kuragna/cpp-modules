#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdlib>

int main(void)
{
	// subject's example
	std::srand(time(NULL));
	
	Span sp(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan()  << std::endl;

	std::cout << "--------------------------" << std::endl;

	//////////////////////////////////////////////////
	
	// test with 10 000
	int	size = 10000;
	std::vector<int> vec;

	while (true)
	{
		if (vec.size() == (size_t)size)
			break ;
		int	value = std::rand() % size;
		if (value)
			vec.push_back(value);
	}

	{
		Span sp(10001);

		sp.addNumber(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << "--------------------------" << std::endl;

	// add numbers more than size
	{
		Span sp(4);
		try {
			sp.addNumber(1);
			sp.addNumber(1);
			sp.addNumber(1);
			sp.addNumber(1);
			sp.addNumber(1);
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << "--------------------------" << std::endl;
	
	// call Span::shortestSpan and Span::longestSpan with less than 2
	{
		Span sp(4);
		sp.addNumber(-1);
		try {
			std::cout << sp.shortestSpan() << std::endl;
			//std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	} 
	
	std::cout << "--------------------------" << std::endl;

	// another test
	{
		std::vector<int> vec;
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(7);
		vec.push_back(29);
		vec.push_back(13);
		vec.push_back(5);
		vec.push_back(11);
		vec.push_back(19);
		vec.push_back(17);
		vec.push_back(23);

		Span sp(10);
		sp.addNumber(vec.begin(), vec.end());

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	

	return 0;
}