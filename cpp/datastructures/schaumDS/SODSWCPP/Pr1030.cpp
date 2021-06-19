//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.30 on page 218
//  A level() function member for the BinaryTree class

int l(Node*,It);

int BinaryTree::level(It it)
{ return l(_root,it);
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
