#include "RPN.hpp"

RPN::RPN(void) : pos(0) {}

RPN::RPN(std::string const &expr) : expr(expr), pos(0)
{
	trim();
}

RPN::RPN(RPN const &obj)
{
	operator=(obj);
}

RPN	&RPN::operator=(RPN const &obj)
{
	if (this != &obj)
	{
		this->expr  = obj.expr;
		this->pos   = obj.pos;
		this->stack = obj.stack;
	}
	return *this;
}

RPN::~RPN(void) {}

bool RPN::isToken(int t) const
{
	return std::string("+-*//").find_first_of(t) != std::string::npos;
}

char RPN::peak(void) const
{
	return expr[pos];
}

bool RPN::isEnd(void) const
{
	return pos == expr.size();
}

void	RPN::trim(void)
{
	while (!isEnd() && std::isspace(expr[pos]))
	{
		pos += 1;
	}
}

std::string RPN::next(void)
{
	std::string str;

	while (!isEnd() && !isToken(expr[pos]) && !std::isspace(expr[pos]))
	{
		str += expr[pos];
		pos += 1;
	}
	return str;
}

bool	RPN::isNumber(std::string &str)
{
	size_t i = 0;
	while (i < str.size())
	{
		if (!std::isdigit(str[i])) return false;
		i += 1;
	}
	return true;
}

void	RPN::eval(void)
{
	std::string str;

	if (isEnd()) return;

	while (!isEnd())
	{
		if (!isToken(peak()))
		{
			str = next();
			if (!isNumber(str)) throw std::runtime_error("Error");
			stack.push(std::atoi(str.c_str()));
		}
		char opr = peak();
		if (isToken(opr))
		{
			if (stack.size() < 2) throw std::runtime_error("Error");
			int	left  = stack.top(); stack.pop();
			int	right = stack.top(); stack.pop();
			switch (opr)
			{
				case '+': stack.push(right + left); break;
				case '-': stack.push(right - left); break;
				case '*': stack.push(right * left); break;
				case '/': stack.push(right / left); break;
			}
			pos += 1;
		}
		trim();
	}
	if (stack.size() != 1) throw std::runtime_error("Error");
	std::cout << stack.top() << std::endl;;
}

