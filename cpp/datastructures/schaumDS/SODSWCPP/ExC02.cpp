// Data Structures with C++ by John R. Hubbard
// Copyright McGraw-Hill 2000
// Example C.2, page287-8
// Using a Reverse Iterator on a vectoe Object

#include <iostream>
#include <vector>
using namespace std;
typedef vector<int>::reverse_iterator RIt;

int main()
{
  vector<int> v(4);
  for (int i=0; i<4; i++)
    v[i] = 222*i + 333;
  cout << "Using the iterator it in a for loop:\n";
  for (RIt rit=v.rbegin(); rit != v.rend(); rit++)
    cout << "\t*rit=" << *rit << "\n";
  cout << "Using the iterator p in a while loop\n";
  RIt rp=v.rbegin();
  while(rp!=v.rend())
  cout << "\t*rp++=" << *rp++ << "\n";
}
