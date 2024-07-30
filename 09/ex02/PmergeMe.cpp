#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void) {}

PmergeMe::PmergeMe(char **argv) : oddFlag(false), last(0)
{
	for (int i = 0; argv[i]; i += 1)
	{
		if (!isPositive(argv[i]))
			throw std::invalid_argument("invalid_argument");
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
	if (this != &pm)
	{
		this->timestamps[0] = pm.timestamps[0];
		this->timestamps[1] = pm.timestamps[1];
		this->last 		    = pm.last;
		this->vec           = pm.vec;
		this->lst           = pm.lst;
	}
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
		this->last    = c.back();
		this->oddFlag = true;
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
	if (this->oddFlag)
	{
		pos = std::lower_bound(mainChain.begin(), mainChain.end(), this->last);
		mainChain.insert(pos, this->last);
		this->oddFlag = false;
	}
}


void	PmergeMe::sortVector(void)
{
	std::vector<unsigned int> pend;
	std::vector<unsigned int> mainChain;
	std::vector<std::pair<unsigned int, unsigned int> > pairs;
	std::vector<std::pair<unsigned int, unsigned int> >::iterator it;

	pairs = makePairs<std::vector<std::pair<unsigned int, unsigned int> >, std::vector<unsigned int> >(vec);
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
	binarySearchInsert<std::vector<unsigned int> >(mainChain, pend);
	this->vec = mainChain;
}

double	PmergeMe::time(clock_t start, clock_t end)
{
	return 1000.0 * static_cast<double>(end - start) / CLOCKS_PER_SEC;
}

void	PmergeMe::sortList(void)
{
	std::list<unsigned int> pend;
	std::list<unsigned int> mainChain;
	std::list<std::pair<unsigned int, unsigned int> > pairs;
	std::list<std::pair<unsigned int, unsigned int> >::iterator it;

	pairs = makePairs<std::list<std::pair<unsigned int, unsigned int> >, std::list<unsigned int> >(lst);
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
	binarySearchInsert<std::list<unsigned int> >(mainChain, pend);
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
	clock_t start;
	clock_t end;

	std::cout << "Before:  ";
	std::for_each(vec.begin(), vec.end(), printV);
	std::cout << std::endl;

	for (size_t i = 0; i < 2 && size != 1; i += 1)
	{
		start  		  = clock();
		(this->*sorts[i])();
		end    		  = clock();
		timestamps[i] = time(start, end);
	}

	std::cout << "After:   ";
	std::for_each(vec.begin(), vec.end(), printV);
	std::cout << std::endl;

	print("vector",   timestamps[0], size);
	print("list  ",   timestamps[1], size);
}

PmergeMe::~PmergeMe(void) {}

