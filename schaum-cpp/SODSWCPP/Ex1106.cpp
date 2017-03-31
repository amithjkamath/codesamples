//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 11.6 on page 227
//  Implementation of string BinarySearchTree class

#include "BinarySearchTree.h"

struct BinarySearchTree::Node
{ Type _;
  Node* _left;
  Node* _right;
  Node(Type =Type(), Node* =0, Node* =0);
};

BinarySearchTree::Node::Node(Type x, Node* left, Node* right)
 : _(x), _left(left), _right(right)
{ 
}

BinarySearchTree::BinarySearchTree() : _root(0)
{
}

void BinarySearchTree::insert(const Type x)
{ insert(_root,x);
}

void BinarySearchTree::print() const
{ print(_root);
  cout << "\n";
}

Type BinarySearchTree::search(const Type x) const
{ return search(_root,x);
}

void BinarySearchTree::insert(Node*& p, const Type x)
{ if (!p) p = new Node(x);
  else if (x == p->_) return;
  else if (x < p->_) return insert(p->_left,x);
  else insert(p->_right,x);
}

void BinarySearchTree::print(Node* p) const
{ if (!p) return;
  print(p->_left);
  cout << p->_ << " ";
  print(p->_right);
}

Type BinarySearchTree::search(Node* p, const Type x) const
{ if (p == 0) return Type();
  else if (x == p->_) return p->_;
  else if (x < p->_) return search(p->_left,x);
  else return search(p->_right,x);
}
