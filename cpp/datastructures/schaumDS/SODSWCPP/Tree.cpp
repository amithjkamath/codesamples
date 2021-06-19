//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Tree.cpp
//  Implementation of string Tree class

#include "Tree.h"
#include <queue>      // defines queue class template
#include <iostream>
using namespace std;
typedef Tree::Type Type;
typedef Tree::List List;
typedef Tree::Node Node;
typedef Tree::Iterator It;
typedef Tree::List::iterator LIt;
typedef Tree::List::const_iterator LCIt;
typedef list<Tree*> TList;
typedef TList::const_iterator TLCIt;
int n(Node*);     // size of subtree
int h(Node*);     // height of sibtree
int l(Node*,It);  // level of *it in subtree
Node* clone(Node*, List&, Node*);

///////////////////////////////////////////////////////////
// definition of protected Tree::Node struct:

struct Tree::Node
{ Type _;
  List _children;
  Node* _parent;
  Node(Type =Type(), Node* =0);
};

Node::Node(Type x, Node* p) : _(x), _parent(p)
{ if (!_parent) _parent = this;
}

///////////////////////////////////////////////////////////
// public member functions of the Tree class:

Tree::Tree()
{
}  

Tree::Tree(const Tree& t)
{ if (t._nodes.empty()) return;
  clone(t._nodes.front(),_nodes,0);
}

Tree::Tree(const Type& x)
{ _nodes.push_back(new Node(x));
}

Tree::Tree(const Type& x, const list<Tree*>& list)
{ Node* root = new Node(x);
  _nodes.push_back(root);
  for(TLCIt it=list.begin(); it!=list.end(); it++)
    if (!((*it)->_nodes).empty())
    { Tree* tp = new Tree(**it);     // duplicate tree **it
      Node* p = tp->_nodes.front();  // points to root of t
      root->_children.push_back(p);      // connect to root
      p->_parent = root;
      LIt lit1=tp->_nodes.begin();
      LIt lit2=tp->_nodes.end();
      LIt lit3=_nodes.end();
      _nodes.insert(lit3,lit1,lit2);  // append *tp's nodes
    }
}

Tree::~Tree()
{ for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    delete *lit;
}

Tree& Tree::operator=(const Tree& t)
{ clear();                               // empty this tree
  Tree* p = new Tree(t);            // use copy constructor
  _nodes = p->_nodes;
  return *this;
}

bool Tree::operator==(const Tree& t) const
{ if (_nodes.size() != t._nodes.size()) return false;
  LCIt tlit=t._nodes.begin();
  for (LCIt lit=_nodes.begin(); lit!=_nodes.end(); lit++, tlit++)
    if ((*lit)->_ != (*tlit)->_) return false;
  return true;
}

bool Tree::operator!=(const Tree& t) const
{ return !(*this == t);
}

void Tree::clear()
{ for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    delete *lit;
  _nodes.clear();
}

bool Tree::empty() const
{ return _nodes.empty();
}

int Tree::size() const
{ return _nodes.size();
}

int Tree::leaves() const
{ return n(_nodes.front());
}

int Tree::height() const
{ return h(_nodes.front());
}

int Tree::level(It it) const
{ return l(_nodes.front(),it);
}

void Tree::print(int n)
{ List list=level(n);
  for (LIt it=list.begin(); it!=list.end(); it++)
    cout << (*it)->_ << " ";
  cout << "\n";
}

void Tree::print()
{ int h=height();
  for (int level=0; level<=h; level++)
    print(level);
}

int Tree::pathLength()
{ int pl=0;
  for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    pl += level(It(this,*lit));
  return pl;
}

int Tree::width(int n)
{ return level(n).size();
}

int Tree::width()
{ if (_nodes.empty()) return 0;               // empty tree
  int w=1;
  for (int k=0; k<=height(); k++)
  { int w1=level(k).size();      // number of nodes at level k
    if (w1>w) w = w1;
  }
  return w;
}

Type& Tree::root() const
{ return _nodes.front()->_;
}

void Tree::reflect()
{ for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    (*lit)->_children.reverse();  // std lib function
}

