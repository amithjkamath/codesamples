//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.31 on page 218
//  A reflect() function member for the BinaryTree class

void r(Node*,It);

void BinaryTree::reflect()
{ return r(_root,it);
}

void r(Node* p)
{ if (!p) return;
  r(p->_left);
  r(p->_right);
  swap(p->_left,p->_right);
}
