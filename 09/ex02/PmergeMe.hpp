#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>
#include <ctime>

class PmergeMe
{
	typedef void (PmergeMe::*fpSort)(void);

	std::vector<int> vec;
	std::list<int>   lst;
	int	last;
	double timestamps[2];


public:

	PmergeMe(void);
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &pmergeme);
	PmergeMe	&operator=(const PmergeMe &pmergeme);
	~PmergeMe(void);

	bool isPositive(std::string const &arg);
	bool isEven(int size);

	void	sortVector(void);
	void	sortList(void);

	double  time(std::clock_t start, std::clock_t end);

	void	print(const char *str, double time, size_t size);
	void	info(void);

	template<class T>
	void	binarySearchInsert(T &mainChain, T &pend);
	

	template<class R, class T>
	R	makePairs(T &c);

};
#endif // PMERGEME_HPP
