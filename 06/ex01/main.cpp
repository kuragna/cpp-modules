#include <cstring>
#include <iostream>
#include <stdint.h>

#define print(a) std::cout << (a) << std::endl

// equivalent
// 		*(int*) <- == -> *reinterpret_cast<int*>(anyPointer)
// 		 (int)  <- == ->  static_cast<int>(any regular variable)


// static_cast -> cast from void* to anytype <->
// 			   -> cast from base to derived  <->
// 			   -> cast primitive types		 <->
// 			   -> not allow between diferente pointers type
// dynamic_cast -> works with classes
// 				-> downcast (from derived to base class)

// my name -> 431198398561

struct Data
{
	int	a;
	int	b;
};

class Serializer
{
	Serializer(void);
public:
	static uintptr_t serialize(Data *ptr);
	static Data		 *deserialize(uintptr_t raw);
};

uintptr_t	Serializer::serialize(Data *ptr)
{
	return *reinterpret_cast<uintptr_t*>(ptr);
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data *data = new Data;
	*data = *reinterpret_cast<Data*>(&raw);
	return data;
}
int	main(void)
{
	// from Data to uintptr_t
	Data data = {
		.a = 42,
		.b = 1337,
	};
	uintptr_t raw = Serializer::serialize(&data);
	std::cout << "raw: " << raw << std::endl;

	// from raw data to Data struct
	Data *data2 = Serializer::deserialize(raw);
	std::cout << "a: " << data2->a << std::endl;
	std::cout << "b: " << data2->b << std::endl;

	return 0;
}