#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>

class Span
{
	typedef std::vector<int>::iterator iterator;
	unsigned int size;
	std::vector<int> items;
	bool	isSorted;
public:
	Span(void);
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
