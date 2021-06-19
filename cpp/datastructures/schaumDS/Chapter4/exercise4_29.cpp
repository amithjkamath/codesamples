#include<iostream>
using std::cout;
using std::endl;

int main(void)
{
int x[10] = {1,2,3,4,5,6,7,8,9,0}; 
int *p = x;

cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;

return 0;
}