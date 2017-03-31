//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.18 on page 188
//  An isYoungestChild() function member of the Tree class

bool Tree::isYoungestChild(Iterator it)
{ Node* p=(*it._lit);
  if (p == p->_parent) return true;       // *p is the root
  return (p == p->_parent->_children.back());
}
