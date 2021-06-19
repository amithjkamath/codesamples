//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_BinaryTree.cpp 
//  Test driver for string BinaryTree class

#include "BinaryTree.h"
typedef BinaryTree::Iterator It;
void print(BinaryTree&);

int main()
{ // bottom-up construction:
  BinaryTree left("Davis");               // third constructor
  BinaryTree right("Evans");              // third constructor
  BinaryTree sub("Cohen",left,right);     // fourth constructor
  left = BinaryTree("Gauss");             // third constructor
  BinaryTree null;                        // default constructor
  right = BinaryTree("Foley",left,null);  // fourth constructor
  left = BinaryTree("Baker",null,sub);    // fourth constructor
  BinaryTree t("Adams",left,right);       // fourth
  print(t);
  // test assignment operator:
  right = t;
  print(right);
  It it=t.begin();
  *it = "Zuber";
  print(t);
  print(right);
  // test level():
  for (It it=t.begin(); it != t.end(); ++it)
    cout << "*it = " << *it
         << ", t.level(it) = " << t.level(it)
         << ", isRoot(it)=" << isRoot(it)
         << ", isLeaf(it)=" << isLeaf(it) << "\n";
  // test find():
  It it = t.find(t.begin(), t.end(), "Gauss");
  if (!it) cout << "Gauss not found.\n";
  else cout << "*it = " << *it << "\n";
  it = t.find(t.begin(), it, "Gauss");
  if (!it) cout << "Gauss not found.\n";
  else cout << "*it = " << *it << "\n";
  it = t.find(t.begin(), t.end(), "Quinn");
  if (!it) cout << "Quinn not found.\n";
  else cout << "*it = " << *it << "\n";
  // test parent(), leftChild(), rightChild():
  for (It it=t.begin(); it != t.end(); ++it)
  { cout << "*it = " << *it;
    It itp=parent(it);
    if (!!itp) cout << ", *parent(it) = " << *itp;
    It itl=leftChild(it);
    if (!!itl) cout << ", *leftChild(it) = " << *itl;
    It itr=rightChild(it);
    if (!!itr) cout << ", *rightChild(it) = " << *itr;
    cout << "\n";
  }
  // test leaves():
  cout << "t.leaves() = " << t.leaves() << "\n";// test leaves():
  cout << "t.leaves() = " << t.leaves() << "\n";
  // test reflect():
  t.reflect();
  print(t);
  // test defoliate():
  t.defoliate();
  print(t);
}

void print(BinaryTree& t)
{ if (t.empty()) cout << "The tree is empty\n";
  cout << "size = " << t.size() << "\n";
  cout << "height = " << t.height() << "\n";
  for (It it=t.begin(); it != t.end(); ++it)
    cout << *it << " ";
  cout << "\n-----------------\n";
}
