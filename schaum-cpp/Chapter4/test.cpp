#include<iostream>
#include<vector>

using std::cout;
using std::endl;
int main(void)
{

std::vector<int> vec;

vec.push_back( 10 );
vec.push_back( 20 ); 
vec.push_back( 30 );
vec.push_back( 40 ); 
for (int i : vec )
{
    cout << i << endl;
}
return 0;
}