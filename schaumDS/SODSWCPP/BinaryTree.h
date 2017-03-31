//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  BinaryTree.h
//  Interface for class of binary trees of strings

#ifndef BINARY_TREE_
#define BINARY_TREE_
#include <string>
#include <iostream>
using namespace std;
typedef string Type;

class BinaryTree
{   struct Node;
    Node* _root;
  public:
    class Iterator;                // BinaryTree::Iterator class
    BinaryTree();                         // default constructor
    BinaryTree(const BinaryTree&);           // copy constructor
    BinaryTree(const Type&);             // constructs singleton
    BinaryTree(const Type&, const BinaryTree&, const BinaryTree&);
    ~BinaryTree();                        // destructs all nodes
    BinaryTree& operator=(const BinaryTree& t);   //  assignment
    void clear();                           // empties this tree
    bool empty() const;           // true iff this tree is empty
    int size() const;         // number of elements in this tree
    int leaves() const;       // number of elements in this tree
    int height() const;                   // height of this tree
    int level(Iterator) const;                  // current level
    void reflect();         // swaps all left and right children
    void defoliate();                  // removes all the leaves
    Type& root() const;     // read-write access to root element
    static bool isRoot(Iterator);              // has no parents
    static bool isLeaf(Iterator);             // has no children
    static Iterator parent(Iterator);
    static Iterator leftChild(Iterator);
    static Iterator rightChild(Iterator);
    Iterator begin();        // inorder traversal starts at root
    Iterator end();                   // ends with null iterator
    Iterator find(Iterator, Iterator, const Type&);
    friend class Iterator                  // preorder traversal
    {   BinaryTree* _tree;           // the tree being traversed
        Node* _p;                            // the current node
      public:
        Iterator();                       // default constructor
        Iterator(const Iterator&);           // copy constructor
        Iterator(BinaryTree*, Node* =0);          // constructor
        void operator=(const Iterator& it);        // assignment
        bool operator==(const Iterator& it);         // equality
        bool operator!=(const Iterator& it);       // inequality
        Iterator& operator++();              // prefix increment
        Iterator operator++(int);           // postfix increment
        Type& operator*() const;              // current element
        bool operator!();               // this iterator is null
        friend class BinaryTree;
    };
};

#endif  // BINARY_TREE_
