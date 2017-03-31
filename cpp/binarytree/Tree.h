//
// Created by Amith Kamath on 3/13/17.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "Node.h"

template <class T>
class Tree {
public:
    Tree(T* array, unsigned long length);
    Tree(void);

    void insert(T data);
    void remove(T data);
    bool hasData(T data) const;
    Node<T>* find(T data) const;
    Node<T>* findBST(T data) const;


    unsigned long size(void) const;
    void print(void) const;

    ~Tree(void);
private:
    unsigned long _size = 0;
    Node<T>* _root = NULL;
};


#endif //BINARYTREE_TREE_H
