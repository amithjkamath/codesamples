//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 10.39 on page 218
//  A find() function member for the BinaryTree class

It BinaryTree::find(It begin, It end, const Type& x)
{ BinaryTree* tree=begin._tree;
  Node* p=begin._p;
  while (p != end._p)
    if (p->_ == x) return It(tree,p);
    else p = preorderSuccessor(p);
  return It(this,0);  // not found
}
