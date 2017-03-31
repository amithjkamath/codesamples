//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 11.5 on page 226
//  Test driver for a BinarySearchTree class

int main()
{ BinarySearchTree t;
  t.insert("oats");
  t.insert("corn");
  t.insert("peas");
  t.insert("tuna");
  t.insert("beer");
  t.insert("pork");
  t.insert("eggs");
  t.insert("wine");
  t.print();
  cout << "Searching for okra: " << t.search("okra") << "\n";
  t.insert("okra");
  t.print();
  cout << "Searching for okra: " << t.search("okra") << "\n";
}
