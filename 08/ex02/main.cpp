#include "MutantStack.hpp"
#include <vector>
#include <algorithm>

template<typename T>
void	print(const T &e)
{
	std::cout << e << std::endl;
}

int main(void)
{
	// subject's example
	std::cout << std::boolalpha;

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;
	std::cout << "--------------" << std::endl;

	mstack.pop();

	std::cout << mstack.size() << std::endl;
	std::cout << "--------------" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "--------------------" << std::endl;

	std::stack<int> stack(mstack);

	/////////////////////////

	std::cout << "\n\n";
	{
		MutantStack<float> mstack;

		mstack.push(5.5f);
		mstack.push(17.3f);

		std::cout << mstack.top() << std::endl;
		std::cout << "--------------" << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;
		std::cout << "--------------" << std::endl;

		mstack.push(3.33f);
		mstack.push(5.33f);
		mstack.push(737.22f);
		//[...]
		mstack.push(0.0f);

		MutantStack<float>::iterator it = mstack.begin();
		MutantStack<float>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			it++;
		}


		std::stack<float> stack(mstack);

	}

	std::cout << "--------------------" << std::endl;

	{
		
		std::string arr[] = {"one", "two", "three", "four", "five", "six"};

		std::vector<std::string> vec(arr, arr + 3);
		std::vector<std::string> vec2(arr + 3, arr + 6);


		MutantStack<std::vector<std::string> > nums;
		nums.push(vec);
		nums.push(vec2);

		MutantStack<std::vector<std::string> >::iterator b = nums.begin();
		while (b != nums.end())
		{
			std::vector<std::string> temp = *b;
			std::for_each(temp.begin(), temp.end(), print<std::string>);
			std::cout << std::endl;
			b++;
		}
		
	}

	std::cout << "-----------------" << std::endl;

	{
		MutantStack<int> s;
		MutantStack<int> s2;

		s.push(-1);
		s2.push(42);

		std::cout << s.top() << " < " << s2.top()  << " -> " << (s < s2) << std::endl;
		std::cout << s.top() << " > " << s2.top()  << " -> " << (s > s2) << std::endl;
		std::cout << s.top() << " = " << s2.top()  << " -> " << (s == s2) << std::endl;
		std::cout << s.top() << " <= " << s2.top() << " -> " << (s <= s2) << std::endl;
		std::cout << s.top() << " >= " << s2.top() << " -> " << (s >= s2) << std::endl;
	}
	return 0;
}