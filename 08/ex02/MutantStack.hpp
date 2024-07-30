#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <deque>
#include <stack>

template<class T>
class MutantStack : public std::stack<T>
{
public:

	MutantStack(void);
	MutantStack(const MutantStack &ms);
	MutantStack &operator=(const MutantStack &ms);
	~MutantStack(void);

	typedef typename std::deque<T>::iterator 			iterator;
	typedef typename std::deque<T>::reverse_iterator	reverse_iterator;
	typedef typename std::deque<T>::const_iterator      const_iterator;

	const_iterator		begin(void) const;
	const_iterator		end() const;
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
	return *this;
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::begin(void)
{
	return this->c.begin();
}

template<class T>
typename MutantStack<T>::iterator MutantStack<T>::end(void)
{
	return this->c.end();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin(void)
{
	return this->c.rbegin();
}

template<class T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend(void)
{
	return this->c.rend();
}


template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::end(void) const
{
	return this->c.end();
}

template<class T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin(void) const
{
	return this->c.begin();
}

template<class T>
MutantStack<T>::~MutantStack<T>(void) {}

#endif // MUTANT_STACK_HPP