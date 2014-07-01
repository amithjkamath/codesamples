#include<iostream>
using std::cout;
using std::endl;


int main(void)
{
unsigned long quiz1 = 0;
int sz = sizeof(quiz1);
unsigned int val = 0;
cout << sz << endl;

for(int i = 0; i < 8*sz; i++)
{
	val = (quiz1 & (1UL << i));
	cout << (val != 0) << " ";
}
cout << endl;

//set bit 27.
quiz1 |= (1UL << 27);

for(int i = 0; i < 8*sz; i++)
{
	val = (quiz1 & (1UL << i));
	cout << (val != 0) << " ";
}
cout << endl;

//set bit 5.
quiz1 |= (1UL << 5);

for(int i = 0; i < 8*sz; i++)
{
	val = (quiz1 & (1UL << i));
	cout << (val != 0) << " ";
}
cout << endl;

//reset bit 27.
quiz1 &= ~(1UL << 27);

for(int i = 0; i < 8*sz; i++)
{
	val = (quiz1 & (1UL << i));
	cout << (val != 0) << " ";
}
cout << endl;

return 0;
}