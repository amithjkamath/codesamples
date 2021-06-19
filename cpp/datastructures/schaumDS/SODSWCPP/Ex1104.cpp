//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 11.4 on page 226
//  Interface for a BinarySearchTree class

class BinarySearchTree
{   struct Node;
    Node* _root;
  public:
    BinarySearchTree();
    void insert(const Type);
    void print() const;
    Type search(const Type) const;
  protected:
    void insert(Node*&, const Type);
    void print(Node*) const;
    Type search(Node*, const Type) const;
};
