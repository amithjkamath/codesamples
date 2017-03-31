//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example 7.1 on page 128
//  Using a list of strings

#include <iostream>
#include <list>             // defines list<T> class template
using namespace std;
typedef list<string> List;  // defines List type
typedef List::iterator It;  // defines It type
void print(List&);          // prints a copy of given List

int main()
{ List cars;
  cars.push_back("sugar");   print(cars);
  cars.push_back("dates");   print(cars);
  cars.push_back("wheat");   print(cars);
  cars.push_front("beans");  print(cars);
  cars.push_front("clams");  print(cars);
  cars.sort();               print(cars);
}

void print(List& list)
{ cout << "size=" << list.size();
  if (list.size() == 0) cout << ":\t()\n";
  else
  { It it=list.begin();
    cout << ":\t(" << *it++;
    while (it != list.end())
      cout << "," << *it++;
    cout << ")\n";
  }
}
