#include <algorithm>  // defines the find() function
#include <iostream>
#include <sstream>  // defines ostringstream class
#include <list>  // defines list class template
#include <queue>  // defines queue class template
using namespace std;

template <class T>
class Tree
{ protected:
    struct Node;
    typedef list<Node*> NPList;
    typedef NPList::iterator NPLIt;
    NPList _nodes;                        // list of tree elements
  public:
    class Iterator;
    Tree() : _nodes(NPList()) { }  
    Tree(const T& t) { _nodes.push_back(new Node(t)); }
    bool empty() const { return _nodes.empty(); }
    int size() const { return _nodes.size(); }
    int height() const;
    int level(Iterator) const;
    const T& root() const { return _nodes.front()->_; }
    void clear() { _nodes.clear(); }
    void print() const;  // level order
    bool isYoungest(Iterator);    // youngest sibling
  protected:
    static int height(Node*);         // recursive helper function
    static string toString(Node*);    // recursive helper function
    Node* read(istream&,Node*);       // recursive helper function
    struct Node
    { T _;
      Node* _parent;
      NPList _children;
      Node(T t=T()) : _(t), _parent(this), _children(NPList()) {}
    };
    typedef NPList::iterator NPLIt;
    friend ostream& operator<<(ostream& ostr, const Tree& t)
    { if (t._nodes.empty()) return ostr << "";
      else return ostr << toString(t._nodes.front());
    }
    friend istream& operator>>(istream& istr, Tree& t)
    { t._nodes.clear();
      t.read(istr,0);
      return istr;
    }
  public:
    friend class Iterator;                   // preorder traversal
    class Iterator                  // preorder traversal
    {   friend class Tree;
      protected:
        Node* _p;                    // the current node
        NPList& _n;     // the _nodes of the tree being traversed 
      public:
        Iterator(Node* p, NPList& t) : _p(p), _n(t) { }
        Iterator(const Iterator& it) : _p(it._p), _n(it._n) { }
        T& operator*() { return _p->_; }
        bool operator!() { return !_p; }
        void operator=(const Iterator& it) {_p = it._p; _n = it._n; }
        bool operator==(const Iterator& it) { return _p==it._p; }
        bool operator!=(const Iterator& it) { return _p!=it._p; }
        Iterator& operator++()  // prefix
        { if (_p->_children.empty())
          { Node* p=_p;
            Node* pp=p->_parent;
            if (pp == p) // pp is root
            { _p = 0;
              return *this;
            }
            while (p == pp->_children.back())  // p is youngest child
            { if (pp == pp->_parent) // pp is root
              { _p = 0;
                return *this;
              }
              p = pp;
              pp = p->_parent;
            }
            NPList list = pp->_children;
            NPLIt it = find(list.begin(),list.end(),p);
            _p = *++it;
            return *this;
          }
          else _p = _p->_children.front();
          return *this;
        }
        Iterator operator++(int)  // postfix
        { Iterator it(*this);
          operator++();         // apply prefix increment operator
          return it;
        }
    };
    Iterator begin()
    { if (_nodes.empty()) return end();
      return Iterator(*(_nodes.begin()),this->_nodes);
    }
    Iterator end() { return Iterator(0,this->_nodes); }
};