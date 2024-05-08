#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	// TODO: make sure that const_iterator is not part of c++11
	typedef std::vector<int>::const_iterator iterator;
	unsigned int size;
	std::vector<int> data;
public:
	Span(unsigned N);
	Span(const Span &s);
	Span	&operator=(const Span &s);
	~Span(void);
	void addNumber(int n);
	void addNumber(iterator begin, iterator end);
	int shortestSpan(void);
	int longestSpan(void);
};

#endif  // SPAN_HPP
