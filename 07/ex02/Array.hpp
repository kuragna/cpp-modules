#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<class T>
class Array
{
	unsigned int _size;
	T *addr;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &obj);
	Array	&operator=(const Array &obj);
	T		&operator[](int idx);
	~Array(void);
	unsigned int size(void) const;
};

template<class T>
Array<T>::Array(void)
{
	this->_size = 1;
	this->addr  = new T[this->_size];
}

template<class T>
Array<T>::Array(unsigned int n)
{
	this->_size = n;
	this->addr  = new T[n];
}

template<class T>
Array<T>::Array(const Array &obj)
{
	this->_size = obj.size();
	this->addr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i += 1)
	{
		this->addr[i] = obj.addr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=(const Array &obj)
{
	this->_size = obj.size();
	delete[] this->addr;
	this->addr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i += 1)
	{
		this->addr[i] = obj.addr[i];
	}
	return *this;
}

template<class T>
T	&Array<T>::operator[](int idx)
{
	if (idx < 0)
		throw std::underflow_error("underflow_error");
	if (idx >= (int)this->size())
		throw std::overflow_error("overflow_error");
	return this->addr[idx];
}

template<class T>
Array<T>::~Array(void)
{
	delete[] this->addr;
}

template<class T>
unsigned int Array<T>::size(void) const
{
	return this->_size;
}

#endif  // ARRAY_HPP