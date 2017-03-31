//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.15 on page 188
//  A parent() function member of the Tree class

Iterator Tree::parent(Iterator it)
{ Node* p=*it._lit;
  Tree* tree=it._tree;
  if (p->_parent == p) return It(tree,tree->_nodes.end());
  return It(tree,p->_parent);
}
