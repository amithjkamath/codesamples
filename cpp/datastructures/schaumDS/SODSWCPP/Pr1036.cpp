//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.36 on page 218
//  A parent() function member for the BinaryTree class

It BinaryTree::parent(It it)
{ if (isRoot(it)) return It(it._tree,0);
  return It(it._tree,(it._p)->_parent);
}
