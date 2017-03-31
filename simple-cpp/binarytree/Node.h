//
// Created by Amith Kamath on 3/13/17.
//

#ifndef BINARYTREE_NODE_H
#define BINARYTREE_NODE_H

template <class T>
class Node {
public:
    Node(T data);

    T getData(void);
    Node<T>* getLeft(void);
    Node<T>* getRight(void);

    void setLeft(Node<T>* pToNode);
    void setRight(Node<T>* pToNode);
    void setData(T data);

    bool hasLeft(void);
    bool hasRight(void);
    void print(void);
private:
    T _data;
    Node<T>* _left;
    Node<T>* _right;
};


#endif //BINARYTREE_NODE_H
