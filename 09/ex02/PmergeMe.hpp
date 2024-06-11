#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cctype>

class PmergeMe
{

	std::vector<int> vec;
	std::list<int>   lst;
	int	last;

public:

	PmergeMe(void);
	PmergeMe(char **argv);
	PmergeMe(const PmergeMe &pmergeme);
	PmergeMe	&operator=(const PmergeMe &pmergeme);
	~PmergeMe(void);


	bool isPositive(std::string const &arg);
	bool isEven(int size);

	std::vector<int> mergeInsertionSort(void);
	void merge(std::vector<int> &mainChain, std::vector<int> &pend);

	template<class T>
	void	binarySearchInsert(T &mainChain, T &pend);
	

	template<class R, class T>
	R	makePairs(T &c);
	//std::vector<std::pair<int, int> > makePairs(void);

};
#endif // PMERGEME_HPP
