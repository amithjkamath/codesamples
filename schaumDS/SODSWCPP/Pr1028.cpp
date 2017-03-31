//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.28 on page 218
//  A leaves() function member for the BinaryTree class

int n(Node*);

int BinaryTree::leaves() const
{ return n(_root);;
}

int n(Node* p)
{ if (!p) return 0;
  if (p->_left == 0 && p->_right == 0) return 1;
  return n(p->_left) + n(p->_right);
}
