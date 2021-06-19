//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.32 on page 189
//  A prune() function member for the Tree class

void Tree::prune(Iterator it)
{ erase(youngestChild(it));
}