void Tree::defoliate()
{ if (_nodes.size() < 2)
  { clear();
    return;
  }
  for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
  { Node* p=*lit;
    if (p->_children.empty())
    { p->_parent->_children.clear();
      delete p;
      LIt tmp=lit;
      --lit;    // save location in _nodes list
      _nodes.erase(tmp);
    }
  }
}

It Tree::insert(It it, const Type& x)
{ // new node is new parent of *it
  // _nodes maintains preorder traversal
  Node* np = new Node(x);
  if (!it)              // insert at (preorder) end of tree
  { Node* pp = _nodes.back();
    pp->_children.push_back(np);
    _nodes.push_back(np);
  }
  else
  { Node* p=(*it._lit);
    Node* pp=p->_parent;
    np->_children.push_back(p);
    LIt lit = find(_nodes.begin(),_nodes.end(),p);
    _nodes.insert(lit,np);
    if (pp != p)                      // *p is not the root
    { List& list = pp->_children;
      lit = find(list.begin(),list.end(),p);
      *lit = np;               // make *np the child of *pp
    }
  }
  return It(this,np);
}

void Tree::erase(It it)
{ if (!it) return;
  Node* p=(*it._lit);
  Node* pp=p->_parent;
  if (p->_children.empty())                 // *p is a leaf
  { LIt lit = find(_nodes.begin(),_nodes.end(),p);
    _nodes.erase(lit);
    if (pp != p)                      // *p is not the root
    { List& list = pp->_children;
      lit = find(list.begin(),list.end(),p);
      list.erase(lit);
    }
    delete p;
  }
  else                      // replace *p with oldest child
  { p->_ = p->_children.front()->_;
    erase(It(this,p->_children.front()));
  }
}

It Tree::grow(It it, const Type& x)
{ LIt lit=it._lit;        // locates current node in _nodes
  Node* pp=*lit;
  Node* p=new Node(x,pp);
  pp->_children.push_back(p);
  Node* ppp=pp->_parent;
  List& ppplist=ppp->_children;
  if ( (ppp == pp)                       // *pp is the root
    || (pp == ppplist.back()) )    // or pp is the youngest
  { _nodes.push_back(p);
    lit=find(lit,_nodes.end(),p);
  }
  else                // find next sibling of pp in _nodes:
  { LIt ppplit=find(ppplist.begin(),ppplist.end(),pp);
    ++ppplit;                 // locates next sibling of pp
    lit=find(lit,_nodes.end(),*ppplit);
    lit = _nodes.insert(lit,p);  
  }
  return It(this,lit);
}

void Tree::prune(It it)
{ erase(youngestChild(it));
}

It Tree::attach(It it, Tree& t1)
{ // PRECONDITION: it is an iterator on this tree;
  // if t is empty, it is replaced by t1;
  // if t1 is empty, there is no change;
  // otherwise, if (it == tree.begin()), the root of t1
  //   becomes the new root of t and the old root 
  //   becomes its youngest child; 
  // otherwise, if (it == tree.end()), the root of t1
  //   becomes the youngest child of the root of t; 
  // otherwise, t1 is inserted in front of *it,
  //   becoming its next older sibling;
  // POSTCONDITIONS: t1 returns empty;
  //   it locates the root of the subtree that was t1;
  if (t1._nodes.empty()) return it;  // no change
  // move t1._nodes list into _nodes list:
  LIt lit1=t1._nodes.begin();
  LIt lit2=it._lit;
  Node* p1=*lit1;                   // points to root of t1
  _nodes.insert(lit2,lit1,t1._nodes.end());
  t1._nodes.clear();
  // connect parent and children links:
  if (p1 == _nodes.front())         // *p1 is the new root:
    if (lit2 == _nodes.end()) ;           // tree was empty
    else    // make old root the youngest child of new root
    { Node* p2=*lit2;                 // points to *it node
      (p1->_children).push_back(p2);
      p2->_parent = p1;
    }
  else // root does not change
    if (lit2 == _nodes.end())  // t1 youngest child of root
    { Node* p2=_nodes.front();
      List& pplist=p2->_children;
      pplist.push_back(p1);
      p1->_parent = p2;
    }
    else
    { Node* p2=*lit2;                 // points to *it node
      List& pplist=p2->_parent->_children;
      LIt litp2=litp(p2);           // locates p2 in pplist
      pplist.insert(litp2,p1);
      p1->_parent = p2->_parent;
    }
  return It(this,lit1);
}

