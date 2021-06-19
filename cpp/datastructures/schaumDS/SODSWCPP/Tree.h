//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Tree.h
//  Interface of string Tree class

#ifndef TREE_
#define TREE_
#include <list>
#include <string>
using namespace std;

class Tree
{   struct Node;
    typedef string Type;
    typedef list<Node*> List;
    typedef List::iterator LIt;
    List _nodes;            // list of tree elements in preorder
  public:
    class Iterator;                      // Tree::Iterator class
    Tree();                               // default constructor
    Tree(const Tree&);                       // copy constructor
    Tree(const Type&);                   // constructs singleton
    Tree(const Type&, const list<Tree*>&);         // definition
    ~Tree();                              // destructs all nodes
    Tree& operator=(const Tree& t);           // Tree assignment
    bool operator==(const Tree& t) const;       // Tree equality
    bool operator!=(const Tree& t) const;     // Tree inequality
    void clear();                           // empties this tree
    bool empty() const;           // true iff this tree is empty
    int size() const;        // number of elements in this three
    int leaves() const;         // number of leaves in this tree
    int height() const;                   // height of this tree
    int level(Iterator it) const;   // level of *it in this tree
    int pathLength();                // path length of this tree
    int width(int);            // number of nodes at given level
    int width();              // maximum number among all levels
    void print(int);                  // prints given generation
    void print();                       // level order traversal
    Type& root() const;         // the root element in this tree
    void reflect();
    void defoliate();
    Iterator insert(Iterator, const Type& =Type());   // std lib
    void erase(Iterator);                             // std lib
    Iterator grow(Iterator, const Type&); // adds youngest child
    void prune(Iterator);              // deletes youngest child
    Iterator attach(Iterator, Tree&); // inserts in front of *it
    void detach(Iterator, Tree&);      // removes subtree at *it
    int generations(Iterator,Iterator);  // levels between nodes
    Iterator begin();        // inorder traversal starts at root
    Iterator end();                   // ends with null iterator
    static bool isRoot(Iterator it);          // *it is the root
    static bool isLeaf(Iterator it);            // *it is a leaf
    static bool isOldestChild(Iterator it);
    static bool isYoungestChild(Iterator it);
    static Iterator oldestChild(Iterator);
    static Iterator youngestChild(Iterator);
    static Iterator parent(Iterator it);// locates parent of *it
    static int numChildren(Iterator it);
    friend class Iterator                  // preorder traversal
    {   Tree* _tree;                 // the tree being traversed
        LIt _lit;                            // the current node
      public:
        Iterator();                       // default constructor
        Iterator(const Iterator&);           // copy constructor
        Iterator(Tree*,Node* =0);                 // constructor
        Iterator(Tree*,LIt);                      // constructor
        void operator=(const Iterator& it);        // assignment
        bool operator==(const Iterator& it);         // equality
        bool operator!=(const Iterator& it);       // inequality
        Iterator& operator++();              // prefix increment
        Iterator operator++(int);           // postfix increment
        Type& operator*() const;              // current element
        bool operator!();               // this iterator is null
        friend class Tree;
    };
  protected:
    List level(int n);   // returns list of all nodes at level n
    LIt litn(Node*);   // the _nodes iterator for the given node
    LIt litp(Node*);    // the _parent->_children iterator for "
    LIt prevSibling(LIt);
    LIt nextSibling(LIt);
};

#endif  // TREE_
