//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.20 on page 148
//  A toInt() funtion for the Integer class

int Integer::toInt() const
{ if (_.size()==0) return 0;
  int n=_.front();
  return (_neg?-n:n);
}
