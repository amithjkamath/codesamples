//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  test_Date.h
//  Test driver for the Date class

#include <fstream>
#include <iomanip>
#include "Date.h"

ofstream fout("Dates.dat");
void printDates();
void print(int);

int main()
{ //printDates();
  Date d(145500);
  cout << "d = " << d << endl;
  cout << "d-365 = " << d-365 << endl;
  cout << "d+7 = " << d+7 << endl;
  cout << "d + 1000 - d = " << d + 1000 - d << endl;
  cout << "d = " << d << endl;
  cout << "++d = " << ++d << endl;
  cout << "d++ = " << d++ << endl;
  cout << "d = " << d << endl;
  cout << "--d = " << --d << endl;
  cout << "d-- = " << d-- << endl;
  cout << "d = " << d << endl;
  d += 365;
  cout << "d = " << d << endl;
  d -= 365;
  cout << "d = " << d << endl;
  cout << "Date::Y2K = " << Date::Y2K << endl;
  cout << "Date::today() = " << Date::today() << endl;
  print(143341);  // Tue Jun 15 1993
  print(136000);  // Tue Jun 15 1993
  cout << "Date(145584) = " << Date(145584) << endl;
  cout << "Date(135530) = " << Date(135530) << endl;
  cout << "145584 - 135530 = " << 145584 - 135530 << endl;
}


void printDates()
{ print(     0);  // Mon Jan  1 1601
  print(     1);  // Mon Jan  1 1601
  print(     2);  // Tue Jan  2 1601
  print(    31);  // Wed Jan 31 1601
  print(    32);  // Thu Feb  1 1601
  print(    59);  // Wed Feb 28 1601
  print(    60);  // Thu Mar  1 1601
  print(   365);  // Mon Dec 31 1601
  print(   366);  // Tue Jan  1 1602
  print( 17328);  // Wed Jun 10 1648
  print( 36524);  // Fri Dec 31 1700
  print( 36525);  // Sat Jan  1 1701
  print( 73048);  // Wed Dec 31 1800
  print( 73049);  // Thu Jan  1 1801 
  print(109572);  // Mon Dec 31 1900
  print(109573);  // Tue Jan  1 1901
  print(143341);  // Tue Jun 15 1993
  print(145731);  // Fri Dec 31 1999
  print(144326);  // Sun Feb 25 1996
  print(145518);  // Tue Jun  1 1999
  print(145731);  // Fri Dec 31 1999
  print(145732);  // Sat Jan  1 2000
  print(146097);  // Sun Dec 31 2000
  print(146098);  // Mon Jan  1 2001
  print(146128);  // Wed Jan 31 2001
  print(146129);  // Thu Feb  1 2001
  print(146157);  // Wed Feb 28 2001
  print(146158);  // Thu Mar  1 2001
  print(146462);  // Mon Dec 31 2001
  print(146463);  // Thu Jan 31 2002
  print(146521);  // Thu Feb 28 2002
  print(146522);  // Fri Mar  1 2002
  print(146827);  // Tue Dec 31 2002
  print(146828);  // Wed Jan  1 2003
}

void print(int d)
{ Date date(d);
  string s = date.toString();
  fout << setw(8) << d << " = " << date << "\t= "
       << s << "\t= " << setw(8) << date.day() << "\n";
}
