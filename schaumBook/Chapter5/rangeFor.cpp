#include<iostream>
#include<vector>
#include<algorithm>

using std::cout;
using std::endl;

// You can provide a container to your for loop, and it will iterate over it. 
// We cannot use a range for to add elements to a vector (or
// other container). In a range for, the value of end() is cached. If we add elements
// to (or remove them from) the sequence, the value of end might be invalidated


// traditional for equivalent:
 for (auto beg = v.begin(), end = v.end(); beg != end; ++beg)
 {
 auto &r = *beg; // r must be a reference so we can change the element
 r *= 2; // double the value of each element in v
 }

int main(void)
{
std::vector<int> vec;
vec.push_back( 10 );
vec.push_back( 40 );
vec.push_back( 30 );
vec.push_back( 20 );

for (int i : vec )
{ // implicitly knows the length of the array.
    cout << i << endl;
}

std::sort(vec.begin(), vec.end());
//sort ascending.
cout << " sorted and incremented version " << std::endl;
for (int& i : vec ) // pass in the address to be able to modify the contents.
{
    i++; // increments the value in the vector
}
for (int i : vec )
{
    // show that the values are updated
    cout << i << endl;
}

}