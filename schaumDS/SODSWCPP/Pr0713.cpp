//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.13 on page 148
//  The List Sort algorithm

#include "OrderedList.hpp"  // See Example 7.7 on page 137

template <class T, class It>
void sort(It it1, It it2);

int main()
{ char* p="GAJBHCHDIEFAGDHC";
  cout << p << '\n';
  sort(p,p+16);
  cout << p << '\n';
}

template <class T, class It>
void sort(It it1, It it2)
{ OrderedList<T> sorter;
  for (It it=it1; it!=it2; it++)
    sorter.add(*it);
  copy(sorter.begin(),sorter.end(),it1);
}
