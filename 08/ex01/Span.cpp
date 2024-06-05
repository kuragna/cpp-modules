#include "Span.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>
#include <limits>

Span::Span(void) : size(0), isSorted(false) {}

Span::Span(unsigned int N) : size(N), isSorted(false) {}

Span::Span(const Span &s)
{
	operator=(s);
}

Span	&Span::operator=(const Span &s)
{
	this->size  = s.size;
	this->items = s.items;
	return *this;
}

void	Span::addNumber(int n)
{
	if (items.size() >= size)
	{
		throw std::length_error("std::length_error");
	}
	items.push_back(n);
}

void	Span::addNumber(iterator begin, iterator end)
{
	for (; begin != end; begin += 1)
	{
		this->addNumber(*begin);
	}
}

int Span::shortestSpan(void)
{
	int re = std::numeric_limits<int>::max();

	if (items.size() < 2)
	{
		throw std::length_error("std::length_error");
	}

	if (!isSorted)
	{
		std::sort(items.begin(), items.end());
		isSorted = true;
	}

	for (size_t i = 1; i < items.size(); i += 1)
	{
		int	dis = std::abs(items[i] - items[i - 1]);
		if (dis < re) re = dis;
	}
	return re;
}

int Span::longestSpan(void)
{
	if (items.size() < 2)
	{
		throw std::length_error("std::length_error");
	}
	if (!isSorted)
	{
		std::sort(items.begin(), items.end());
		isSorted = true;
	}
	return std::abs(items[0] - items[items.size() - 1]);
}

Span::~Span(void) {}
