#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cstring>

template<class T>
class Array
{
	unsigned int _size;
	T *addr;
public:
	Array(void);
	Array(unsigned int n);
	Array(Array &obj);
	Array	&operator=(Array &obj);
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
Array<T>::Array(Array &obj)
{
	this->_size = obj.size();
	this->addr = new T[this->_size];
	for (size_t i = 0; i < this->_size; i += 1)
	{
		this->addr[i] = obj.addr[i];
	}
	//operator=(obj);
}

template<class T>
Array<T> &Array<T>::operator=(Array &obj)
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
	if (idx < 0 || idx >= (int)this->size())
	{
		throw std::out_of_range("index is out of bounds fuck you!");
	}
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