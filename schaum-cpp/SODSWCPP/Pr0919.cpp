//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.19 on page 188
//  An oldestChild() function member of the Tree class

Iterator Tree::oldestChild(Iterator it)
{ if (!it) return 0;
  Node* p=*it._lit;
  if (!p) return 0;
  Tree* tree=it._tree;
  if (p->_children.empty()) return 0;
  return It(tree,(*it._lit)->_children.front());
}
