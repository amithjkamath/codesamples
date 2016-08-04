#include <iostream>
#include <vector>

int main(void)
{
std::vector<int> myVector = {1,2,3,4,5,6,7,8,9,10};

auto beg = myVector.begin();
auto end = myVector.end();

for(auto i = beg; i != end; i++)
{
	std::cout << *i << " is the old value" << std::endl;
	*i = (*i % 2 == 1) ? *i*2 : *i;
	std::cout << *i << " is the new value" << std::endl;
}
return 0;
}