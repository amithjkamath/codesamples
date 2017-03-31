#include <iostream>
#include "Tree.h"

int main() {
    std::cout << " Binary Tree example, " << __FILE__ << " compiled on " << __DATE__ << " at " << __TIME__ << std::endl;
    /*
    Node<int> root =  Node<int>(5);
    Node<int> leftChild = Node<int>(4);
    Node<int> rightChild = Node<int>(7);

    std::cout << root.getData() << std::endl;
    root.setLeft(&leftChild);
    root.setRight(&rightChild);
    std::cout << root.getLeft()->getData() << std::endl;
    std::cout << root.getRight()->getData() << std::endl;
    root.getRight()->setData(9);
    std::cout << root.getRight()->getData() << std::endl;
    */

    int testArray[10] = {4, 2, 6, 3, 8, 5, 9, 7, 0, 1};
    Tree<int> testTree = Tree<int>(testArray, 10);
    testTree.print();
    std::cout << testTree.hasData(-1) << std::endl;
    testTree.insert(-1);
    testTree.print();
    testTree.insert(100);
    testTree.print();

    std::cout << testTree.hasData(8) << std::endl;
    std::cout << testTree.hasData(4) << std::endl;
    std::cout << testTree.hasData(-1) << std::endl;
    std::cout << testTree.hasData(31) << std::endl;
    std::cout << testTree.hasData(100) << std::endl;
    return 0;
}