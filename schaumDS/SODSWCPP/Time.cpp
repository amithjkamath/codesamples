//  Data Structures with C++ by John R. Hubbard
//  Copyright McGraw-Hill, 1999
//  Time.cpp
//  Implementation of Time class

#include "Time.h"

//////////////////////////////////////////////////////////////////////
//  friend function:

ostream& operator<<(ostream& ostr, const Time& time)
{ return ostr << time.toString();
}

istream& operator>>(istream& istr, Time& time)
{ string str;
  istr >> str;
  time = Time(str);
  time.validate();
  return istr;
}

Time operator+(const Time& time1, const Time& time2)
{ return Time(time1._sec + time2._sec);
}

Time operator-(const Time& time1, const Time& time2)
{ return Time(time1._sec - time2._sec);
}

Time operator+(const Time& time1, const double x)
{ return Time(time1._sec + x);
}

Time operator-(const Time& time1, const double x)
{ return Time(time1._sec - x);
}

//////////////////////////////////////////////////////////////////////
//  public members:

Time::Time(double sec)
{ _sec = ( sec>SECONDS_PER_DAY ? sec-SECONDS_PER_DAY : sec);
  validate();
}

Time::Time(int h, int m, double s)
{ _sec = sec(h,m,s);
  validate();
}

Time::Time(string str)
{ int h = atoi(str.substr(0,2).c_str());
  int m = atoi(str.substr(3,2).c_str());
  double s = atof(str.substr(6,2).c_str());
  _sec = sec(h,m,s);
  validate();
}

int Time::hour() const
{ return int(_sec)/3600;
}

int Time::minute() const
{ return (int(_sec)%3600)/60;
}

double Time::second() const
{ int hours = int(_sec)/60;
  return _sec - 60*hours;
}

double Time::hours() const
{ return _sec/3600.0;
}

double Time::minutes() const
{ return _sec/60.0;
}

double Time::seconds() const
{ return _sec;
}

string Time::toString() const
{ int h = hour();
  int m = minute();
  double s = second();
  ostringstream out;
  out << (h<10?"0":"") << h << ":"
      << (m<10?"0":"") << m << ":"
      << (s<10?"0":"") << s;
  return out.str();
}

const Time Time::MIDNIGHT(0,0);

const Time Time::NOON(12,0);

Time Time::now()
{ return Time(__TIME__);
}

Time& Time::operator++()
{ ++_sec;
  validate();
  return *this;
}

Time& Time::operator--()
{ --_sec;
  validate();
  return *this;
}

Time Time::operator++(int)
{ Time temp = *this;
  ++(*this);
  return temp;
}

Time Time::operator--(int)
{ Time temp = *this;
  --(*this);
  return temp;
}

Time& Time::operator+=(const Time& time)
{ _sec += time._sec;
  return *this;
}

Time& Time::operator-=(const Time& time)
{ _sec -= time._sec;
  return *this;
}

Time& Time::operator+=(const double sec)
{ _sec += sec;
  return *this;
}

Time& Time::operator-=(const double sec)
{ _sec -= sec;
  return *this;
}

bool Time::operator<(const Time& t) const
{ return _sec < t._sec;
}

bool Time::operator>(const Time& t) const
{ return _sec > t._sec;
}

bool Time::operator<=(const Time& t) const
{ return _sec <= t._sec;
}

bool Time::operator>=(const Time& t) const
{ return _sec >= t._sec;
}

bool Time::operator==(const Time& t) const
{ return _sec == t._sec;
}

bool Time::operator!=(const Time& t) const
{ return _sec != t._sec;
}

//////////////////////////////////////////////////////////////////////
//  private members:

double Time::sec(int h, int m, double s)
{ return 60.0*(60.0*h + m) + s;
}

void Time::validate()
{ if (_sec < 0.0 || _sec >= SECONDS_PER_DAY) _sec = 0.0;
}

const double Time::SECONDS_PER_DAY=86400.0;
