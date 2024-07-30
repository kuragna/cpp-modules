#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void	iter(T *p, const int size, void (*fptr)(T &e))
{
	for (int i = 0; i < size; i += 1)
	{
		fptr(p[i]);
	}
}	

#endif  // ITER_HPP