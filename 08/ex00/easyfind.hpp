#ifndef EASY_FIND_HPP
#define EASY_FIND_HPP

#include <iostream>

// TODO: needs to return a reference of `T`
// NOTE: dont use indeces
template<typename T>
int	easyfind(T &c, int value)
{
	if (std::find(c.begin(), c.end(), value) != c.end())
		return value;
	throw std::runtime_error("has not found");
}
#endif  // EASY_FIND_HPP