//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.34 on page 218
//  An isRoot() function member for the BinaryTree class

bool BinaryTree::isRoot(It it)
{ return bool(_p == _tree._root);
}
