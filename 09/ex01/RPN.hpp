#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN
{
	std::string expr;
	size_t pos;
	std::stack<int> stack;

public:

	RPN(void);
	RPN(std::string const &expr);
	RPN(RPN const &obj);
	RPN	&operator=(RPN const &obj);
	~RPN(void);

	char peak(void) const;
	bool isToken(int t) const;
	bool isEnd(void) const;
	void trim(void);
	std::string next(void);
	bool	isNumber(std::string &str);
	void	eval(void);
};

#endif // RPN_HPP
