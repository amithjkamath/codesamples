//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  BinaryTree.cpp
//  Implementation of string BinaryTree class

#include "BinaryTree.h"
typedef BinaryTree::Node Node;
typedef BinaryTree::Iterator It;
void destroy(Node*);    // postorder deletion for destructor
int s(Node*);
int n(Node*);
int h(Node*);
int l(Node*,It);
void r(Node*);
void d(Node*);
Node* preorderSuccessor(Node*);
Node* clone(Node*,Node*);

///////////////////////////////////////////////////////////
// definition of protected BinaryTree::Node struct:

struct BinaryTree::Node
{ Type _;
  Node* _left;
  Node* _right;
  Node* _parent;
  Node(Type =Type(), Node* =0, Node* =0, Node* =0);
};

BinaryTree::Node::Node(Type x, Node* left, Node* right,
                       Node* parent)
 : _(x), _left(left), _right(right), _parent(parent)
{ if (!_parent) _parent = this;  // the root
}

///////////////////////////////////////////////////////////
// public member functions of the BinaryTree class:

BinaryTree::BinaryTree() : _root(0)
{ 
}  

BinaryTree::BinaryTree(const BinaryTree& t)
{ _root = clone(t._root,0);
}

BinaryTree::BinaryTree(const Type& x)
{ _root = new Node(x);
}

BinaryTree::BinaryTree(const Type& x, const BinaryTree& lTree,
                       const BinaryTree& rTree)
{ _root = new Node(x);
  _root->_left = clone(lTree._root,_root);
  _root->_right = clone(rTree._root,_root);
}

BinaryTree::~BinaryTree()
{ destroy(_root);
}

BinaryTree& BinaryTree::operator=(const BinaryTree& t)
{ clear();                               // empty this tree
  BinaryTree* p = new BinaryTree(t); // use copy constructor
  _root = p->_root;
  return *this;
}

void BinaryTree::clear()
{ destroy(_root);
}

bool BinaryTree::empty() const
{ return _root == 0;
}

int BinaryTree::size() const
{ return s(_root);
}

int BinaryTree::leaves() const
{ return n(_root);
}

int BinaryTree::height() const
{ return h(_root);
}

int BinaryTree::level(It it) const
{ return l(_root,it);
}

void BinaryTree::reflect()
{ r(_root);
}

void BinaryTree::defoliate()
{ if (!_root) return;
  if (_root->_left || _root->_right) d(_root);
  else clear();
}

Type& BinaryTree::root() const
{ return _root->_;
}

bool BinaryTree::isRoot(It it)
{ return it._p == it._tree->_root;
}

bool BinaryTree::isLeaf(It it)
{ Node* p=it._p;
  if (!p || p->_left || p->_right) return false;
  return true;
}

It BinaryTree::parent(It it)
{ if (isRoot(it)) return It(it._tree,0);
  return It(it._tree,(it._p)->_parent);
}

It BinaryTree::leftChild(It it)
{ Node* p=it._p;
  if (!p || p->_left) return It(it._tree,p->_left);
  return It(it._tree,0);
}

It BinaryTree::rightChild(It it)
{ Node* p=it._p;
  if (!p || p->_right) return It(it._tree,p->_right);
  return It(it._tree,0);
}

It BinaryTree::begin()
{ return It(this,_root);
}

It BinaryTree::end()
{ return It(this,0);
}

It BinaryTree::find(It begin, It end, const Type& x)
{ BinaryTree* tree=begin._tree;
  Node* p=begin._p;
  while (p != end._p)
    if (p->_ == x) return It(tree,p);
    else p = preorderSuccessor(p);
  return It(this,0);  // not found
}

///////////////////////////////////////////////////////////
//  public member functions of the BinaryTree::Iterator class:

It::Iterator()
{ 
}

It::Iterator(const It& it) : _tree(it._tree), _p(it._p)
{
}

It::Iterator(BinaryTree* tree, Node* p) : _tree(tree), _p(p)
{
}

void It::operator=(const It& it)
{ _tree = it._tree;
  _p = it._p;
}

bool It::operator==(const It& it)
{ return _tree == it._tree && _p == it._p;
}

bool It::operator!=(const It& it)
{ return _tree != it._tree || _p != it._p;
}

It& It::operator++()                    // prefix increment
{ _p = preorderSuccessor(_p);
  return *this;
}

It It::operator++(int)        // postfix increment operator
{ It it(*this);                       // copy this iterator
  operator++();                  // increment this iterator
  return it;                             // return the copy
}

Type& It::operator*() const
{ return _p->_;
}

bool It::operator!()
{ return _p == 0;
}

///////////////////////////////////////////////////////////
//  local recursive utility functions:

void destroy(Node* p)
{ if (!p) return;
  destroy(p->_left);
  destroy(p->_right);
  delete p;
}

int s(Node* p)
{ if (!p) return 0;
  int nl=s(p->_left);
  int nr=s(p->_right);
  return 1 + nl + nr;
}

int n(Node* p)
{ if (!p) return 0;
  if (p->_left == 0 && p->_right == 0) return 1;
  return n(p->_left) + n(p->_right);
}

int h(Node* p)
{ if (!p) return -1;
  int hl=h(p->_left);
  int hr=h(p->_right);
  return 1 + max(hl,hr);
}

int l(Node* p, It it)
{ if (!p) return -1;
  if (p->_ == *it) return 0;
  int ll=l(p->_left,it);
  if (ll > -1) return 1 + ll;
  int lr=l(p->_right,it);
  if (lr > -1) return 1 + lr;
  return -1;
}

void r(Node* p)
{ if (!p) return;
  r(p->_left);
  r(p->_right);
  swap(p->_left,p->_right);
}

void d(Node* p)
{ // invariant: *p is not a leaf
  Node* lc=p->_left;
  if (lc && (lc->_left || lc->_right)) d(lc);
  else  // *lc is a leaf
  { delete lc;
    p->_left = 0;
  }
  Node* rc=p->_right;
  if (rc && (rc->_left || rc->_right)) d(rc);
  else  // *rc is a leaf
  { delete rc;
    p->_right = 0;
  }
}

Node* preorderSuccessor(Node* p)
{ if (p->_left) return p->_left;
  if (p->_right) return p->_right;
  // move up tree until p is the root or p has a younger sibling
  while (p->_parent!=p
         && (p->_parent->_right==p || p->_parent->_right==0))
    p = p->_parent;
  if (p->_parent==p) return 0;  // p is the root
  return p->_parent->_right;  // younger sibling is successor
}

Node* clone(Node* p,Node* pp)
{ // recursive preorder traversal;
  // returns a duplicate of Node *p,
  // including the duplication of all its descendants
  if (!p) return 0;                  // basis of the recursion
  Node* cp = new Node(p->_,0,0,pp);  // duplicate the current node
  cp->_left = clone(p->_left,cp);    // duplicate the left subtree
  cp->_right = clone(p->_right,cp);  // duplicate the right subtree
  return cp;
}
