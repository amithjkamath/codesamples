//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_OrderedList.cpp
//  Test driver for OrderedList class template

#include "OrderedList.hpp"

template <class T>
ostream& operator<<(ostream&, const list<T>&);

int main()
{ OrderedList<string> instruments;
  instruments.add(string("viola"));
  instruments.add(string("flute"));
  instruments.add(string("cello"));
  instruments.add(string("piano"));
  instruments.add(string("organ"));
  cout << instruments;
}

template <class T>
ostream& operator<<(ostream& ostr, const list<T>& l)
{ ostr << "size=" << l.size();
  if (l.empty()) cout << ":\t()\n";
  else
  { list<T>::const_iterator it=l.begin();
    ostr << ": (" << *it++;
    while (it!=l.end())
      ostr << "," << *it++;
    ostr << ")\n";
  }
  return ostr;
}  