void Tree::detach(It it, Tree& t1)
{ // PRECONDITION: it is an iterator on this tree;
  // if t is empty or if (it == tree.end()),
  //   then t is left unchanged and t1 returns empty;
  // if (it == tree.begin()), then t1 is replaced by t
  //   and t returns empty;
  // POSTCONDITIONS: the previous contents of t1 are lost;
  //   t1 contains the nodes that were in the subtree of t
  //   rooted at it;
  t1._nodes.clear();
  if (_nodes.empty() || it == end()) return;    // t1 empty
  if (it == begin())
  { t1._nodes = _nodes;          // copy entire _nodes list
    _nodes.clear();                    // empty _nodes list
    return;
  }
  // move [lit1,lit2[ from _nodes to t1._nodes:
  LIt lit1=it._lit;
  LIt lit2=_nodes.end();
  for (Node* p=*lit1; lit2 == _nodes.end() && p != p->_parent; p = p->_parent)
    lit2=nextSibling(litn(p));
  t1._nodes.insert(t1._nodes.end(),lit1,lit2);
  _nodes.erase(lit1,lit2);
  // reset node pointers to disconnect subtree:
  Node* p1=*lit1;            
  Node* pp=p1->_parent;     
  List& pplist=pp->_children;
  LIt pplit1=litp(p1);      // p1's parent's pointer to *it
  pplist.erase(pplit1);
  p1->_parent = p1;      // *p1 is the root of the sub tree
}

int Tree::generations(It it, It jt)
{ if (!it || !jt) return -1;
  if (it == jt) return 0;
  int n=0;
  Node* p=(*jt._lit)->_parent;
  while (jt != it && p != *jt._lit)
  { Tree* tp=this;
    p=(*jt._lit)->_parent;
    jt = It(tp,p);
    ++n;
  }
  if (jt == it) return n;
  n = generations(jt,it);
  if (n != -1 && !!it && !!jt) return -n;
  return -1;
}

It Tree::begin()
{ return It(this,_nodes.begin());
}

It Tree::end()
{ return It(this,_nodes.end());
}

It Tree::oldestChild(It it)
{ if (!it) return 0;
  Node* p=*it._lit;
  if (!p) return 0;
  Tree* tree=it._tree;
  if (p->_children.empty()) return 0;
  return It(tree,(*it._lit)->_children.front());
}

It Tree::youngestChild(It it)
{ if (!it) return 0;
  Node* p=*it._lit;
  if (!p) return 0;
  Tree* tree=it._tree;
  if (p->_children.empty()) return 0;
  return It(tree,(*it._lit)->_children.back());
}

bool Tree::isRoot(It it)
{ Node* p=*it._lit;
  return it._lit == (it._tree->_nodes).begin();;
}

bool Tree::isLeaf(It it)
{ return (*it._lit)->_children.empty();
}

It Tree::parent(It it)
{ Node* p=*it._lit;
  Tree* tree=it._tree;
  if (p->_parent == p) return It(tree,tree->_nodes.end());
  return It(tree,p->_parent);
}

int Tree::numChildren(Iterator it)
{ return (*it._lit)->_children.size();
}

bool Tree::isOldestChild(It it)
{ Node* p=(*it._lit);
  if (p == p->_parent) return true;       // *p is the root
  return (p == p->_parent->_children.front());
}

bool Tree::isYoungestChild(It it)
{ Node* p=(*it._lit);
  if (p == p->_parent) return true;       // *p is the root
  return (p == p->_parent->_children.back());
}

///////////////////////////////////////////////////////////
//  public member functions of the Tree::Iterator class:

It::Iterator()
{ 
}

It::Iterator(const It& it)
  : _tree(it._tree), _lit(it._lit)
{
}

It::Iterator(Tree* tree, Node* p) : _tree(tree)
{ List& nodes=_tree->_nodes;
  _lit = find(nodes.begin(),nodes.end(),p);
}

It::Iterator(Tree* tree, LIt lit) : _tree(tree), _lit(lit)
{
}

