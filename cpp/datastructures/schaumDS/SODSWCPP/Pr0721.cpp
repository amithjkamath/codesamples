//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 2000
//  Problem 7.21 on page 148
//  A toDouble() funtion for the Integer class

double Integer::toDouble() const
{ if (_.size()==0) return 0.0;
  Integer::CRIt it=_.rbegin();  // last element of _ list
  double t=double(*it++);
  while (t<DBL_MAX-RADIX && it!=_.rend())
    t = RADIX*t + double(*it++);
  if (it==_.rend()) return (_neg?-t:t);
  else return 0.0;
}
