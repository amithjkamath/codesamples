//refOverload.cpp
// build as g++ -o refOverload refOverload.cpp
#include <iostream>

enum day {
	Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, not_a_day
	};

day &operator++(day& d)
{
	d = (day)(d+1);
	return d;
}

// This will not work, as we need to call ++&d in main, which is not intuitive.
//day *operator++(day* d)
//{
//	d = day)(*d+1);
//	return d;
//}

// This will not work, because the updated version of d is local to this function.
//day operator++(day d)
//{
//	d = (day)(d+1);
//	return d;
//}

int main(void)
{
	day d = Sunday;
	while(d <= Saturday)
	{
		std::cout << d << std::endl;
		++d;
	}
	return 0;
}