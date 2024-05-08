#include "Span.hpp"
#include <cassert>
#include <iostream>
#include <algorithm>

Span::Span(unsigned int N)
{
	this->size = N;
}

Span::Span(const Span &s)
{
	operator=(s);
}

Span	&Span::operator=(const Span &s)
{
	this->size = s.size;
	this->data = s.data;
	return *this;
}

void	Span::addNumber(int n)
{
	if (this->data.size() >= this->size)
	{
		assert("throw an exception" && 0);
	}
	this->data.push_back(n);
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
	if (this->data.size() < 2)
	{
		assert("throw an exception" && 0);
	}
	assert("not implemented" && 0);
}

int Span::longestSpan(void)
{
	if (this->data.size() < 2)
	{
		assert("throw an exception" && 0);
	}
	assert("not implemented" && 0);
}

Span::~Span(void) {}
