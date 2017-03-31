//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  BSTSorter.h
//  Interface for class of binary search trees of strings
//  that can sort an array

#ifndef BST_SORTER_
#define BST_SORTER_
#include "BinarySearchTree.h"

class BSTSorter : public BinarySearchTree
{ public:
    void load(Type*) const;
//  protected:
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

#endif  // BST_SORTER_
