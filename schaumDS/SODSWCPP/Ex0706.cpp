//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.6 page 135
//  The Josephus Problem

#include <iostream>
using namespace std;

class List
{ // circular list of chars
  protected:
    struct Node
    { Node(const char& ch=0) : _ch(ch) { }
      char _ch;
      Node* _next;
    };
    Node* _last;  // points to last node
    int _size;
  public:
    List(int=0);
    friend ostream& operator<<(ostream&, const List&);
    int size() const { return _size; }
    bool empty() const { return _size == 0; }
    char last() const { return _last->_ch; }
    char kill(int);
};

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
  cout << list.last() << " survived.\n";
}

List::List(int n) : _size(n)
{ _last = new Node('A'+n-1);
  Node* p = _last;
  for (int i=0; i<n-1; i++)
    p = p->_next = new Node('A'+i);
  p->_next = _last;
}

ostream& operator<<(ostream& ostr, const List& list)
{ ostr << "\tsize=" << list._size;
  if (list.empty()) cout << ":\t()\n";
  else
  { List::Node* p = list._last->_next;  // first node
    ostr << ": (" << p->_ch;
    for (p = p->_next; p != list._last->_next; p = p->_next)
      ostr << "," << p->_ch;
    ostr << ")\n";
  }
  return ostr;
}  

char List::kill(int k)
{ static Node* p=_last;
  for (int i=0; i<k; i++)  // advance k nodes
    p = p->_next;
  Node* temp=p->_next;
  char killed = temp->_ch;
  p->_next = temp->_next;
  if (temp == _last) _last = p;
  delete temp;
  --_size;
  return killed;
}
