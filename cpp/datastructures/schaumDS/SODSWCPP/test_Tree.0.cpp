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
    PList _list;                            // list of tree elements
  public:
    Tree() : _root(0), _list(PList()) { }  
    Tree(const T&);
    bool empty() const { return _list.empty(); }
    int size() const { return _list.size(); }
//    int height() const { return height(_root); }
    const T& root() const { return *(_list.front()); }
    class Iterator;
  protected:
    static int height(Node*);          // recursive helper function
    static string toString(Node*);     // recursive helper function
    static Node* read(istream&,int&);  // recursive helper function
    struct Node
    { T* _;
      Node* _parent;
      NPList _children;
      Node(T* p=0) : _(p), _parent(this), _children(NPList()) { }
    };
    typedef PList::iterator PLIt;
    typedef NPList::iterator NPLIt;
};

void print(const Tree<char>&);

int main()
{ Tree<char> t;         print(t);
  t = Tree<char>('A');  print(t);
}
///////////////////////////////////////////////////////////////////

template <class T>
Tree<T>::Tree(const T& t)
{ T* p = new T(t);  // clone the element t
  _root = new Node(p);
  _list.push_back(p);
}


void print(const Tree<char>& t)
{ cout << "size=" << t.size();
  if (!t.empty()) cout << ", root=" << t.root();
  cout << "\n";
}

