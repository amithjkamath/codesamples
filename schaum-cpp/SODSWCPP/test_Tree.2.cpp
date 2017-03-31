//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Tree.cpp 
//  Test driver for Tree class template

#include <iostream>
#include <sstream>  // defines ostringstream class
#include <list>
using namespace std;

template <class T>
class Tree
{ protected:
    struct Node;
    typedef list<T*> PList;
    typedef list<Node*> NPList;
    Node* _root;
  public:
    PList _list;                            // list of tree elements
  public:
    Tree() : _root(0), _list(PList()) { }  
    Tree(const T&);
    bool empty() const { return _list.empty(); }
    int size() const { return _list.size(); }
    int height() const { return height(_root); }
    const T& root() const { return *(_list.front()); }
    class Iterator;
  protected:
    static int height(Node*);          // recursive helper function
    static string toString(Node*);     // recursive helper function
    static Node* read(istream&);       // recursive helper function
    struct Node
    { T* _;
      Node* _parent;
      NPList _children;
      Node(T t=T()) : _(new T(t)), _parent(this), _children(NPList()) { }
    };
    typedef PList::iterator PLIt;
    typedef NPList::iterator NPLIt;
  public:
    friend ostream& operator<<(ostream& ostr, const Tree& t)
      { return ostr << toString(t._root); }
    friend istream& operator>>(istream& istr, Tree& t)
      { t._root = read(istr);  return istr; }
};

void print(const Tree<char>&);

int main()
{ Tree<char> t;         print(t);
  t = Tree<char>('A');  print(t);
  string s("A+B+DEF-C+G--");
  istringstream in(s);
  in >> t;         print(t);
  cout << t << "\n" << s << "\n";
  cout << "t._list.size()=" << t._list.size() << "\n";
  cout << "*(t._list.front())=" << *(t._list.front()) << "\n";
  cout << "*(t._list.back())=" << *(t._list.back()) << "\n";
}
///////////////////////////////////////////////////////////////////

template <class T>
string Tree<T>::toString(Node* p)
{ // preorder traversal
  if (!p) return "";
  ostringstream out;
  out << *(p->_);
  NPList list=p->_children;
  if (!list.empty())
  { out << '+';
    for (NPLIt it=list.begin(); it!=list.end(); it++)
      out << toString(*it);
    out << '-';
  }
  return out.str();
}

template <class T>
Tree<T>::Node* Tree<T>::read(istream& istr)
{ // preorder traversal
  Tree<T>::Node* p = new Node(istr.get());
  if (istr.peek() == '+')  // add children to *p
  { istr.ignore();  // eat the '+'
    while (isalpha(istr.peek()))
      (p->_children).push_back(read(istr));
    istr.ignore();  // eat the '-'
  }
  return p;
}

template <class T>
Tree<T>::Tree(const T& t) : _root(new Node(t))
{  _list.push_back(_root->_);
}

template <class T>
int Tree<T>::height(Node* p)
{ if (!p) return -1;
  NPList list=p->_children;
  if (list.empty()) return 0;
  int h=0;
  for (NPLIt it=list.begin(); it!=list.end(); it++)
  { int h1=height(*it);
    if (h1>h) h = h1;
  }
  return h+1;
}

///////////////////////////////////////////////////////////////////

void print(const Tree<char>& t)
{ cout << "size=" << t.size() << ", height=" << t.height();
  if (!t.empty()) cout << ", root=" << t.root();
  cout << "\n";
}
============================================
size=0, height=-1
size=1, height=0, root=A
size=1, height=2, root=A
A+B+DEF-C+G--
A+B+DEF-C+G--
t._list.size()=1
*(t._list.front())=A
*(t._list.back())=A

