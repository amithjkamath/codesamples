//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.38 on page 218
//  A rightChild() function member for the BinaryTree class

It BinaryTree::rightChild(It it)
{ Node* p=it._p;
  if (!p || p->_right) return It(it._tree,p->_right);
  return It(it._tree,0);
}
