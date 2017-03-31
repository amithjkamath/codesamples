//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Example 8.13 on page 167
//  Using A compression hash function

template <class K>
struct Hash
{ // PRECONDITION: K == string
  int operator()(K s)
  { int h=0;
    for (string::const_iterator it=s.begin(); it!=s.end(); it++)
      h = (h<<1)^*it;
    return h;
  }
}
