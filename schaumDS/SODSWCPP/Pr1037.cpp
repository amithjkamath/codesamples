//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.37 on page 218
//  A leftChild() function member for the BinaryTree class

It BinaryTree::leftChild(It it)
{ Node* p=it._p;
  if (!p || p->_left) return It(it._tree,p->_left);
  return It(it._tree,0);
}
