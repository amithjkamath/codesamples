//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Date.h
//  Implementation of Date class


#include "Date.h"

//////////////////////////////////////////////////////////////////////
//  friend functions:

ostream& operator<<(ostream& ostr, const Date& date)
{ return ostr << date.toString();
}

istream& operator>>(istream& istr, Date& date)
{ string str;
  istr >> str;
  date = Date(str);
  return istr;
}

int operator-(const Date& date1, const Date& date2)
{ return date1._day - date2._day;
}

Date operator+(const Date& date1, const int days)
{ return Date(date1._day + days);
}

Date operator-(const Date& date1, const int days)
{ return Date(date1._day - days);
}

//////////////////////////////////////////////////////////////////////
//  public members:

Date::Date(int day) : _day(day)
{ validate();
}

Date::Date(int year, int month, int day)
{ int y = year - BASE_YEAR;  // number of years in current era
  int nqc = y/400;  // number of quadcenturies in current era
  int nc  = y%400/100;  // number of centuries in current quadcentury
  int nqy  = y%100/4;  // number of quadyears in current century
  int ny  = y%4;  // number of years in current quadyear
  _day = LQC*nqc + LC*nc + LQY*nqy + LY*ny;
  for (int m=1; m<month; m++)
    _day += daysInMonth(m,year);
  _day += day;
  validate();
}

Date::Date(string s)
{ char* buf = new char[s.length()+1];
  s.copy(buf,s.length(),0);  // copy C++ string s into C-string p
  buf[s.length()] = 0;       // C-strings are null-terminated
  const char* p = strtok(buf, " ,");  // see p. 213 in PWCPP
  string monthName(p);  // convert C-string to C++ string 
  int m = monthNumber(monthName);
  p = strtok(NULL, " ,");  // extract day of month number
  if (isalpha(*p)) // maybe this is the month name
  { string monthName(p);  // convert C-string to C++ string 
    m = monthNumber(monthName);
    p = strtok(NULL, " ,");  // extract day of month number
  }
  int d = atoi(p);
  p = strtok(NULL, " ,");  // extract year number
  int y = atoi(p);
  *this = Date(y,m,d);
  validate();
}

int Date::day() const
{ return _day;
}

int Date::year() const
{ // returns the current calendar year
  int qcn1 = quadcenturyNum()-1;
  int cn1 = centuryNum()-1;
  int qyn1 = quadyearNum()-1;
  int yn1 = yearNum()-1;
  return BASE_YEAR + 400*qcn1 + 100*cn1 + 4*qyn1 + yn1;
}

int Date::month() const
{ int d = dayOfYear();
  int y = year();
  for (int m=1; m<12; m++)
  { if (d <= daysInMonth(m,y)) return m;
    d -= daysInMonth(m,y);
  }
  return 12;
}

int Date::dayOfMonth() const
{ int d = dayOfYear();
  int y = year();
  for (int m=1; m<12; m++)
  { if (d <= daysInMonth(m,y)) return d;
    d -= daysInMonth(m,y);
  }
  return d;
}

int Date::dayOfYear() const
{ // returns the current day number within the current year
  return (_day-1)%LQC%LC%LQY%LY+1;
}

