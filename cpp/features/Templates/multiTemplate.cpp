#include <iostream>

using namespace std;

template <typename T, typename U>
U sum(const T a, const U b) 
{ 
	return a + b;
}

int main(void) 
{
	cout << sum<int, float>(1, 2.5) << endl;
	cout << sum<float, float>(1.5, 2.5) << endl;
	cout << sum<int, double>(1, 2.7) << endl;
	//cout << sum<int, Point>(1, 2.7) << endl;
	return 0;
}