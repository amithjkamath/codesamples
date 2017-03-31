//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.12 on page 148
//  The Josephus problem

#include <iostream>
#include <list>
using namespace std;
class List : public list<char>
{ // circular list of chars
  public:
    List(int);
    char kill(int);
};
ostream& operator<<(ostream&, const List&);
int main()
{ int n, skip;
  cout << "Enter number of men: ";
  cin >> n;
  List list(n);
  cout << "\t\t" << list;
  cout << "Enter skip number: ";
  cin >> skip;
  while (list.size() > 1)
  { cout << '\t' << list.kill(skip) << " killed" << list;
  }
  cout << list.back() << " survived.\n";
}
List::List(int n)
{ for (int i=0; i<n; i++)
    push_back('A'+i);
}
ostream& operator<<(ostream& ostr, const List& l)
{ ostr << "\tsize=" << l.size();
  if (l.empty()) cout << ":\t()\n";
  else
  { list<char>::const_iterator it=l.begin();
    ostr << ": (" << *it++;
    while (it!=l.end())
      ostr << "," << *it++;
    ostr << ")\n";
  }
  return ostr;
}  
char List::kill(int k)
{ static list<char>::iterator it=begin();
  for (int i=0; i<k; i++)  // advance k elements
    it = ( ++it==end() ? begin() : it );  // circular wrap
  list<char>::iterator jt=it;
  it = ( ++it==end() ? begin() : it );
  char killed = *jt;
  erase(jt);
  return killed;
}
