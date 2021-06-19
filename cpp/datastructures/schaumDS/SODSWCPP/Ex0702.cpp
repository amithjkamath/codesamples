//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Example 7.2 on page 129
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
    It it1=cars.begin();        // it1 points to beans car
  ++it1;                      // now it1 points to clams car
  *it1 = "ducks";             // changes clams to ducks car
  print(cars);                // now it1 points to ducks car
  cars.insert(it1,3,"beer");  // adds 3 beer cars
  print(cars);                // it1 still points to ducks car
  It it2=cars.end();          // it2 points to dummy end element
  --it2;                      // now it2 points to wheat car
  --it2;                      // now it2 points to sugar car
  --it2;                      // now it2 points to dates car
  cars.erase(it2);            // removes dates car
  print(cars);                // now it2 is undefined
  it2=it1;                    // now it2 points to ducks car
  ++it1;                      // now it1 points to sugar car
  ++it1;                      // now it1 points to wheat car
  cars.splice(it2,cars,it1);  // moves wheat in front of ducks
  print(cars);                // now it1 is undefined
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
