//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.17 on page 188
//  An isOldestChild() function member of the Tree class

bool Tree::isOldestChild(Iterator it)
{ Node* p=(*it._lit);
  if (p == p->_parent) return true;       // *p is the root
  return (p == p->_parent->_children.front());
}
