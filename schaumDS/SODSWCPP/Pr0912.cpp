//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.12 on page 188
//  An isLeaf() function member of the Tree class

bool Tree::isLeaf(Iterator it)
{ return (*it._lit)->_children.empty();
}
