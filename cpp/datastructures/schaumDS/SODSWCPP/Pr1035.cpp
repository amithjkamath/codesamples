//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.35 on page 218
//  An isLeaf() function member for the BinaryTree class

bool BinaryTree::isLeaf(It it)
{ Node* p=it._p;
  if (!p || p->_left || p->_right) return false;
  return true;
}
