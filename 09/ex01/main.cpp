
#include <stack>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <sys/wait.h>


#define LEN(xs) sizeof(xs) / sizeof(xs[0])


class RPN
{
	std::stack<int> stack;
	std::string expr;
	int	pos;
public:
	RPN(const std::string &expr) : expr(expr), pos(0) {}
	
	void error(void);
	void firstNumbers(void);
	bool checkExpr(void);
	bool isNumber(std::string &str);
	bool isOperator(int c);
	void trim(void);
	std::string next(void);
	int	eval(void);
};

void	RPN::error(void)
{
	std::cerr << "Error: invalid expression: `"
	   		  << expr
		  	  << "`" << std::endl;
	exit(1);
}

bool	RPN::isOperator(int c)
{
	return !!std::strchr("+-*/", c);
}


bool	RPN::isNumber(std::string &str)
{
	int	i = 0;
	if (str[i] == '-' && str.size() > 1) i += 1;
	while (i < str.size())
	{
		if (!std::isdigit(str[i])) return false;
		i += 1;
	}
	return true;
}
void	RPN::trim(void)
{
	while (pos < expr.size() && std::isspace(expr[pos]))
	{
		pos += 1;	
	}
}
std::string RPN::next(void)
{
	std::string str = "";
	trim();
	while (pos < expr.size() && !std::isspace(expr[pos]))
	{
		str += expr[pos];
		pos += 1;
	}
	return str;
}
int		RPN::eval(void)
{
	firstNumbers();
	while (pos < expr.size())
	{
		std::string str = next();
		if (isNumber(str))
		{
			stack.push(std::atoi(str.c_str()));
		}
		else if (isOperator(str[0]) && stack.size() >= 2)
		{
			int	left  = stack.top(); stack.pop();
			int	right = stack.top(); stack.pop();
			switch (str[0])
			{
			case '+': stack.push(right + left); break;
			case '-': stack.push(right - left); break;
			case '*': stack.push(right * left); break;
			case '/': stack.push(right / left); break;
			}
		}
		else error();
	}
	if (stack.size() != 1) error();
	return stack.top();
}

void	RPN::firstNumbers(void)
{
	for (int i = 0; i < 2 && pos < expr.size(); i += 1)
	{
		std::string str = next();
		if (!isNumber(str)) error();
		stack.push(std::atoi(str.c_str()));
		trim();
	}
}

// -2 -2 + valid
// 2 2 +   valid
// 2 + +   invalid
// a	   invalid
// 2 + +   invalid
// 2 a +   invalid
// 2 2 a   invalid








int main(void)
{
	std::string exprs[] = {
		"(1 + 1)"
		"1 + +",
		"a",
		"            1337 ",
		"-2 -2 1 + *",
		"-2 -2 -",
		"1 0 +",
		"3 5 + 7 2 - *",			
		"1 2 + 2 - 2 + 2 4 - +" ,
		"4 4 - 4 +"				,
		"8 9 * 9 - 9 - 9 - 4 - 1 +" ,
		"7 7 * 7 -"				,
		"1 2 * 2 / 2 * 2 4 - +",    
	};
	RPN rpn(exprs[0]);
	std::cout << rpn.eval() << std::endl;

	// 3 5 + 7 2 - *
	// 5 3 +
	// 8 7 2 - *
	// 2 7 8
	// 2 7 -
	// 
	return 0;
}