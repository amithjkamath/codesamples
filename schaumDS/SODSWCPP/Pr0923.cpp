//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 9.23 on page 188
//  A print(int) function member of the Tree class

void Tree::print(int n)
{ List list=level(n);
  for (LIt it=list.begin(); it!=list.end(); it++)
    cout << (*it)->_ << " ";
  cout << "\n";
}
