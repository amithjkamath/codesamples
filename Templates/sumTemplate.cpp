#include <iostream>

// templatized function
template <typename T> 
T sum(const T a, const T b) 
{
	return a + b;
}

int main(void)
{
	std::cout << sum<int>(1,2) << std::endl;
	std::cout << sum<float>(1.21,2.43) << std::endl;
	return 0;
}