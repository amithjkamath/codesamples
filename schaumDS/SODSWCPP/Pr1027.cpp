//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.27 on page 217
//  A size() function member for the BinaryTree class

int s(Node*);

int BinaryTree::size() const
{ return s(_root);;
}

int s(Node* p)
{ if (!p) return 0;
  int nl=s(p->_left);
  int nr=s(p->_right);
  return 1 + nl + nr;
}
