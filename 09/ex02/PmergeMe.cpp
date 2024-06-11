#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv)
{
	for (int i = 0; argv[i]; i += 1)
	{
		if (!isPositive(argv[i]))
			throw std::invalid_argument("invalid argument");
		int	value = std::atoi(argv[i]);
		vec.push_back(value);
		lst.push_back(value);
	}
}


PmergeMe::PmergeMe(const PmergeMe &pm)
{
	operator=(pm);
}

PmergeMe	&PmergeMe::operator=(const PmergeMe &pm)
{
	this->vec = pm.vec;
	this->lst = pm.lst;
	return *this;
}

bool PmergeMe::isPositive(std::string const &arg)
{
	std::string::const_iterator it = arg.begin();
	if (*it == '+') it++;
	if (!*it) return false;
	while (it != arg.end())
	{
		if (!std::isdigit(*it)) return false;
		it++;
	}
	return true;
}

bool	PmergeMe::isEven(int size)
{
	return (size % 2) == 0;
}

void	printV(const int &e)
{
	std::cout << e << " ";
}

template<class R, class T>
R	PmergeMe::makePairs(T &c)
{
	R	pairs;
	typename T::iterator it  = c.begin();
	typename T::iterator eit = c.end();
	
	while (it != eit)
	{
		int	first  = *it; it++;
		int	second = *it; it++;

		if (first < second)
			std::swap(first, second);

		pairs.push_back(std::make_pair(first, second));
	}

	return pairs;
}

template<class T>
void	PmergeMe::binarySearchInsert(T &mainChain, T &pend)
{
	typename T::iterator pos;
	typename T::iterator it;

	while (it != pend.end())
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
		mainChain.insert(pos, *it);
		it++;
	}
}

// void	binarySearchInsert(std::vector<int> &mainChain, std::vector<int> &pend)
// {
// 	std::vector<int>::iterator pos;

// 	for (size_t i = 0; i < pend.size(); i += 1)
// 	{
// 		int	target = pend[i];
// 		pos = std::lower_bound(mainChain.begin(), mainChain.end(), target);
// 		mainChain.insert(pos, target);
// 	}
// }

void	PmergeMe::merge(std::vector<int> &mainChain, std::vector<int> &pend)
{
	//std::vector<std::pair<int, int> > pairs = makePairs();
	
	last = -1;
	if (!isEven(vec.size()))
	{
		last = vec.back();
		vec.pop_back();
	}

	std::vector<std::pair<int, int> > pairs = makePairs<std::vector<std::pair<int, int> >, std::vector<int> >(vec);

	
	std::sort(pairs.begin(), pairs.end());
	
	mainChain.push_back(pairs[0].second);
	mainChain.push_back(pairs[0].first);

	for (size_t i = 1; i < pairs.size(); i += 1)
	{
		mainChain.push_back(pairs[i].first);
		pend.push_back(pairs[i].second);
	}
	binarySearchInsert(mainChain, pend);
}

std::vector<int> PmergeMe::mergeInsertionSort(void)
{
	std::vector<int> mainChain;
	std::vector<int> pend;
	merge(mainChain, pend);
	
	std::cout << "--- sorted ---\n";
	std::for_each(mainChain.begin(), mainChain.end(), printV);


	return mainChain;
}


PmergeMe::~PmergeMe(void) {}

