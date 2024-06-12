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
	//std::vector<int> S;
	std::vector<int> vec;
	std::list<int>   lst;
	int	last;

	double timestamp[2];

// 	// time
// 	std::clock_t	start;
// 	std::clock_t	end;

	bool isPositive(std::string const &arg);
	bool isEven(int size);

	typedef void (PmergeMe::*fpSort)(void);

public:

	PmergeMe(void);
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &pmergeme);
	PmergeMe	&operator=(const PmergeMe &pmergeme);
	~PmergeMe(void);


	double  time(std::clock_t start, std::clock_t end);
	void	sortVector(void);
	void	sortList(void);

	std::vector<int> mergeInsertionSort(void);

	void	print(const char *str, double time, size_t size);
	void	info(void);

	template<class T>
	void	binarySearchInsert(T &mainChain, T &pend);
	

	template<class R, class T>
	R	makePairs(T &c);

};
#endif // PMERGEME_HPP
