//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Problem 1.36 on page 120
//  Prints calendars

#include <iomanip>   // defines setw() and setiosflags() functions
#include <iostream>  // defines cout object
#include <sstream>   // defines ostringstream class
#include "calendar.h"
using namespace std;
string calendar(int& y, int& m, int& d);

int main()
{ // prints calendars
  int year, month, count;
  cout << "Enter year (e.g. 1999): ";           cin >> year;
  cout << "Enter month number (e.g. 9): ";      cin >> month;
  cout << "Enter number of months (e.g. 6): ";  cin >> count;
  int day = 1 - firstDayOf(month,year);
  for (int i=0; i<count; i += 2)
    cout << calendar(year,month,day);
}

void load(string&, const int, const int, const int, int&);

string calendar(int& y, int& m, int& d)
{ // returns a string of 8 lines containing the calendar
  // for the 2 months beginning with month m od year y;
  // the number d (-5 <= d <= 1) is the day number
  // of the first Sunday of month m in year y
  ostringstream ost;
  string line[] = { "", "", "", "", "", "", "", "" };
  for (int n=0; n<8; n++)
    load(line[n],n,y,m,d);
  d = (d - daysIn(m,y))%7;
  if (d > 1) d -= 7;
  ++m;
  if (m > 12)
  { m -= 12;
    ++y;
  }
  string buffer;
  for (int n=0; n<8; n++)
  { load(buffer,n,y,m,d);
    ost << setw(40) << setiosflags(ios::left)
           << line[n] << buffer << "\n";
  }
  ost << "\n";
  d = (d - daysIn(m,y))%7;
  if (d > 1) d -= 7;
  ++m;
  if (m > 12)
  { m -= 12;
    ++y;
  }
  return ost.str();
}


void load(string& buf, const int n, const int y, const int m, int& day)
{ ostringstream out;
  if (n==0) out << " " << setw(23) << setiosflags(ios::left)
             << month(m) << y;
  else if (n==1) out << " Sun Mon Tue Wed Thu Fri Sat";
  else 
    for (int j=0; j<7; j++, day++)
      if (day>0 && day<=daysIn(m,y)) out << setw(4) << day;
      else       out << setw(4) << "";
  buf = out.str();
}
