#include <iostream>
#include <cstdlib>

class Base
{
public:
	virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};

Base *genrate(void)
{
	switch (std::rand() % 3)
	{
	case 0: return new A();
	case 1: return new B();
	case 2: return new C();
	}
	return NULL;
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	identify(&p);
}

int main()
{
	std::srand(time(NULL)); // to get differente random number from prev one
	
	// create random object of A, B, or C.
	for (int i = 0; i < 10; i += 1)
	{
		Base *base = genrate();
		identify(base);
		delete base;
	}
	return 0;
}