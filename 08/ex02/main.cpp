
#include <iostream>
#include <vector>
#include <stack>
#include <list>
#include <cassert>

#define print(e) std::cout << (e) << std::endl;
// TODO: no match a function
// TODO: should we copy original stack to ours?

template<class T>
class MutantStack
{
	std::list<T> list;
public:
	MutantStack(void);
	~MutantStack(void);
	MutantStack(const MutantStack &ms);
	MutantStack &operator=(const MutantStack &ms);

	void	push(const T &value);
	void	pop(void);
	const T	&top() const;
	bool	empty(void) const;
	size_t	size(void) const;

	typedef typename std::list<T>::iterator iterator;
	typename std::list<T>::iterator	begin(void);
	typename std::list<T>::iterator end(void);
};

/* ==================================================
 * = 				Operator overload				=
 * ==================================================
 */
template<class T>
bool	operator==(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() == rhs.top();
}

template<class T>
bool	operator!=(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() != rhs.top();
}

template<class T>
bool	operator<(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() < rhs.top();
}

template<class T>
bool	operator<=(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() <= rhs.top();
}

template<class T>
bool	operator>(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() > rhs.top();
}

template<class T>
bool	operator>=(const MutantStack<T> &lhs, const MutantStack<T> &rhs)
{
	return lhs.top() >= rhs.top();
}

template<class T>
MutantStack<T>::MutantStack(void) {}

template<class T>
MutantStack<T>::MutantStack(const MutantStack &ms)
{
	operator=(ms);
}

template<class T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack<T> &ms)
{
	this->list = ms.list;
}

template<class T>
bool	MutantStack<T>::empty(void) const
{
	return this->list.empty();
}

template<class T>
size_t	MutantStack<T>::size(void) const
{
	return this->list.size();
}

template<class T>
void	MutantStack<T>::push(const T &value)
{
	this->list.push_front(value);
}

template<class T>
void	MutantStack<T>::pop(void)
{
	if (!this->list.empty())
		return;
	this->list.pop_front();
}

template<class T>
const T	&MutantStack<T>::top(void) const
{
	// TODO: check if stack is empty
	return this->list.front();
}

template<class T>
typename std::list<T>::iterator	MutantStack<T>::begin(void)
{
	return this->list.begin();
}

template<class T>
typename std::list<T>::iterator	MutantStack<T>::end(void)
{
	return this->list.end();
}

template<class T>
MutantStack<T>::~MutantStack(void) {}

int main()
{
	MutantStack<int> mstack;
	mstack.push(1337);
	mstack.push(42);
	mstack.push(42 / 2);

	MutantStack<int>::iterator it  = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end(); 

	it++;
	--it;

	while (it != ite)
	{
		print(*it);
		it++;
	}




	return 0;
}