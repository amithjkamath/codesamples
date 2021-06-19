//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.16 on page 188
//  A numChildren() function member of the Tree class

int Tree::numChildren(Iterator it)
{ return (*it._lit)->_children.size();
}
