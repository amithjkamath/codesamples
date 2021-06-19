//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.11 on page 188
//  An isRoot() function member of the Tree class

bool Tree::isRoot(Iterator it)
{ Node* p=*it._lit;
  return it._lit == (it._tree->_nodes).begin();
}
