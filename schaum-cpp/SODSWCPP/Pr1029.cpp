//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.29 on page 218
//  A height() function member for the BinaryTree class

int h(Node*);

int BinaryTree::height() const
{ return h(_root);
}

int h(Node* p)
{ if (!p) return -1;
  int hl=h(p->_left);
  int hr=h(p->_right);
  return 1 + max(hl,hr);
}
