//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.27 on page 189
//  A reflect() function member for the Tree class

void Tree::reflect()
{ for (LIt lit=_nodes.begin(); lit!=_nodes.end(); lit++)
    (*lit)->_children.reverse();  // std lib function
}
