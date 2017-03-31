//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 11.3 on page 231
//  A sort() function for the BinarySearchTree class

void sort(Type* a, int n)
{ BinarySearchTree t;
  for (int i=0; i < n; i++)
    t.insert(a[i]);
  t.load(a);
}

void BinarySearchTree::load(Type* a) const
{ int i=0;
  load(_root,a,i);
}

void BinarySearchTree::load(Node* p, Type* a, int& i) const
{ if (!p) return;
  load(p->_left,a,i);
  a[i++] = p->_;
  load(p->_right,a,i);
}
