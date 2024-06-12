#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv) : last(-1)
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
	this->last = pm.last;
	this->vec  = pm.vec;
	this->lst  = pm.lst;
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
	R pairs;
	typename T::iterator it;
	typename T::iterator eit;

	if (!isEven(c.size()))
	{
		this->last = c.back();
		c.pop_back();
	}

	it  = c.begin();
	eit = c.end();
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
	typename T::iterator it = pend.begin();

	while (it != pend.end())
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), *it);
		mainChain.insert(pos, *it);
		it++;
	}
	if (this->last != -1)
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), this->last);
		mainChain.insert(pos, this->last);
		this->last = -1;
	}
}


void	PmergeMe::sortVector(void)
{
	std::vector<int> pend;
	std::vector<int> mainChain;
	std::vector<std::pair<int, int> > pairs;
	std::vector<std::pair<int, int> >::iterator it;

	pairs = makePairs<std::vector<std::pair<int, int> >, std::vector<int> >(vec);
	std::sort(pairs.begin(), pairs.end());
	it = pairs.begin();

	mainChain.push_back((*it).second);
	mainChain.push_back((*it).first);

	it++;
	while (it != pairs.end())
	{
		mainChain.push_back((*it).first);
		pend.push_back((*it).second);
		it++;
	}
	binarySearchInsert<std::vector<int> >(mainChain, pend);
	this->vec = mainChain;
}

double	PmergeMe::time(std::clock_t start, std::clock_t end)
{
	return 100.0 * (end - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sortList(void)
{
	std::list<int> pend;
	std::list<int> mainChain;
	std::list<std::pair<int, int> > pairs;
	std::list<std::pair<int, int> >::iterator it;

	pairs = makePairs<std::list<std::pair<int, int> >, std::list<int> >(lst);
	pairs.sort();
	it = pairs.begin();

	mainChain.push_back((*it).second);
	mainChain.push_back((*it).first);

	it++;
	while (it != pairs.end())
	{
		mainChain.push_back((*it).first);
		pend.push_back((*it).second);
		it++;
	}
	binarySearchInsert<std::list<int> >(mainChain, pend);
}

void	PmergeMe::print(const char *str, double time, size_t size)
{
	std::cout << "Time to process a range of " << size; 
	std::cout << " elements with std::" << str << " : ";
	std::cout << std::fixed << std::setprecision(5) << time << " us";
	std::cout << std::endl;
}

void	PmergeMe::info(void)
{
	const size_t size = vec.size();
	const fpSort sorts[2] = {&PmergeMe::sortVector, &PmergeMe::sortList};
	std::clock_t start;
	std::clock_t end;

	std::cout << "Before:  ";
	std::for_each(vec.begin(), vec.end(), printV);
	std::cout << std::endl;

	for (size_t i = 0; i < 2 && size != 1; i += 1)
	{
		start  		  = std::clock();
		(this->*sorts[i])();
		end    		  = std::clock();
		timestamps[i] = time(start, end);
	}

	std::cout << "After:   ";
	std::for_each(vec.begin(), vec.end(), printV);
	std::cout << std::endl;

	print("vector",   timestamps[0], size);
	print("list  ",   timestamps[1], size);
}

PmergeMe::~PmergeMe(void) {}

