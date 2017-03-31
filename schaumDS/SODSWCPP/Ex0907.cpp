//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 9.7 on page 182
//  The bottom-up construction of a binary tree

int main()
{ TList tlist;
  tlist.push_back(new Tree("Cohen"));
  tlist.push_back(new Tree("Davis"));
  tlist.push_back(new Tree("Evans"));
  Tree t0("Baker",tlist);
  tlist.clear();
  tlist.push_back(new Tree("Gauss"));
  Tree t1("Foley",tlist);
  tlist.clear();
  tlist.push_back(&t0);
  tlist.push_back(&t1);
  Tree t("Adams",tlist);
  for (It it=t.begin(); it!=t.end(); it++)
    cout << *it << " ";
  cout << "\n";
}
