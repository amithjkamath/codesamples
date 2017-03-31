//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  BinarySearchTree.h
//  Interface for class of binary search trees of strings

#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_
#include <iostream>
using namespace std;
typedef string Type;

class BinarySearchTree
{ public:
    BinarySearchTree();
    void insert(const Type);
    void print() const;
    Type search(const Type) const;
  protected:
    struct Node;
    Node* _root;
    void insert(Node*&, const Type);
    void print(Node*) const;
    Type search(Node*, const Type) const;
};

#endif  // BINARY_SEARCH_TREE_
