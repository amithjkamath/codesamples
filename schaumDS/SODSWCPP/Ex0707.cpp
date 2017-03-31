//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 7.7 page 137
//  An OrderedList class template

#include <iostream>
#include <list>
#include <string>
using namespace std;

template <class T>
class OrderedList : public list<T>
{ // elements are kept in nondecreasing order
  public:
    void add(const T&);
};

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
void OrderedList<T>::add(const T& t)
{ list<T>::iterator it=begin();
  while (it!=end() && *it<t)
    ++it;
  insert(it,t);
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
