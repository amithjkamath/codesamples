//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_List.cpp 
//  Test driver for the List class

#include "List.hpp"
#include <iostream>
#include <string>
using namespace std;
typedef List<string>::Iterator It;

template <class T>
void print(List<T>&);          // prints a copy of given List

int main()
{ List<string> l1(8);      print(l1);
  List<string> l2(8,"Z");  print(l2);
  List<string> l;          print(l);
  l.push_back("first");    print(l);
  l.push_back("second");   print(l);
  l.push_back("third");    print(l);
  l.push_front("extra");   print(l);
  l.pop_back();            print(l);
  l.pop_front();           print(l);
  It it = l.begin();
  ++it;
  l.insert(it,"A");        print(l);
  ++it;
  l.insert(it,"B");        print(l);
  --it;
  l.insert(it,4,"X");      print(l);
  l.clear();               print(l);
  l.push_back("A");
  l.push_back("B");
  l.push_back("C");
  l.push_back("D");
  l.push_back("E");
  l.push_back("F");
  l.push_back("G");        print(l);
  it=l.end();
  --it;
  l.erase(it);             print(l);
  It i=l.begin();
  ++i;
  It j=l.end();
  --j;
  List<string> l3(i,j);    print(l3);
  l.erase(i,j);            print(l);
  l.clear();               print(l);
  print(l1);
  print(l2);
  print(l3);
  i=l3.begin();
  ++i;
  j=l3.end();
  --j;
  l.splice(i,l3,j);    print(l3);
  j=l2.begin();
  l.splice(i,l2,j);    print(l2);    print(l3);
}

template <class T>
void print(List<T>& l)
{ cout << "size=" << l.size();
  if (l.size()>0)
  { It it=l.begin();
    cout << ":\t(" << *(it++);
    while (it != l.end())
      cout << "," << *it++;
    cout << ")";
  }
  cout << "\n";
}
