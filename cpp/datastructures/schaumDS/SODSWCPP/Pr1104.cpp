//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 11.4 on page 231
//  A sorter class for the  BinarySearchTree class

class BSTSorter : public BinarySearchTree
{ public:
    void load(Type*) const;
    void load(Node*, Type*, int&) const;
};

void BSTSorter::load(Type* a) const
{ int i=0;
  load(_root,a,i);
}

void BSTSorter::load(Node* p, Type* a, int& i) const
{ if (!p) return;
  load(p->_left,a,i);
  a[i++] = p->_;
  load(p->_right,a,i);
}