string Date::dayOfWeek() const
{ string day[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
  return day[_day%7];  // Dec 31 1600 was a Sunday
}

string Date::toString() const
{ ostringstream out;
  if (_day == 0) return "NAD";  // "Not A Date"
  out << dayOfWeek() << " " << monthName(month()) << " "
      << dayOfMonth() << " " << year();
  return out.str();
}

const Date Date::Y2K(145732);  // Sat Jan  1 2000

Date Date::today()
{ return Date(__DATE__);
}

Date& Date::operator++()
{ ++_day;
  validate();
  return *this;
}

Date& Date::operator--()
{ --_day;
  validate();
  return *this;
}

Date Date::operator++(int)
{ Date temp = *this;
  ++(*this);
  return temp;
}

Date Date::operator--(int)
{ Date temp = *this;
  --(*this);
  return temp;
}

Date& Date::operator+=(const int days)
{ _day += days;
  return *this;
}

Date& Date::operator-=(const int days)
{ _day -= days;
  return *this;
}

bool Date::operator<(const Date& date) const
{ return _day < date._day;
}

bool Date::operator>(const Date& date) const
{ return _day > date._day;
}

bool Date::operator<=(const Date& date) const
{ return _day <= date._day;
}

bool Date::operator>=(const Date& date) const
{ return _day >= date._day;
}

bool Date::operator==(const Date& date) const
{ return _day == date._day;
}

bool Date::operator!=(const Date& date) const
{ return _day != date._day;
}

//////////////////////////////////////////////////////////////////////
//  private members:

int Date::yearNum() const
{ // returns the year number within its quadyear period
  // INVARIANT: 1 <= yearNum() <= 4
  // 1 = (Jan 1 1601 - Dec 31 1601) = (Jan 1 1997 - Dec 31 1997)
  // 4 = (Jan 1 1604 - Dec 31 1604) = (Jan 1 2000 - Dec 31 2000)
  return (_day-1)%LQC%LC%LQY/LY+1;
}

int Date::quadyearNum() const
{ // returns the quadyear number within its century
  // INVARIANT: 1 <= quadyearNum() <= 25
  // 1 = (Jan 1 1601 - Dec 31 1604) = (Jan 1 1901 - Dec 31 1904)
  // 25 = (Jan 1 1997 - Dec 31 2000)
  return (_day-1)%LQC%LC/LQY+1;
}

int Date::centuryNum() const
{ // returns the century number within its quadcentury period
  // INVARIANT: 1 <= centuryNum() <= 4
  // 1 = (Jan 1 1601 - Dec 31 1700) = (Jan 1 2001 - Dec 31 2100)
  // 4 = (Jan 1 1901 - Dec 31 2000)
  return (_day-1)%LQC/LC+1;
}

int Date::quadcenturyNum() const
{ // returns the quadcentury number beginning with 1601-2000
  // INVARIANT: 1 <= quadyearNum()
  // 1 = (Jan 1 1601 - Dec 31 2000)
  // 2 = (Jan 1 2001 - Dec 31 2400)
  return (_day-1)/LQC+1;
}

bool Date::isLeap(const int y)
{ if (y%400 == 0) return true;
  if (y%100 == 0) return false;
  if (y%4 == 0) return true;
  return false;
}

int Date::monthNumber(string s)
{ if (s.length() < 3) return 12;
  s = s.substr(0,3);
  s[0] = toupper(s[0]);
  s[1] = toupper(s[1]);
  s[2] = toupper(s[2]);
  if (s=="JAN") return 1;
  if (s=="FEB") return 2;
  if (s=="MAR") return 3;
  if (s=="APR") return 4;
  if (s=="MAY") return 5;
  if (s=="JUN") return 6;
  if (s=="JUL") return 7;
  if (s=="AUG") return 8;
  if (s=="SEP") return 9;
  if (s=="OCT") return 10;
  if (s=="NOV") return 11;
  return 12;
}

string Date::monthName(const int m)
{ switch (m)
  { case  1: return "Jan";
    case  2: return "Feb";
    case  3: return "Mar";
    case  4: return "Apr";
    case  5: return "May";
    case  6: return "Jun";
    case  7: return "Jul";
    case  8: return "Aug";
    case  9: return "Sep";
    case 10: return "Oct";
    case 11: return "Nov";
    default: return "Dec";  
  }
}

int Date::daysInMonth(const int m, const int y)
{ switch (m)
  { case  1: return 31;
    case  2: return 28 + (isLeap(y)?1:0);
    case  3: return 31;
    case  4: return 30;
    case  5: return 31;
    case  6: return 30;
    case  7: return 31;
    case  8: return 31;
    case  9: return 30;
    case 10: return 31;
    case 11: return 30;
    default: return 31;  
  }
}

void Date::validate()
{ if (_day<1) _day = 0;
}

const int Date::LY=365;
const int Date::LQY=4*LY+1;    //   1461
const int Date::LC= 25*LQY-1;  //  36524
const int Date::LQC=4*LC+1;    // 146097
const int Date::BASE_YEAR=1601;
