#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

template<class T>
class MutantStack : public std::stack<T>
{
	std::deque<T> dq;
public:

	MutantStack(void);
	MutantStack(const MutantStack &ms);
	MutantStack &operator=(const MutantStack &ms);
	~MutantStack(void);

	void	push(const T &value);
	void	pop(void);
	bool	empty(void) const;
	size_t	size(void) const;

	// iterators
	typedef typename std::deque<T>::iterator 			iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;

	iterator			begin(void);
	iterator 			end(void);
	reverse_iterator	rbegin(void);
	reverse_iterator	rend(void);
};

template<class T>
MutantStack<T>::MutantStack(void) : std::stack<T>() {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack<T> &ms) : std::stack<T>(ms) {}

template<class T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &ms)
{
	std::stack<T>::operator=(ms);
}

template<class T>
void	MutantStack<T>::push(const T &value)
{
	std::stack<T>::push(value);
	dq.push_front(value);
}

template<class T>
void	MutantStack<T>::pop(void)
{
	std::stack<T>::pop();
	dq.pop_front();
}

template<class T>
bool	MutantStack<T>::empty(void) const
{
	return dq.empty();
}

template<class T>
size_t	MutantStack<T>::size(void) const
{
	return dq.size();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return dq.begin();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return dq.end();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return dq.rbegin();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return dq.rend();
}

template<class T>
MutantStack<T>::~MutantStack<T>(void) {}

template<typename T>
void	print(const T &e)
{
	std::cout << e << std::endl;
}

int main(void)
{
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

		std::cout << "--------------------" << std::endl;

		std::stack<float> stack(mstack);

	}

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