void It::operator=(const It& it)
{ _tree = it._tree;
  _lit = it._lit;
}

bool It::operator==(const It& it)
{ return _tree == it._tree && _lit == it._lit;
}

bool It::operator!=(const It& it)
{ return _tree != it._tree || _lit != it._lit;
}

It& It::operator++()                    // prefix increment
{ ++_lit;
  return *this;
}

It It::operator++(int)        // postfix increment operator
{ It it(*this);                       // copy this iterator
  operator++();                  // increment this iterator
  return it;                             // return the copy
}

Type& It::operator*() const
{ return (*_lit)->_;
}

bool It::operator!()
{ return _lit == _tree->_nodes.end();
}

///////////////////////////////////////////////////////////
//  protected member functions of the Tree class:

List Tree::level(int n)
{ List listn;
  if (empty()) return listn;
  queue<List*> q;
  Node* root=*(_nodes.begin());           // points to root
  if (n==0) return List(1,root);
  q.push(&(root->_children));
  while (!q.empty())
  { List* p=q.front();
    List& list=*p;
    for (LIt lit=list.begin(); lit!=list.end(); lit++)
    { Node* p=*lit;
      It it(this,*lit);
      if (level(it)==n)
        listn.push_back(*lit);
      q.push(&((*lit)->_children));
    }
    q.pop();
  }
  return listn;
}

LIt Tree::litn(Node* p)
{ // returns the LIt for _nodes that locates p:
  if (p == 0) return LIt();  
  return find(_nodes.begin(),_nodes.end(),p);
}

LIt Tree::litp(Node* p)
{ // returns the LIt for p->_parent that locates p:
  if (p == 0 || p == _nodes.front()) return LIt();  
  List& pplist=p->_parent->_children;
  return find(pplist.begin(),pplist.end(),p);
}

LIt Tree::prevSibling(LIt lit)
{ // returns the LIt for _node that locates
  // the next older sibling of *lit
  if (_nodes.empty() || lit==_nodes.begin())
    return _nodes.end();  
  if (lit==_nodes.end()) return _nodes.begin();  
  Node* p1=*lit;
  LIt litp1=litp(p1);
  if (p1 == (p1->_parent->_children).front())
    return _nodes.end();
  return find(_nodes.begin(),--lit,*--litp1);
}

LIt Tree::nextSibling(LIt lit)
{ // returns the LIt for _node that locates
  // the next younger sibling of *lit
  if (lit==_nodes.begin() || lit==_nodes.end())
    return _nodes.end();  
  Node* p2=*lit;
  LIt litp2=litp(p2);
  if (p2 == (p2->_parent->_children).back())
    return _nodes.end();
  return find(++lit,_nodes.begin(),*++litp2);
}

///////////////////////////////////////////////////////////
//  local recursive utility functions:

int n(Node* p)
{ if (!p) return 0;
  List& plist=p->_children;
  if (plist.empty()) return 1;  // *p is a leaf
  int n0=0;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
    n0 += n(*plit);
  return n0;
}

int h(Node* p)
{ if (!p) return -1;  // the empty tree has height -1
  List& plist=p->_children;
  if (plist.empty()) return 0;
  int h0=0;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
  { int h1=h(*plit);
    if (h1>h0) h0 = h1;
  }
  return h0+1;
}

int l(Node* p, It it)
{ if (!p) return -1;  // the empty tree has height -1
  if (p->_ == *it) return 0;         // *it was found
  List& plist=p->_children;
  for (LIt plit=plist.begin(); plit!=plist.end(); plit++)
  { int lc=l(*plit,it);
    if (lc>-1) return lc+1;
  }
  return -1;  // *it is not in this subtree
}

Node* clone(Node* p, List& nodes, Node* pp)
{ // recursive preorder traversal;
  // creates the copy *cp of Node *p,
  // including the duplication of all its descendants
  Node* cp = new Node(p->_,pp);
  nodes.push_back(cp);
  List& l=p->_children;
  List& cl=cp->_children;
  for (LIt lit=l.begin(); lit!=l.end(); lit++)
    cl.push_back(clone(*lit,nodes,cp));
  return cp;
}
