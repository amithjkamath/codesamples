//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_BinarySearchTree.cpp 
//  Test driver for string BinaryTree class

#include "BinarySearchTree.h"

int main()
{ BinarySearchTree t;
  t.insert("oats");
  t.insert("corn");
  t.insert("peas");
  t.insert("tuna");
  t.insert("beer");
  t.insert("pork");
  t.print();
  cout << "Searching for okra: " << t.search("okra") << "\n";
  t.insert("okra");
  t.print();
  cout << "Searching for okra: " << t.search("okra") << "\n";
}
