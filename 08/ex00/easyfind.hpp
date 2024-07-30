#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>
#include <algorithm>

template<class T>
typename T::iterator easyfind(T &c, const int &value)
{
	return std::find(c.begin(), c.end(), value);
}

#endif  // EASY_FIND_HPP